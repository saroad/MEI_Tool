#include <iostream>
#include <string.h>
#include <QtGui/QApplication>
#include <QDebug>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <QMessageBox>


#include "ExpressionList.h"
#include "Expression.h"
#include "AutoIt_Connector.h"
#include "Output.h"
#include "LatexImageBuilder.h"
#include "IO_Wait.h"

using namespace std;

#ifndef IO_CENTER_H
#define IO_CENTER_H

class IO_Center : public QObject
{
	
	Q_OBJECT

public:
    static IO_Center* getInstance();
    ~IO_Center();
	//string process(string input);
	//void run();
	void begin();
	bool *runAgain;

private:
    static bool instanceFlag;
    static IO_Center *instance;
    IO_Center();
	AutoIt_Connector *connector;
	Expression *formula;
	void initialise();
	LatexImageBuilder *builder;
	ExpressionList *GUI;
	vector<string> *exprResults;
	IO_Wait *pendingThread;
	QMessageBox* msgBox;
	//
	void interactWithUser();
	void sendGUIHandle();
	string getUserInput();
	void processInput(string input);
	void loadSuggestions();
	//string waitForUserChoice();
	int getUserChoice();
	void sendOutput();
	void finish();

public slots:
	//void sendOutput();
	void trigger();
	
};

#endif