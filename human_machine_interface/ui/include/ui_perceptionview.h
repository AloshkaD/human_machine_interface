#ifndef UI_PERCEPTIONVIEW_H
#define UI_PERCEPTIONVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_perceptionView
{
public:
    QWidget *dockWidgetContents;
    QWidget *widget;

    void setupUi(QDockWidget *perceptionView)
    {
        if (perceptionView->objectName().isEmpty())
            perceptionView->setObjectName(QString::fromUtf8("perceptionView"));
        perceptionView->resize(476, 528);
        perceptionView->setFeatures(QDockWidget::NoDockWidgetFeatures);
        perceptionView->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setEnabled(true);
        widget = new QWidget(dockWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-20, 0, 871, 521));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(325, 395));
        widget->setLayoutDirection(Qt::LeftToRight);
        perceptionView->setWidget(dockWidgetContents);

        retranslateUi(perceptionView);

        QMetaObject::connectSlotsByName(perceptionView);
    } // setupUi

    void retranslateUi(QDockWidget *perceptionView)
    {
#ifndef QT_NO_STATUSTIP
        perceptionView->setStatusTip(QApplication::translate("perceptionView", "Show the perceived state and estimated position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        perceptionView->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class perceptionView: public Ui_perceptionView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERCEPTIONVIEW_H
