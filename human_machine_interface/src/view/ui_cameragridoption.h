/********************************************************************************
** Form generated from reading UI file 'cameragridoption.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAGRIDOPTION_H
#define UI_CAMERAGRIDOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraGridOption
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QFrame *frame_4;
    QLabel *label_3;
    QFrame *frame_3;
    QLabel *label_4;
    QLabel *camera1_frame;
    QLabel *camera2_frame;
    QLabel *camera3_frame;
    QLabel *camera4_frame;

    void setupUi(QWidget *CameraGridOption)
    {
        if (CameraGridOption->objectName().isEmpty())
            CameraGridOption->setObjectName(QString::fromUtf8("CameraGridOption"));
        CameraGridOption->resize(681, 601);
        gridLayout = new QGridLayout(CameraGridOption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(CameraGridOption);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 20));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(CameraGridOption);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(16777215, 20));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame_4 = new QFrame(CameraGridOption);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMaximumSize(QSize(16777215, 20));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_4, 2, 0, 1, 1);

        frame_3 = new QFrame(CameraGridOption);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMaximumSize(QSize(16777215, 20));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_3, 2, 1, 1, 1);

        camera1_frame = new QLabel(CameraGridOption);
        camera1_frame->setObjectName(QString::fromUtf8("camera1_frame"));

        gridLayout->addWidget(camera1_frame, 1, 0, 1, 1);

        camera2_frame = new QLabel(CameraGridOption);
        camera2_frame->setObjectName(QString::fromUtf8("camera2_frame"));

        gridLayout->addWidget(camera2_frame, 1, 1, 1, 1);

        camera3_frame = new QLabel(CameraGridOption);
        camera3_frame->setObjectName(QString::fromUtf8("camera3_frame"));

        gridLayout->addWidget(camera3_frame, 3, 0, 1, 1);

        camera4_frame = new QLabel(CameraGridOption);
        camera4_frame->setObjectName(QString::fromUtf8("camera4_frame"));

        gridLayout->addWidget(camera4_frame, 3, 1, 1, 1);


        retranslateUi(CameraGridOption);

        QMetaObject::connectSlotsByName(CameraGridOption);
    } // setupUi

    void retranslateUi(QWidget *CameraGridOption)
    {
        CameraGridOption->setWindowTitle(QApplication::translate("CameraGridOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CameraGridOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CameraGridOption", "Camera 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CameraGridOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CameraGridOption", "Camera 4", 0, QApplication::UnicodeUTF8));
        camera1_frame->setText(QString());
        camera2_frame->setText(QString());
        camera3_frame->setText(QString());
        camera4_frame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraGridOption: public Ui_CameraGridOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAGRIDOPTION_H
