#ifndef UI_DINAMICSVIEW_H
#define UI_DINAMICSVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dinamicsView
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridVehicle;

    void setupUi(QWidget *dinamicsView)
    {
        if (dinamicsView->objectName().isEmpty())
            dinamicsView->setObjectName(QString::fromUtf8("dinamicsView"));
        dinamicsView->resize(250, 319);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dinamicsView->sizePolicy().hasHeightForWidth());
        dinamicsView->setSizePolicy(sizePolicy);
        dinamicsView->setMaximumSize(QSize(350, 16777215));
        gridLayout = new QGridLayout(dinamicsView);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridVehicle = new QGridLayout();
        gridVehicle->setSpacing(0);
        gridVehicle->setObjectName(QString::fromUtf8("gridVehicle"));

        gridLayout->addLayout(gridVehicle, 0, 0, 1, 1);


        retranslateUi(dinamicsView);

        QMetaObject::connectSlotsByName(dinamicsView);
    } // setupUi

    void retranslateUi(QWidget *dinamicsView)
    {
        dinamicsView->setWindowTitle(QApplication::translate("dinamicsView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dinamicsView: public Ui_dinamicsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINAMICSVIEW_H
