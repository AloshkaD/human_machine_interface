/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_connection
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *group_box;
    QGridLayout *gridLayout;
    QLabel *label_ros_master;
    QCheckBox *checkbox_remember_settings;
    QLabel *label_IP;
    QLineEdit *line_edit_master;
    QSpacerItem *vertical_spacer;
    QLineEdit *line_edit_host;
    QSpacerItem *horizontal_spacer;
    QCheckBox *checkbox_use_environment;
    QPushButton *connect_button;

    void setupUi(QDialog *connection)
    {
        if (connection->objectName().isEmpty())
            connection->setObjectName(QString::fromUtf8("connection"));
        connection->resize(328, 346);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        connection->setWindowIcon(icon);
        connection->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(connection);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(connection);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(connection);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(connection);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        gridLayout_2 = new QGridLayout(connection);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(connection);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        group_box = new QGroupBox(frame);
        group_box->setObjectName(QString::fromUtf8("group_box"));
        gridLayout = new QGridLayout(group_box);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_ros_master = new QLabel(group_box);
        label_ros_master->setObjectName(QString::fromUtf8("label_ros_master"));
        label_ros_master->setFrameShape(QFrame::StyledPanel);
        label_ros_master->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_ros_master, 0, 0, 1, 1);

        checkbox_remember_settings = new QCheckBox(group_box);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 6, 0, 1, 1);

        label_IP = new QLabel(group_box);
        label_IP->setObjectName(QString::fromUtf8("label_IP"));
        label_IP->setFrameShape(QFrame::StyledPanel);
        label_IP->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_IP, 2, 0, 1, 1);

        line_edit_master = new QLineEdit(group_box);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));
        line_edit_master->setMouseTracking(true);

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 1);

        vertical_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(vertical_spacer, 4, 0, 1, 1);

        line_edit_host = new QLineEdit(group_box);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));
        line_edit_host->setMouseTracking(true);

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 1);

        horizontal_spacer = new QSpacerItem(170, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontal_spacer, 8, 0, 1, 1);

        checkbox_use_environment = new QCheckBox(group_box);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 5, 0, 1, 1);

        connect_button = new QPushButton(group_box);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));

        gridLayout->addWidget(connect_button, 7, 0, 1, 1);


        verticalLayout_3->addWidget(group_box);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(connection);

        QMetaObject::connectSlotsByName(connection);
    } // setupUi

    void retranslateUi(QDialog *connection)
    {
        connection->setWindowTitle(QApplication::translate("connection", "QRosApp", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        connection->setStatusTip(QApplication::translate("connection", "Allow the user to communicate the HMI with the master machine", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Quit->setText(QApplication::translate("connection", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("connection", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("connection", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("connection", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("connection", "About &Qt", 0, QApplication::UnicodeUTF8));
        group_box->setTitle(QApplication::translate("connection", "Ros Master", 0, QApplication::UnicodeUTF8));
        label_ros_master->setText(QApplication::translate("connection", "Ros Master Url", 0, QApplication::UnicodeUTF8));
        checkbox_remember_settings->setText(QApplication::translate("connection", "Remember settings on startup", 0, QApplication::UnicodeUTF8));
        label_IP->setText(QApplication::translate("connection", "Ros IP", 0, QApplication::UnicodeUTF8));
        line_edit_master->setText(QApplication::translate("connection", "http://192.168.1.2:11311/", 0, QApplication::UnicodeUTF8));
        line_edit_host->setText(QApplication::translate("connection", "192.168.1.67", 0, QApplication::UnicodeUTF8));
        checkbox_use_environment->setText(QApplication::translate("connection", "Use environment variables", 0, QApplication::UnicodeUTF8));
        connect_button->setText(QApplication::translate("connection", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class connection: public Ui_connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
