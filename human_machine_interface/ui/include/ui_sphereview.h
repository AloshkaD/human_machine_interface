#ifndef UI_SPHEREVIEW_H
#define UI_SPHEREVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sphereView
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;

    void setupUi(QWidget *sphereView)
    {
        if (sphereView->objectName().isEmpty())
            sphereView->setObjectName(QString::fromUtf8("sphereView"));
        sphereView->resize(350, 283);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sphereView->sizePolicy().hasHeightForWidth());
        sphereView->setSizePolicy(sizePolicy);
        sphereView->setMaximumSize(QSize(350, 16777215));
        QFont font;
        font.setPointSize(9);
        sphereView->setFont(font);
        gridLayout = new QGridLayout(sphereView);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(sphereView);

        QMetaObject::connectSlotsByName(sphereView);
    } // setupUi

    void retranslateUi(QWidget *sphereView)
    {
        sphereView->setWindowTitle(QApplication::translate("sphereView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sphereView: public Ui_sphereView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHEREVIEW_H
