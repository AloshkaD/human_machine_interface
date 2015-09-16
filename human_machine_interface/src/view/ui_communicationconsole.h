/********************************************************************************
** Form generated from reading UI file 'communicationconsole.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATIONCONSOLE_H
#define UI_COMMUNICATIONCONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicationConsole
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tab_widget;
    QWidget *tab1;
    QGridLayout *gridLayout;
    QListView *list_view_tab1;
    QWidget *tab2;
    QGridLayout *gridLayout_2;
    QListView *list_view_tab2;
    QWidget *tab3;
    QGridLayout *gridLayout_3;
    QListView *list_view_tab3;
    QWidget *tab4;
    QGridLayout *gridLayout_6;
    QListView *list_view_tab4;
    QWidget *tab5;
    QGridLayout *gridLayout_7;
    QListView *list_view_tab5;
    QWidget *tab6;
    QGridLayout *gridLayout_4;
    QListView *list_view_tab6;

    void setupUi(QDialog *CommunicationConsole)
    {
        if (CommunicationConsole->objectName().isEmpty())
            CommunicationConsole->setObjectName(QString::fromUtf8("CommunicationConsole"));
        CommunicationConsole->resize(650, 345);
        gridLayout_5 = new QGridLayout(CommunicationConsole);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tab_widget = new QTabWidget(CommunicationConsole);
        tab_widget->setObjectName(QString::fromUtf8("tab_widget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout = new QGridLayout(tab1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        list_view_tab1 = new QListView(tab1);
        list_view_tab1->setObjectName(QString::fromUtf8("list_view_tab1"));

        gridLayout->addWidget(list_view_tab1, 0, 0, 1, 1);

        tab_widget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_2 = new QGridLayout(tab2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        list_view_tab2 = new QListView(tab2);
        list_view_tab2->setObjectName(QString::fromUtf8("list_view_tab2"));

        gridLayout_2->addWidget(list_view_tab2, 0, 0, 1, 1);

        tab_widget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        gridLayout_3 = new QGridLayout(tab3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        list_view_tab3 = new QListView(tab3);
        list_view_tab3->setObjectName(QString::fromUtf8("list_view_tab3"));

        gridLayout_3->addWidget(list_view_tab3, 0, 0, 1, 1);

        tab_widget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        gridLayout_6 = new QGridLayout(tab4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        list_view_tab4 = new QListView(tab4);
        list_view_tab4->setObjectName(QString::fromUtf8("list_view_tab4"));

        gridLayout_6->addWidget(list_view_tab4, 0, 0, 1, 1);

        tab_widget->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        gridLayout_7 = new QGridLayout(tab5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        list_view_tab5 = new QListView(tab5);
        list_view_tab5->setObjectName(QString::fromUtf8("list_view_tab5"));

        gridLayout_7->addWidget(list_view_tab5, 0, 0, 1, 1);

        tab_widget->addTab(tab5, QString());
        tab6 = new QWidget();
        tab6->setObjectName(QString::fromUtf8("tab6"));
        gridLayout_4 = new QGridLayout(tab6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        list_view_tab6 = new QListView(tab6);
        list_view_tab6->setObjectName(QString::fromUtf8("list_view_tab6"));

        gridLayout_4->addWidget(list_view_tab6, 0, 0, 1, 1);

        tab_widget->addTab(tab6, QString());

        gridLayout_5->addWidget(tab_widget, 0, 0, 1, 1);


        retranslateUi(CommunicationConsole);

        tab_widget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(CommunicationConsole);
    } // setupUi

    void retranslateUi(QDialog *CommunicationConsole)
    {
        CommunicationConsole->setWindowTitle(QApplication::translate("CommunicationConsole", "Dialog", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        CommunicationConsole->setStatusTip(QApplication::translate("CommunicationConsole", "Shows the incoming messages of monitored processes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        tab_widget->setTabText(tab_widget->indexOf(tab1), QApplication::translate("CommunicationConsole", "telemetry", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(tab2), QApplication::translate("CommunicationConsole", "odometry", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(tab3), QApplication::translate("CommunicationConsole", "supervisor", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(tab4), QApplication::translate("CommunicationConsole", "cameras", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(tab5), QApplication::translate("CommunicationConsole", "mission planner", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(tab6), QApplication::translate("CommunicationConsole", "user commands", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommunicationConsole: public Ui_CommunicationConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONCONSOLE_H
