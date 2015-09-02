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
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout;
    QListView *ListView_tab1;
    QWidget *tab3;
    QGridLayout *gridLayout_2;
    QListView *ListView_tab3;
    QWidget *tab4;
    QGridLayout *gridLayout_3;
    QListView *ListView_tab4;
    QWidget *tab5;
    QGridLayout *gridLayout_6;
    QListView *ListView_tab6;
    QWidget *tab7;
    QGridLayout *gridLayout_7;
    QListView *ListView_tab8;
    QWidget *tab9;
    QGridLayout *gridLayout_4;
    QListView *listView_tab9;

    void setupUi(QDialog *CommunicationConsole)
    {
        if (CommunicationConsole->objectName().isEmpty())
            CommunicationConsole->setObjectName(QString::fromUtf8("CommunicationConsole"));
        CommunicationConsole->resize(650, 345);
        gridLayout_5 = new QGridLayout(CommunicationConsole);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget = new QTabWidget(CommunicationConsole);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout = new QGridLayout(tab1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ListView_tab1 = new QListView(tab1);
        ListView_tab1->setObjectName(QString::fromUtf8("ListView_tab1"));

        gridLayout->addWidget(ListView_tab1, 0, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        gridLayout_2 = new QGridLayout(tab3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ListView_tab3 = new QListView(tab3);
        ListView_tab3->setObjectName(QString::fromUtf8("ListView_tab3"));

        gridLayout_2->addWidget(ListView_tab3, 0, 0, 1, 1);

        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        gridLayout_3 = new QGridLayout(tab4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ListView_tab4 = new QListView(tab4);
        ListView_tab4->setObjectName(QString::fromUtf8("ListView_tab4"));

        gridLayout_3->addWidget(ListView_tab4, 0, 0, 1, 1);

        tabWidget->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        gridLayout_6 = new QGridLayout(tab5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        ListView_tab6 = new QListView(tab5);
        ListView_tab6->setObjectName(QString::fromUtf8("ListView_tab6"));

        gridLayout_6->addWidget(ListView_tab6, 0, 0, 1, 1);

        tabWidget->addTab(tab5, QString());
        tab7 = new QWidget();
        tab7->setObjectName(QString::fromUtf8("tab7"));
        gridLayout_7 = new QGridLayout(tab7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        ListView_tab8 = new QListView(tab7);
        ListView_tab8->setObjectName(QString::fromUtf8("ListView_tab8"));

        gridLayout_7->addWidget(ListView_tab8, 0, 0, 1, 1);

        tabWidget->addTab(tab7, QString());
        tab9 = new QWidget();
        tab9->setObjectName(QString::fromUtf8("tab9"));
        gridLayout_4 = new QGridLayout(tab9);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        listView_tab9 = new QListView(tab9);
        listView_tab9->setObjectName(QString::fromUtf8("listView_tab9"));

        gridLayout_4->addWidget(listView_tab9, 0, 0, 1, 1);

        tabWidget->addTab(tab9, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(CommunicationConsole);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CommunicationConsole);
    } // setupUi

    void retranslateUi(QDialog *CommunicationConsole)
    {
        CommunicationConsole->setWindowTitle(QApplication::translate("CommunicationConsole", "Dialog", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("CommunicationConsole", "telemetry", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("CommunicationConsole", "odometry", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QApplication::translate("CommunicationConsole", "supervisor", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab5), QApplication::translate("CommunicationConsole", "cameras", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab7), QApplication::translate("CommunicationConsole", "mission planner", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab9), QApplication::translate("CommunicationConsole", "user commands", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommunicationConsole: public Ui_CommunicationConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONCONSOLE_H
