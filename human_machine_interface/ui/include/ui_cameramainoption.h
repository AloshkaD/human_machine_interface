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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameramainoption
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_1;
    QLabel *title_1;
    QFrame *frame_2;
    QLabel *title_2;
    QPushButton *imageCamera1;
    QPushButton *imageCamera2;
    QFrame *frame_3;
    QLabel *title_3;
    QPushButton *imageCamera3;
    QFrame *frame_6;
    QLabel *title_6;
    QFrame *frame_5;
    QLabel *title_5;
    QFrame *frame_4;
    QLabel *title_4;
    QPushButton *imageCamera6;
    QPushButton *imageCamera5;
    QPushButton *imageCamera4;

    void setupUi(QWidget *cameramainoption)
    {
        if (cameramainoption->objectName().isEmpty())
            cameramainoption->setObjectName(QString::fromUtf8("cameramainoption"));
        cameramainoption->resize(1074, 718);
        gridLayout = new QGridLayout(cameramainoption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_1 = new QFrame(cameramainoption);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_1->sizePolicy().hasHeightForWidth());
        frame_1->setSizePolicy(sizePolicy);
        frame_1->setMaximumSize(QSize(16777215, 20));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        title_1 = new QLabel(frame_1);
        title_1->setObjectName(QString::fromUtf8("title_1"));
        title_1->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_1, 0, 0, 1, 2);

        frame_2 = new QFrame(cameramainoption);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(16777215, 20));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        title_2 = new QLabel(frame_2);
        title_2->setObjectName(QString::fromUtf8("title_2"));
        title_2->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_2, 0, 2, 1, 1);

        imageCamera1 = new QPushButton(cameramainoption);
        imageCamera1->setObjectName(QString::fromUtf8("imageCamera1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageCamera1->sizePolicy().hasHeightForWidth());
        imageCamera1->setSizePolicy(sizePolicy1);
        imageCamera1->setFocusPolicy(Qt::NoFocus);
        imageCamera1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera1->setCheckable(false);
        imageCamera1->setAutoDefault(false);
        imageCamera1->setDefault(false);
        imageCamera1->setFlat(false);

        gridLayout->addWidget(imageCamera1, 1, 0, 3, 2);

        imageCamera2 = new QPushButton(cameramainoption);
        imageCamera2->setObjectName(QString::fromUtf8("imageCamera2"));
        sizePolicy1.setHeightForWidth(imageCamera2->sizePolicy().hasHeightForWidth());
        imageCamera2->setSizePolicy(sizePolicy1);
        imageCamera2->setFocusPolicy(Qt::NoFocus);
        imageCamera2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera2->setCheckable(false);
        imageCamera2->setAutoDefault(false);
        imageCamera2->setDefault(false);
        imageCamera2->setFlat(false);

        gridLayout->addWidget(imageCamera2, 1, 2, 1, 1);

        frame_3 = new QFrame(cameramainoption);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMaximumSize(QSize(16777215, 20));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        title_3 = new QLabel(frame_3);
        title_3->setObjectName(QString::fromUtf8("title_3"));
        title_3->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_3, 2, 2, 1, 1);

        imageCamera3 = new QPushButton(cameramainoption);
        imageCamera3->setObjectName(QString::fromUtf8("imageCamera3"));
        sizePolicy1.setHeightForWidth(imageCamera3->sizePolicy().hasHeightForWidth());
        imageCamera3->setSizePolicy(sizePolicy1);
        imageCamera3->setFocusPolicy(Qt::NoFocus);
        imageCamera3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera3->setCheckable(false);
        imageCamera3->setAutoDefault(false);
        imageCamera3->setDefault(false);
        imageCamera3->setFlat(false);

        gridLayout->addWidget(imageCamera3, 3, 2, 1, 1);

        frame_6 = new QFrame(cameramainoption);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMaximumSize(QSize(16777215, 20));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        title_6 = new QLabel(frame_6);
        title_6->setObjectName(QString::fromUtf8("title_6"));
        title_6->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_6, 4, 0, 1, 1);

        frame_5 = new QFrame(cameramainoption);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMaximumSize(QSize(16777215, 20));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        title_5 = new QLabel(frame_5);
        title_5->setObjectName(QString::fromUtf8("title_5"));
        title_5->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_5, 4, 1, 1, 1);

        frame_4 = new QFrame(cameramainoption);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMaximumSize(QSize(16777215, 20));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        title_4 = new QLabel(frame_4);
        title_4->setObjectName(QString::fromUtf8("title_4"));
        title_4->setGeometry(QRect(10, 0, 67, 17));

        gridLayout->addWidget(frame_4, 4, 2, 1, 1);

        imageCamera6 = new QPushButton(cameramainoption);
        imageCamera6->setObjectName(QString::fromUtf8("imageCamera6"));
        sizePolicy1.setHeightForWidth(imageCamera6->sizePolicy().hasHeightForWidth());
        imageCamera6->setSizePolicy(sizePolicy1);
        imageCamera6->setFocusPolicy(Qt::NoFocus);
        imageCamera6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera6->setCheckable(false);
        imageCamera6->setAutoDefault(false);
        imageCamera6->setDefault(false);
        imageCamera6->setFlat(false);

        gridLayout->addWidget(imageCamera6, 5, 0, 1, 1);

        imageCamera5 = new QPushButton(cameramainoption);
        imageCamera5->setObjectName(QString::fromUtf8("imageCamera5"));
        sizePolicy1.setHeightForWidth(imageCamera5->sizePolicy().hasHeightForWidth());
        imageCamera5->setSizePolicy(sizePolicy1);
        imageCamera5->setFocusPolicy(Qt::NoFocus);
        imageCamera5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera5->setCheckable(false);
        imageCamera5->setAutoDefault(false);
        imageCamera5->setDefault(false);
        imageCamera5->setFlat(false);

        gridLayout->addWidget(imageCamera5, 5, 1, 1, 1);

        imageCamera4 = new QPushButton(cameramainoption);
        imageCamera4->setObjectName(QString::fromUtf8("imageCamera4"));
        sizePolicy1.setHeightForWidth(imageCamera4->sizePolicy().hasHeightForWidth());
        imageCamera4->setSizePolicy(sizePolicy1);
        imageCamera4->setFocusPolicy(Qt::NoFocus);
        imageCamera4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));
        imageCamera4->setCheckable(false);
        imageCamera4->setAutoDefault(false);
        imageCamera4->setDefault(false);
        imageCamera4->setFlat(false);

        gridLayout->addWidget(imageCamera4, 5, 2, 1, 1);


        retranslateUi(cameramainoption);

        QMetaObject::connectSlotsByName(cameramainoption);
    } // setupUi

    void retranslateUi(QWidget *cameramainoption)
    {
        cameramainoption->setWindowTitle(QApplication::translate("cameramainoption", "Form", 0, QApplication::UnicodeUTF8));
        title_1->setText(QApplication::translate("cameramainoption", "Camera 1", 0, QApplication::UnicodeUTF8));
        title_2->setText(QApplication::translate("cameramainoption", "Camera 2", 0, QApplication::UnicodeUTF8));
        imageCamera1->setText(QString());
        imageCamera2->setText(QString());
        title_3->setText(QApplication::translate("cameramainoption", "Camera 3", 0, QApplication::UnicodeUTF8));
        imageCamera3->setText(QString());
        title_6->setText(QApplication::translate("cameramainoption", "Camera 6", 0, QApplication::UnicodeUTF8));
        title_5->setText(QApplication::translate("cameramainoption", "Camera 5", 0, QApplication::UnicodeUTF8));
        title_4->setText(QApplication::translate("cameramainoption", "Camera 4", 0, QApplication::UnicodeUTF8));
        imageCamera6->setText(QString());
        imageCamera5->setText(QString());
        imageCamera4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cameramainoption: public Ui_cameramainoption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAMAINOPTION_H
