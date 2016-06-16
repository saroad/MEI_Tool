#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klfbackend.h"
#include <QDebug>
#include <time.h>
#include <typeinfo>

#include "Output.h"

float t;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//qDebug()<<"This: "<<typeid(this).name();

    input.mathmode = "\\[ ... \\]";

    input.dpi = 100;
    //ui->label->setMinimumHeight(input.dpi/2);
	ui->label->setFixedHeight(50);

//    input.bg_color = qRgba(225, 225, 225, 225);
    input.preamble = QString("\\usepackage{amssymb,amsmath,mathrsfs}");

    if(!KLFBackend::detectSettings(&settings)) {
        qDebug() << "unable to find LaTeX in default directories.";
    } else {
        qDebug() << "default settings working!";
    }

    // setup variables:
    mPreviewBuilderThread = new KLFPreviewBuilderThread(this, input, settings);
    // make connections
   /* connect(ui->plainTextEdit, SIGNAL(textChanged()), this,
        SLOT(updatePreviewBuilderThreadInput()), Qt::QueuedConnection);*/
    connect(mPreviewBuilderThread, SIGNAL(previewAvailable(const QImage&, bool)),
        this, SLOT(showRealTimePreview(const QImage&, bool)), Qt::QueuedConnection);
    connect(ui->clipBtn, SIGNAL(clicked()), this, SLOT(copyToClipboard()));
	connect(ui->processButton, SIGNAL(clicked()), this, SLOT(sendToProcess()));

    ui->plainTextEdit->setFocus();
    ui->statusBar->showMessage("Waiting for input...");

	//this->show();

	//hub=IO_Center::getInstance();
}

void MainWindow::copyToClipboard()
{
    clipboard->setPixmap(pixmap);
    ui->statusBar->showMessage("your image has been copied to clipboard");
}

MainWindow::~MainWindow()
{
    delete mPreviewBuilderThread;
    delete ui;
}

//void MainWindow::updatePreviewBuilderThreadInput()
//{
//    // in linux, I need to reinstate the preamble when rendering. No idea why.
//    input.preamble = QString("\\usepackage{amssymb,amsmath}");
//    input.latex = ui->plainTextEdit->toPlainText();
//    if(mPreviewBuilderThread->inputChanged(input)) {
//        qDebug() << "input changed. Render...";
//        ui->statusBar->showMessage("Input changed. Render...");
//        mPreviewBuilderThread->start();
//  }
//}

void MainWindow::showRealTimePreview(const QImage& preview, bool latexerror)
{
    if (latexerror) {
      ui->statusBar->showMessage("Unable to render your equation. Please double check.");
    } else {
      ui->statusBar->showMessage("render is succesful!! :D");
      pixmap = QPixmap::fromImage(preview);
	  ui->label->setPixmap(pixmap);
      ui->label->adjustSize();
    }

	Output out;
	out=Output("Render time: ")+Output((clock()-t)/CLOCKS_PER_SEC);
	out.printOutput();
}

void MainWindow::sendToProcess(){
	t=clock();
	string input=ui->plainTextEdit->toPlainText().toStdString();
	string output=hub->process(input);
	showSuggestions(QString::fromStdString(output));
	Output out=Output("Latex: ") + Output(output);
	out.printOutput();
}

void MainWindow::showSuggestions(QString suggesstion){
	input.preamble = QString("\\usepackage{amssymb,amsmath}");
    //input.latex = ui->plainTextEdit->toPlainText();
	input.latex=suggesstion;
    if(mPreviewBuilderThread->inputChanged(input)) {
        qDebug() << "input changed. Render...";
        //ui->statusBar->showMessage("Input changed. Render...");
        mPreviewBuilderThread->start();
		ui->statusBar->showMessage("Input changed. Render...");
	}
}