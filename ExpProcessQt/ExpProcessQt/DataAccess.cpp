#include "DataAccess.h"

#include <typeinfo>
#include <malloc.h>
#include <QDebug>
#include <cstdlib>

DataAccess* DataAccess::instance;
sqlite3* DataAccess::database;
bool DataAccess::instanceFlag=false;
vector<AnyType>* DataAccess::tokenMappings;

DataAccess::DataAccess(){

	DataAccess::setConnection();
	DataAccess::loadData();

}

DataAccess* DataAccess::getInstance()
{
    if(!instanceFlag)
    {
        instance = new DataAccess();
		instanceFlag=true;
        return instance;
    }
    else
    {
        return instance;
    }
}

DataAccess::~DataAccess(){
	sqlite3_close(database);
	instanceFlag=false;
	delete(instance);
}

void DataAccess::setConnection(){

	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("C:\\Users\\Melanka Saroad\\Desktop\\Moratuwa Engineering\\Semester5\\Software Engineering Project\\TestingCodes\\ExpProcessQt\\ExpProcessQt\\math_exp_db", &database);
	if( rc ){
		DataAccess::out=Output("Can't open database: ")+Output(const_cast<char*>(sqlite3_errmsg(database)));
		DataAccess::out.printOutput();
		exit(1);
	}
	else{
		DataAccess::out=Output("Opened database successfully");
		DataAccess::out.printOutput();
	}
	
}


void DataAccess::loadData(){

	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback function called";
	char* query1="SELECT COUNT(*) FROM exp_map";
	
	rc = sqlite3_exec(database, query1, setCount, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		DataAccess::out=Output("SQL error in count: ")+Output(const_cast<char*>(sqlite3_errmsg(database)));
		DataAccess::out.printOutput();
		sqlite3_free(zErrMsg);
	}
	else{
		DataAccess::out=Output("Operation (count) done successfully");
		DataAccess::out.printOutput();
	}

	char* query2="SELECT input_str, latex, mathml, exp_type, brac_essential, no_of_para, hits, para, input_format FROM exp_map ORDER BY input_str ASC";

	rc = sqlite3_exec(database, query2, setMappings, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		DataAccess::out=Output("SQL error in load data: ")+Output(const_cast<char*>(sqlite3_errmsg(database)));
		DataAccess::out.printOutput();
		sqlite3_free(zErrMsg);
	}
	else{
		DataAccess::out=Output("Operation (load data) done successfully");
		DataAccess::out.printOutput();
	}
}

int DataAccess::setCount(void *data, int argc, char **argv, char **azColName){

	int rowCount=atoi(argv[0]);
	qDebug()<<"Row Count: "<<rowCount;
	tokenMappings=new vector<AnyType>();
	tokenMappings->reserve((int)(rowCount*1.1));

	return(0);
}

int DataAccess::setMappings(void *data, int numOfCols, char **row, char **colName){

	AnyType *temp;

	temp=new AnyType(numOfCols);
	temp->setItem(row[0]? (string)row[0] : "NULL", "input_str");
	temp->setItem(row[1]? (string)row[1] : "NULL", "latex");
	temp->setItem(row[2]? (string)row[2] : "NULL", "mathml");
	temp->setItem(row[3]? (string)row[3] : "NULL", "exp_type");
	temp->setItem((bool)(strcmp((char*)row[4],"1")==0? true : false), "brac_essential");
	temp->setItem((int)row[5], "no_of_para");
	temp->setItem((long long)row[6], "hits");
	temp->setItem(row[7]? (string)row[7] : "NULL", "para");
	temp->setItem(row[8]? (string)row[8] : "NULL", "input_format");
	DataAccess::tokenMappings->push_back(*temp);

	//WriteToFile(numOfCols, row, colName);
		
	return(0);
}

vector<AnyType>* DataAccess::getMappings(){
	return(DataAccess::tokenMappings);
}

void DataAccess::WriteToFile(int numOfCols, char **row, char **colName){

	fstream file;
	file.open ("C:\\Users\\Melanka Saroad\\Desktop\\Moratuwa Engineering\\Semester5\\Software Engineering Project\\TestingCodes\\OutputFiles\\MappingTable.txt", std::fstream::app);
	
	string *temp=new string[numOfCols];

	temp[0]=(row[0]? (string)row[0] : "NULL");
	temp[1]=(row[1]? (string)row[1] : "NULL");
	temp[2]=(row[2]? (string)row[2] : "NULL");
	temp[3]=(row[3]? (string)row[3] : "NULL");
	temp[4]=(strcmp((char*)row[4],"1")==0? "True" : "False");
	temp[5]=string(row[5]);
	temp[6]=string(row[6]);
	temp[7]=(row[7]? (string)row[7] : "NULL");
	temp[8]=(row[8]? (string)row[8] : "NULL");

	file<<left<<setw(20)<<temp[0]<<setw(40)<<temp[1]<<setw(10)<<temp[2]<<setw(15)<<temp[3]<<setw(6)<<temp[4]<<setw(3)<<temp[5]<<setw(3)<<temp[6]<<setw(15)<<temp[7]<<setw(40)<<temp[8]<<endl;

	file.close();

}