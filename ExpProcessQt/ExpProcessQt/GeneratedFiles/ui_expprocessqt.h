/********************************************************************************
** Form generated from reading UI file 'expprocessqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPPROCESSQT_H
#define UI_EXPPROCESSQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpProcessQtClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExpProcessQtClass)
    {
        if (ExpProcessQtClass->objectName().isEmpty())
            ExpProcessQtClass->setObjectName(QString::fromUtf8("ExpProcessQtClass"));
        ExpProcessQtClass->resize(600, 400);
        centralWidget = new QWidget(ExpProcessQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 140, 75, 23));
        ExpProcessQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExpProcessQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ExpProcessQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExpProcessQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExpProcessQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExpProcessQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExpProcessQtClass->setStatusBar(statusBar);

        retranslateUi(ExpProcessQtClass);

        QMetaObject::connectSlotsByName(ExpProcessQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExpProcessQtClass)
    {
        ExpProcessQtClass->setWindowTitle(QApplication::translate("ExpProcessQtClass", "ExpProcessQt", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ExpProcessQtClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpProcessQtClass: public Ui_ExpProcessQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPPROCESSQT_H
