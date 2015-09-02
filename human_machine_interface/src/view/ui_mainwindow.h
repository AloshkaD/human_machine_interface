/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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
    QAction *actionCommunication_Console;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QTabWidget *tabManager;
    QWidget *tabParameters;
    QGridLayout *gridLayout_8;
    QGridLayout *gridParameters;
    QWidget *tabCameraView;
    QGridLayout *gridLayout;
    QWidget *widget_CamOptions;
    QGridLayout *gridLayout_10;
    QPushButton *mainCameraButton;
    QPushButton *fourCameraButton;
    QLabel *labelDisplayOptions;
    QPushButton *oneCameraButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveImageButton;
    QGridLayout *gridCamera;
    QWidget *tabPerformance;
    QGridLayout *gridLayout_11;
    QGridLayout *gridPerformance;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QTabWidget *tab_controlPanel;
    QWidget *widget_controlPanel;
    QGridLayout *gridLayout_5;
    QLabel *label_flyingTime;
    QLabel *value_Warnings;
    QPushButton *emergencyStop_Button;
    QLabel *label_warnings;
    QLabel *value_currentGoal;
    QLabel *value_wifi;
    QToolButton *yawzeroButton;
    QToolButton *resetButton;
    QLabel *value_battery;
    QToolButton *hoverButton;
    QComboBox *selection_vehicle;
    QLabel *value_FligthTime;
    QFrame *line_2;
    QLabel *value_Errors;
    QComboBox *selection_mode;
    QLabel *label_battery_2;
    QLabel *label_controlMode;
    QLabel *label_selVehicle;
    QLabel *label_currentGoal;
    QToolButton *landButton;
    QFrame *line;
    QLabel *label_wifi;
    QLabel *label_errors;
    QToolButton *takeoffButton;
    QTabWidget *tab_dynamicView;
    QWidget *widget_vehicle;
    QGridLayout *gridLayout_3;
    QGridLayout *grid_vehicle;
    QFrame *panel_vehicle;
    QGridLayout *grid_panelVehicle;
    QLabel *valueVehicle_Yaw;
    QLabel *labelVehicle_X;
    QLabel *valueVehicle_roll;
    QLabel *labelVehicle_Z;
    QLabel *labelVehicle_yaw;
    QSpacerItem *horizontalSpacer_right;
    QLabel *labelVehicle_roll;
    QLabel *valueVehicle_Y;
    QSpacerItem *horizontalSpacer_left;
    QLabel *valueVehicle_pitch;
    QLabel *valueVehicle_X;
    QSpacerItem *horizontalSpacer_middle;
    QLabel *labelVehicle_Y;
    QLabel *labelVehicle_pitch;
    QLabel *valueVehicle_Z;
    QLabel *vehicleScene;
    QWidget *widget_sphere;
    QGridLayout *gridLayout_4;
    QGridLayout *grid_sphere;
    QLabel *sphereScene;
    QFrame *panel_sphere;
    QGridLayout *grid_panelSphere;
    QLabel *valueSphere_yaw;
    QLabel *labelSphere_X;
    QLabel *valueSphere_roll;
    QLabel *labelSphere_Z;
    QLabel *labelSphere_yaw;
    QSpacerItem *horizontalSpacer_right_2;
    QLabel *labelSphere_roll;
    QLabel *valueSphere_Y;
    QSpacerItem *horizontalSpacer_left_2;
    QLabel *labelSphere_Y;
    QLabel *valueSphere_pitch;
    QLabel *labelSphere_pitch;
    QLabel *valueSphere_X;
    QSpacerItem *horizontalSpacer_middle_2;
    QLabel *valueSphere_Z;
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
        MainWindow->resize(1382, 1064);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1882, 16777215));
        MainWindow->setBaseSize(QSize(0, 0));
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
        actionCommunication_Console = new QAction(MainWindow);
        actionCommunication_Console->setObjectName(QString::fromUtf8("actionCommunication_Console"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tabManager = new QTabWidget(centralWidget);
        tabManager->setObjectName(QString::fromUtf8("tabManager"));
        tabManager->setEnabled(true);
        sizePolicy.setHeightForWidth(tabManager->sizePolicy().hasHeightForWidth());
        tabManager->setSizePolicy(sizePolicy);
        tabManager->setMinimumSize(QSize(0, 0));
        tabManager->setMaximumSize(QSize(32909, 1501));
        tabManager->setSizeIncrement(QSize(0, 0));
        tabManager->setBaseSize(QSize(0, 0));
        tabManager->setFocusPolicy(Qt::NoFocus);
        tabManager->setTabShape(QTabWidget::Rounded);
        tabManager->setElideMode(Qt::ElideNone);
        tabManager->setUsesScrollButtons(false);
        tabManager->setDocumentMode(false);
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

        tabManager->addTab(tabParameters, QString());
        tabCameraView = new QWidget();
        tabCameraView->setObjectName(QString::fromUtf8("tabCameraView"));
        gridLayout = new QGridLayout(tabCameraView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_CamOptions = new QWidget(tabCameraView);
        widget_CamOptions->setObjectName(QString::fromUtf8("widget_CamOptions"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_CamOptions->sizePolicy().hasHeightForWidth());
        widget_CamOptions->setSizePolicy(sizePolicy1);
        widget_CamOptions->setMaximumSize(QSize(270, 75));
        gridLayout_10 = new QGridLayout(widget_CamOptions);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 0, -1, -1);
        mainCameraButton = new QPushButton(widget_CamOptions);
        mainCameraButton->setObjectName(QString::fromUtf8("mainCameraButton"));
        sizePolicy1.setHeightForWidth(mainCameraButton->sizePolicy().hasHeightForWidth());
        mainCameraButton->setSizePolicy(sizePolicy1);
        mainCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/multiplecameraview.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainCameraButton->setIcon(icon);
        mainCameraButton->setIconSize(QSize(70, 35));

        gridLayout_10->addWidget(mainCameraButton, 1, 1, 1, 1);

        fourCameraButton = new QPushButton(widget_CamOptions);
        fourCameraButton->setObjectName(QString::fromUtf8("fourCameraButton"));
        sizePolicy1.setHeightForWidth(fourCameraButton->sizePolicy().hasHeightForWidth());
        fourCameraButton->setSizePolicy(sizePolicy1);
        fourCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/ic_view_stream_24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        fourCameraButton->setIcon(icon1);
        fourCameraButton->setIconSize(QSize(40, 40));

        gridLayout_10->addWidget(fourCameraButton, 1, 2, 1, 1);

        labelDisplayOptions = new QLabel(widget_CamOptions);
        labelDisplayOptions->setObjectName(QString::fromUtf8("labelDisplayOptions"));

        gridLayout_10->addWidget(labelDisplayOptions, 0, 0, 1, 3);

        oneCameraButton = new QPushButton(widget_CamOptions);
        oneCameraButton->setObjectName(QString::fromUtf8("oneCameraButton"));
        sizePolicy1.setHeightForWidth(oneCameraButton->sizePolicy().hasHeightForWidth());
        oneCameraButton->setSizePolicy(sizePolicy1);
        oneCameraButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/ic_image_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        oneCameraButton->setIcon(icon2);
        oneCameraButton->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(oneCameraButton, 1, 0, 1, 1);


        gridLayout->addWidget(widget_CamOptions, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(747, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        saveImageButton = new QPushButton(tabCameraView);
        saveImageButton->setObjectName(QString::fromUtf8("saveImageButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        saveImageButton->setIcon(icon3);

        gridLayout->addWidget(saveImageButton, 0, 2, 1, 1);

        gridCamera = new QGridLayout();
        gridCamera->setSpacing(0);
        gridCamera->setObjectName(QString::fromUtf8("gridCamera"));

        gridLayout->addLayout(gridCamera, 1, 0, 1, 3);

        tabManager->addTab(tabCameraView, QString());
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

        tabManager->addTab(tabPerformance, QString());

        gridLayout_9->addWidget(tabManager, 0, 1, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(350, 0));
        widget->setMaximumSize(QSize(350, 16777215));
        widget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setVerticalSpacing(4);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        tab_controlPanel = new QTabWidget(widget);
        tab_controlPanel->setObjectName(QString::fromUtf8("tab_controlPanel"));
        sizePolicy2.setHeightForWidth(tab_controlPanel->sizePolicy().hasHeightForWidth());
        tab_controlPanel->setSizePolicy(sizePolicy2);
        tab_controlPanel->setMinimumSize(QSize(0, 380));
        tab_controlPanel->setMaximumSize(QSize(350, 800));
        tab_controlPanel->setFocusPolicy(Qt::NoFocus);
        tab_controlPanel->setUsesScrollButtons(false);
        widget_controlPanel = new QWidget();
        widget_controlPanel->setObjectName(QString::fromUtf8("widget_controlPanel"));
        gridLayout_5 = new QGridLayout(widget_controlPanel);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_flyingTime = new QLabel(widget_controlPanel);
        label_flyingTime->setObjectName(QString::fromUtf8("label_flyingTime"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_flyingTime->sizePolicy().hasHeightForWidth());
        label_flyingTime->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_flyingTime, 2, 0, 1, 2);

        value_Warnings = new QLabel(widget_controlPanel);
        value_Warnings->setObjectName(QString::fromUtf8("value_Warnings"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(value_Warnings->sizePolicy().hasHeightForWidth());
        value_Warnings->setSizePolicy(sizePolicy4);
        value_Warnings->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_Warnings, 5, 3, 1, 3);

        emergencyStop_Button = new QPushButton(widget_controlPanel);
        emergencyStop_Button->setObjectName(QString::fromUtf8("emergencyStop_Button"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(emergencyStop_Button->sizePolicy().hasHeightForWidth());
        emergencyStop_Button->setSizePolicy(sizePolicy5);
        emergencyStop_Button->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        emergencyStop_Button->setIcon(icon4);
        emergencyStop_Button->setAutoRepeat(true);
        emergencyStop_Button->setAutoDefault(true);
        emergencyStop_Button->setDefault(true);

        gridLayout_5->addWidget(emergencyStop_Button, 11, 0, 1, 6);

        label_warnings = new QLabel(widget_controlPanel);
        label_warnings->setObjectName(QString::fromUtf8("label_warnings"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_warnings->sizePolicy().hasHeightForWidth());
        label_warnings->setSizePolicy(sizePolicy6);
        label_warnings->setMinimumSize(QSize(140, 0));

        gridLayout_5->addWidget(label_warnings, 5, 0, 1, 3);

        value_currentGoal = new QLabel(widget_controlPanel);
        value_currentGoal->setObjectName(QString::fromUtf8("value_currentGoal"));
        sizePolicy4.setHeightForWidth(value_currentGoal->sizePolicy().hasHeightForWidth());
        value_currentGoal->setSizePolicy(sizePolicy4);
        value_currentGoal->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_currentGoal, 3, 3, 1, 3);

        value_wifi = new QLabel(widget_controlPanel);
        value_wifi->setObjectName(QString::fromUtf8("value_wifi"));
        sizePolicy4.setHeightForWidth(value_wifi->sizePolicy().hasHeightForWidth());
        value_wifi->setSizePolicy(sizePolicy4);
        value_wifi->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_wifi, 0, 3, 1, 3);

        yawzeroButton = new QToolButton(widget_controlPanel);
        yawzeroButton->setObjectName(QString::fromUtf8("yawzeroButton"));
        sizePolicy5.setHeightForWidth(yawzeroButton->sizePolicy().hasHeightForWidth());
        yawzeroButton->setSizePolicy(sizePolicy5);
        yawzeroButton->setMinimumSize(QSize(60, 0));
        yawzeroButton->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setPointSize(10);
        yawzeroButton->setFont(font);
        yawzeroButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        yawzeroButton->setIcon(icon5);
        yawzeroButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(yawzeroButton, 10, 2, 1, 2);

        resetButton = new QToolButton(widget_controlPanel);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        sizePolicy5.setHeightForWidth(resetButton->sizePolicy().hasHeightForWidth());
        resetButton->setSizePolicy(sizePolicy5);
        resetButton->setMinimumSize(QSize(60, 0));
        resetButton->setMaximumSize(QSize(60, 16777215));
        resetButton->setFont(font);
        resetButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        resetButton->setIcon(icon6);
        resetButton->setIconSize(QSize(14, 14));
        resetButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(resetButton, 10, 5, 1, 1);

        value_battery = new QLabel(widget_controlPanel);
        value_battery->setObjectName(QString::fromUtf8("value_battery"));
        sizePolicy4.setHeightForWidth(value_battery->sizePolicy().hasHeightForWidth());
        value_battery->setSizePolicy(sizePolicy4);
        value_battery->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_battery, 1, 3, 1, 3);

        hoverButton = new QToolButton(widget_controlPanel);
        hoverButton->setObjectName(QString::fromUtf8("hoverButton"));
        hoverButton->setMinimumSize(QSize(60, 0));
        hoverButton->setMaximumSize(QSize(60, 70));
        hoverButton->setFont(font);
        hoverButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/air_plane_airport_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        hoverButton->setIcon(icon7);
        hoverButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(hoverButton, 10, 4, 1, 1);

        selection_vehicle = new QComboBox(widget_controlPanel);
        selection_vehicle->setObjectName(QString::fromUtf8("selection_vehicle"));
        sizePolicy1.setHeightForWidth(selection_vehicle->sizePolicy().hasHeightForWidth());
        selection_vehicle->setSizePolicy(sizePolicy1);
        selection_vehicle->setMinimumSize(QSize(0, 25));
        selection_vehicle->setMaximumSize(QSize(185, 370));
        selection_vehicle->setFocusPolicy(Qt::NoFocus);
        selection_vehicle->setLayoutDirection(Qt::LeftToRight);
        selection_vehicle->setInsertPolicy(QComboBox::InsertAtTop);
        selection_vehicle->setFrame(true);

        gridLayout_5->addWidget(selection_vehicle, 7, 2, 1, 4);

        value_FligthTime = new QLabel(widget_controlPanel);
        value_FligthTime->setObjectName(QString::fromUtf8("value_FligthTime"));
        sizePolicy4.setHeightForWidth(value_FligthTime->sizePolicy().hasHeightForWidth());
        value_FligthTime->setSizePolicy(sizePolicy4);
        value_FligthTime->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_FligthTime, 2, 3, 1, 3);

        line_2 = new QFrame(widget_controlPanel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 9, 0, 1, 6);

        value_Errors = new QLabel(widget_controlPanel);
        value_Errors->setObjectName(QString::fromUtf8("value_Errors"));
        sizePolicy4.setHeightForWidth(value_Errors->sizePolicy().hasHeightForWidth());
        value_Errors->setSizePolicy(sizePolicy4);
        value_Errors->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_Errors, 4, 3, 1, 3);

        selection_mode = new QComboBox(widget_controlPanel);
        selection_mode->setObjectName(QString::fromUtf8("selection_mode"));
        sizePolicy1.setHeightForWidth(selection_mode->sizePolicy().hasHeightForWidth());
        selection_mode->setSizePolicy(sizePolicy1);
        selection_mode->setMinimumSize(QSize(1, 25));
        selection_mode->setMaximumSize(QSize(185, 300));
        selection_mode->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(selection_mode, 8, 2, 1, 4);

        label_battery_2 = new QLabel(widget_controlPanel);
        label_battery_2->setObjectName(QString::fromUtf8("label_battery_2"));
        sizePolicy3.setHeightForWidth(label_battery_2->sizePolicy().hasHeightForWidth());
        label_battery_2->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_battery_2, 1, 0, 1, 2);

        label_controlMode = new QLabel(widget_controlPanel);
        label_controlMode->setObjectName(QString::fromUtf8("label_controlMode"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_controlMode->sizePolicy().hasHeightForWidth());
        label_controlMode->setSizePolicy(sizePolicy7);
        label_controlMode->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_controlMode, 8, 0, 1, 2);

        label_selVehicle = new QLabel(widget_controlPanel);
        label_selVehicle->setObjectName(QString::fromUtf8("label_selVehicle"));
        sizePolicy7.setHeightForWidth(label_selVehicle->sizePolicy().hasHeightForWidth());
        label_selVehicle->setSizePolicy(sizePolicy7);
        label_selVehicle->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_selVehicle, 7, 0, 1, 2);

        label_currentGoal = new QLabel(widget_controlPanel);
        label_currentGoal->setObjectName(QString::fromUtf8("label_currentGoal"));
        sizePolicy7.setHeightForWidth(label_currentGoal->sizePolicy().hasHeightForWidth());
        label_currentGoal->setSizePolicy(sizePolicy7);
        label_currentGoal->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_currentGoal, 3, 0, 1, 2);

        landButton = new QToolButton(widget_controlPanel);
        landButton->setObjectName(QString::fromUtf8("landButton"));
        sizePolicy5.setHeightForWidth(landButton->sizePolicy().hasHeightForWidth());
        landButton->setSizePolicy(sizePolicy5);
        landButton->setMinimumSize(QSize(60, 0));
        landButton->setMaximumSize(QSize(60, 16777215));
        landButton->setFont(font);
        landButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/airplane-landing.png"), QSize(), QIcon::Normal, QIcon::Off);
        landButton->setIcon(icon8);
        landButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(landButton, 10, 1, 1, 1);

        line = new QFrame(widget_controlPanel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 6, 0, 1, 6);

        label_wifi = new QLabel(widget_controlPanel);
        label_wifi->setObjectName(QString::fromUtf8("label_wifi"));
        sizePolicy7.setHeightForWidth(label_wifi->sizePolicy().hasHeightForWidth());
        label_wifi->setSizePolicy(sizePolicy7);
        label_wifi->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_wifi, 0, 0, 1, 2);

        label_errors = new QLabel(widget_controlPanel);
        label_errors->setObjectName(QString::fromUtf8("label_errors"));
        sizePolicy7.setHeightForWidth(label_errors->sizePolicy().hasHeightForWidth());
        label_errors->setSizePolicy(sizePolicy7);
        label_errors->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_errors, 4, 0, 1, 2);

        takeoffButton = new QToolButton(widget_controlPanel);
        takeoffButton->setObjectName(QString::fromUtf8("takeoffButton"));
        sizePolicy5.setHeightForWidth(takeoffButton->sizePolicy().hasHeightForWidth());
        takeoffButton->setSizePolicy(sizePolicy5);
        takeoffButton->setMinimumSize(QSize(60, 0));
        takeoffButton->setMaximumSize(QSize(60, 16777215));
        takeoffButton->setFont(font);
        takeoffButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/airplane-takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        takeoffButton->setIcon(icon9);
        takeoffButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(takeoffButton, 10, 0, 1, 1);

        tab_controlPanel->addTab(widget_controlPanel, QString());
        label_wifi->raise();
        value_wifi->raise();
        label_battery_2->raise();
        value_battery->raise();
        label_flyingTime->raise();
        value_FligthTime->raise();
        label_currentGoal->raise();
        value_currentGoal->raise();
        label_errors->raise();
        value_Errors->raise();
        label_warnings->raise();
        value_Warnings->raise();
        line->raise();
        label_selVehicle->raise();
        selection_vehicle->raise();
        label_controlMode->raise();
        selection_mode->raise();
        line_2->raise();
        takeoffButton->raise();
        landButton->raise();
        yawzeroButton->raise();
        hoverButton->raise();
        resetButton->raise();
        emergencyStop_Button->raise();

        gridLayout_7->addWidget(tab_controlPanel, 0, 0, 1, 1);

        tab_dynamicView = new QTabWidget(widget);
        tab_dynamicView->setObjectName(QString::fromUtf8("tab_dynamicView"));
        tab_dynamicView->setEnabled(true);
        sizePolicy2.setHeightForWidth(tab_dynamicView->sizePolicy().hasHeightForWidth());
        tab_dynamicView->setSizePolicy(sizePolicy2);
        tab_dynamicView->setMaximumSize(QSize(350, 600));
        tab_dynamicView->setFocusPolicy(Qt::NoFocus);
        tab_dynamicView->setUsesScrollButtons(false);
        tab_dynamicView->setDocumentMode(false);
        tab_dynamicView->setTabsClosable(false);
        tab_dynamicView->setMovable(false);
        widget_vehicle = new QWidget();
        widget_vehicle->setObjectName(QString::fromUtf8("widget_vehicle"));
        gridLayout_3 = new QGridLayout(widget_vehicle);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        grid_vehicle = new QGridLayout();
        grid_vehicle->setSpacing(6);
        grid_vehicle->setObjectName(QString::fromUtf8("grid_vehicle"));
        panel_vehicle = new QFrame(widget_vehicle);
        panel_vehicle->setObjectName(QString::fromUtf8("panel_vehicle"));
        sizePolicy4.setHeightForWidth(panel_vehicle->sizePolicy().hasHeightForWidth());
        panel_vehicle->setSizePolicy(sizePolicy4);
        panel_vehicle->setMaximumSize(QSize(350, 16777215));
        panel_vehicle->setFrameShape(QFrame::NoFrame);
        panel_vehicle->setFrameShadow(QFrame::Raised);
        grid_panelVehicle = new QGridLayout(panel_vehicle);
        grid_panelVehicle->setSpacing(6);
        grid_panelVehicle->setContentsMargins(11, 11, 11, 11);
        grid_panelVehicle->setObjectName(QString::fromUtf8("grid_panelVehicle"));
        valueVehicle_Yaw = new QLabel(panel_vehicle);
        valueVehicle_Yaw->setObjectName(QString::fromUtf8("valueVehicle_Yaw"));
        sizePolicy4.setHeightForWidth(valueVehicle_Yaw->sizePolicy().hasHeightForWidth());
        valueVehicle_Yaw->setSizePolicy(sizePolicy4);
        valueVehicle_Yaw->setMinimumSize(QSize(50, 0));
        valueVehicle_Yaw->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_Yaw, 0, 5, 1, 1);

        labelVehicle_X = new QLabel(panel_vehicle);
        labelVehicle_X->setObjectName(QString::fromUtf8("labelVehicle_X"));

        grid_panelVehicle->addWidget(labelVehicle_X, 0, 1, 1, 1);

        valueVehicle_roll = new QLabel(panel_vehicle);
        valueVehicle_roll->setObjectName(QString::fromUtf8("valueVehicle_roll"));
        sizePolicy4.setHeightForWidth(valueVehicle_roll->sizePolicy().hasHeightForWidth());
        valueVehicle_roll->setSizePolicy(sizePolicy4);
        valueVehicle_roll->setMinimumSize(QSize(50, 0));
        valueVehicle_roll->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_roll, 2, 5, 1, 2);

        labelVehicle_Z = new QLabel(panel_vehicle);
        labelVehicle_Z->setObjectName(QString::fromUtf8("labelVehicle_Z"));

        grid_panelVehicle->addWidget(labelVehicle_Z, 2, 1, 1, 1);

        labelVehicle_yaw = new QLabel(panel_vehicle);
        labelVehicle_yaw->setObjectName(QString::fromUtf8("labelVehicle_yaw"));

        grid_panelVehicle->addWidget(labelVehicle_yaw, 0, 4, 1, 1);

        horizontalSpacer_right = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontalSpacer_right, 0, 6, 1, 1);

        labelVehicle_roll = new QLabel(panel_vehicle);
        labelVehicle_roll->setObjectName(QString::fromUtf8("labelVehicle_roll"));

        grid_panelVehicle->addWidget(labelVehicle_roll, 2, 4, 1, 1);

        valueVehicle_Y = new QLabel(panel_vehicle);
        valueVehicle_Y->setObjectName(QString::fromUtf8("valueVehicle_Y"));
        sizePolicy4.setHeightForWidth(valueVehicle_Y->sizePolicy().hasHeightForWidth());
        valueVehicle_Y->setSizePolicy(sizePolicy4);
        valueVehicle_Y->setMinimumSize(QSize(50, 0));
        valueVehicle_Y->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_Y, 1, 2, 1, 1);

        horizontalSpacer_left = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontalSpacer_left, 0, 0, 1, 1);

        valueVehicle_pitch = new QLabel(panel_vehicle);
        valueVehicle_pitch->setObjectName(QString::fromUtf8("valueVehicle_pitch"));
        sizePolicy4.setHeightForWidth(valueVehicle_pitch->sizePolicy().hasHeightForWidth());
        valueVehicle_pitch->setSizePolicy(sizePolicy4);
        valueVehicle_pitch->setMinimumSize(QSize(50, 0));
        valueVehicle_pitch->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_pitch, 1, 5, 1, 2);

        valueVehicle_X = new QLabel(panel_vehicle);
        valueVehicle_X->setObjectName(QString::fromUtf8("valueVehicle_X"));
        sizePolicy4.setHeightForWidth(valueVehicle_X->sizePolicy().hasHeightForWidth());
        valueVehicle_X->setSizePolicy(sizePolicy4);
        valueVehicle_X->setMinimumSize(QSize(50, 0));
        valueVehicle_X->setMaximumSize(QSize(33, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_X, 0, 2, 1, 1);

        horizontalSpacer_middle = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontalSpacer_middle, 0, 3, 1, 1);

        labelVehicle_Y = new QLabel(panel_vehicle);
        labelVehicle_Y->setObjectName(QString::fromUtf8("labelVehicle_Y"));

        grid_panelVehicle->addWidget(labelVehicle_Y, 1, 1, 1, 1);

        labelVehicle_pitch = new QLabel(panel_vehicle);
        labelVehicle_pitch->setObjectName(QString::fromUtf8("labelVehicle_pitch"));

        grid_panelVehicle->addWidget(labelVehicle_pitch, 1, 4, 1, 1);

        valueVehicle_Z = new QLabel(panel_vehicle);
        valueVehicle_Z->setObjectName(QString::fromUtf8("valueVehicle_Z"));
        sizePolicy4.setHeightForWidth(valueVehicle_Z->sizePolicy().hasHeightForWidth());
        valueVehicle_Z->setSizePolicy(sizePolicy4);
        valueVehicle_Z->setMinimumSize(QSize(50, 0));
        valueVehicle_Z->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(valueVehicle_Z, 2, 2, 1, 1);


        grid_vehicle->addWidget(panel_vehicle, 1, 0, 1, 1);

        vehicleScene = new QLabel(widget_vehicle);
        vehicleScene->setObjectName(QString::fromUtf8("vehicleScene"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(vehicleScene->sizePolicy().hasHeightForWidth());
        vehicleScene->setSizePolicy(sizePolicy8);

        grid_vehicle->addWidget(vehicleScene, 0, 0, 1, 1);


        gridLayout_3->addLayout(grid_vehicle, 0, 0, 1, 1);

        tab_dynamicView->addTab(widget_vehicle, QString());
        tab_dynamicView->setTabText(tab_dynamicView->indexOf(widget_vehicle), QString::fromUtf8("Vehicle Dynamics"));
        widget_sphere = new QWidget();
        widget_sphere->setObjectName(QString::fromUtf8("widget_sphere"));
        gridLayout_4 = new QGridLayout(widget_sphere);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        grid_sphere = new QGridLayout();
        grid_sphere->setSpacing(6);
        grid_sphere->setObjectName(QString::fromUtf8("grid_sphere"));
        sphereScene = new QLabel(widget_sphere);
        sphereScene->setObjectName(QString::fromUtf8("sphereScene"));
        sizePolicy8.setHeightForWidth(sphereScene->sizePolicy().hasHeightForWidth());
        sphereScene->setSizePolicy(sizePolicy8);

        grid_sphere->addWidget(sphereScene, 0, 0, 1, 1);

        panel_sphere = new QFrame(widget_sphere);
        panel_sphere->setObjectName(QString::fromUtf8("panel_sphere"));
        sizePolicy4.setHeightForWidth(panel_sphere->sizePolicy().hasHeightForWidth());
        panel_sphere->setSizePolicy(sizePolicy4);
        panel_sphere->setMaximumSize(QSize(350, 16777215));
        panel_sphere->setFrameShape(QFrame::NoFrame);
        panel_sphere->setFrameShadow(QFrame::Raised);
        grid_panelSphere = new QGridLayout(panel_sphere);
        grid_panelSphere->setSpacing(6);
        grid_panelSphere->setContentsMargins(11, 11, 11, 11);
        grid_panelSphere->setObjectName(QString::fromUtf8("grid_panelSphere"));
        valueSphere_yaw = new QLabel(panel_sphere);
        valueSphere_yaw->setObjectName(QString::fromUtf8("valueSphere_yaw"));
        sizePolicy4.setHeightForWidth(valueSphere_yaw->sizePolicy().hasHeightForWidth());
        valueSphere_yaw->setSizePolicy(sizePolicy4);
        valueSphere_yaw->setMinimumSize(QSize(50, 0));
        valueSphere_yaw->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_yaw, 0, 5, 1, 1);

        labelSphere_X = new QLabel(panel_sphere);
        labelSphere_X->setObjectName(QString::fromUtf8("labelSphere_X"));

        grid_panelSphere->addWidget(labelSphere_X, 0, 1, 1, 1);

        valueSphere_roll = new QLabel(panel_sphere);
        valueSphere_roll->setObjectName(QString::fromUtf8("valueSphere_roll"));
        sizePolicy4.setHeightForWidth(valueSphere_roll->sizePolicy().hasHeightForWidth());
        valueSphere_roll->setSizePolicy(sizePolicy4);
        valueSphere_roll->setMinimumSize(QSize(50, 0));
        valueSphere_roll->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_roll, 2, 5, 1, 2);

        labelSphere_Z = new QLabel(panel_sphere);
        labelSphere_Z->setObjectName(QString::fromUtf8("labelSphere_Z"));

        grid_panelSphere->addWidget(labelSphere_Z, 2, 1, 1, 1);

        labelSphere_yaw = new QLabel(panel_sphere);
        labelSphere_yaw->setObjectName(QString::fromUtf8("labelSphere_yaw"));

        grid_panelSphere->addWidget(labelSphere_yaw, 0, 4, 1, 1);

        horizontalSpacer_right_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontalSpacer_right_2, 0, 6, 1, 1);

        labelSphere_roll = new QLabel(panel_sphere);
        labelSphere_roll->setObjectName(QString::fromUtf8("labelSphere_roll"));

        grid_panelSphere->addWidget(labelSphere_roll, 2, 4, 1, 1);

        valueSphere_Y = new QLabel(panel_sphere);
        valueSphere_Y->setObjectName(QString::fromUtf8("valueSphere_Y"));
        sizePolicy4.setHeightForWidth(valueSphere_Y->sizePolicy().hasHeightForWidth());
        valueSphere_Y->setSizePolicy(sizePolicy4);
        valueSphere_Y->setMinimumSize(QSize(50, 0));
        valueSphere_Y->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_Y, 1, 2, 1, 1);

        horizontalSpacer_left_2 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontalSpacer_left_2, 0, 0, 1, 1);

        labelSphere_Y = new QLabel(panel_sphere);
        labelSphere_Y->setObjectName(QString::fromUtf8("labelSphere_Y"));

        grid_panelSphere->addWidget(labelSphere_Y, 1, 1, 1, 1);

        valueSphere_pitch = new QLabel(panel_sphere);
        valueSphere_pitch->setObjectName(QString::fromUtf8("valueSphere_pitch"));
        sizePolicy4.setHeightForWidth(valueSphere_pitch->sizePolicy().hasHeightForWidth());
        valueSphere_pitch->setSizePolicy(sizePolicy4);
        valueSphere_pitch->setMinimumSize(QSize(50, 0));
        valueSphere_pitch->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_pitch, 1, 5, 1, 2);

        labelSphere_pitch = new QLabel(panel_sphere);
        labelSphere_pitch->setObjectName(QString::fromUtf8("labelSphere_pitch"));

        grid_panelSphere->addWidget(labelSphere_pitch, 1, 4, 1, 1);

        valueSphere_X = new QLabel(panel_sphere);
        valueSphere_X->setObjectName(QString::fromUtf8("valueSphere_X"));
        sizePolicy4.setHeightForWidth(valueSphere_X->sizePolicy().hasHeightForWidth());
        valueSphere_X->setSizePolicy(sizePolicy4);
        valueSphere_X->setMinimumSize(QSize(50, 0));
        valueSphere_X->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_X, 0, 2, 1, 1);

        horizontalSpacer_middle_2 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontalSpacer_middle_2, 0, 3, 1, 1);

        valueSphere_Z = new QLabel(panel_sphere);
        valueSphere_Z->setObjectName(QString::fromUtf8("valueSphere_Z"));
        sizePolicy4.setHeightForWidth(valueSphere_Z->sizePolicy().hasHeightForWidth());
        valueSphere_Z->setSizePolicy(sizePolicy4);
        valueSphere_Z->setMinimumSize(QSize(50, 0));
        valueSphere_Z->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(valueSphere_Z, 2, 2, 1, 1);


        grid_sphere->addWidget(panel_sphere, 1, 0, 1, 1);


        gridLayout_4->addLayout(grid_sphere, 0, 0, 1, 1);

        tab_dynamicView->addTab(widget_sphere, QString());

        gridLayout_7->addWidget(tab_dynamicView, 1, 0, 1, 1);


        gridLayout_9->addWidget(widget, 0, 0, 1, 1);

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
        menuSettings->addAction(actionCommunication_Console);
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionAbout_Ground_Control_System);
        menuHelp->addAction(actionUser_Commands_Manual);

        retranslateUi(MainWindow);

        tabManager->setCurrentIndex(2);
        tab_controlPanel->setCurrentIndex(0);
        tab_dynamicView->setCurrentIndex(0);


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
        actionCommunication_Console->setText(QApplication::translate("MainWindow", "Communication Console", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tabManager->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabManager->setTabText(tabManager->indexOf(tabParameters), QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        mainCameraButton->setText(QString());
        fourCameraButton->setText(QString());
        labelDisplayOptions->setText(QApplication::translate("MainWindow", "Display Options:", 0, QApplication::UnicodeUTF8));
        oneCameraButton->setText(QString());
        saveImageButton->setText(QString());
        tabManager->setTabText(tabManager->indexOf(tabCameraView), QApplication::translate("MainWindow", "Camera Views", 0, QApplication::UnicodeUTF8));
        tabManager->setTabText(tabManager->indexOf(tabPerformance), QApplication::translate("MainWindow", "Performance Monitor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_controlPanel->setToolTip(QApplication::translate("MainWindow", "Panel Control", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tab_controlPanel->setStatusTip(QApplication::translate("MainWindow", "Shows the current state of the UAV and the basic control actions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_flyingTime->setText(QApplication::translate("MainWindow", "Flying Time :", 0, QApplication::UnicodeUTF8));
        value_Warnings->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        emergencyStop_Button->setText(QApplication::translate("MainWindow", "Emergency Stop", 0, QApplication::UnicodeUTF8));
        label_warnings->setText(QApplication::translate("MainWindow", "Detected Warnings :", 0, QApplication::UnicodeUTF8));
        value_currentGoal->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        value_wifi->setText(QApplication::translate("MainWindow", "Disconnected", 0, QApplication::UnicodeUTF8));
        yawzeroButton->setText(QApplication::translate("MainWindow", "Yaw Zero", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        value_battery->setText(QApplication::translate("MainWindow", "0%", 0, QApplication::UnicodeUTF8));
        hoverButton->setText(QApplication::translate("MainWindow", "Hover", 0, QApplication::UnicodeUTF8));
        selection_vehicle->clear();
        selection_vehicle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "UAV_1", 0, QApplication::UnicodeUTF8)
        );
        value_FligthTime->setText(QApplication::translate("MainWindow", "0:00", 0, QApplication::UnicodeUTF8));
        value_Errors->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        selection_mode->clear();
        selection_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Autonomous", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Automatic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8)
        );
        label_battery_2->setText(QApplication::translate("MainWindow", "Battery Charge :", 0, QApplication::UnicodeUTF8));
        label_controlMode->setText(QApplication::translate("MainWindow", "Control Mode :", 0, QApplication::UnicodeUTF8));
        label_selVehicle->setText(QApplication::translate("MainWindow", "Selected Vehicle :", 0, QApplication::UnicodeUTF8));
        label_currentGoal->setText(QApplication::translate("MainWindow", "Current Goal :", 0, QApplication::UnicodeUTF8));
        landButton->setText(QApplication::translate("MainWindow", "Land", 0, QApplication::UnicodeUTF8));
        label_wifi->setText(QApplication::translate("MainWindow", "Wifi Connection :", 0, QApplication::UnicodeUTF8));
        label_errors->setText(QApplication::translate("MainWindow", "Detected Errors :", 0, QApplication::UnicodeUTF8));
        takeoffButton->setText(QApplication::translate("MainWindow", "Take Off", 0, QApplication::UnicodeUTF8));
        tab_controlPanel->setTabText(tab_controlPanel->indexOf(widget_controlPanel), QApplication::translate("MainWindow", "Control Panel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tab_dynamicView->setStatusTip(QApplication::translate("MainWindow", "Shows the rotation angles and the current position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        valueVehicle_Yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelVehicle_X->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        valueVehicle_roll->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelVehicle_Z->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        labelVehicle_yaw->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        labelVehicle_roll->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        valueVehicle_Y->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        valueVehicle_pitch->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        valueVehicle_X->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelVehicle_Y->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        labelVehicle_pitch->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        valueVehicle_Z->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        vehicleScene->setText(QString());
        sphereScene->setText(QString());
        valueSphere_yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelSphere_X->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        valueSphere_roll->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelSphere_Z->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        labelSphere_yaw->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        labelSphere_roll->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        valueSphere_Y->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelSphere_Y->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        valueSphere_pitch->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelSphere_pitch->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        valueSphere_X->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        valueSphere_Z->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        tab_dynamicView->setTabText(tab_dynamicView->indexOf(widget_sphere), QApplication::translate("MainWindow", "Sphere Dynamics", 0, QApplication::UnicodeUTF8));
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
