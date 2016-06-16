#include "Expression.h"


Expression::Expression(string txt){

	inputText=new string(txt);
	tokenLibrary=TokenLibrary::getInstance();

	processExpression();
	
}

void Expression::processExpression(){

	string input=StringFunctions::removeWhiteSpaces(*inputText);
	input=StringFunctions::replaceAll(input, "{", "(");
	input=StringFunctions::replaceAll(input, "}", ")");
	input=StringFunctions::insertBrackets(input, make_pair('(',')'));

	vector<string> result=translate1(input);
	vector<string> temp;

	for(int i=0; i<result.size(); i++){
		out=Output(result[i]);
		out.printOutput();
		result[i]=StringFunctions::replaceAll(result[i], "(", "{(");
		result[i]=StringFunctions::replaceAll(result[i], ")", ")}");
		temp=translate2(result[i], 0);
		processedResult=StringFunctions::appendVectors(processedResult, temp);
	}

	sort(processedResult.begin(), processedResult.end(), compareFormula);

	/*qDebug()<<"Final Results("<<processedResult.size()<<"): ";
	for(int i=0; i<processedResult.size(); i++){
		out=Output(processedResult[i]);
		out.printOutput();
	}*/

	createOutput();

}

void Expression::createOutput(){ //Maybe optimised

	int total=processedResult.size(); 

	if(total<=MAX_OUT_SIZE) {
		outputResult=processedResult;
		return;
	}

	int index, r;

	for(int i=0; i<MAX_OUT_SIZE; i++){

		if(i%2==0) r=i/2;
		else r=MAX_OUT_SIZE-1-(i-1)/2;

		index=(int)(total*r/MAX_OUT_SIZE);
		outputResult.push_back(processedResult[index]);
	}

	if(outputResult[1]!=processedResult.back()) outputResult.insert(outputResult.begin()+1, processedResult.back());

}

//string Expression::processExpression(string input){
//	bool modify;
//    int i;
//    string stPart;
//    stack<string> *Stk=new stack<string>();
//    Stk->push("");
//    while(input!=")"){
//    	i=1;
//    	modify=false;
//    	while(input[i]!='('){
//    		if(input[i]==')'){
//    			if(input[0]==')'){
//	   				stPart=Expression::popStack(Stk)+input.substr(1,i-1);
//                    //while(stPart.contains("--")) stPart=stPart.replaceAll("--", "+");
//					stPart=Expression::translate1(stPart);
//	   				stPart=Expression::popStack(Stk)+stPart;
//	   				Stk->push(stPart);
//	   				input=input.substr(i);
//	   				modify=true;
//	   				break;
//    			}
//    			else{
//		            stPart=input.substr(1,i-1);
//                    //while(stPart.contains("--")) stPart=stPart.replaceAll("--", "+");
//    				stPart=Expression::translate1(stPart);
//    				stPart=Expression::popStack(Stk)+stPart;
//    				Stk->push(stPart);
//    				input=input.substr(i);
//    				modify=true;
//    				break;
//    			}
//    		}
//    		i++;
//    	}
//    	if(modify==true) continue;
//    	if(input[0]=='('){
//    		Stk->push(input.substr(1,i-1));
//    		input=input.substr(i);
//    	}
//    	else{
//    		stPart=Expression::popStack(Stk)+input.substr(1,i-1);
//    		Stk->push(stPart);
//    		input=input.substr(i);
//    	}
//    }
//    return(Expression::popStack(Stk));
//}


//string Expression::translate(string input){
//
//	vector<string> tokens;
//	string output="";
//
//	if(input.find("+")==string::npos && input.find("-")==string::npos && input.find("/")==string::npos && input.find("*")==string::npos){
//		return(input);
//	}
//	if(input=="+" || input=="-" || input=="/" || input=="*"){
//		return(Expression::getLatex(input));
//	}
//	if(input.find("+-")!=string::npos){
//		tokens=StringFunctions::splitString(input, "+-");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}
//	if(input.find("-+")!=string::npos){
//		tokens=StringFunctions::splitString(input, "-+");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}
//	if(input.find("+")!=string::npos){
//		tokens=StringFunctions::splitString(input, "+");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}
//	if(input.find("-")!=string::npos){
//		tokens=StringFunctions::splitString(input, "-");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}
//	if(input.find("*")!=string::npos){
//		tokens=StringFunctions::splitString(input, "*");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}
//	if(input.find("/")!=string::npos){
//		size_t pos=input.find("/");
//		string numerator = input.substr(0, pos);
//		input.erase(0, pos + 1);
//		output=Expression::translate("/")+"{"+Expression::translate(numerator)+"}{"+Expression::translate(input)+"}";
//		return(output);
//	}
//	/*if(input.find("*")!=string::npos){
//		tokens=StringFunctions::splitString(input, "*");
//		for(int i=0; i<tokens.size(); i++) output+=Expression::translate(tokens[i]);
//		return(output);
//	}*/
//	return("");
//}

