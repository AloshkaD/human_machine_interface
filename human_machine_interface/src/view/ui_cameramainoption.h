#ifndef UI_CAMERAMAINOPTION_H
#define UI_CAMERAMAINOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameraMainOption
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frameTitle;
    QLabel *labelTitle;
    QLabel *mainImage;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *leftButton;
    QPushButton *rightButton;

    void setupUi(QWidget *cameraMainOption)
    {
        if (cameraMainOption->objectName().isEmpty())
            cameraMainOption->setObjectName(QString::fromUtf8("cameraMainOption"));
        cameraMainOption->resize(667, 420);
        gridLayout_2 = new QGridLayout(cameraMainOption);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frameTitle = new QFrame(cameraMainOption);
        frameTitle->setObjectName(QString::fromUtf8("frameTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameTitle->sizePolicy().hasHeightForWidth());
        frameTitle->setSizePolicy(sizePolicy);
        frameTitle->setMaximumSize(QSize(16777215, 20));
        frameTitle->setFrameShape(QFrame::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Raised);
        labelTitle = new QLabel(frameTitle);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(10, 0, 67, 17));

        gridLayout_2->addWidget(frameTitle, 0, 0, 1, 1);

        mainImage = new QLabel(cameraMainOption);
        mainImage->setObjectName(QString::fromUtf8("mainImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainImage->sizePolicy().hasHeightForWidth());
        mainImage->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(mainImage, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(558, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        leftButton = new QPushButton(cameraMainOption);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ic_skip_previous_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon);

        gridLayout->addWidget(leftButton, 0, 1, 1, 1);

        rightButton = new QPushButton(cameraMainOption);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_skip_next_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon1);

        gridLayout->addWidget(rightButton, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        retranslateUi(cameraMainOption);

        QMetaObject::connectSlotsByName(cameraMainOption);
    } // setupUi

    void retranslateUi(QWidget *cameraMainOption)
    {
        cameraMainOption->setWindowTitle(QApplication::translate("cameraMainOption", "Form", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("cameraMainOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        mainImage->setText(QString());
        leftButton->setText(QString());
        rightButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cameraMainOption: public Ui_cameraMainOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAMAINOPTION_H
