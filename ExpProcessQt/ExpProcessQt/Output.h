#include <iostream>
#include <QDebug>
#include <QString>

using namespace std;

#ifndef OUTPUT_H
#define OUTPUT_H

class Output{

public:
	Output();
	Output(int data);
	Output(float data);
	Output(double data);
	Output(char* data);
	//Output(const char* data);
	Output(string data);
	Output(QString data);
	/*Output(int data);
	Output(int data);
	Output(int data);*/
	~Output();
	Output operator+(Output other);
	void printOutput();
	QString getDataStr();

private:
	QString DataStr;

};


#endif