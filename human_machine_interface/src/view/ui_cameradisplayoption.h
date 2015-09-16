/********************************************************************************
** Form generated from reading UI file 'cameradisplayoption.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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
    QFrame *frame_camera1;
    QLabel *title_camera1;
    QFrame *frame_camera2;
    QLabel *title_camera2;
    QPushButton *image_camera1;
    QPushButton *image_camera2;
    QFrame *frame_camera3;
    QLabel *title_camera3;
    QPushButton *image_camera3;
    QFrame *frame_camera6;
    QLabel *title_camera6;
    QFrame *frame_camera5;
    QLabel *title_camera5;
    QFrame *frameCamera4;
    QLabel *title_camera4;
    QPushButton *image_camera6;
    QPushButton *image_camera5;
    QPushButton *image_camera4;

    void setupUi(QWidget *cameraDisplayOption)
    {
        if (cameraDisplayOption->objectName().isEmpty())
            cameraDisplayOption->setObjectName(QString::fromUtf8("cameraDisplayOption"));
        cameraDisplayOption->resize(965, 718);
        gridLayout = new QGridLayout(cameraDisplayOption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_camera1 = new QFrame(cameraDisplayOption);
        frame_camera1->setObjectName(QString::fromUtf8("frame_camera1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_camera1->sizePolicy().hasHeightForWidth());
        frame_camera1->setSizePolicy(sizePolicy);
        frame_camera1->setMaximumSize(QSize(16777215, 20));
        frame_camera1->setFrameShape(QFrame::StyledPanel);
        frame_camera1->setFrameShadow(QFrame::Raised);
        title_camera1 = new QLabel(frame_camera1);
        title_camera1->setObjectName(QString::fromUtf8("title_camera1"));
        title_camera1->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_camera1, 0, 0, 1, 2);

        frame_camera2 = new QFrame(cameraDisplayOption);
        frame_camera2->setObjectName(QString::fromUtf8("frame_camera2"));
        sizePolicy.setHeightForWidth(frame_camera2->sizePolicy().hasHeightForWidth());
        frame_camera2->setSizePolicy(sizePolicy);
        frame_camera2->setMaximumSize(QSize(16777215, 20));
        frame_camera2->setFrameShape(QFrame::StyledPanel);
        frame_camera2->setFrameShadow(QFrame::Raised);
        title_camera2 = new QLabel(frame_camera2);
        title_camera2->setObjectName(QString::fromUtf8("title_camera2"));
        title_camera2->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_camera2, 0, 2, 1, 1);

        image_camera1 = new QPushButton(cameraDisplayOption);
        image_camera1->setObjectName(QString::fromUtf8("image_camera1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image_camera1->sizePolicy().hasHeightForWidth());
        image_camera1->setSizePolicy(sizePolicy1);
        image_camera1->setFocusPolicy(Qt::NoFocus);
        image_camera1->setCheckable(false);
        image_camera1->setAutoDefault(false);
        image_camera1->setDefault(false);
        image_camera1->setFlat(false);

        gridLayout->addWidget(image_camera1, 1, 0, 3, 2);

        image_camera2 = new QPushButton(cameraDisplayOption);
        image_camera2->setObjectName(QString::fromUtf8("image_camera2"));
        sizePolicy1.setHeightForWidth(image_camera2->sizePolicy().hasHeightForWidth());
        image_camera2->setSizePolicy(sizePolicy1);
        image_camera2->setFocusPolicy(Qt::NoFocus);
        image_camera2->setAutoFillBackground(false);
        image_camera2->setCheckable(false);
        image_camera2->setAutoDefault(false);
        image_camera2->setDefault(false);

        gridLayout->addWidget(image_camera2, 1, 2, 1, 1);

        frame_camera3 = new QFrame(cameraDisplayOption);
        frame_camera3->setObjectName(QString::fromUtf8("frame_camera3"));
        sizePolicy.setHeightForWidth(frame_camera3->sizePolicy().hasHeightForWidth());
        frame_camera3->setSizePolicy(sizePolicy);
        frame_camera3->setMaximumSize(QSize(16777215, 20));
        frame_camera3->setFrameShape(QFrame::StyledPanel);
        frame_camera3->setFrameShadow(QFrame::Raised);
        title_camera3 = new QLabel(frame_camera3);
        title_camera3->setObjectName(QString::fromUtf8("title_camera3"));
        title_camera3->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_camera3, 2, 2, 1, 1);

        image_camera3 = new QPushButton(cameraDisplayOption);
        image_camera3->setObjectName(QString::fromUtf8("image_camera3"));
        sizePolicy1.setHeightForWidth(image_camera3->sizePolicy().hasHeightForWidth());
        image_camera3->setSizePolicy(sizePolicy1);
        image_camera3->setFocusPolicy(Qt::NoFocus);
        image_camera3->setCheckable(false);
        image_camera3->setAutoDefault(false);
        image_camera3->setDefault(false);
        image_camera3->setFlat(false);

        gridLayout->addWidget(image_camera3, 3, 2, 1, 1);

        frame_camera6 = new QFrame(cameraDisplayOption);
        frame_camera6->setObjectName(QString::fromUtf8("frame_camera6"));
        sizePolicy.setHeightForWidth(frame_camera6->sizePolicy().hasHeightForWidth());
        frame_camera6->setSizePolicy(sizePolicy);
        frame_camera6->setMaximumSize(QSize(16777215, 20));
        frame_camera6->setFrameShape(QFrame::StyledPanel);
        frame_camera6->setFrameShadow(QFrame::Raised);
        title_camera6 = new QLabel(frame_camera6);
        title_camera6->setObjectName(QString::fromUtf8("title_camera6"));
        title_camera6->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_camera6, 4, 0, 1, 1);

        frame_camera5 = new QFrame(cameraDisplayOption);
        frame_camera5->setObjectName(QString::fromUtf8("frame_camera5"));
        sizePolicy.setHeightForWidth(frame_camera5->sizePolicy().hasHeightForWidth());
        frame_camera5->setSizePolicy(sizePolicy);
        frame_camera5->setMaximumSize(QSize(16777215, 20));
        frame_camera5->setFrameShape(QFrame::StyledPanel);
        frame_camera5->setFrameShadow(QFrame::Raised);
        title_camera5 = new QLabel(frame_camera5);
        title_camera5->setObjectName(QString::fromUtf8("title_camera5"));
        title_camera5->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_camera5, 4, 1, 1, 1);

        frameCamera4 = new QFrame(cameraDisplayOption);
        frameCamera4->setObjectName(QString::fromUtf8("frameCamera4"));
        sizePolicy.setHeightForWidth(frameCamera4->sizePolicy().hasHeightForWidth());
        frameCamera4->setSizePolicy(sizePolicy);
        frameCamera4->setMaximumSize(QSize(16777215, 20));
        frameCamera4->setFrameShape(QFrame::StyledPanel);
        frameCamera4->setFrameShadow(QFrame::Raised);
        title_camera4 = new QLabel(frameCamera4);
        title_camera4->setObjectName(QString::fromUtf8("title_camera4"));
        title_camera4->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frameCamera4, 4, 2, 1, 1);

        image_camera6 = new QPushButton(cameraDisplayOption);
        image_camera6->setObjectName(QString::fromUtf8("image_camera6"));
        sizePolicy1.setHeightForWidth(image_camera6->sizePolicy().hasHeightForWidth());
        image_camera6->setSizePolicy(sizePolicy1);
        image_camera6->setFocusPolicy(Qt::NoFocus);
        image_camera6->setCheckable(false);
        image_camera6->setAutoDefault(false);
        image_camera6->setDefault(false);
        image_camera6->setFlat(false);

        gridLayout->addWidget(image_camera6, 5, 0, 1, 1);

        image_camera5 = new QPushButton(cameraDisplayOption);
        image_camera5->setObjectName(QString::fromUtf8("image_camera5"));
        sizePolicy1.setHeightForWidth(image_camera5->sizePolicy().hasHeightForWidth());
        image_camera5->setSizePolicy(sizePolicy1);
        image_camera5->setFocusPolicy(Qt::NoFocus);
        image_camera5->setCheckable(false);
        image_camera5->setAutoDefault(false);
        image_camera5->setDefault(false);
        image_camera5->setFlat(false);

        gridLayout->addWidget(image_camera5, 5, 1, 1, 1);

        image_camera4 = new QPushButton(cameraDisplayOption);
        image_camera4->setObjectName(QString::fromUtf8("image_camera4"));
        sizePolicy1.setHeightForWidth(image_camera4->sizePolicy().hasHeightForWidth());
        image_camera4->setSizePolicy(sizePolicy1);
        image_camera4->setFocusPolicy(Qt::NoFocus);
        image_camera4->setCheckable(false);
        image_camera4->setAutoDefault(false);
        image_camera4->setDefault(false);
        image_camera4->setFlat(false);

        gridLayout->addWidget(image_camera4, 5, 2, 1, 1);


        retranslateUi(cameraDisplayOption);

        QMetaObject::connectSlotsByName(cameraDisplayOption);
    } // setupUi

    void retranslateUi(QWidget *cameraDisplayOption)
    {
        cameraDisplayOption->setWindowTitle(QApplication::translate("cameraDisplayOption", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        cameraDisplayOption->setStatusTip(QApplication::translate("cameraDisplayOption", "Allows the user to monitorize different cameras and select the main camera.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        title_camera1->setText(QApplication::translate("cameraDisplayOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        title_camera2->setText(QApplication::translate("cameraDisplayOption", "Camera 2", 0, QApplication::UnicodeUTF8));
        image_camera1->setText(QString());
        image_camera2->setText(QString());
        title_camera3->setText(QApplication::translate("cameraDisplayOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        image_camera3->setText(QString());
        title_camera6->setText(QApplication::translate("cameraDisplayOption", "Camera 6", 0, QApplication::UnicodeUTF8));
        title_camera5->setText(QApplication::translate("cameraDisplayOption", "Camera 5", 0, QApplication::UnicodeUTF8));
        title_camera4->setText(QApplication::translate("cameraDisplayOption", "Camera 4", 0, QApplication::UnicodeUTF8));
        image_camera6->setText(QString());
        image_camera5->setText(QString());
        image_camera4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cameraDisplayOption: public Ui_cameraDisplayOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADISPLAYOPTION_H
