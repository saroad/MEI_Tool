#ifndef IO_WAIT_H
#define IO_WAIT_H

#include <QThread>
#include <QObject>

#include "AutoIt_Connector.h"

class IO_Wait : public QThread{

public:
	IO_Wait(bool *check);
	~IO_Wait();

private:
	string waitForUserChoice();
	AutoIt_Connector *connector;
	void run();
	bool *runAgain;
	
};

#endif