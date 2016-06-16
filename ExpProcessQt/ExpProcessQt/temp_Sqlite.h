#include <iostream>
#include <sqlite3\sqlite3.h>
#include "Output.h"

using namespace std;

#ifndef TEMP_SQLITE_H
#define TEMP_SQLITE_H

class temp_Sqlite{

public:
	temp_Sqlite();
	~temp_Sqlite();
	void createTable(string createStmt);
	void insertValues(string insertStatement);
	void dropTable(string dropStmt);

private:
	Output out;
	sqlite3 *db;

};


#endif