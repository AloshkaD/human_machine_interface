/********************************************************************************
** Form generated from reading UI file 'parametertemporalseries.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERTEMPORALSERIES_H
#define UI_PARAMETERTEMPORALSERIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parameterTemporalSeries
{
public:
    QGridLayout *gridLayout_2;
    QTreeWidget *tree_widget;
    QWidget *plot_widget;
    QGridLayout *grid_layout;
    QPushButton *stop_button;
    QLabel *label;
    QPushButton *save_plot_button;
    QLabel *label_2;
    QSpinBox *spin_box_min_axis;
    QSpinBox *spin_box_max_axis;

    void setupUi(QWidget *parameterTemporalSeries)
    {
        if (parameterTemporalSeries->objectName().isEmpty())
            parameterTemporalSeries->setObjectName(QString::fromUtf8("parameterTemporalSeries"));
        parameterTemporalSeries->resize(1391, 822);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(parameterTemporalSeries->sizePolicy().hasHeightForWidth());
        parameterTemporalSeries->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(parameterTemporalSeries);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tree_widget = new QTreeWidget(parameterTemporalSeries);
        tree_widget->setObjectName(QString::fromUtf8("tree_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tree_widget->sizePolicy().hasHeightForWidth());
        tree_widget->setSizePolicy(sizePolicy1);
        tree_widget->setMaximumSize(QSize(340, 16777215));
        tree_widget->setFocusPolicy(Qt::NoFocus);
        tree_widget->header()->setDefaultSectionSize(190);

        gridLayout_2->addWidget(tree_widget, 0, 0, 1, 1);

        plot_widget = new QWidget(parameterTemporalSeries);
        plot_widget->setObjectName(QString::fromUtf8("plot_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plot_widget->sizePolicy().hasHeightForWidth());
        plot_widget->setSizePolicy(sizePolicy2);
        plot_widget->setMaximumSize(QSize(1200, 16777215));

        gridLayout_2->addWidget(plot_widget, 0, 1, 2, 1);

        grid_layout = new QGridLayout();
        grid_layout->setObjectName(QString::fromUtf8("grid_layout"));
        stop_button = new QPushButton(parameterTemporalSeries);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Selected, QIcon::On);
        stop_button->setIcon(icon);
        stop_button->setIconSize(QSize(16, 16));
        stop_button->setCheckable(true);
        stop_button->setAutoRepeat(true);

        grid_layout->addWidget(stop_button, 2, 1, 1, 4);

        label = new QLabel(parameterTemporalSeries);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);

        grid_layout->addWidget(label, 0, 0, 1, 1);

        save_plot_button = new QPushButton(parameterTemporalSeries);
        save_plot_button->setObjectName(QString::fromUtf8("save_plot_button"));
        save_plot_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        save_plot_button->setIcon(icon1);

        grid_layout->addWidget(save_plot_button, 2, 0, 1, 1);

        label_2 = new QLabel(parameterTemporalSeries);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        grid_layout->addWidget(label_2, 1, 0, 1, 1);

        spin_box_min_axis = new QSpinBox(parameterTemporalSeries);
        spin_box_min_axis->setObjectName(QString::fromUtf8("spin_box_min_axis"));
        spin_box_min_axis->setFocusPolicy(Qt::NoFocus);
        spin_box_min_axis->setKeyboardTracking(false);
        spin_box_min_axis->setMinimum(-99);
        spin_box_min_axis->setMaximum(0);

        grid_layout->addWidget(spin_box_min_axis, 1, 1, 1, 4);

        spin_box_max_axis = new QSpinBox(parameterTemporalSeries);
        spin_box_max_axis->setObjectName(QString::fromUtf8("spin_box_max_axis"));
        spin_box_max_axis->setFocusPolicy(Qt::NoFocus);
        spin_box_max_axis->setKeyboardTracking(false);
        spin_box_max_axis->setMaximum(50);
        spin_box_max_axis->setValue(20);

        grid_layout->addWidget(spin_box_max_axis, 0, 1, 1, 4);


        gridLayout_2->addLayout(grid_layout, 1, 0, 1, 1);


        retranslateUi(parameterTemporalSeries);

        QMetaObject::connectSlotsByName(parameterTemporalSeries);
    } // setupUi

    void retranslateUi(QWidget *parameterTemporalSeries)
    {
#ifndef QT_NO_STATUSTIP
        parameterTemporalSeries->setStatusTip(QApplication::translate("parameterTemporalSeries", "Shows the parameters list. Allows the user to display plots of selected parameters.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        QTreeWidgetItem *___qtreewidgetitem = tree_widget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("parameterTemporalSeries", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("parameterTemporalSeries", "Parameter", 0, QApplication::UnicodeUTF8));
        stop_button->setText(QApplication::translate("parameterTemporalSeries", "Stop", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("parameterTemporalSeries", " Max Vertical Axis", 0, QApplication::UnicodeUTF8));
        save_plot_button->setText(QApplication::translate("parameterTemporalSeries", "Save Plot ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("parameterTemporalSeries", " Min Vertical Axis", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class parameterTemporalSeries: public Ui_parameterTemporalSeries {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERTEMPORALSERIES_H
