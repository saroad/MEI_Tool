#ifndef EXPPROCESSQT_H
#define EXPPROCESSQT_H

#include <QtGui/QMainWindow>
#include "ui_expprocessqt.h"
#include "mainwindow.h"

class ExpProcessQt : public QMainWindow
{
	Q_OBJECT

public:
	ExpProcessQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ExpProcessQt();

private:
	Ui::ExpProcessQtClass ui;
	//static MainWindow mainGUI;
};

#endif // EXPPROCESSQT_H
