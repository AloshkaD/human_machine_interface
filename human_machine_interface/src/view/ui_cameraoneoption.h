#ifndef UI_CAMERAONEOPTION_H
#define UI_CAMERAONEOPTION_H

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

class Ui_cameraoneoption
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;
    QWidget *widget;

    void setupUi(QWidget *cameraoneoption)
    {
        if (cameraoneoption->objectName().isEmpty())
            cameraoneoption->setObjectName(QString::fromUtf8("cameraoneoption"));
        cameraoneoption->resize(667, 420);
        gridLayout = new QGridLayout(cameraoneoption);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(cameraoneoption);
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

        widget = new QWidget(cameraoneoption);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/iarc_floor.png);"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(cameraoneoption);

        QMetaObject::connectSlotsByName(cameraoneoption);
    } // setupUi

    void retranslateUi(QWidget *cameraoneoption)
    {
        cameraoneoption->setWindowTitle(QApplication::translate("cameraoneoption", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cameraoneoption", "Camera 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cameraoneoption: public Ui_cameraoneoption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAONEOPTION_H
