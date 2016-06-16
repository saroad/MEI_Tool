#include "TokenLibrary.h"

TokenLibrary* TokenLibrary::instance;
bool TokenLibrary::instanceFlag=false;

TokenLibrary::TokenLibrary(){
	DataManager=DataAccess::getInstance();
	tokenTable=DataManager->getMappings();
	filter();
	stringManipulator=StringFunctions::getInstance();
}

TokenLibrary* TokenLibrary::getInstance()
{
    if(!instanceFlag)
    {
        instance = new TokenLibrary();
		instanceFlag=true;
        return instance;
    }
    else
    {
        return instance;
    }
}

TokenLibrary::~TokenLibrary(){
	instanceFlag=false;
	delete(instance);
}

string TokenLibrary::getToken(int index){
	string out;
	tokenTable->at(index).getItem(&out, "input_str");
	return(out);
}

string TokenLibrary::getToken(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	string out;

	list[index].getItem(&out, "input_str");

	return(out);
}

string TokenLibrary::getLatex(int index){
	string out;
	tokenTable->at(index).getItem(&out, "latex");
	return(out);
}

string TokenLibrary::getLatex(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	string out;

	list[index].getItem(&out, "latex");

	return(out);
}

string TokenLibrary::getRegex(int index){
	string out;
	tokenTable->at(index).getItem(&out, "input_format");
	return(out);
}

string TokenLibrary::getRegex(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	string out;

	list[index].getItem(&out, "input_format");

	return(out);
}

int TokenLibrary::getNumOfPara(int index){
	int out;
	tokenTable->at(index).getItem(&out, "no_of_para");
	return(out);
}

int TokenLibrary::getNumOfPara(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	int out;

	list[index].getItem(&out, "no_of_para");

	return(out);
}

vector<string> TokenLibrary::getPara(int index){
	string out;
	tokenTable->at(index).getItem(&out, "para");
	vector<string> para=StringFunctions::splitString(out,"||",false);
	return(para);
}

vector<string> TokenLibrary::getPara(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	string out;

	list[index].getItem(&out, "para");

	vector<string> para=StringFunctions::splitString(out,"||",false);
	return(para);
}

bool TokenLibrary::getBracketState(int index){

	bool out;
	tokenTable->at(index).getItem(&out, "brac_essential");
	return(out);
}

bool TokenLibrary::getBracketState(int index, string type){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	bool out;

	list[index].getItem(&out, "brac_essential");

	return(out);
}

pair<int,int> TokenLibrary::searchToken(string input){

	int start=-1, end=-1, i=0;

	while(i<tokenTable->size()){
		if(stringManipulator->match(input+"#", getToken(i))){
			start=i;
			break;
		}
		i++;
	}

	if(start==-1) return(make_pair(start, end));
	while(i<tokenTable->size()){
		if(!(stringManipulator->match(input+"#", getToken(i)))){
			break;
		}
		i++;
		end=i;
	}
	
	return(make_pair(start, end));
}

pair<AnyType*, int> TokenLibrary::getList(string type){
	
	if(type=="operator") return(make_pair(operatorList,operatorListSize));
	else if (type=="letter" || type=="symbol") return(make_pair(letterList,letterListSize));
	else if (type=="constructs") return(make_pair(constructList,constructListSize));
	else if (type=="function") return(make_pair(functionList,functionListSize));

}

pair<int,int> TokenLibrary::searchToken(string input, string type, int start, int end){

	pair<AnyType*, int> listDetails=getList(type);
	AnyType *list=listDetails.first;
	int size=listDetails.second;
	string token;
	int i;
	if(start==-1) i=0;
	else{
		i=start;
		start=-1;
	}
	if(end==-1) end=size;

	while(i<end){
		list[i].getItem(&token,"input_str");
		if(stringManipulator->match(input+"#", token)){
			start=i;
			break;
		}
		i++;
	}

	if(start==-1) return(make_pair(start, end));
	int tempEnd=end;
	while(i<tempEnd){
		list[i].getItem(&token,"input_str");
		if(!(stringManipulator->match(input+"#", token))){
			break;
		}
		i++;
		end=i;
	}
	
	return(make_pair(start, end));
}

void TokenLibrary::filter(){
	
	vector<int> operators, letters, constructs, functions;
	string type, token;

	for(int i=0; i<tokenTable->size(); i++){

		tokenTable->at(i).getItem(&type, "exp_type");
		tokenTable->at(i).getItem(&token, "input_str");

		if(type=="operator") operators.push_back(i);
		else if (type=="letter" || type=="symbol") letters.push_back(i);
		else if (type=="constructs" && token!="{" && token!="}") constructs.push_back(i);
		else if (type=="function") functions.push_back(i);

	}

	operatorListSize=operators.size();
	letterListSize=letters.size();
	functionListSize=functions.size();
	constructListSize=constructs.size();

	operatorList=new AnyType[operatorListSize];
	for(int i=0; i<operatorListSize; i++) operatorList[i]=tokenTable->at(operators[i]);

	letterList=new AnyType[letterListSize];
	for(int i=0; i<letterListSize; i++) letterList[i]=tokenTable->at(letters[i]);

	constructList=new AnyType[constructListSize];
	for(int i=0; i<constructListSize; i++){
		constructList[i]=tokenTable->at(constructs[i]);
	}

	functionList=new AnyType[functionListSize];
	for(int i=0; i<functionListSize; i++) functionList[i]=tokenTable->at(functions[i]);

	qDebug()<<"Total size: "<<operatorListSize+letterListSize+functionListSize+constructListSize;

}