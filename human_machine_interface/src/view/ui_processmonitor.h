#ifndef UI_PROCESSMONITOR_H
#define UI_PROCESSMONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processMonitor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QTableWidget *tableProcessViewer;

    void setupUi(QWidget *processMonitor)
    {
        if (processMonitor->objectName().isEmpty())
            processMonitor->setObjectName(QString::fromUtf8("processMonitor"));
        processMonitor->resize(845, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(processMonitor->sizePolicy().hasHeightForWidth());
        processMonitor->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(processMonitor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 5, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(processMonitor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_4 = new QLabel(processMonitor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(processMonitor);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_3 = new QPushButton(processMonitor);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(processMonitor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(processMonitor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        checkBox = new QCheckBox(processMonitor);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(processMonitor);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(processMonitor);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(checkBox_3);

        checkBox_5 = new QCheckBox(processMonitor);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(checkBox_5);

        checkBox_4 = new QCheckBox(processMonitor);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(checkBox_4);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_2 = new QPushButton(processMonitor);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_radio_button_on_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Selected, QIcon::Off);
        pushButton_2->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(processMonitor);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        tableWidget = new QTableWidget(processMonitor);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setLineWidth(1);
        tableWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        tableWidget->setShowGrid(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(300);
        tableWidget->verticalHeader()->setMinimumSectionSize(220);

        gridLayout->addWidget(tableWidget, 5, 0, 1, 1);

        tableProcessViewer = new QTableWidget(processMonitor);
        if (tableProcessViewer->columnCount() < 8)
            tableProcessViewer->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableProcessViewer->setHorizontalHeaderItem(7, __qtablewidgetitem13);
        tableProcessViewer->setObjectName(QString::fromUtf8("tableProcessViewer"));
        tableProcessViewer->setFocusPolicy(Qt::WheelFocus);
        tableProcessViewer->setContextMenuPolicy(Qt::CustomContextMenu);
        tableProcessViewer->horizontalHeader()->setDefaultSectionSize(300);

        gridLayout->addWidget(tableProcessViewer, 1, 0, 1, 1);


        retranslateUi(processMonitor);

        QMetaObject::connectSlotsByName(processMonitor);
    } // setupUi

    void retranslateUi(QWidget *processMonitor)
    {
        processMonitor->setWindowTitle(QApplication::translate("processMonitor", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        processMonitor->setStatusTip(QApplication::translate("processMonitor", "Allow the control and monitor of processes and messages", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("processMonitor", "Process Viewer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("processMonitor", "Filter Process: ", 0, QApplication::UnicodeUTF8));
        lineEdit->setPlaceholderText(QApplication::translate("processMonitor", "Filter...", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("processMonitor", "Stop Message Display", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("processMonitor", "Message Viewer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("processMonitor", "Filter Messages:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("processMonitor", "Info", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("processMonitor", "Debug", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("processMonitor", "Warn", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("processMonitor", "Error", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("processMonitor", "Fatal", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("processMonitor", "Record Process Activity", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("processMonitor", "Save Current State", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("processMonitor", "Message", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("processMonitor", "Error location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("processMonitor", "Error type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("processMonitor", "Process", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("processMonitor", "Hostname", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("processMonitor", "Severity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableProcessViewer->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("processMonitor", "Process", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableProcessViewer->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("processMonitor", "State", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableProcessViewer->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("processMonitor", "Localization", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableProcessViewer->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("processMonitor", "ProcessID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableProcessViewer->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("processMonitor", "StartTime", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableProcessViewer->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("processMonitor", "EndTime", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableProcessViewer->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("processMonitor", "CPU%", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableProcessViewer->horizontalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("processMonitor", "Threads", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processMonitor: public Ui_processMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMONITOR_H
