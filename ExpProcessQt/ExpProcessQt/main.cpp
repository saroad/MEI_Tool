#include "expprocessqt.h"
#include <QtGui/QApplication>
#include <QtGUI>

#include <iostream>
#include <fstream>
#include <time.h>
#include <utility>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <typeinfo>
#include <sqlite3\sqlite3.h> 

#include "IO_Center.h"
#include "Expression.h"
#include "DataAccess.h"
#include "TokenLibrary.h"
#include "Output.h"
#include "mainwindow.h"
#include "temp_Sqlite.h"

using namespace std;

void setupDatabase();


int main(int argc, char *argv[])
{

	Output out;

	//_______ Only to initiate DataBase _______
	//setupDatabase();
	//DataAccess* instance=DataAccess::getInstance();
	//_________________________________________

	//float t=clock();
	//Expression formula("sigmax=(-b+-4throot((sinx)^2+4ac))/(2.4sigma)(6/7)");
	////Expression formula("8/x");
	//out=Output("Process time: ")+Output((clock()-t)/CLOCKS_PER_SEC);
	//out.printOutput();

	//vector<string> outputResult=formula.getOutput();

	//qDebug()<<"Output Results("<<outputResult.size()<<"): ";
	//for(int i=0; i<outputResult.size(); i++){
	//	out=Output(outputResult[i]);
	//	out.printOutput();
	//}	
	
	QApplication a(argc, argv);

	IO_Center *session=IO_Center::getInstance();
	session->begin();

	qDebug()<<"Passed";


	return a.exec();

	//return(0);
}

void setupDatabase(){

	temp_Sqlite newDb=temp_Sqlite();
	newDb.dropTable("DROP TABLE exp_map;");
	string create="CREATE TABLE exp_map("\
				"exp_id INT PRIMARY KEY,"\
				"input_str VARCHAR(225) NOT NULL,"\
				"latex VARCHAR(225),"\
				"mathml VARCHAR(225),"\
				"exp_type VARCHAR(225) NOT NULL,"\
				"brac_essential TINYINT NOT NULL,"\
				"no_of_para INT NOT NULL,"\
				"hits INT NOT NULL,"\
				"para VARCHAR(225),"\
				"input_format VARCHAR(225));";
	newDb.createTable(create);

	string line;
  	ifstream myfile ("C:\\Users\\Melanka Saroad\\Desktop\\Moratuwa Engineering\\Semester5\\Software Engineering Project\\TestingCodes\\OutputFiles\\InsertQueries.txt");
  	if (myfile.is_open())
  	{
		//cout<<"Open"<<endl;
    	while (! myfile.eof() )
    	{
      		getline (myfile,line);
			newDb.insertValues(line);
			qDebug()<<QString::fromStdString(line);
		}
		myfile.close();
  	}
  	else qDebug() << "Unable to open file";

}