vector<string> Expression::translate1(string input){

	vector<string> resultSet;

	if(input==""){
		resultSet.push_back("");
		return(resultSet);
	}

	vector<pair<int, int>> searchResult;
	pair<int, int> tempPair;
	vector<string> tempVec;

	string type;
	type="operator";
	searchResult=searchLatex(input, type);
	if(searchResult.size()!=0){
		for(int i=0; i<searchResult.size(); i++){
			tempPair=searchResult[i];
			tempVec.push_back("{"+tokenLibrary->getLatex(tempPair.first,type)+"}");
			resultSet=StringFunctions::appendVectors(resultSet, StringFunctions::addVectorValues(tempVec, translate1(input.substr(tempPair.second))));
			tempVec.clear();
		}
		return(resultSet);
	}

	type="letter";
	searchResult=searchLatex(input, type);
	if(searchResult.size()!=0){
		for(int i=0; i<searchResult.size(); i++){
			tempPair=searchResult[i];
			tempVec.push_back("{"+tokenLibrary->getLatex(tempPair.first,type)+"}");
			resultSet=StringFunctions::appendVectors(resultSet, StringFunctions::addVectorValues(tempVec, translate1(input.substr(tempPair.second))));
			tempVec.clear();
		}
		return(resultSet);
	}

	tempVec.push_back(input.substr(0,1));

	return(StringFunctions::addVectorValues(tempVec,translate1(input.substr(1))));
}

vector<string> Expression::translate2(string input, int start){

	vector<string> resultSet;

	if(input==""){
		resultSet.push_back("");
		return(resultSet);
	}

	pair<int, int> tempPair;
	vector<string> tempVec;
	pair<vector<string>, pair<int, int> > latexResults;
	string tempLatex, inputCopy;
	vector<pair<int, int> > searchResult;
	int pos=start;

	while(pos<input.size()){

		searchResult=searchLatex(input.substr(pos), "constructs");
		/*out=Output("Input: ")+Output(input);
		out.printOutput();*/
		if(searchResult.size()!=0) break;
		pos++;
	}

	if(pos==input.size()){
		resultSet.push_back(input);
		return(resultSet);
	}
		
	for(int i=0; i<searchResult.size(); i++){
		latexResults=processParameters(&input, pos, pos+searchResult[i].second, searchResult[i].first, "constructs");
		for(int j=0; j<latexResults.first.size(); j++){
			tempLatex=latexResults.first.at(j);
			inputCopy=input;
			//input->replace(prePair.first, end+postPair.first-prePair.first+1,latex); //end+postPair.first-prePair.first+1=(start-prePair.first)+(end-start)+(postPair.first+1)=total replaceable lenghth
			inputCopy.replace(latexResults.second.first, pos+searchResult[i].second+latexResults.second.second-latexResults.second.first+1,tempLatex);
			//retun(prePair.first+latex.size());
			resultSet=StringFunctions::appendVectors(resultSet, translate2(inputCopy, latexResults.second.first+tempLatex.size()));
		}
	}

	return(resultSet);

}

pair<vector<string>, pair<int, int> > Expression::processParameters(string *input, int start, int end, int tokenIndex, string type){
	
	vector<vector<string> > paraAll;
	vector<string> paraList=tokenLibrary->getPara(tokenIndex, type);
	string regex=tokenLibrary->getRegex(tokenIndex, type);
	pair<string, string> fixes=StringFunctions::getPrePostFixes(regex, tokenLibrary->getToken(tokenIndex, type));
	string prefix=fixes.first, postfix=fixes.second;
	
	int prePara=0, postPara=0;
	for(int i=0; i<paraList.size(); i++){
		prePara+=StringFunctions::countSubstr(prefix, paraList[i]);
		postPara+=StringFunctions::countSubstr(postfix, paraList[i]);
	}
	
	pair<int, vector<string> > prePair=extractParameters(input->substr(0,start),prePara,-1);
	reverse(prePair.second.begin(),prePair.second.end());
	while(prePair.second.size()<prePara) prePair.second.push_back("");

	pair<int, vector<string> > postPair=extractParameters(input->substr(end),postPara,1);
	vector<vector<string> > combinedPostPair;
	for(int i=0; i<postPair.second.size(); i++) combinedPostPair=StringFunctions::combineVectors(combinedPostPair, translate2(postPair.second.at(i), 0));
	for(int i=0; i<combinedPostPair.size(); i++){
		while(combinedPostPair.at(i).size()<postPara) combinedPostPair.at(i).push_back("");
		paraAll.push_back(StringFunctions::appendVectors(prePair.second, combinedPostPair[i]));
	}

	if(!tokenLibrary->getBracketState(tokenIndex, type)){;
		vector<string> tempPara1;
		vector<string> tempPara2;
		bool isChanged;
		string processedPara;
		pair<char, char> bracketPair=make_pair('(', ')');
		int paraListNum=paraAll.size();

		for(int i=0; i<paraListNum; i++){
			tempPara1=paraAll[i];
			isChanged=false;
			for(int j=0; j<tempPara1.size(); j++){
				processedPara=StringFunctions::removeBracketPair(tempPara1[j], bracketPair);
				tempPara2.push_back(processedPara);
				if(tempPara1[j]!=processedPara) isChanged=true;
			}
			if(isChanged) paraAll.push_back(tempPara2);
			tempPara2.clear();
		}
	}

	string latex=tokenLibrary->getLatex(tokenIndex, type);
	vector<string> latexList;

	for(int i=0; i<paraAll.size(); i++){
		latexList.push_back(latex);
		for(int j=0; j<paraList.size(); j++) latexList[i]=insertParameters(latexList[i], paraList[j], &(paraAll[i]), regex);
		latexList[i]="{"+latexList[i]+"}";
	}

	return(make_pair(latexList, make_pair(prePair.first, postPair.first)));

}

