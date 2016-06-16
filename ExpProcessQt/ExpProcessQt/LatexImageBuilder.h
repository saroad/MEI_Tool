#ifndef LATEXIMAGEBUILDER_H
#define LATEXIMAGEBUILDER_H

#include <QDebug>
#include <time.h>
#include <vector>
#include <QtGui/QLabel>
#include <QThread>
#include <QObject>
//#include <QMainWindow>
//#include <QClipboard>
#include "klfbackend.h"
#include "klfpreviewbuilderthread.h"

//#include "ExpressionList.h"
//#include "ui_mainwindow.h"
//#include "klfbackend.h"
#include "Output.h"
#include "ImageBuilder.h"

#define IMAGE_HEIGHT 50

class LatexImageBuilder : public QObject{

	Q_OBJECT

public:
	explicit LatexImageBuilder();
	~LatexImageBuilder();
	void setInput(string inputList[], int listSize);
	QLabel* getLabels();

private:
	//ExpressionList *parent;
	int size;
	QString *inputStrings;
	//vector<KLFPreviewBuilderThread*> *builderThreads;
	KLFPreviewBuilderThread **builderThreads;
    KLFBackend::klfInput *latexInputs;
    KLFBackend::klfSettings settings;
	void createThreads();
	QLabel *labelList;
	int numLabels;
	ImageBuilder **builders;
	QString *threadIds;


public slots:
	void createLabels(const QImage& preview, QString threadId);
	void checkConnect();

};

#endif
