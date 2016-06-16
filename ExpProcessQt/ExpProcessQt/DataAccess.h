#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <my_global.h>
#include <winsock.h>
#include <mysql.h>
#include <stdlib.h>
#include <sqlite3\sqlite3.h>
#include <fstream>
#include <iomanip>

#include "AnyType.h"
#include "Output.h"

using namespace std;

#ifndef DATAACCESS_H
#define DATAACCESS_H

class DataAccess
{
private:
    static bool instanceFlag;
    static DataAccess *instance;
    DataAccess();
	static sqlite3 *database;
	static vector<AnyType> *tokenMappings;
	static int setMappings(void *data, int numOfCols, char **row, char **colName);
	static int setCount(void *data, int argc, char **argv, char **azColName);
	void setConnection();
	void loadData();
	static void WriteToFile(int numOfCols, char **row, char **colName);
	Output out;
    
public:
    static DataAccess* getInstance();
    ~DataAccess();
	vector<AnyType>* getMappings();
};

#endif