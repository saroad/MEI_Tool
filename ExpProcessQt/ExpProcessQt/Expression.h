#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>

#include "StringFunctions.h"
#include "TokenLibrary.h"
#include "Output.h"

#define MAX_OUT_SIZE 6

using namespace std;

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression{

public:
	Expression(string txt);
	vector<string> getOutput();
	template<class T> T popStack(stack<T> *stk);

private:
	string *inputText;
	string outputText;
	vector<string> processedResult;
	vector<string> outputResult;
	vector<string> translate1(string input);
	vector<string> translate2(string input, int start);
	void processExpression();
	TokenLibrary *tokenLibrary;
	vector<pair<int, int> > searchLatex(string input, string type);
	pair<vector<string>, pair<int, int> > processParameters(string *input, int start, int end, int tokenIndex, string type);
	pair<int, vector<string> > extractParameters(string input, int count, int direction);
	string insertParameters(string latex, string para, vector<string> *parameters, string regex);
	static bool compareFormula(string input1, string input2);
	void createOutput();

	Output out;
};

template<class T> T Expression::popStack(stack<T> *stk){
	string out=stk->top();
	stk->pop();
	return(out);
}



#endif