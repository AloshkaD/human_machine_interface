/********************************************************************************
** Form generated from reading UI file 'maincameraoption.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCAMERAOPTION_H
#define UI_MAINCAMERAOPTION_H

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
    QFrame *frame_title;
    QLabel *label_title;
    QLabel *main_image;
    QGridLayout *grid_layout;
    QSpacerItem *horizontal_spacer;
    QPushButton *left_button;
    QPushButton *right_button;

    void setupUi(QWidget *cameraMainOption)
    {
        if (cameraMainOption->objectName().isEmpty())
            cameraMainOption->setObjectName(QString::fromUtf8("cameraMainOption"));
        cameraMainOption->resize(667, 420);
        cameraMainOption->setFocusPolicy(Qt::NoFocus);
        cameraMainOption->setContextMenuPolicy(Qt::CustomContextMenu);
        gridLayout_2 = new QGridLayout(cameraMainOption);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_title = new QFrame(cameraMainOption);
        frame_title->setObjectName(QString::fromUtf8("frame_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_title->sizePolicy().hasHeightForWidth());
        frame_title->setSizePolicy(sizePolicy);
        frame_title->setMaximumSize(QSize(16777215, 20));
        frame_title->setFrameShape(QFrame::StyledPanel);
        frame_title->setFrameShadow(QFrame::Raised);
        label_title = new QLabel(frame_title);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(10, 0, 67, 17));

        gridLayout_2->addWidget(frame_title, 0, 0, 1, 1);

        main_image = new QLabel(cameraMainOption);
        main_image->setObjectName(QString::fromUtf8("main_image"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(main_image->sizePolicy().hasHeightForWidth());
        main_image->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(main_image, 1, 0, 1, 1);

        grid_layout = new QGridLayout();
        grid_layout->setObjectName(QString::fromUtf8("grid_layout"));
        horizontal_spacer = new QSpacerItem(558, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        grid_layout->addItem(horizontal_spacer, 0, 0, 1, 1);

        left_button = new QPushButton(cameraMainOption);
        left_button->setObjectName(QString::fromUtf8("left_button"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ic_skip_previous_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        left_button->setIcon(icon);

        grid_layout->addWidget(left_button, 0, 1, 1, 1);

        right_button = new QPushButton(cameraMainOption);
        right_button->setObjectName(QString::fromUtf8("right_button"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_skip_next_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        right_button->setIcon(icon1);

        grid_layout->addWidget(right_button, 0, 2, 1, 1);


        gridLayout_2->addLayout(grid_layout, 2, 0, 1, 1);


        retranslateUi(cameraMainOption);

        QMetaObject::connectSlotsByName(cameraMainOption);
    } // setupUi

    void retranslateUi(QWidget *cameraMainOption)
    {
        cameraMainOption->setWindowTitle(QApplication::translate("cameraMainOption", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        cameraMainOption->setStatusTip(QApplication::translate("cameraMainOption", "Show the camera images in full screen ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_title->setText(QApplication::translate("cameraMainOption", "Camera 1", 0, QApplication::UnicodeUTF8));
        main_image->setText(QString());
        left_button->setText(QString());
        right_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cameraMainOption: public Ui_cameraMainOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCAMERAOPTION_H
