#include "temp_Sqlite.h"

//sqlite3* temp_Sqlite::db;

temp_Sqlite::temp_Sqlite(){

	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("C:\\Users\\Melanka Saroad\\Desktop\\Moratuwa Engineering\\Semester5\\Software Engineering Project\\TestingCodes\\ExpProcessQt\\ExpProcessQt\\math_exp_db", &db);
	if( rc ){
		temp_Sqlite::out=Output("Can't open database: ")+Output(const_cast<char*>(sqlite3_errmsg(db)));
		exit(0);
	}
	else{;
		temp_Sqlite::out=Output("Opened database successfully");
	}
	temp_Sqlite::out.printOutput();
}

temp_Sqlite::~temp_Sqlite(){
	sqlite3_close(db);
}

void temp_Sqlite::createTable(string createStmt){

	char *zErrMsg = 0;
	const char *query  = createStmt.c_str();
	int rc = sqlite3_exec(db, query, NULL, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		temp_Sqlite::out=Output("SQL error: ")+Output(const_cast<char*>(zErrMsg));
		sqlite3_free(zErrMsg);
	}
	else{
	  temp_Sqlite::out=Output("Table created successfully");
	}
	temp_Sqlite::out.printOutput();
}


void temp_Sqlite::dropTable(string dropStmt){

	char *zErrMsg = 0;
	const char *query  = dropStmt.c_str();
	int rc = sqlite3_exec(db, query, NULL, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		temp_Sqlite::out=Output("SQL error: ")+Output(const_cast<char*>(zErrMsg));
		sqlite3_free(zErrMsg);
	}
	else{
	  temp_Sqlite::out=Output("Table created deleted");
	}
	temp_Sqlite::out.printOutput();
}

void temp_Sqlite::insertValues(string insertStatement){

	char *zErrMsg = 0;
	const char *query  = insertStatement.c_str();
	int rc = sqlite3_exec(db, query, NULL, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		temp_Sqlite::out=Output("SQL error: ")+Output(const_cast<char*>(zErrMsg));
		sqlite3_free(zErrMsg);
	}
	else{
	  temp_Sqlite::out=Output("Records created successfully");
	}
	temp_Sqlite::out.printOutput();
}
