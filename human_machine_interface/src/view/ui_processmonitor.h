/********************************************************************************
** Form generated from reading UI file 'processmonitor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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

class Ui_performanceMonitor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontal_layout;
    QLabel *label;
    QSpacerItem *horizontal_spacer_3;
    QLabel *label_4;
    QLineEdit *line_edit;
    QHBoxLayout *horizontal_layout_4;
    QPushButton *stop_display_button;
    QSpacerItem *horizontal_spacer_5;
    QHBoxLayout *horizontal_layout_2;
    QLabel *label_2;
    QSpacerItem *horizontal_spacer;
    QSpacerItem *horizontal_spacer_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontal_layout_3;
    QPushButton *push_button_2;
    QPushButton *push_button_4;
    QSpacerItem *horizontal_spacer_4;
    QSpacerItem *vertical_spacer;
    QTableWidget *table_widget;
    QTableWidget *table_process_viewer;

    void setupUi(QWidget *performanceMonitor)
    {
        if (performanceMonitor->objectName().isEmpty())
            performanceMonitor->setObjectName(QString::fromUtf8("performanceMonitor"));
        performanceMonitor->resize(1152, 692);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(performanceMonitor->sizePolicy().hasHeightForWidth());
        performanceMonitor->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(performanceMonitor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 5, -1, -1);
        horizontal_layout = new QHBoxLayout();
        horizontal_layout->setObjectName(QString::fromUtf8("horizontal_layout"));
        label = new QLabel(performanceMonitor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontal_layout->addWidget(label);

        horizontal_spacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout->addItem(horizontal_spacer_3);

        label_4 = new QLabel(performanceMonitor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontal_layout->addWidget(label_4);

        line_edit = new QLineEdit(performanceMonitor);
        line_edit->setObjectName(QString::fromUtf8("line_edit"));
        line_edit->setFocusPolicy(Qt::ClickFocus);

        horizontal_layout->addWidget(line_edit);


        gridLayout->addLayout(horizontal_layout, 0, 0, 1, 1);

        horizontal_layout_4 = new QHBoxLayout();
        horizontal_layout_4->setObjectName(QString::fromUtf8("horizontal_layout_4"));
        stop_display_button = new QPushButton(performanceMonitor);
        stop_display_button->setObjectName(QString::fromUtf8("stop_display_button"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Selected, QIcon::On);
        stop_display_button->setIcon(icon);
        stop_display_button->setCheckable(true);

        horizontal_layout_4->addWidget(stop_display_button);

        horizontal_spacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_4->addItem(horizontal_spacer_5);


        gridLayout->addLayout(horizontal_layout_4, 6, 0, 1, 1);

        horizontal_layout_2 = new QHBoxLayout();
        horizontal_layout_2->setObjectName(QString::fromUtf8("horizontal_layout_2"));
        label_2 = new QLabel(performanceMonitor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontal_layout_2->addWidget(label_2);

        horizontal_spacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontal_layout_2->addItem(horizontal_spacer);

        horizontal_spacer_2 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_2->addItem(horizontal_spacer_2);

        label_3 = new QLabel(performanceMonitor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontal_layout_2->addWidget(label_3);

        checkBox = new QCheckBox(performanceMonitor);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMaximumSize(QSize(100, 16777215));

        horizontal_layout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(performanceMonitor);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMaximumSize(QSize(100, 16777215));

        horizontal_layout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(performanceMonitor);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMaximumSize(QSize(100, 16777215));

        horizontal_layout_2->addWidget(checkBox_3);

        checkBox_5 = new QCheckBox(performanceMonitor);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setMaximumSize(QSize(100, 16777215));

        horizontal_layout_2->addWidget(checkBox_5);

        checkBox_4 = new QCheckBox(performanceMonitor);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setMaximumSize(QSize(100, 16777215));

        horizontal_layout_2->addWidget(checkBox_4);


        gridLayout->addLayout(horizontal_layout_2, 4, 0, 1, 1);

        horizontal_layout_3 = new QHBoxLayout();
        horizontal_layout_3->setObjectName(QString::fromUtf8("horizontal_layout_3"));
        push_button_2 = new QPushButton(performanceMonitor);
        push_button_2->setObjectName(QString::fromUtf8("push_button_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_radio_button_on_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_radio_button_on_24px.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_radio_button_on_24px.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Selected, QIcon::On);
        push_button_2->setIcon(icon1);
        push_button_2->setCheckable(true);

        horizontal_layout_3->addWidget(push_button_2);

        push_button_4 = new QPushButton(performanceMonitor);
        push_button_4->setObjectName(QString::fromUtf8("push_button_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        push_button_4->setIcon(icon2);

        horizontal_layout_3->addWidget(push_button_4);

        horizontal_spacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_3->addItem(horizontal_spacer_4);


        gridLayout->addLayout(horizontal_layout_3, 2, 0, 1, 1);

        vertical_spacer = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(vertical_spacer, 3, 0, 1, 1);

        table_widget = new QTableWidget(performanceMonitor);
        if (table_widget->columnCount() < 4)
            table_widget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_widget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_widget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_widget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_widget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_widget->setObjectName(QString::fromUtf8("table_widget"));
        table_widget->setFrameShape(QFrame::Panel);
        table_widget->setLineWidth(1);
        table_widget->setDragDropMode(QAbstractItemView::NoDragDrop);
        table_widget->setShowGrid(true);
        table_widget->horizontalHeader()->setDefaultSectionSize(300);
        table_widget->verticalHeader()->setMinimumSectionSize(220);

        gridLayout->addWidget(table_widget, 5, 0, 1, 1);

        table_process_viewer = new QTableWidget(performanceMonitor);
        if (table_process_viewer->columnCount() < 2)
            table_process_viewer->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_process_viewer->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_process_viewer->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        table_process_viewer->setObjectName(QString::fromUtf8("table_process_viewer"));
        table_process_viewer->setFocusPolicy(Qt::WheelFocus);
        table_process_viewer->setContextMenuPolicy(Qt::CustomContextMenu);
        table_process_viewer->horizontalHeader()->setDefaultSectionSize(600);

        gridLayout->addWidget(table_process_viewer, 1, 0, 1, 1);


        retranslateUi(performanceMonitor);

        QMetaObject::connectSlotsByName(performanceMonitor);
    } // setupUi

    void retranslateUi(QWidget *performanceMonitor)
    {
        performanceMonitor->setWindowTitle(QApplication::translate("performanceMonitor", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        performanceMonitor->setStatusTip(QApplication::translate("performanceMonitor", "Allow the control and monitor of processes and messages", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("performanceMonitor", "Process Viewer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("performanceMonitor", "Filter Process: ", 0, QApplication::UnicodeUTF8));
        line_edit->setPlaceholderText(QApplication::translate("performanceMonitor", "Filter...", 0, QApplication::UnicodeUTF8));
        stop_display_button->setText(QApplication::translate("performanceMonitor", "Stop Message Display", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("performanceMonitor", "Message Viewer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("performanceMonitor", "Filter Messages:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("performanceMonitor", "Info", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("performanceMonitor", "Debug", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("performanceMonitor", "Warn", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("performanceMonitor", "Error", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("performanceMonitor", "Fatal", 0, QApplication::UnicodeUTF8));
        push_button_2->setText(QApplication::translate("performanceMonitor", "Record Process Activity", 0, QApplication::UnicodeUTF8));
        push_button_4->setText(QApplication::translate("performanceMonitor", "Save Current State", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table_widget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("performanceMonitor", "Message", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table_widget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("performanceMonitor", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table_widget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("performanceMonitor", "Process", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = table_widget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("performanceMonitor", "Hostname", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = table_process_viewer->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("performanceMonitor", "Process", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = table_process_viewer->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("performanceMonitor", "State", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class performanceMonitor: public Ui_performanceMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMONITOR_H
