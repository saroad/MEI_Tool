#include "IO_Center.h"

IO_Center* IO_Center::instance;
bool IO_Center::instanceFlag=false;

using namespace std;

IO_Center::IO_Center(){
	
	msgBox = new QMessageBox();
	msgBox->setWindowTitle("IO_Center");
	msgBox->setText("This is an always-on-top QMessageBox!");
	initialise();
	qDebug()<<"IO_Center1";
	runAgain=new bool(true);
	qDebug()<<"IO_Center2";
}

IO_Center* IO_Center::getInstance()
{
    if(!instanceFlag)
    {
        instance = new IO_Center();
		instanceFlag=true;
        return instance;
    }
    else
    {
        return instance;
    }
}

IO_Center::~IO_Center(){
	instanceFlag=false;
	delete connector;
	delete(instance);
}

IO_Wait::IO_Wait(bool *check){
	
	runAgain=check;
	connector=AutoIt_Connector::getInstance();
}

IO_Wait::~IO_Wait(){}

void IO_Wait::run(){

	if(waitForUserChoice()=="Again"){
		qDebug()<<"Again";
		*runAgain=true;
	}
	else{
		qDebug()<<"Okay";
		*runAgain=false;
	}
	return;
}

//string IO_Center::process(std::string input){
//
//	formula=new Expression(input);
//	return(formula->getOutput());
//}

void IO_Center::begin(){

	sendGUIHandle();
	interactWithUser();

}

void IO_Center::interactWithUser(){
	
	processInput(getUserInput());

	qDebug()<<"processInput(getUserInput())";

	loadSuggestions();

	qDebug()<<"loadSuggestions()";

	pendingThread=new IO_Wait(runAgain);
	connect(pendingThread, SIGNAL(finished()), this, SLOT(trigger()), Qt::QueuedConnection);
	pendingThread->start();

}

void IO_Center::initialise(){

	GUI=new ExpressionList();
	builder=new LatexImageBuilder();
	connector=AutoIt_Connector::getInstance();
	//msgBox->show();
	GUI->show();

	/*string *Input=new string[5];
	Input[0]="\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}";
	Input[1]="\\frac{2}{7}";
	Input[2]="\\frac{2}{11}";
	Input[3]="\\frac{2}{x}";
	Input[4]="\\frac{2}{a}";
	builder->setInput(Input,5);
	GUI->setLabels(builder->getLabels(),5);*/

}

void IO_Center::sendGUIHandle(){

	HWND wid=GUI->winId();
	int handle=(int)wid;
	qDebug()<<wid;
	qDebug()<<handle;

	char buffer [33];
	itoa (handle,buffer,10);

	connector->recieveData();
	connector->sendData(string(buffer));

}

string IO_Center::getUserInput(){

	string userInput=connector->recieveData();
	connector->sendData(string("Okay"));

	return(userInput);
}

void IO_Center::processInput(string input){ //Would change

	Output out(input);
	out.printOutput();

	formula=new Expression(input);
	exprResults=new vector<string>();

	/*out=Output(formula->getOutput());
	out.printOutput();*/

	*exprResults=formula->getOutput();

}

void IO_Center::loadSuggestions(){

	qDebug()<<"loadSuggestions1";

	int len=exprResults->size();
	string* output=new string[len];

	for(int i=0; i<len; i++) output[i]=exprResults->at(i);

	qDebug()<<"loadSuggestions2";

	builder->setInput(output,exprResults->size());
	GUI->setLabels(builder->getLabels(),exprResults->size());

	qDebug()<<"loadSuggestions3 "<<exprResults->size();

	/*string *Input=new string[5];
	Input[0]="\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}+\\frac{2}{9}";
	Input[1]="\\frac{2}{7}";
	Input[2]="\\frac{2}{11}";
	Input[3]="\\frac{2}{x}";
	Input[4]="\\frac{2}{a}";
	builder->setInput(Input,5);
	GUI->setLabels(builder->getLabels(),5);*/
}

string IO_Wait::waitForUserChoice(){

	qDebug()<<"waitForUserChoice";
	string choice=connector->recieveData();
	connector->sendData("Okay");
	qDebug()<<"Choice: "<<QString::fromStdString(choice);
	return(choice);

}

int IO_Center::getUserChoice(){

	return(GUI->selectedIndex());

}

void IO_Center::sendOutput(){

	qDebug()<<"sendOutput1";

	int index=getUserChoice();

	connector->recieveData();
	connector->sendData(exprResults->at(index));

	connector->recieveData();
	connector->sendData("Okay");

	finish();

}

void IO_Center::trigger(){

	qDebug()<<"trigger1";
	if(*runAgain) interactWithUser();
	else sendOutput();

}

void IO_Center::finish(){
	
	float t=clock();
	while((clock()-t)/CLOCKS_PER_SEC<1){}
	connector->~AutoIt_Connector();
	exit(0);

}
