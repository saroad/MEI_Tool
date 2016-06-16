#ifndef EXPRESSIONLIST_H
#define EXPRESSIONLIST_H

#include <QMainWindow>
#include <QClipboard>
#include <QtGui/QLabel>
#include <QtGui/QListWidgetItem>
#include "klfbackend.h"
#include "klfpreviewbuilderthread.h"

//#include "IO_Center.h"

#define IMAGE_HEIGHT 50

namespace Ui {
class ExpressionList;
}

class ExpressionList : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ExpressionList(QWidget *parent = 0);
    ~ExpressionList();
	void setLabels(QLabel *labels, int num);
	int selectedIndex();
    
private slots:
   
private:
    Ui::ExpressionList *ui;
	//void showSuggestions(QString suggesstion);
	QLabel *latexLabels;
	QListWidgetItem **items;
	QItemSelectionModel *selected;
	void showLabels();
	int numLabels;

};

#endif
