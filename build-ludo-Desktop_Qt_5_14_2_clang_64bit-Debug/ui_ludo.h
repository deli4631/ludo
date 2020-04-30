/********************************************************************************
** Form generated from reading UI file 'ludo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUDO_H
#define UI_LUDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ludo
{
public:
    QWidget *centralwidget;
    QGraphicsView *playingField;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ludo)
    {
        if (ludo->objectName().isEmpty())
            ludo->setObjectName(QString::fromUtf8("ludo"));
        ludo->resize(877, 652);
        centralwidget = new QWidget(ludo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        playingField = new QGraphicsView(centralwidget);
        playingField->setObjectName(QString::fromUtf8("playingField"));
        playingField->setGeometry(QRect(150, 30, 550, 550));
        ludo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ludo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 22));
        ludo->setMenuBar(menubar);
        statusbar = new QStatusBar(ludo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ludo->setStatusBar(statusbar);

        retranslateUi(ludo);

        QMetaObject::connectSlotsByName(ludo);
    } // setupUi

    void retranslateUi(QMainWindow *ludo)
    {
        ludo->setWindowTitle(QCoreApplication::translate("ludo", "ludo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ludo: public Ui_ludo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUDO_H
