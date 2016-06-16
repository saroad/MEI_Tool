#include <stdlib.h>
#include <typeinfo>
#include <string>

#include "LatexImageBuilder.h"

using namespace std;

float T;

LatexImageBuilder::LatexImageBuilder(){

	size=0;

	if(!KLFBackend::detectSettings(&settings)) {
        qDebug() << "unable to find LaTeX in default directories.";
    } else {
        qDebug() << "default settings working!";
    }
}

LatexImageBuilder::~LatexImageBuilder(){
	delete[] inputStrings;
	delete[] builderThreads;
	delete[] builders;
}

ImageBuilder::ImageBuilder(){}

ImageBuilder::~ImageBuilder(){}

void LatexImageBuilder::setInput(string inputList[], int listSize){

	inputStrings=new QString[listSize];
	size=listSize;

	for(int i=0; i<listSize; i++){
		inputStrings[i]=QString::fromStdString(inputList[i]);
	}

}

void LatexImageBuilder::createThreads(){

	qDebug()<<"createThreads";

	KLFBackend::klfInput tempInput;
	tempInput.mathmode = "\\[ ... \\]";
	tempInput.dpi = 2*IMAGE_HEIGHT;
//  input.bg_color = qRgba(225, 225, 225, 225);
    tempInput.preamble = QString("\\usepackage{amssymb,amsmath,mathrsfs}");
 
	builderThreads=new KLFPreviewBuilderThread*[size];
	builders=new ImageBuilder*[size];
	threadIds=new QString[size];
	KLFPreviewBuilderThread *tempPointer;

	for(int i=0; i<size; i++){

		tempInput.latex=inputStrings[i];

		builderThreads[i]=new KLFPreviewBuilderThread(this, tempInput, settings);
		threadIds[i]=QString::number((long long)(builderThreads[i]),16);
		builders[i]=new ImageBuilder();
		builders[i]->moveToThread(builderThreads[i]);

		connect(builderThreads[i], SIGNAL(previewAvailable(const QImage&, bool)),
        builders[i], SLOT(getThreadId(const QImage&, bool)));

		connect(builders[i], SIGNAL(giveThreadId(const QImage&, QString)),
        this, SLOT(createLabels(const QImage&, QString)),Qt::QueuedConnection);

		connect(builders[i], SIGNAL(giveThreadId(const QImage&, QString)),
        this, SLOT(checkConnect()),Qt::QueuedConnection);

	}

}

void LatexImageBuilder::checkConnect(){

	qDebug()<<"Connect Checked";

}

void LatexImageBuilder::createLabels(const QImage& preview, QString threadId){

	QPixmap pixmap;
	qDebug()<<"createLabels1";
	
	pixmap = QPixmap::fromImage(preview);

	for(int i=0; i<size; i++){
		if(threadId== threadIds[i]){
			qDebug()<<"Label: "<<i;
			labelList[i].setPixmap(pixmap);
			labelList[i].adjustSize();
			break;
		}
	}
	numLabels++;
	qDebug()<<"NumLabels: "<<numLabels;
	qDebug()<<"Time: "<<(clock()-T)/CLOCKS_PER_SEC<<"s";
}

void ImageBuilder::getThreadId(const QImage &preview, bool latexerror){

	qDebug()<<"getThreadId1";

	if (latexerror) {
      qDebug()<<"Unable to render your equation. Please double check.";
    } 
	else {
		qDebug()<<"getThreadId2";
		emit giveThreadId(preview, QString::number((long long)(QThread::currentThread()),16));
		qDebug()<<"getThreadId3";
	}

}

QLabel* LatexImageBuilder::getLabels(){
	
	qDebug()<<"getLabels1";
	T=clock();
	numLabels=0;
	labelList=new QLabel[size];
	createThreads();
	//qDebug()<<"This: "<<typeid(builderThreads).name();
	for(int i=0; i<size; i++){
		//qDebug()<<"Thread(i): "<<QString::number((long long)(builderThreads[i]),16);
		builderThreads[i]->start();
		qDebug()<<"getLabels2";
	}
	qDebug()<<"getLabels3";
	return labelList;

}