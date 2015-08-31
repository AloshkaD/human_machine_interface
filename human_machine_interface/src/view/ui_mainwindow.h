#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_perception_configuration;
    QAction *actionNew_connection;
    QAction *actionCameras;
    QAction *actionParameter_Temporal_Series;
    QAction *actionProcess_Monitor;
    QAction *actionSystem_Status;
    QAction *action3D_Perception_View;
    QAction *actionContents;
    QAction *actionAbout_Ground_Control_System;
    QAction *actionUser_Commands_Manual;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget_2;
    QWidget *tab_6;
    QGridLayout *gridLayout_3;
    QGridLayout *gridVehicle;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_Yaw_2;
    QLabel *label_16;
    QLabel *label_Roll_2;
    QLabel *label_17;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_19;
    QLabel *label_Y_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_Pitch_2;
    QLabel *label_X_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_Z_2;
    QLabel *vehicleScene;
    QWidget *tab_7;
    QGridLayout *gridLayout_4;
    QGridLayout *gridSphere;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_Yaw;
    QLabel *label_2;
    QLabel *label_Roll;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QLabel *label_Y;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Pitch;
    QLabel *label_X;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_Z;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QComboBox *selection_vehicle;
    QLabel *label_12;
    QLabel *label_Warnings;
    QFrame *line;
    QLabel *label_battery;
    QLabel *label_Errors;
    QLabel *label_Connection;
    QLabel *label_10;
    QLabel *label;
    QToolButton *yawzeroButton;
    QToolButton *resetButton;
    QPushButton *pushButton_EmergencyStop;
    QLabel *label_14;
    QLabel *label_15;
    QComboBox *selection_armed_;
    QFrame *line_2;
    QToolButton *takeoffButton;
    QToolButton *landButton;
    QComboBox *selection_Mode;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_FligthTime;
    QLabel *label_CurrentGoal;
    QLabel *label_11;
    QTabWidget *tabWidget;
    QWidget *tabParameters;
    QGridLayout *gridLayout_8;
    QGridLayout *gridParameters;
    QWidget *tab_4;
    QGridLayout *gridLayout_15;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridCamera;
    QWidget *widget_CamOptions;
    QGridLayout *gridLayout_10;
    QPushButton *mainCameraButton;
    QPushButton *fourCameraButton;
    QPushButton *sixCameraButton;
    QPushButton *gridCameraButton;
    QPushButton *oneCameraButton;
    QLabel *labelDisplayOptions;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridMap;
    QWidget *tabPerformance;
    QGridLayout *gridLayout_11;
    QGridLayout *gridPerformance;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1382, 1432);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1882, 16777215));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionOpen_perception_configuration = new QAction(MainWindow);
        actionOpen_perception_configuration->setObjectName(QString::fromUtf8("actionOpen_perception_configuration"));
        actionNew_connection = new QAction(MainWindow);
        actionNew_connection->setObjectName(QString::fromUtf8("actionNew_connection"));
        actionCameras = new QAction(MainWindow);
        actionCameras->setObjectName(QString::fromUtf8("actionCameras"));
        actionParameter_Temporal_Series = new QAction(MainWindow);
        actionParameter_Temporal_Series->setObjectName(QString::fromUtf8("actionParameter_Temporal_Series"));
        actionProcess_Monitor = new QAction(MainWindow);
        actionProcess_Monitor->setObjectName(QString::fromUtf8("actionProcess_Monitor"));
        actionSystem_Status = new QAction(MainWindow);
        actionSystem_Status->setObjectName(QString::fromUtf8("actionSystem_Status"));
        action3D_Perception_View = new QAction(MainWindow);
        action3D_Perception_View->setObjectName(QString::fromUtf8("action3D_Perception_View"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QString::fromUtf8("actionContents"));
        actionAbout_Ground_Control_System = new QAction(MainWindow);
        actionAbout_Ground_Control_System->setObjectName(QString::fromUtf8("actionAbout_Ground_Control_System"));
        actionUser_Commands_Manual = new QAction(MainWindow);
        actionUser_Commands_Manual->setObjectName(QString::fromUtf8("actionUser_Commands_Manual"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(350, 0));
        widget->setMaximumSize(QSize(350, 16777215));
        widget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(-1, 0, -1, -1);
        tabWidget_2 = new QTabWidget(widget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy1);
        tabWidget_2->setMaximumSize(QSize(350, 600));
        tabWidget_2->setFocusPolicy(Qt::NoFocus);
        tabWidget_2->setUsesScrollButtons(false);
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_3 = new QGridLayout(tab_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridVehicle = new QGridLayout();
        gridVehicle->setSpacing(6);
        gridVehicle->setObjectName(QString::fromUtf8("gridVehicle"));
        frame_2 = new QFrame(tab_6);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setMaximumSize(QSize(350, 16777215));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_Yaw_2 = new QLabel(frame_2);
        label_Yaw_2->setObjectName(QString::fromUtf8("label_Yaw_2"));
        sizePolicy2.setHeightForWidth(label_Yaw_2->sizePolicy().hasHeightForWidth());
        label_Yaw_2->setSizePolicy(sizePolicy2);
        label_Yaw_2->setMinimumSize(QSize(35, 0));
        label_Yaw_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_Yaw_2, 0, 5, 1, 1);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 0, 1, 1, 1);

        label_Roll_2 = new QLabel(frame_2);
        label_Roll_2->setObjectName(QString::fromUtf8("label_Roll_2"));
        sizePolicy2.setHeightForWidth(label_Roll_2->sizePolicy().hasHeightForWidth());
        label_Roll_2->setSizePolicy(sizePolicy2);
        label_Roll_2->setMinimumSize(QSize(35, 0));
        label_Roll_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_Roll_2, 2, 5, 1, 2);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 2, 1, 1, 1);

        label_18 = new QLabel(frame_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 6, 1, 1);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_2->addWidget(label_19, 2, 4, 1, 1);

        label_Y_2 = new QLabel(frame_2);
        label_Y_2->setObjectName(QString::fromUtf8("label_Y_2"));
        sizePolicy2.setHeightForWidth(label_Y_2->sizePolicy().hasHeightForWidth());
        label_Y_2->setSizePolicy(sizePolicy2);
        label_Y_2->setMinimumSize(QSize(38, 0));
        label_Y_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_Y_2, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        label_Pitch_2 = new QLabel(frame_2);
        label_Pitch_2->setObjectName(QString::fromUtf8("label_Pitch_2"));
        sizePolicy2.setHeightForWidth(label_Pitch_2->sizePolicy().hasHeightForWidth());
        label_Pitch_2->setSizePolicy(sizePolicy2);
        label_Pitch_2->setMinimumSize(QSize(35, 0));
        label_Pitch_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_Pitch_2, 1, 5, 1, 2);

        label_X_2 = new QLabel(frame_2);
        label_X_2->setObjectName(QString::fromUtf8("label_X_2"));
        sizePolicy2.setHeightForWidth(label_X_2->sizePolicy().hasHeightForWidth());
        label_X_2->setSizePolicy(sizePolicy2);
        label_X_2->setMinimumSize(QSize(38, 0));
        label_X_2->setMaximumSize(QSize(33, 16777215));

        gridLayout_2->addWidget(label_X_2, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_2->addWidget(label_20, 1, 1, 1, 1);

        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_2->addWidget(label_21, 1, 4, 1, 1);

        label_Z_2 = new QLabel(frame_2);
        label_Z_2->setObjectName(QString::fromUtf8("label_Z_2"));
        sizePolicy2.setHeightForWidth(label_Z_2->sizePolicy().hasHeightForWidth());
        label_Z_2->setSizePolicy(sizePolicy2);
        label_Z_2->setMinimumSize(QSize(38, 0));
        label_Z_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_Z_2, 2, 2, 1, 1);


        gridVehicle->addWidget(frame_2, 1, 0, 1, 1);

        vehicleScene = new QLabel(tab_6);
        vehicleScene->setObjectName(QString::fromUtf8("vehicleScene"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(vehicleScene->sizePolicy().hasHeightForWidth());
        vehicleScene->setSizePolicy(sizePolicy3);

        gridVehicle->addWidget(vehicleScene, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridVehicle, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QString::fromUtf8("Vehicle Dynamics"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_4 = new QGridLayout(tab_7);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridSphere = new QGridLayout();
        gridSphere->setSpacing(6);
        gridSphere->setObjectName(QString::fromUtf8("gridSphere"));
        frame = new QFrame(tab_7);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMaximumSize(QSize(350, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Yaw = new QLabel(frame);
        label_Yaw->setObjectName(QString::fromUtf8("label_Yaw"));
        sizePolicy2.setHeightForWidth(label_Yaw->sizePolicy().hasHeightForWidth());
        label_Yaw->setSizePolicy(sizePolicy2);
        label_Yaw->setMinimumSize(QSize(35, 0));
        label_Yaw->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_Yaw, 0, 5, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_Roll = new QLabel(frame);
        label_Roll->setObjectName(QString::fromUtf8("label_Roll"));
        sizePolicy2.setHeightForWidth(label_Roll->sizePolicy().hasHeightForWidth());
        label_Roll->setSizePolicy(sizePolicy2);
        label_Roll->setMinimumSize(QSize(35, 0));
        label_Roll->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_Roll, 2, 5, 1, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 4, 1, 1);

        label_Y = new QLabel(frame);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        sizePolicy2.setHeightForWidth(label_Y->sizePolicy().hasHeightForWidth());
        label_Y->setSizePolicy(sizePolicy2);
        label_Y->setMinimumSize(QSize(35, 0));
        label_Y->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_Y, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        label_Pitch = new QLabel(frame);
        label_Pitch->setObjectName(QString::fromUtf8("label_Pitch"));
        sizePolicy2.setHeightForWidth(label_Pitch->sizePolicy().hasHeightForWidth());
        label_Pitch->setSizePolicy(sizePolicy2);
        label_Pitch->setMinimumSize(QSize(35, 0));
        label_Pitch->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_Pitch, 1, 5, 1, 2);

        label_X = new QLabel(frame);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        sizePolicy2.setHeightForWidth(label_X->sizePolicy().hasHeightForWidth());
        label_X->setSizePolicy(sizePolicy2);
        label_X->setMinimumSize(QSize(35, 0));
        label_X->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_X, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 4, 1, 1);

        label_Z = new QLabel(frame);
        label_Z->setObjectName(QString::fromUtf8("label_Z"));
        sizePolicy2.setHeightForWidth(label_Z->sizePolicy().hasHeightForWidth());
        label_Z->setSizePolicy(sizePolicy2);
        label_Z->setMinimumSize(QSize(35, 0));
        label_Z->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label_Z, 2, 2, 1, 1);


        gridSphere->addWidget(frame, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridSphere->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridSphere, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_7, QString());

        gridLayout_7->addWidget(tabWidget_2, 1, 0, 1, 1);

        tabWidget_3 = new QTabWidget(widget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        sizePolicy1.setHeightForWidth(tabWidget_3->sizePolicy().hasHeightForWidth());
        tabWidget_3->setSizePolicy(sizePolicy1);
        tabWidget_3->setMinimumSize(QSize(0, 400));
        tabWidget_3->setMaximumSize(QSize(350, 800));
        tabWidget_3->setFocusPolicy(Qt::NoFocus);
        tabWidget_3->setUsesScrollButtons(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        label_13->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_13, 7, 0, 1, 2);

        selection_vehicle = new QComboBox(tab_5);
        selection_vehicle->setObjectName(QString::fromUtf8("selection_vehicle"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(selection_vehicle->sizePolicy().hasHeightForWidth());
        selection_vehicle->setSizePolicy(sizePolicy5);
        selection_vehicle->setMinimumSize(QSize(0, 25));
        selection_vehicle->setMaximumSize(QSize(160, 370));
        selection_vehicle->setFocusPolicy(Qt::NoFocus);
        selection_vehicle->setLayoutDirection(Qt::LeftToRight);
        selection_vehicle->setInsertPolicy(QComboBox::InsertAtTop);
        selection_vehicle->setFrame(true);

        gridLayout_5->addWidget(selection_vehicle, 7, 2, 1, 3);

        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy6);
        label_12->setMinimumSize(QSize(140, 0));

        gridLayout_5->addWidget(label_12, 5, 0, 1, 2);

        label_Warnings = new QLabel(tab_5);
        label_Warnings->setObjectName(QString::fromUtf8("label_Warnings"));
        sizePolicy2.setHeightForWidth(label_Warnings->sizePolicy().hasHeightForWidth());
        label_Warnings->setSizePolicy(sizePolicy2);
        label_Warnings->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_Warnings, 5, 3, 1, 2);

        line = new QFrame(tab_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 6, 0, 1, 5);

        label_battery = new QLabel(tab_5);
        label_battery->setObjectName(QString::fromUtf8("label_battery"));
        sizePolicy2.setHeightForWidth(label_battery->sizePolicy().hasHeightForWidth());
        label_battery->setSizePolicy(sizePolicy2);
        label_battery->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_battery, 1, 3, 1, 2);

        label_Errors = new QLabel(tab_5);
        label_Errors->setObjectName(QString::fromUtf8("label_Errors"));
        sizePolicy2.setHeightForWidth(label_Errors->sizePolicy().hasHeightForWidth());
        label_Errors->setSizePolicy(sizePolicy2);
        label_Errors->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_Errors, 4, 3, 1, 2);

        label_Connection = new QLabel(tab_5);
        label_Connection->setObjectName(QString::fromUtf8("label_Connection"));
        sizePolicy2.setHeightForWidth(label_Connection->sizePolicy().hasHeightForWidth());
        label_Connection->setSizePolicy(sizePolicy2);
        label_Connection->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_Connection, 0, 3, 1, 2);

        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);
        label_10->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_10, 3, 0, 1, 2);

        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label, 0, 0, 1, 2);

        yawzeroButton = new QToolButton(tab_5);
        yawzeroButton->setObjectName(QString::fromUtf8("yawzeroButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(yawzeroButton->sizePolicy().hasHeightForWidth());
        yawzeroButton->setSizePolicy(sizePolicy7);
        yawzeroButton->setMinimumSize(QSize(70, 0));
        yawzeroButton->setMaximumSize(QSize(70, 16777215));
        yawzeroButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        yawzeroButton->setIcon(icon);
        yawzeroButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(yawzeroButton, 11, 3, 1, 1);

        resetButton = new QToolButton(tab_5);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        sizePolicy7.setHeightForWidth(resetButton->sizePolicy().hasHeightForWidth());
        resetButton->setSizePolicy(sizePolicy7);
        resetButton->setMinimumSize(QSize(70, 0));
        resetButton->setMaximumSize(QSize(70, 16777215));
        resetButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        resetButton->setIcon(icon1);
        resetButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(resetButton, 11, 4, 1, 1);

        pushButton_EmergencyStop = new QPushButton(tab_5);
        pushButton_EmergencyStop->setObjectName(QString::fromUtf8("pushButton_EmergencyStop"));
        sizePolicy7.setHeightForWidth(pushButton_EmergencyStop->sizePolicy().hasHeightForWidth());
        pushButton_EmergencyStop->setSizePolicy(sizePolicy7);
        pushButton_EmergencyStop->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EmergencyStop->setIcon(icon2);
        pushButton_EmergencyStop->setAutoRepeat(true);
        pushButton_EmergencyStop->setAutoDefault(true);
        pushButton_EmergencyStop->setDefault(true);

        gridLayout_5->addWidget(pushButton_EmergencyStop, 12, 0, 1, 5);

        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy4.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy4);
        label_14->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_14, 8, 0, 1, 2);

        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy8);
        label_15->setMaximumSize(QSize(16777215, 20));

        gridLayout_5->addWidget(label_15, 9, 0, 1, 1);

        selection_armed_ = new QComboBox(tab_5);
        selection_armed_->setObjectName(QString::fromUtf8("selection_armed_"));
        sizePolicy5.setHeightForWidth(selection_armed_->sizePolicy().hasHeightForWidth());
        selection_armed_->setSizePolicy(sizePolicy5);
        selection_armed_->setMinimumSize(QSize(0, 25));
        selection_armed_->setMaximumSize(QSize(160, 300));
        selection_armed_->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(selection_armed_, 9, 2, 1, 3);

        line_2 = new QFrame(tab_5);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 10, 0, 1, 5);

        takeoffButton = new QToolButton(tab_5);
        takeoffButton->setObjectName(QString::fromUtf8("takeoffButton"));
        sizePolicy7.setHeightForWidth(takeoffButton->sizePolicy().hasHeightForWidth());
        takeoffButton->setSizePolicy(sizePolicy7);
        takeoffButton->setMinimumSize(QSize(70, 0));
        takeoffButton->setMaximumSize(QSize(70, 16777215));
        takeoffButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/airplane-takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        takeoffButton->setIcon(icon3);
        takeoffButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(takeoffButton, 11, 0, 1, 1);

        landButton = new QToolButton(tab_5);
        landButton->setObjectName(QString::fromUtf8("landButton"));
        sizePolicy7.setHeightForWidth(landButton->sizePolicy().hasHeightForWidth());
        landButton->setSizePolicy(sizePolicy7);
        landButton->setMinimumSize(QSize(70, 0));
        landButton->setMaximumSize(QSize(70, 16777215));
        landButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/airplane-landing.png"), QSize(), QIcon::Normal, QIcon::Off);
        landButton->setIcon(icon4);
        landButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(landButton, 11, 1, 1, 2);

        selection_Mode = new QComboBox(tab_5);
        selection_Mode->setObjectName(QString::fromUtf8("selection_Mode"));
        sizePolicy5.setHeightForWidth(selection_Mode->sizePolicy().hasHeightForWidth());
        selection_Mode->setSizePolicy(sizePolicy5);
        selection_Mode->setMinimumSize(QSize(1, 25));
        selection_Mode->setMaximumSize(QSize(160, 300));
        selection_Mode->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(selection_Mode, 8, 2, 1, 3);

        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy9);

        gridLayout_5->addWidget(label_9, 2, 0, 1, 2);

        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy9.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy9);

        gridLayout_5->addWidget(label_8, 1, 0, 1, 2);

        label_FligthTime = new QLabel(tab_5);
        label_FligthTime->setObjectName(QString::fromUtf8("label_FligthTime"));
        sizePolicy2.setHeightForWidth(label_FligthTime->sizePolicy().hasHeightForWidth());
        label_FligthTime->setSizePolicy(sizePolicy2);
        label_FligthTime->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_FligthTime, 2, 3, 1, 2);

        label_CurrentGoal = new QLabel(tab_5);
        label_CurrentGoal->setObjectName(QString::fromUtf8("label_CurrentGoal"));
        sizePolicy2.setHeightForWidth(label_CurrentGoal->sizePolicy().hasHeightForWidth());
        label_CurrentGoal->setSizePolicy(sizePolicy2);
        label_CurrentGoal->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_CurrentGoal, 3, 3, 1, 2);

        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_11, 4, 0, 1, 2);

        tabWidget_3->addTab(tab_5, QString());

        gridLayout_7->addWidget(tabWidget_3, 0, 0, 1, 1);


        gridLayout_9->addWidget(widget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(32909, 1501));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabParameters = new QWidget();
        tabParameters->setObjectName(QString::fromUtf8("tabParameters"));
        gridLayout_8 = new QGridLayout(tabParameters);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 0, -1, -1);
        gridParameters = new QGridLayout();
        gridParameters->setSpacing(6);
        gridParameters->setObjectName(QString::fromUtf8("gridParameters"));
        gridParameters->setHorizontalSpacing(0);

        gridLayout_8->addLayout(gridParameters, 0, 0, 1, 1);

        tabWidget->addTab(tabParameters, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_15 = new QGridLayout(tab_4);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        horizontalSpacer = new QSpacerItem(747, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridCamera = new QGridLayout();
        gridCamera->setSpacing(0);
        gridCamera->setObjectName(QString::fromUtf8("gridCamera"));

        gridLayout_15->addLayout(gridCamera, 1, 0, 1, 2);

        widget_CamOptions = new QWidget(tab_4);
        widget_CamOptions->setObjectName(QString::fromUtf8("widget_CamOptions"));
        sizePolicy5.setHeightForWidth(widget_CamOptions->sizePolicy().hasHeightForWidth());
        widget_CamOptions->setSizePolicy(sizePolicy5);
        widget_CamOptions->setMaximumSize(QSize(270, 75));
        gridLayout_10 = new QGridLayout(widget_CamOptions);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 0, -1, -1);
        mainCameraButton = new QPushButton(widget_CamOptions);
        mainCameraButton->setObjectName(QString::fromUtf8("mainCameraButton"));
        sizePolicy5.setHeightForWidth(mainCameraButton->sizePolicy().hasHeightForWidth());
        mainCameraButton->setSizePolicy(sizePolicy5);
        mainCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/multiplecameraview.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainCameraButton->setIcon(icon5);
        mainCameraButton->setIconSize(QSize(70, 35));

        gridLayout_10->addWidget(mainCameraButton, 1, 1, 1, 1);

        fourCameraButton = new QPushButton(widget_CamOptions);
        fourCameraButton->setObjectName(QString::fromUtf8("fourCameraButton"));
        sizePolicy5.setHeightForWidth(fourCameraButton->sizePolicy().hasHeightForWidth());
        fourCameraButton->setSizePolicy(sizePolicy5);
        fourCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/ic_view_stream_24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        fourCameraButton->setIcon(icon6);
        fourCameraButton->setIconSize(QSize(40, 40));

        gridLayout_10->addWidget(fourCameraButton, 1, 2, 1, 1);

        sixCameraButton = new QPushButton(widget_CamOptions);
        sixCameraButton->setObjectName(QString::fromUtf8("sixCameraButton"));
        sizePolicy5.setHeightForWidth(sixCameraButton->sizePolicy().hasHeightForWidth());
        sixCameraButton->setSizePolicy(sizePolicy5);
        sixCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/ic_view_module_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        sixCameraButton->setIcon(icon7);
        sixCameraButton->setIconSize(QSize(30, 30));

        gridLayout_10->addWidget(sixCameraButton, 1, 3, 1, 1);

        gridCameraButton = new QPushButton(widget_CamOptions);
        gridCameraButton->setObjectName(QString::fromUtf8("gridCameraButton"));
        sizePolicy5.setHeightForWidth(gridCameraButton->sizePolicy().hasHeightForWidth());
        gridCameraButton->setSizePolicy(sizePolicy5);
        gridCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/ic_view_comfortable_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        gridCameraButton->setIcon(icon8);
        gridCameraButton->setIconSize(QSize(30, 30));

        gridLayout_10->addWidget(gridCameraButton, 1, 4, 1, 1);

        oneCameraButton = new QPushButton(widget_CamOptions);
        oneCameraButton->setObjectName(QString::fromUtf8("oneCameraButton"));
        sizePolicy5.setHeightForWidth(oneCameraButton->sizePolicy().hasHeightForWidth());
        oneCameraButton->setSizePolicy(sizePolicy5);
        oneCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/ic_image_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        oneCameraButton->setIcon(icon9);
        oneCameraButton->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(oneCameraButton, 1, 0, 1, 1);

        labelDisplayOptions = new QLabel(widget_CamOptions);
        labelDisplayOptions->setObjectName(QString::fromUtf8("labelDisplayOptions"));

        gridLayout_10->addWidget(labelDisplayOptions, 0, 0, 1, 3);


        gridLayout_15->addWidget(widget_CamOptions, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 0, -1, -1);
        gridMap = new QGridLayout();
        gridMap->setSpacing(6);
        gridMap->setObjectName(QString::fromUtf8("gridMap"));

        gridLayout_6->addLayout(gridMap, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tabPerformance = new QWidget();
        tabPerformance->setObjectName(QString::fromUtf8("tabPerformance"));
        gridLayout_11 = new QGridLayout(tabPerformance);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(-1, 0, -1, -1);
        gridPerformance = new QGridLayout();
        gridPerformance->setSpacing(6);
        gridPerformance->setObjectName(QString::fromUtf8("gridPerformance"));

        gridLayout_11->addLayout(gridPerformance, 0, 0, 1, 1);

        tabWidget->addTab(tabPerformance, QString());

        gridLayout_9->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1382, 25));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_perception_configuration);
        menuView->addAction(actionCameras);
        menuView->addSeparator();
        menuView->addAction(actionParameter_Temporal_Series);
        menuView->addSeparator();
        menuView->addAction(actionProcess_Monitor);
        menuView->addAction(actionSystem_Status);
        menuView->addSeparator();
        menuView->addAction(action3D_Perception_View);
        menuSettings->addAction(actionNew_connection);
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionAbout_Ground_Control_System);
        menuHelp->addAction(actionUser_Commands_Manual);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen_perception_configuration->setText(QApplication::translate("MainWindow", "Open perception config file ", 0, QApplication::UnicodeUTF8));
        actionNew_connection->setText(QApplication::translate("MainWindow", "New Connection ", 0, QApplication::UnicodeUTF8));
        actionCameras->setText(QApplication::translate("MainWindow", "Cameras", 0, QApplication::UnicodeUTF8));
        actionParameter_Temporal_Series->setText(QApplication::translate("MainWindow", "Parameter Temporal Series", 0, QApplication::UnicodeUTF8));
        actionProcess_Monitor->setText(QApplication::translate("MainWindow", "Process Monitor", 0, QApplication::UnicodeUTF8));
        actionSystem_Status->setText(QApplication::translate("MainWindow", "System Status", 0, QApplication::UnicodeUTF8));
        action3D_Perception_View->setText(QApplication::translate("MainWindow", "3D Perception View", 0, QApplication::UnicodeUTF8));
        actionContents->setText(QApplication::translate("MainWindow", "Contents", 0, QApplication::UnicodeUTF8));
        actionAbout_Ground_Control_System->setText(QApplication::translate("MainWindow", "About Ground Control System", 0, QApplication::UnicodeUTF8));
        actionUser_Commands_Manual->setText(QApplication::translate("MainWindow", "User Commands Manual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tabWidget_2->setStatusTip(QApplication::translate("MainWindow", "Shows the rotation angles and the current position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_Yaw_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_Roll_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        label_Y_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_Pitch_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_X_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        label_Z_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        vehicleScene->setText(QString());
        label_Yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_Roll->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        label_Y->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_Pitch->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_X->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        label_Z->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Sphere Dynamics", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget_3->setToolTip(QApplication::translate("MainWindow", "Panel Control", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tabWidget_3->setStatusTip(QApplication::translate("MainWindow", "Shows the current state of the UAV and the basic control actions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_13->setText(QApplication::translate("MainWindow", "Selected Vehicle :", 0, QApplication::UnicodeUTF8));
        selection_vehicle->clear();
        selection_vehicle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "UAV_1", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("MainWindow", "Detected Warnings :", 0, QApplication::UnicodeUTF8));
        label_Warnings->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_battery->setText(QApplication::translate("MainWindow", "0%", 0, QApplication::UnicodeUTF8));
        label_Errors->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_Connection->setText(QApplication::translate("MainWindow", "Disconnected", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Current Goal :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Wifi Connection :", 0, QApplication::UnicodeUTF8));
        yawzeroButton->setText(QApplication::translate("MainWindow", "Yaw Zero", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        pushButton_EmergencyStop->setText(QApplication::translate("MainWindow", "Emergency Stop", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Control Mode :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Armed :", 0, QApplication::UnicodeUTF8));
        selection_armed_->clear();
        selection_armed_->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "True", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "False", 0, QApplication::UnicodeUTF8)
        );
        takeoffButton->setText(QApplication::translate("MainWindow", "Take Off", 0, QApplication::UnicodeUTF8));
        landButton->setText(QApplication::translate("MainWindow", "Land", 0, QApplication::UnicodeUTF8));
        selection_Mode->clear();
        selection_Mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Autonomous", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Automatic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("MainWindow", "Flying Time :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Battery Charge :", 0, QApplication::UnicodeUTF8));
        label_FligthTime->setText(QApplication::translate("MainWindow", "0:00", 0, QApplication::UnicodeUTF8));
        label_CurrentGoal->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Detected Errors :", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("MainWindow", "Control Panel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tabParameters), QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        mainCameraButton->setText(QString());
        fourCameraButton->setText(QString());
        sixCameraButton->setText(QString());
        gridCameraButton->setText(QString());
        oneCameraButton->setText(QString());
        labelDisplayOptions->setText(QApplication::translate("MainWindow", "Display Options:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Camera Views", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Environment Understanding", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPerformance), QApplication::translate("MainWindow", "Performance Monitor", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