string Expression::insertParameters(string latex, string para, vector<string> *parameters, string regex){
	
	int latexPos=0, regexPos=0, count=0;
	while(1){

		latexPos=latex.find(para, latexPos);
		if(latexPos==string::npos) break;
		regexPos=regex.find("para", regexPos);
		count++;
		if(regex[regexPos-1]==para[0]){
			latex.replace(latexPos, para.size(), parameters->at(count-1));
			latexPos+=parameters->at(count-1).size();
			parameters->at(count-1)="";
		}
		regexPos+=para.size();

	}
	
	int i=0;
	while(i<parameters->size()){
		if(parameters->at(i)==""){
			parameters->erase(parameters->begin()+i);
			continue;
		}
		i++;
	}

	return(latex);
}


pair<int, vector<string>> Expression::extractParameters(string input, int count, int direction){
	
	int start, end, brackets, pos, lastTaken;
	char posVal;
	bool proceed1, proceed2;
	string paraBuff;
	vector<string> paraStrings;

	if(direction==1){
		start=0;
		end=input.size();
	}
	else {
		start=input.size()-1;
		end=-1;
	}
	pos=start;

	for(int i=0; i<count; i++){
		if(pos==end) break;
		proceed1=false;
		proceed2=true;
		brackets=0;
		paraBuff="";
		lastTaken=-1;

		do{
			if(pos==end) break;

			posVal=input[pos];

			if(posVal=='{' && (pos==start || brackets!=0)){
				brackets++;
				if(direction==1) paraBuff+=string(1, posVal);
				else paraBuff=string(1, posVal)+paraBuff;
				lastTaken=pos;
				if(brackets==0) proceed2=false;
			}
			else if(posVal=='}' && (pos==start || brackets!=0)){
				brackets--;
				if(direction==1) paraBuff+=string(1, posVal);
				else paraBuff=string(1, posVal)+paraBuff;
				lastTaken=pos;
				if(brackets==0) proceed2=false;
			}
			else if(isalnum(posVal) || posVal=='.'){
				proceed1=true;
				if(direction==1) paraBuff+=string(1, posVal);
				else paraBuff=string(1, posVal)+paraBuff;
				lastTaken=pos;
			}
			else{
				proceed1=false;
				if(brackets!=0){
					if(direction==1) paraBuff+=string(1, posVal);
					else paraBuff=string(1, posVal)+paraBuff;
					lastTaken=pos;
				}
			}
			
			pos+=direction;
			/*out=Output("Pos: ")+Output(pos);
			out.printOutput();*/

		}while(proceed2 && (proceed1 || brackets!=0));
		pos=lastTaken+direction;
		paraStrings.push_back(paraBuff);
	}
	
	return(make_pair(lastTaken, paraStrings));
}

vector<pair<int, int>> Expression::searchLatex(string input, string type){

	vector<pair<int, int>> result;	
	pair<int, int> range;
	int start, end, len=0;
	string substring, tempSubstring;
	
	tempSubstring=input.substr(0,1);
	range=tokenLibrary->searchToken(tempSubstring, type);

	if(range.first!=-1){
		substring=tempSubstring;
		len=1;
		start=range.first; end=range.second;
		for(int i=1; i<input.size(); i++){
			tempSubstring=input.substr(0,i+1);
			range=tokenLibrary->searchToken(tempSubstring, type, start, end);
			if(range.first==-1) break;
			substring=tempSubstring;
			len=i+1;
			start=range.first;
			end=range.second;
		}
		for(int i=start; i<end; i++){
			if(substring==tokenLibrary->getToken(i, type)){
				result.push_back(make_pair(i,len));
			}
		}
	}
	return(result);
}


bool Expression::compareFormula(string input1, string input2){

	if(input1.size()<input2.size()) return(false);
	else if(input1.size()>input2.size()) return(true);
	else{
		if(input1.compare(input2)<=0) return(false);
		else return(true);
	}
}
vector<string> Expression::getOutput(){
	return(outputResult);
}