#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klfbackend.h"
#include <QDebug>
//#include "Expression.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    input.mathmode = "\\[ ... \\]";

    input.dpi = 150;
    ui->label->setMinimumHeight(input.dpi/2);

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
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this,
        SLOT(updatePreviewBuilderThreadInput()), Qt::QueuedConnection);
    connect(mPreviewBuilderThread, SIGNAL(previewAvailable(const QImage&, bool)),
        this, SLOT(showRealTimePreview(const QImage&, bool)), Qt::QueuedConnection);
    connect(ui->clipBtn, SIGNAL(clicked()), this, SLOT(copyToClipboard()));

    ui->plainTextEdit->setFocus();
    ui->statusBar->showMessage("Waiting for input...");
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

void MainWindow::updatePreviewBuilderThreadInput()
{
    // in linux, I need to reinstate the preamble when rendering. No idea why.
    input.preamble = QString("\\usepackage{amssymb,amsmath}");

    //Expression exp("2+3/6/7");
    //QString qstr = QString::fromStdString(exp.outputText);
    //ui->plainTextEdit->setPlainText(qstr);

    input.latex = ui->plainTextEdit->toPlainText();
    //input.latex=qstr;
    if(mPreviewBuilderThread->inputChanged(input)) {
        //qDebug() << "Y";
        //ui->plainTextEdit->setPlainText(qstr);
        qDebug() << "input changed. Render...";
        ui->statusBar->showMessage("Input changed. Render...");
        mPreviewBuilderThread->start();
  }
}

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
}

