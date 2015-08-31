#ifndef UI_GRIDCAMERAOPTION_H
#define UI_GRIDCAMERAOPTION_H

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

class Ui_gridCameraOption
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QFrame *frame_3;
    QLabel *label_3;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QFrame *frame_6;
    QLabel *label_4;
    QFrame *frame_5;
    QLabel *label_5;
    QFrame *frame_4;
    QLabel *label_6;
    QWidget *widget_11;
    QWidget *widget_10;
    QWidget *widget_6;
    QFrame *frame_9;
    QLabel *label_7;
    QFrame *frame_8;
    QLabel *label_8;
    QFrame *frame_7;
    QLabel *label_9;
    QWidget *widget_13;
    QWidget *widget_12;
    QWidget *widget_9;

    void setupUi(QWidget *gridCameraOption)
    {
        if (gridCameraOption->objectName().isEmpty())
            gridCameraOption->setObjectName(QString::fromUtf8("gridCameraOption"));
        gridCameraOption->resize(887, 757);
        gridLayout = new QGridLayout(gridCameraOption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(gridCameraOption);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 20));
        frame->setMaximumSize(QSize(16777215, 20));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(gridCameraOption);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 20));
        frame_2->setMaximumSize(QSize(16777215, 20));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame_3 = new QFrame(gridCameraOption);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 20));
        frame_3->setMaximumSize(QSize(16777215, 20));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_3, 0, 2, 1, 1);

        widget = new QWidget(gridCameraOption);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(gridCameraOption);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_2, 1, 1, 1, 1);

        widget_3 = new QWidget(gridCameraOption);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_3, 1, 2, 1, 1);

        frame_6 = new QFrame(gridCameraOption);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMinimumSize(QSize(0, 20));
        frame_6->setMaximumSize(QSize(16777215, 20));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_6, 2, 0, 1, 1);

        frame_5 = new QFrame(gridCameraOption);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(0, 20));
        frame_5->setMaximumSize(QSize(16777215, 20));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_5, 2, 1, 1, 1);

        frame_4 = new QFrame(gridCameraOption);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(0, 20));
        frame_4->setMaximumSize(QSize(16777215, 20));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_4, 2, 2, 1, 1);

        widget_11 = new QWidget(gridCameraOption);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_11, 3, 0, 1, 1);

        widget_10 = new QWidget(gridCameraOption);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_10, 3, 1, 1, 1);

        widget_6 = new QWidget(gridCameraOption);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_6, 3, 2, 1, 1);

        frame_9 = new QFrame(gridCameraOption);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        sizePolicy.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy);
        frame_9->setMinimumSize(QSize(0, 20));
        frame_9->setMaximumSize(QSize(16777215, 20));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_9);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_9, 4, 0, 1, 1);

        frame_8 = new QFrame(gridCameraOption);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy);
        frame_8->setMinimumSize(QSize(0, 20));
        frame_8->setMaximumSize(QSize(16777215, 20));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_8, 4, 1, 1, 1);

        frame_7 = new QFrame(gridCameraOption);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        frame_7->setMinimumSize(QSize(0, 20));
        frame_7->setMaximumSize(QSize(16777215, 20));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 0, 67, 17));

        gridLayout->addWidget(frame_7, 4, 2, 1, 1);

        widget_13 = new QWidget(gridCameraOption);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_13, 5, 0, 1, 1);

        widget_12 = new QWidget(gridCameraOption);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_12, 5, 1, 1, 1);

        widget_9 = new QWidget(gridCameraOption);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget_9, 5, 2, 1, 1);


        retranslateUi(gridCameraOption);

        QMetaObject::connectSlotsByName(gridCameraOption);
    } // setupUi

    void retranslateUi(QWidget *gridCameraOption)
    {
        gridCameraOption->setWindowTitle(QApplication::translate("gridCameraOption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("gridCameraOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("gridCameraOption", "Camera 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("gridCameraOption", "Camera 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("gridCameraOption", "Camera 4", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("gridCameraOption", "Camera 5", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("gridCameraOption", "Camera 6", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("gridCameraOption", "Camera 7", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("gridCameraOption", "Camera 8", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("gridCameraOption", "Camera 9", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gridCameraOption: public Ui_gridCameraOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDCAMERAOPTION_H
