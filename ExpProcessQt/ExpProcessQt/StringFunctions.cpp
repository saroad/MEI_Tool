#include "StringFunctions.h"

StringFunctions* StringFunctions::instance;
bool StringFunctions::instanceFlag=false;

StringFunctions::StringFunctions(){}

StringFunctions* StringFunctions::getInstance()
{
	//cout<<"X"<<endl;
    if(!instanceFlag)
    {
        instance = new StringFunctions();
		instanceFlag=true;
		//cout<<"Y"<<endl;
        return instance;
    }
    else
    {
        return instance;
    }
}

StringFunctions::~StringFunctions(){
	instanceFlag=false;
	delete(instance);
}


vector<string> StringFunctions::splitString(string input, string delimiter, bool withDelimiter){
	vector<string> output;
    size_t pos = 0;
	string token;
	
	while ( pos != string::npos) {
        pos = input.find(delimiter);
    	token = input.substr(0, pos);
		if(!token.empty()){
			output.push_back(token);
			if(withDelimiter && pos!=string::npos) output.push_back(delimiter);
		}
    	//cout << token <<endl;
    	input.erase(0, pos + delimiter.length());
	}
	return(output);
	//cout << delimiter.length() <<endl;
}

pair<string, string> StringFunctions::getPrePostFixes(string input, string delimiter){

	int start=input.find(delimiter);
	int end=start+delimiter.size();
	return(make_pair(input.substr(0,start),input.substr(end)));

}

int StringFunctions::countSubstr(string input, string substr){

	int pos=input.find(substr), count=0;
	while ( pos != string::npos) {
		count++;
        pos=input.find(substr, pos+substr.size());
	}
	return(count);

}

string StringFunctions::removeWhiteSpaces(string input){
	input.erase(remove(input.begin(),input.end(),' '),input.end());
	return input;
}

bool StringFunctions::match(string regex, string input){
	int i;
	if(regex.size()==0) return(true);
	if(regex[0]=='#'){
		i=0;
		do{
			if(match(regex.substr(1), input.substr(i))) return(true);
			i++;
		}while(i<input.size());
		return(false);
	}
	if(regex[0]==input[0]) return(match(regex.substr(1), input.substr(1)));
	else return(false);
}

string StringFunctions::replaceAll(string input, string replaceable, string replacer){
	int pos=input.find(replaceable);
	while ( pos != string::npos) {
        input.replace(pos, replaceable.size(), replacer);
        pos=input.find(replaceable, pos+replacer.size());
	}
	return(input);
}

vector<string> StringFunctions::addVectorValues(vector<string> vec1, vector<string> vec2){

	vector<string> combinedVec;
	string temp;
	int len1=vec1.size(), len2=vec2.size();

	combinedVec.reserve((int)(len1*len2*1.1));

	for(int i=0; i<len1; i++){
		temp=vec1[i];
		for(int j=0; j<len2; j++) combinedVec.push_back(temp+vec2[j]);
	}

	return(combinedVec);
}

vector<vector<string> > StringFunctions::combineVectors(vector<vector<string> > vec1, vector<string> vec2){

	vector<string> temp;
	int len1=vec1.size(), len2=vec2.size();

	if(len1==0){
        for(int j=0; j<len2; j++){
			temp.push_back(vec2[j]);
			vec1.push_back(temp);
			temp.clear();
		}
		return(vec1);
	}

	for(int i=0; i<len1; i++){
        temp=vec1[i];
		for(int j=0; j<len2; j++){

			temp.push_back(vec2[j]);
			vec1.push_back(temp);
			temp.erase(temp.end()-1);
		}
	}
	
	vec1.erase(vec1.begin(),vec1.begin()+len1);

	return(vec1);
}

pair<int, int> StringFunctions::getBracketInclusion(string input, pair<char, char> bracketPair){

	int start=0, end=input.size()-1;

	while(end>start){

		if(input[start]==bracketPair.first && input[end]==bracketPair.second) return(make_pair(start, end));
		if(input[start]!='{' || input[end]!='}') break;
		start++;
		end--;
	}

	return(make_pair(-1, -1));
}

string StringFunctions::removeBracketPair(string input, pair<char, char> bracketPair){

	pair<int, int> pos=getBracketInclusion(input, bracketPair);
	
	if(pos.first!=-1){
		input.replace(pos.first, 1, "");
		input.replace(pos.second-1, 1, "");
	}

	return(input);
}

string StringFunctions::insertBrackets(string input, pair<char,char> bracketPair){

	int pos=0, posOpen=0;
	string bracOpen(1, bracketPair.first), bracClose(1, bracketPair.second);
	char posVal;
	vector<int> bracStack;

	while(pos<input.size()){

		posVal=input[pos];
		if(posVal==bracketPair.first){
			bracStack.push_back(pos);
		}
		else if(posVal==bracketPair.second){
			if(bracStack.size()>0){
				posOpen=bracStack.back();
				bracStack.pop_back();
			}
			else{
				insertChar(&input, posOpen, bracOpen);
				pos++;
			}
		}

		pos++;
	}
	while(bracStack.size()){
		input+=bracClose;
		bracStack.pop_back();
	}

	return(input);
}

void StringFunctions::insertChar(string *input, int index, string inserted){

	string prefix=input->substr(0, index), postfix=input->substr(index);
	*input=prefix+inserted+postfix;

}