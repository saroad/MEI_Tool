#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

#ifndef ANY_TYPE_H
#define ANY_TYPE_H

class AnyType{

public:
	AnyType();
	AnyType(int _maxItem);
	~AnyType();
	void setItem(int item, string field);
	void setItem(string item, string field);
	void setItem(bool item, string field);
	void setItem(long long item, string field);
	void setItem(double item, string field);
	void getItem(int *item, string field);
	void getItem(string *item, string field);
	void getItem(bool *item, string field);
	void getItem(long long *item, string field);
	void getItem(double *item, string field);


private:
	int *intItem, maxItem, index;
	string *stringItem;
	bool *boolItem;
	long long *longLongItem;
	double *doubleItem;
	string *dictionary;
	int findField(string field);
	
};


#endif