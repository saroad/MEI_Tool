#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <string.h>
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <QMessageBox>
#include <WinSock2.h>
#include <Windows.h>
#include <vector>
#include "AutoItX3_DLL.h"

#define SCK_VERSION2 0x0202
#define DEFAULT_BUFLEN 512
#define IP_Address "127.0.0.1"
#define portNo 1

#include "Stringfunctions.h"
#include "Output.h"

using namespace std;

#ifndef AUTOIT_CONNECTOR_H
#define AUTOIT_CONNECTOR_H

class AutoIt_Connector
{
private:
    static bool instanceFlag;
    static AutoIt_Connector *instance;
    AutoIt_Connector();
	SOCKET connection;
	void setConnection();
	LPCWSTR processId;
	QMessageBox* msgBox;
    
public:
    static AutoIt_Connector* getInstance();
    ~AutoIt_Connector();
	string recieveData();
	void sendData(string data);
};

#endif