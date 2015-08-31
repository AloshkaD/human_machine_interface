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
    QTreeWidget *treeWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *plotWidget;

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
        treeWidget = new QTreeWidget(parameterTemporalSeries);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setMaximumSize(QSize(340, 16777215));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->header()->setDefaultSectionSize(180);

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(parameterTemporalSeries);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(parameterTemporalSeries);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setFocusPolicy(Qt::NoFocus);
        spinBox_2->setMaximum(50);
        spinBox_2->setValue(20);

        gridLayout->addWidget(spinBox_2, 0, 1, 1, 1);

        pushButton = new QPushButton(parameterTemporalSeries);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(parameterTemporalSeries);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_pause_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/ic_play_arrow_24px.svg"), QSize(), QIcon::Selected, QIcon::On);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(16, 16));
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoRepeat(true);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        plotWidget = new QWidget(parameterTemporalSeries);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plotWidget->sizePolicy().hasHeightForWidth());
        plotWidget->setSizePolicy(sizePolicy2);
        plotWidget->setMaximumSize(QSize(1200, 16777215));

        gridLayout_2->addWidget(plotWidget, 0, 1, 2, 1);


        retranslateUi(parameterTemporalSeries);

        QMetaObject::connectSlotsByName(parameterTemporalSeries);
    } // setupUi

    void retranslateUi(QWidget *parameterTemporalSeries)
    {
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("parameterTemporalSeries", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("parameterTemporalSeries", "Parameter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("parameterTemporalSeries", " Max Vertical Axis", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("parameterTemporalSeries", "Save Plot ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("parameterTemporalSeries", "Stop", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(parameterTemporalSeries);
    } // retranslateUi

};

namespace Ui {
    class parameterTemporalSeries: public Ui_parameterTemporalSeries {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERTEMPORALSERIES_H
