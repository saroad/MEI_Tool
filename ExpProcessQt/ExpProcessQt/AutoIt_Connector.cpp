#include "AutoIt_Connector.h"

AutoIt_Connector* AutoIt_Connector::instance;
bool AutoIt_Connector::instanceFlag=false;

AutoIt_Connector::AutoIt_Connector(){

	setConnection();

}

AutoIt_Connector* AutoIt_Connector::getInstance()
{
    if(!instanceFlag)
    {
        instance = new AutoIt_Connector();
		instanceFlag=true;
        return instance;
    }
    else
    {
        return instance;
    }
}

AutoIt_Connector::~AutoIt_Connector(){
	instanceFlag=false;
	closesocket(connection);
	//delete(instance);
}


void AutoIt_Connector::setConnection(){

	Output out;

	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION=MAKEWORD(2,1);

	SUCCESSFUL=WSAStartup(DLLVERSION, &WinSockData);

	SOCKADDR_IN ADDRESS;
	int AddressSize=sizeof(ADDRESS);

	SOCKET sock_LISTEN;
	//SOCKET sock_CONNECTION;

	//connection=socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr=inet_addr("127.0.0.1");
	ADDRESS.sin_family=AF_INET;
	ADDRESS.sin_port=htons(portNo);

	sock_LISTEN=socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_LISTEN, SOMAXCONN);

	int result=AU3_Run(L"C:\\Users\\Melanka Saroad\\Desktop\\Moratuwa Engineering\\Semester5\\Software Engineering Project\\TestingCodes\\ExpProcessQt\\ExpProcessQt\\AutoITScripts\\ExpressionInput.exe", L"");
	out=Output("Connection Result: ")+Output(result);
	out.printOutput();


	while(1){
		if(connection=accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)){
			
			out=Output("Connection Successful!!!");
			out.printOutput();
			break;
		}
	}
	//connection=sock_CONNECTION;
}

string AutoIt_Connector::recieveData(){

	int result;
	const int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[recvbuflen];
	string data;
	Output out;

	while(1){
		result = recv(connection, recvbuf, recvbuflen, 0);
		out=Output("Data Recieved Result: ")+Output(result);
		out.printOutput();
		if(result>0){
			data=string(recvbuf);
			vector<string> splittedData=StringFunctions::splitString(data,"@",false);
			int len=atoi(splittedData[0].c_str());
			data=splittedData[1].substr(0,(size_t)len);
			//out=Output("Recieved Data!!!");
			//out.printOutput();
			//out=Output(recvbuf);
			//out.printOutput();
			return data;
		}
	}
}

void AutoIt_Connector::sendData(string data){

	int result;
	char *sendbuf=new char(data.size()+1);
	strcpy(sendbuf, data.c_str());
	const int sendbuflen = (int)strlen(sendbuf);
	Output out;
	out=Output(sendbuf)+Output(" ")+Output(sendbuflen);
	out.printOutput();

	result = send( connection, sendbuf, sendbuflen, 0 );

	out=Output("Data Sent Result: ")+Output(result);
	out.printOutput();

}