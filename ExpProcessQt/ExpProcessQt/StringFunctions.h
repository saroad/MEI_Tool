#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Output.h"

using namespace std;

#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

class StringFunctions
{
private:
    static bool instanceFlag;
    static StringFunctions *instance;
    StringFunctions();
    
public:
    static StringFunctions* getInstance();
    ~StringFunctions();
	static vector<string> splitString(string input, string delimiter, bool withDelimiter=true);
	static string removeWhiteSpaces(string input);
	static bool match(string regex, string input);
	static string replaceAll(string input, string replaceable, string replacer);
	static pair<string, string> StringFunctions::getPrePostFixes(string input, string delimiter);
	static int countSubstr(string input, string substr);
	static vector<string> addVectorValues(vector<string> vec1, vector<string> vec2);
	template<class T> static vector<T> appendVectors(vector<T> vec1, vector<T> vec2);
	static vector<vector<string> > combineVectors(vector<vector<string> >  vec1, vector<string> vec2);
	static pair<int, int> getBracketInclusion(string input, pair<char, char> bracketPair);
	static string removeBracketPair(string input, pair<char, char> bracketPair);
	static string insertBrackets(string input, pair<char, char> bracketPair);
	static void insertChar(string *input, int index, string inserted);
};

template<class T> vector<T> StringFunctions::appendVectors(vector<T> vec1, vector<T> vec2){

	vector<T> combinedVec(vec1);
	int len1=vec1.size();

	for(int i=0; i<vec2.size(); i++){
		combinedVec.push_back(vec2[i]);
	}

	return(combinedVec);
}

#endif