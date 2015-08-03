#ifndef UI_SIXCAMERAOPTION_H
#define UI_SIXCAMERAOPTION_H

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

class Ui_sixCameraOption
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_5;
    QLabel *label_2;
    QFrame *frame_6;
    QLabel *label_3;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QFrame *frame_4;
    QLabel *label_4;
    QFrame *frame_3;
    QLabel *label_5;
    QFrame *frame_2;
    QLabel *label_6;
    QWidget *widget_4;
    QWidget *widget_5;
    QWidget *widget_6;

    void setupUi(QWidget *sixCameraOption)
    {
        if (sixCameraOption->objectName().isEmpty())
            sixCameraOption->setObjectName(QString::fromUtf8("sixCameraOption"));
        sixCameraOption->resize(871, 487);
        gridLayout_3 = new QGridLayout(sixCameraOption);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(sixCameraOption);
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

        frame_5 = new QFrame(sixCameraOption);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMaximumSize(QSize(16777215, 20));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_5, 0, 1, 1, 1);

        frame_6 = new QFrame(sixCameraOption);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMaximumSize(QSize(16777215, 20));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_6, 0, 2, 1, 1);

        widget = new QWidget(sixCameraOption);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(sixCameraOption);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_2, 1, 1, 1, 1);

        widget_3 = new QWidget(sixCameraOption);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);\n"
"border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_3, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_4 = new QFrame(sixCameraOption);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMaximumSize(QSize(16777215, 20));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 67, 17));

        gridLayout_2->addWidget(frame_4, 0, 0, 1, 1);

        frame_3 = new QFrame(sixCameraOption);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMaximumSize(QSize(16777215, 20));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 67, 17));

        gridLayout_2->addWidget(frame_3, 0, 1, 1, 1);

        frame_2 = new QFrame(sixCameraOption);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(16777215, 20));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 67, 17));

        gridLayout_2->addWidget(frame_2, 0, 2, 1, 1);

        widget_4 = new QWidget(sixCameraOption);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout_2->addWidget(widget_4, 1, 0, 1, 1);

        widget_5 = new QWidget(sixCameraOption);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout_2->addWidget(widget_5, 1, 1, 1, 1);

        widget_6 = new QWidget(sixCameraOption);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);\n"
"border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout_2->addWidget(widget_6, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(sixCameraOption);

        QMetaObject::connectSlotsByName(sixCameraOption);
    } // setupUi

    void retranslateUi(QWidget *sixCameraOption)
    {
        sixCameraOption->setWindowTitle(QApplication::translate("sixCameraOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sixCameraOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sixCameraOption", "Camera 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sixCameraOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sixCameraOption", "Camera 4", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sixCameraOption", "Camera 5", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("sixCameraOption", "Camera 6", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sixCameraOption: public Ui_sixCameraOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIXCAMERAOPTION_H
