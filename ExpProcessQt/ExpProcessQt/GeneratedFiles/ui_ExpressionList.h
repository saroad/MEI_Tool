/********************************************************************************
** Form generated from reading UI file 'ExpressionList.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPRESSIONLIST_H
#define UI_EXPRESSIONLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpressionList
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ExpressionList)
    {
        if (ExpressionList->objectName().isEmpty())
            ExpressionList->setObjectName(QString::fromUtf8("ExpressionList"));
        ExpressionList->resize(155, 212);
        centralwidget = new QWidget(ExpressionList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 0, 141, 171));
        ExpressionList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ExpressionList);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 155, 21));
        ExpressionList->setMenuBar(menubar);
        statusbar = new QStatusBar(ExpressionList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ExpressionList->setStatusBar(statusbar);

        retranslateUi(ExpressionList);

        QMetaObject::connectSlotsByName(ExpressionList);
    } // setupUi

    void retranslateUi(QMainWindow *ExpressionList)
    {
        ExpressionList->setWindowTitle(QApplication::translate("ExpressionList", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpressionList: public Ui_ExpressionList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPRESSIONLIST_H
