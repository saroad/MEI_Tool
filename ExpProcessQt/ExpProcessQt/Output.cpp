#include "Output.h"

Output::Output(){
	DataStr="";
}

Output::Output(int data){
	DataStr=QString::number(data);
}

Output::Output(float data){
	DataStr=QString::number(data);	
}

Output::Output(double data){
	DataStr=QString::number(data);
}

Output::Output(char* data){
	DataStr=QString::fromUtf8(data);
}

Output::Output(string data){
	DataStr=QString::fromStdString(data);
}

Output::Output(QString data){
	DataStr=data;
}

Output::~Output(){};

QString Output::getDataStr(){
	return(DataStr);
}

void Output::printOutput(){
	qDebug() <<qPrintable(DataStr);
}

Output Output::operator +(Output other){
	return(Output(DataStr+other.getDataStr()));
}