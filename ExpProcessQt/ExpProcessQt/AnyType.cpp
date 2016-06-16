#include "AnyType.h"

//int* AnyType::intItem;
//string* AnyType::stringItem;
//bool* AnyType::boolItem;
//long long* AnyType::longLongItem;
//double* AnyType::doubleItem;
//string* AnyType::dictionary;
//int* AnyType::maxItem;
//int* AnyType::index;

AnyType::AnyType(){}

AnyType::AnyType(int _maxItem){
	index=0;
	maxItem=_maxItem;
	intItem=new int[maxItem];
	stringItem=new string[maxItem];
	boolItem=new bool[maxItem];
	longLongItem=new long long[maxItem];
	doubleItem=new double[maxItem];
	dictionary=new string[maxItem];
}

AnyType::~AnyType(){
	delete[] intItem;
	delete[] stringItem;
	delete[] boolItem;
	delete[] longLongItem;
	delete[] doubleItem;
	delete[] dictionary;
}

void AnyType::setItem(int item, string field){
	intItem[index]=item;
	dictionary[index]=field;
	index++;
}

void AnyType::setItem(string item, string field){
	stringItem[index]=item;
	dictionary[index]=field;
	index++;
}

void AnyType::setItem(bool item, string field){
	boolItem[index]=item;
	dictionary[index]=field;
	index++;
}

void AnyType::setItem(long long item, string field){
	longLongItem[index]=item;
	dictionary[index]=field;
	index++;
}

void AnyType::setItem(double item, string field){
	doubleItem[index]=item;
	dictionary[index]=field;
	index++;
}

void AnyType::getItem(int *item, string field){
	int ind=findField(field);
	*item=intItem[ind];
}

void AnyType::getItem(string *item, string field){
	int ind=findField(field);
	*item=stringItem[ind];
}

void AnyType::getItem(bool *item, string field){
	int ind=findField(field);
	*item=boolItem[ind];
}

void AnyType::getItem(long long *item, string field){
	int ind=findField(field);
	*item=longLongItem[ind];
}

void AnyType::getItem(double *item, string field){
	int ind=findField(field);
	*item=doubleItem[ind];
}



int AnyType::findField(string field){
	for(int i=0; i<maxItem; i++){
		if(dictionary[i]==field) return(i);
	}
	return(maxItem);
}