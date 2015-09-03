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
    QWidget *widget_1;
    QWidget *widget_2;
    QFrame *frame_4;
    QLabel *label_3;
    QFrame *frame_3;
    QLabel *label_4;
    QWidget *widget_5;
    QWidget *widget_4;

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

        widget_1 = new QWidget(CameraGridOption);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_1, 1, 0, 1, 1);

        widget_2 = new QWidget(CameraGridOption);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_2, 1, 1, 1, 1);

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

        widget_5 = new QWidget(CameraGridOption);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_5, 3, 0, 1, 1);

        widget_4 = new QWidget(CameraGridOption);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_4, 3, 1, 1, 1);


        retranslateUi(CameraGridOption);

        QMetaObject::connectSlotsByName(CameraGridOption);
    } // setupUi

    void retranslateUi(QWidget *CameraGridOption)
    {
        CameraGridOption->setWindowTitle(QApplication::translate("CameraGridOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CameraGridOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CameraGridOption", "Camera 2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        widget_1->setStatusTip(QApplication::translate("CameraGridOption", "Show the camera views ordered in a grid", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_3->setText(QApplication::translate("CameraGridOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CameraGridOption", "Camera 4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraGridOption: public Ui_CameraGridOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAGRIDOPTION_H
