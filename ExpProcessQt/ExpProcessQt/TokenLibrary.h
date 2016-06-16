#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <QDebug>

#include "DataAccess.h"
#include "StringFunctions.h"
#include "AnyType.h"

using namespace std;

#ifndef TOKENLIBRARY_H
#define TOKENLIBRARY_H

class TokenLibrary
{
private:
    static bool instanceFlag;
    static TokenLibrary *instance;
    TokenLibrary();
	vector<AnyType> *tokenTable;
	DataAccess* DataManager;
	StringFunctions *stringManipulator;
	AnyType *operatorList;
	AnyType *letterList;
	AnyType *functionList;
	AnyType *constructList;
	void filter();
	pair<AnyType*, int> getList(string type);
	int operatorListSize, letterListSize, functionListSize, constructListSize;
    
public:
    static TokenLibrary* getInstance();
    ~TokenLibrary();
	pair<int, int> searchToken(string input);
	pair<int, int> searchToken(string input, string type, int start=-1, int end=-1);
	string getToken(int index);
	string getToken(int index, string type);
	string getLatex(int index);
	string getLatex(int index, string type);
	string getRegex(int index);
	string getRegex(int index, string type);
	int getNumOfPara(int index);
	int getNumOfPara(int index, string type);
	bool getBracketState(int index);
	bool getBracketState(int index, string type);
	vector<string> getPara(int index);
	vector<string> getPara(int index, string type);
	int getHits(int index);
	vector<string> getParaLiteral(int index);
};

#endif