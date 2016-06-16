#include "ExpressionList.h"
#include "ui_ExpressionList.h"
#include "klfbackend.h"
#include <QDebug>
#include <time.h>

#include "Output.h"

bool check=false;

ExpressionList::ExpressionList(QWidget *parent):QMainWindow(parent),ui(new Ui::ExpressionList){

    ui->setupUi(this);

	//setting properties

	//setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
	setWindowFlags(Qt::SubWindow);
	Qt::WindowFlags flags = this->windowFlags();
	this->setWindowFlags(flags | Qt::WindowStaysOnTopHint);
	//setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	this->setFixedSize(this->size());

	numLabels=0;
}

ExpressionList::~ExpressionList(){
    //delete mPreviewBuilderThread;
	qDebug()<<"Item Selected: "<<selected->currentIndex().row();
	delete[] latexLabels;
    delete ui;
}

void ExpressionList::setLabels(QLabel *labels, int num){
	
	for(int i=0; i<numLabels; i++){
		items[i]->setHidden(true);
		//ui->listWidget->removeItemWidget(ui->listWidget->item(i));
		//ui->listWidget->item(i)->deleteLater();
		//delete items[i];
	}
	latexLabels=labels;
	numLabels=num;
	showLabels();

}

void ExpressionList::showLabels(){
	
	qDebug()<<"showLabels1"; 
	
	selected= ui->listWidget->selectionModel();
	//ui->listWidget->setStyleSheet( "QListWidget::item { border: 1px solid black; }" );
	ui->listWidget->setStyleSheet("QListWidget:item:selected:active {border-top: 2px solid blue;border-bottom: 2px solid blue;}");
	//if(items!=) delete[] items;
	qDebug()<<"showLabels2";
	if(!check) items = new QListWidgetItem*[numLabels];
	check=true;

	for(int i=0; i<numLabels; i++){
		
		//latexLabels[i].setStyleSheet("QListWidget:item:selected:active {background: 2px solid blue;}");
		latexLabels[i].setFixedHeight(IMAGE_HEIGHT);
		qDebug()<<"In GUI ("<<i<<"): "<<latexLabels[i].width();
		//latexLabels[i].setFixedWidth(100);
		items[i]=new QListWidgetItem();
		items[i]->setSizeHint(QSize(latexLabels[i].width(),latexLabels[i].height())); 
		//ui->listWidget->addItem(items[i]);
		ui->listWidget->insertItem(i, items[i]);
		//if(ui->listWidget->count()>i+1) ui->listWidget->removeItemWidget(ui->listWidget->item(i+1));
		ui->listWidget->setItemWidget(items[i],latexLabels+i);
		qDebug()<<"showLabels3";

	}

	ui->listWidget->setCurrentItem(items[0]);

}

int ExpressionList::selectedIndex(){
	
	qDebug()<<"selectedIndex";
	return(selected->currentIndex().row());

}
