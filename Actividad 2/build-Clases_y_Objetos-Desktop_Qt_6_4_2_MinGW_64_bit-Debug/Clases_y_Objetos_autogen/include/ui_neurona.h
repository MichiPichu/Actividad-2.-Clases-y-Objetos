/********************************************************************************
** Form generated from reading UI file 'neurona.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEURONA_H
#define UI_NEURONA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Neurona
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Neurona)
    {
        if (Neurona->objectName().isEmpty())
            Neurona->setObjectName("Neurona");
        Neurona->resize(800, 600);
        centralwidget = new QWidget(Neurona);
        centralwidget->setObjectName("centralwidget");
        Neurona->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Neurona);
        menubar->setObjectName("menubar");
        Neurona->setMenuBar(menubar);
        statusbar = new QStatusBar(Neurona);
        statusbar->setObjectName("statusbar");
        Neurona->setStatusBar(statusbar);

        retranslateUi(Neurona);

        QMetaObject::connectSlotsByName(Neurona);
    } // setupUi

    void retranslateUi(QMainWindow *Neurona)
    {
        Neurona->setWindowTitle(QCoreApplication::translate("Neurona", "Neurona", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Neurona: public Ui_Neurona {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEURONA_H
