#ifndef UI_CAMERADISPLAYOPTION_H
#define UI_CAMERADISPLAYOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameraDisplayOption
{
public:
    QGridLayout *gridLayout;
    QFrame *frameCamera1;
    QLabel *titleCamera1;
    QFrame *frameCamera2;
    QLabel *titleCamera2;
    QPushButton *imageCamera1;
    QPushButton *imageCamera2;
    QFrame *frameCamera3;
    QLabel *titleCamera3;
    QPushButton *imageCamera3;
    QFrame *frameCamera6;
    QLabel *titleCamera6;
    QFrame *frameCamera5;
    QLabel *titleCamera5;
    QFrame *frameCamera4;
    QLabel *titleCamera4;
    QPushButton *imageCamera6;
    QPushButton *imageCamera5;
    QPushButton *imageCamera4;

    void setupUi(QWidget *cameraDisplayOption)
    {
        if (cameraDisplayOption->objectName().isEmpty())
            cameraDisplayOption->setObjectName(QString::fromUtf8("cameraDisplayOption"));
        cameraDisplayOption->resize(965, 718);
        gridLayout = new QGridLayout(cameraDisplayOption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frameCamera1 = new QFrame(cameraDisplayOption);
        frameCamera1->setObjectName(QString::fromUtf8("frameCamera1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameCamera1->sizePolicy().hasHeightForWidth());
        frameCamera1->setSizePolicy(sizePolicy);
        frameCamera1->setMaximumSize(QSize(16777215, 20));
        frameCamera1->setFrameShape(QFrame::StyledPanel);
        frameCamera1->setFrameShadow(QFrame::Raised);
        titleCamera1 = new QLabel(frameCamera1);
        titleCamera1->setObjectName(QString::fromUtf8("titleCamera1"));
        titleCamera1->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera1, 0, 0, 1, 2);

        frameCamera2 = new QFrame(cameraDisplayOption);
        frameCamera2->setObjectName(QString::fromUtf8("frameCamera2"));
        sizePolicy.setHeightForWidth(frameCamera2->sizePolicy().hasHeightForWidth());
        frameCamera2->setSizePolicy(sizePolicy);
        frameCamera2->setMaximumSize(QSize(16777215, 20));
        frameCamera2->setFrameShape(QFrame::StyledPanel);
        frameCamera2->setFrameShadow(QFrame::Raised);
        titleCamera2 = new QLabel(frameCamera2);
        titleCamera2->setObjectName(QString::fromUtf8("titleCamera2"));
        titleCamera2->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera2, 0, 2, 1, 1);

        imageCamera1 = new QPushButton(cameraDisplayOption);
        imageCamera1->setObjectName(QString::fromUtf8("imageCamera1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageCamera1->sizePolicy().hasHeightForWidth());
        imageCamera1->setSizePolicy(sizePolicy1);
        imageCamera1->setFocusPolicy(Qt::NoFocus);
        imageCamera1->setCheckable(false);
        imageCamera1->setAutoDefault(false);
        imageCamera1->setDefault(false);
        imageCamera1->setFlat(false);

        gridLayout->addWidget(imageCamera1, 1, 0, 3, 2);

        imageCamera2 = new QPushButton(cameraDisplayOption);
        imageCamera2->setObjectName(QString::fromUtf8("imageCamera2"));
        sizePolicy1.setHeightForWidth(imageCamera2->sizePolicy().hasHeightForWidth());
        imageCamera2->setSizePolicy(sizePolicy1);
        imageCamera2->setFocusPolicy(Qt::NoFocus);
        imageCamera2->setAutoFillBackground(false);
        imageCamera2->setCheckable(false);
        imageCamera2->setAutoDefault(false);
        imageCamera2->setDefault(false);

        gridLayout->addWidget(imageCamera2, 1, 2, 1, 1);

        frameCamera3 = new QFrame(cameraDisplayOption);
        frameCamera3->setObjectName(QString::fromUtf8("frameCamera3"));
        sizePolicy.setHeightForWidth(frameCamera3->sizePolicy().hasHeightForWidth());
        frameCamera3->setSizePolicy(sizePolicy);
        frameCamera3->setMaximumSize(QSize(16777215, 20));
        frameCamera3->setFrameShape(QFrame::StyledPanel);
        frameCamera3->setFrameShadow(QFrame::Raised);
        titleCamera3 = new QLabel(frameCamera3);
        titleCamera3->setObjectName(QString::fromUtf8("titleCamera3"));
        titleCamera3->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera3, 2, 2, 1, 1);

        imageCamera3 = new QPushButton(cameraDisplayOption);
        imageCamera3->setObjectName(QString::fromUtf8("imageCamera3"));
        sizePolicy1.setHeightForWidth(imageCamera3->sizePolicy().hasHeightForWidth());
        imageCamera3->setSizePolicy(sizePolicy1);
        imageCamera3->setFocusPolicy(Qt::NoFocus);
        imageCamera3->setCheckable(false);
        imageCamera3->setAutoDefault(false);
        imageCamera3->setDefault(false);
        imageCamera3->setFlat(false);

        gridLayout->addWidget(imageCamera3, 3, 2, 1, 1);

        frameCamera6 = new QFrame(cameraDisplayOption);
        frameCamera6->setObjectName(QString::fromUtf8("frameCamera6"));
        sizePolicy.setHeightForWidth(frameCamera6->sizePolicy().hasHeightForWidth());
        frameCamera6->setSizePolicy(sizePolicy);
        frameCamera6->setMaximumSize(QSize(16777215, 20));
        frameCamera6->setFrameShape(QFrame::StyledPanel);
        frameCamera6->setFrameShadow(QFrame::Raised);
        titleCamera6 = new QLabel(frameCamera6);
        titleCamera6->setObjectName(QString::fromUtf8("titleCamera6"));
        titleCamera6->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera6, 4, 0, 1, 1);

        frameCamera5 = new QFrame(cameraDisplayOption);
        frameCamera5->setObjectName(QString::fromUtf8("frameCamera5"));
        sizePolicy.setHeightForWidth(frameCamera5->sizePolicy().hasHeightForWidth());
        frameCamera5->setSizePolicy(sizePolicy);
        frameCamera5->setMaximumSize(QSize(16777215, 20));
        frameCamera5->setFrameShape(QFrame::StyledPanel);
        frameCamera5->setFrameShadow(QFrame::Raised);
        titleCamera5 = new QLabel(frameCamera5);
        titleCamera5->setObjectName(QString::fromUtf8("titleCamera5"));
        titleCamera5->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera5, 4, 1, 1, 1);

        frameCamera4 = new QFrame(cameraDisplayOption);
        frameCamera4->setObjectName(QString::fromUtf8("frameCamera4"));
        sizePolicy.setHeightForWidth(frameCamera4->sizePolicy().hasHeightForWidth());
        frameCamera4->setSizePolicy(sizePolicy);
        frameCamera4->setMaximumSize(QSize(16777215, 20));
        frameCamera4->setFrameShape(QFrame::StyledPanel);
        frameCamera4->setFrameShadow(QFrame::Raised);
        titleCamera4 = new QLabel(frameCamera4);
        titleCamera4->setObjectName(QString::fromUtf8("titleCamera4"));
        titleCamera4->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera4, 4, 2, 1, 1);

        imageCamera6 = new QPushButton(cameraDisplayOption);
        imageCamera6->setObjectName(QString::fromUtf8("imageCamera6"));
        sizePolicy1.setHeightForWidth(imageCamera6->sizePolicy().hasHeightForWidth());
        imageCamera6->setSizePolicy(sizePolicy1);
        imageCamera6->setFocusPolicy(Qt::NoFocus);
        imageCamera6->setCheckable(false);
        imageCamera6->setAutoDefault(false);
        imageCamera6->setDefault(false);
        imageCamera6->setFlat(false);

        gridLayout->addWidget(imageCamera6, 5, 0, 1, 1);

        imageCamera5 = new QPushButton(cameraDisplayOption);
        imageCamera5->setObjectName(QString::fromUtf8("imageCamera5"));
        sizePolicy1.setHeightForWidth(imageCamera5->sizePolicy().hasHeightForWidth());
        imageCamera5->setSizePolicy(sizePolicy1);
        imageCamera5->setFocusPolicy(Qt::NoFocus);
        imageCamera5->setCheckable(false);
        imageCamera5->setAutoDefault(false);
        imageCamera5->setDefault(false);
        imageCamera5->setFlat(false);

        gridLayout->addWidget(imageCamera5, 5, 1, 1, 1);

        imageCamera4 = new QPushButton(cameraDisplayOption);
        imageCamera4->setObjectName(QString::fromUtf8("imageCamera4"));
        sizePolicy1.setHeightForWidth(imageCamera4->sizePolicy().hasHeightForWidth());
        imageCamera4->setSizePolicy(sizePolicy1);
        imageCamera4->setFocusPolicy(Qt::NoFocus);
        imageCamera4->setCheckable(false);
        imageCamera4->setAutoDefault(false);
        imageCamera4->setDefault(false);
        imageCamera4->setFlat(false);

        gridLayout->addWidget(imageCamera4, 5, 2, 1, 1);


        retranslateUi(cameraDisplayOption);

        QMetaObject::connectSlotsByName(cameraDisplayOption);
    } // setupUi

    void retranslateUi(QWidget *cameraDisplayOption)
    {
        cameraDisplayOption->setWindowTitle(QApplication::translate("cameraDisplayOption", "Form", 0, QApplication::UnicodeUTF8));
        titleCamera1->setText(QApplication::translate("cameraDisplayOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        titleCamera2->setText(QApplication::translate("cameraDisplayOption", "Camera 2", 0, QApplication::UnicodeUTF8));
        imageCamera1->setText(QString());
        imageCamera2->setText(QString());
        titleCamera3->setText(QApplication::translate("cameraDisplayOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        imageCamera3->setText(QString());
        titleCamera6->setText(QApplication::translate("cameraDisplayOption", "Camera 6", 0, QApplication::UnicodeUTF8));
        titleCamera5->setText(QApplication::translate("cameraDisplayOption", "Camera 5", 0, QApplication::UnicodeUTF8));
        titleCamera4->setText(QApplication::translate("cameraDisplayOption", "Camera 4", 0, QApplication::UnicodeUTF8));
        imageCamera6->setText(QString());
        imageCamera5->setText(QString());
        imageCamera4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cameraDisplayOption: public Ui_cameraDisplayOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADISPLAYOPTION_H
