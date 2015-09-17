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
#include <QtGui/QSplitter>
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
    QAction *action_cameras;
    QAction *actionParameter_Temporal_Series;
    QAction *actionProcess_Monitor;
    QAction *actionSystem_Status;
    QAction *action3D_Perception_View;
    QAction *actionContents;
    QAction *actionAbout_Human_Machine_Interface;
    QAction *actionUser_Commands_Manual;
    QAction *actionCommunication_Console;
    QWidget *central_widget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QTabWidget *tab_dynamic_view;
    QWidget *widget_vehicle;
    QGridLayout *gridLayout_3;
    QGridLayout *grid_vehicle;
    QFrame *panel_vehicle;
    QGridLayout *grid_panelVehicle;
    QLabel *value_vehicle_yaw;
    QLabel *label_vehicle_x;
    QLabel *value_vehicle_roll;
    QLabel *label_vehicle_z;
    QLabel *label_vehicle_yaw;
    QSpacerItem *horizontal_spacer_right;
    QLabel *label_vehicle_roll;
    QLabel *value_vehicle_y;
    QSpacerItem *horizontal_spacer_left;
    QLabel *value_vehicle_pitch;
    QLabel *value_vehicle_x;
    QSpacerItem *horizontal_spacer_middle;
    QLabel *label_vehicle_y;
    QLabel *label_vehicle_pitch;
    QLabel *value_vehicle_z;
    QLabel *vehicle_scene;
    QWidget *widget_sphere;
    QGridLayout *gridLayout_4;
    QGridLayout *grid_sphere;
    QLabel *sphere_scene;
    QFrame *panel_sphere;
    QGridLayout *grid_panelSphere;
    QLabel *value_sphere_yaw;
    QLabel *label_sphere_x;
    QLabel *value_sphere_roll;
    QLabel *label_sphere_z;
    QLabel *label_sphere_yaw;
    QSpacerItem *horizontal_spacer_right_2;
    QLabel *label_sphere_roll;
    QLabel *value_sphere_y;
    QSpacerItem *horizontal_spacer_left_2;
    QLabel *label_sphere_y;
    QLabel *value_sphere_pitch;
    QLabel *label_sphere_pitch;
    QLabel *value_sphere_x;
    QSpacerItem *horizontal_spacer_middle_2;
    QLabel *value_sphere_z;
    QTabWidget *tab_control_panel;
    QWidget *widget_control_panel;
    QGridLayout *gridLayout_5;
    QLabel *value_wifi;
    QToolButton *take_off_button;
    QLabel *label_flying_time;
    QFrame *line;
    QLabel *label_sel_vehicle;
    QComboBox *selection_vehicle;
    QLabel *value_errors;
    QToolButton *land_button;
    QComboBox *selection_mode;
    QFrame *line_2;
    QLabel *label_battery_2;
    QPushButton *emergency_stop_button;
    QLabel *value_battery;
    QToolButton *yaw_zero_button;
    QLabel *label_current_goal;
    QLabel *value_currentGoal;
    QLabel *label_errors;
    QLabel *label_wifi;
    QLabel *label_control_mode;
    QLabel *value_fligth_time;
    QToolButton *hover_button;
    QTabWidget *tab_manager;
    QWidget *tab_parameters;
    QGridLayout *gridLayout_8;
    QGridLayout *grid_parameters;
    QWidget *tab_camera_view;
    QGridLayout *gridLayout;
    QPushButton *save_image_button;
    QWidget *widget_cam_options;
    QGridLayout *gridLayout_10;
    QPushButton *main_camera_button;
    QPushButton *four_camera_button;
    QLabel *label_display_options;
    QPushButton *one_camera_button;
    QSpacerItem *horizontal_spacer;
    QGridLayout *grid_camera;
    QWidget *tab_performance;
    QGridLayout *gridLayout_11;
    QGridLayout *grid_performance;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QMenu *menu_view;
    QMenu *menu_settings;
    QMenu *menu_help;
    QStatusBar *status_bar;

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
        actionNew_connection->setCheckable(false);
        actionNew_connection->setChecked(false);
        actionNew_connection->setEnabled(true);
        action_cameras = new QAction(MainWindow);
        action_cameras->setObjectName(QString::fromUtf8("action_cameras"));
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
        actionAbout_Human_Machine_Interface = new QAction(MainWindow);
        actionAbout_Human_Machine_Interface->setObjectName(QString::fromUtf8("actionAbout_Human_Machine_Interface"));
        actionUser_Commands_Manual = new QAction(MainWindow);
        actionUser_Commands_Manual->setObjectName(QString::fromUtf8("actionUser_Commands_Manual"));
        actionCommunication_Console = new QAction(MainWindow);
        actionCommunication_Console->setObjectName(QString::fromUtf8("actionCommunication_Console"));
        central_widget = new QWidget(MainWindow);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        gridLayout_2 = new QGridLayout(central_widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(central_widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
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
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setVerticalSpacing(4);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        tab_dynamic_view = new QTabWidget(widget);
        tab_dynamic_view->setObjectName(QString::fromUtf8("tab_dynamic_view"));
        tab_dynamic_view->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tab_dynamic_view->sizePolicy().hasHeightForWidth());
        tab_dynamic_view->setSizePolicy(sizePolicy2);
        tab_dynamic_view->setMaximumSize(QSize(350, 16777215));
        tab_dynamic_view->setFocusPolicy(Qt::NoFocus);
        tab_dynamic_view->setUsesScrollButtons(false);
        tab_dynamic_view->setDocumentMode(false);
        tab_dynamic_view->setTabsClosable(false);
        tab_dynamic_view->setMovable(false);
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
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(panel_vehicle->sizePolicy().hasHeightForWidth());
        panel_vehicle->setSizePolicy(sizePolicy3);
        panel_vehicle->setMaximumSize(QSize(350, 16777215));
        panel_vehicle->setFrameShape(QFrame::NoFrame);
        panel_vehicle->setFrameShadow(QFrame::Raised);
        grid_panelVehicle = new QGridLayout(panel_vehicle);
        grid_panelVehicle->setSpacing(6);
        grid_panelVehicle->setContentsMargins(11, 11, 11, 11);
        grid_panelVehicle->setObjectName(QString::fromUtf8("grid_panelVehicle"));
        value_vehicle_yaw = new QLabel(panel_vehicle);
        value_vehicle_yaw->setObjectName(QString::fromUtf8("value_vehicle_yaw"));
        sizePolicy3.setHeightForWidth(value_vehicle_yaw->sizePolicy().hasHeightForWidth());
        value_vehicle_yaw->setSizePolicy(sizePolicy3);
        value_vehicle_yaw->setMinimumSize(QSize(50, 0));
        value_vehicle_yaw->setMaximumSize(QSize(80, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_yaw, 0, 5, 1, 1);

        label_vehicle_x = new QLabel(panel_vehicle);
        label_vehicle_x->setObjectName(QString::fromUtf8("label_vehicle_x"));

        grid_panelVehicle->addWidget(label_vehicle_x, 0, 1, 1, 1);

        value_vehicle_roll = new QLabel(panel_vehicle);
        value_vehicle_roll->setObjectName(QString::fromUtf8("value_vehicle_roll"));
        sizePolicy3.setHeightForWidth(value_vehicle_roll->sizePolicy().hasHeightForWidth());
        value_vehicle_roll->setSizePolicy(sizePolicy3);
        value_vehicle_roll->setMinimumSize(QSize(50, 0));
        value_vehicle_roll->setMaximumSize(QSize(80, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_roll, 2, 5, 1, 2);

        label_vehicle_z = new QLabel(panel_vehicle);
        label_vehicle_z->setObjectName(QString::fromUtf8("label_vehicle_z"));

        grid_panelVehicle->addWidget(label_vehicle_z, 2, 1, 1, 1);

        label_vehicle_yaw = new QLabel(panel_vehicle);
        label_vehicle_yaw->setObjectName(QString::fromUtf8("label_vehicle_yaw"));

        grid_panelVehicle->addWidget(label_vehicle_yaw, 0, 4, 1, 1);

        horizontal_spacer_right = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontal_spacer_right, 0, 6, 1, 1);

        label_vehicle_roll = new QLabel(panel_vehicle);
        label_vehicle_roll->setObjectName(QString::fromUtf8("label_vehicle_roll"));

        grid_panelVehicle->addWidget(label_vehicle_roll, 2, 4, 1, 1);

        value_vehicle_y = new QLabel(panel_vehicle);
        value_vehicle_y->setObjectName(QString::fromUtf8("value_vehicle_y"));
        sizePolicy3.setHeightForWidth(value_vehicle_y->sizePolicy().hasHeightForWidth());
        value_vehicle_y->setSizePolicy(sizePolicy3);
        value_vehicle_y->setMinimumSize(QSize(50, 0));
        value_vehicle_y->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_y, 1, 2, 1, 1);

        horizontal_spacer_left = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontal_spacer_left, 0, 0, 1, 1);

        value_vehicle_pitch = new QLabel(panel_vehicle);
        value_vehicle_pitch->setObjectName(QString::fromUtf8("value_vehicle_pitch"));
        sizePolicy3.setHeightForWidth(value_vehicle_pitch->sizePolicy().hasHeightForWidth());
        value_vehicle_pitch->setSizePolicy(sizePolicy3);
        value_vehicle_pitch->setMinimumSize(QSize(50, 0));
        value_vehicle_pitch->setMaximumSize(QSize(80, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_pitch, 1, 5, 1, 2);

        value_vehicle_x = new QLabel(panel_vehicle);
        value_vehicle_x->setObjectName(QString::fromUtf8("value_vehicle_x"));
        sizePolicy3.setHeightForWidth(value_vehicle_x->sizePolicy().hasHeightForWidth());
        value_vehicle_x->setSizePolicy(sizePolicy3);
        value_vehicle_x->setMinimumSize(QSize(50, 0));
        value_vehicle_x->setMaximumSize(QSize(33, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_x, 0, 2, 1, 1);

        horizontal_spacer_middle = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelVehicle->addItem(horizontal_spacer_middle, 0, 3, 1, 1);

        label_vehicle_y = new QLabel(panel_vehicle);
        label_vehicle_y->setObjectName(QString::fromUtf8("label_vehicle_y"));

        grid_panelVehicle->addWidget(label_vehicle_y, 1, 1, 1, 1);

        label_vehicle_pitch = new QLabel(panel_vehicle);
        label_vehicle_pitch->setObjectName(QString::fromUtf8("label_vehicle_pitch"));

        grid_panelVehicle->addWidget(label_vehicle_pitch, 1, 4, 1, 1);

        value_vehicle_z = new QLabel(panel_vehicle);
        value_vehicle_z->setObjectName(QString::fromUtf8("value_vehicle_z"));
        sizePolicy3.setHeightForWidth(value_vehicle_z->sizePolicy().hasHeightForWidth());
        value_vehicle_z->setSizePolicy(sizePolicy3);
        value_vehicle_z->setMinimumSize(QSize(50, 0));
        value_vehicle_z->setMaximumSize(QSize(30, 16777215));

        grid_panelVehicle->addWidget(value_vehicle_z, 2, 2, 1, 1);


        grid_vehicle->addWidget(panel_vehicle, 1, 0, 1, 1);

        vehicle_scene = new QLabel(widget_vehicle);
        vehicle_scene->setObjectName(QString::fromUtf8("vehicle_scene"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(vehicle_scene->sizePolicy().hasHeightForWidth());
        vehicle_scene->setSizePolicy(sizePolicy4);

        grid_vehicle->addWidget(vehicle_scene, 0, 0, 1, 1);


        gridLayout_3->addLayout(grid_vehicle, 0, 0, 1, 1);

        tab_dynamic_view->addTab(widget_vehicle, QString());
        tab_dynamic_view->setTabText(tab_dynamic_view->indexOf(widget_vehicle), QString::fromUtf8("Vehicle Dynamics"));
        widget_sphere = new QWidget();
        widget_sphere->setObjectName(QString::fromUtf8("widget_sphere"));
        gridLayout_4 = new QGridLayout(widget_sphere);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        grid_sphere = new QGridLayout();
        grid_sphere->setSpacing(6);
        grid_sphere->setObjectName(QString::fromUtf8("grid_sphere"));
        sphere_scene = new QLabel(widget_sphere);
        sphere_scene->setObjectName(QString::fromUtf8("sphere_scene"));
        sizePolicy4.setHeightForWidth(sphere_scene->sizePolicy().hasHeightForWidth());
        sphere_scene->setSizePolicy(sizePolicy4);

        grid_sphere->addWidget(sphere_scene, 0, 0, 1, 1);

        panel_sphere = new QFrame(widget_sphere);
        panel_sphere->setObjectName(QString::fromUtf8("panel_sphere"));
        sizePolicy3.setHeightForWidth(panel_sphere->sizePolicy().hasHeightForWidth());
        panel_sphere->setSizePolicy(sizePolicy3);
        panel_sphere->setMaximumSize(QSize(350, 16777215));
        panel_sphere->setFrameShape(QFrame::NoFrame);
        panel_sphere->setFrameShadow(QFrame::Raised);
        grid_panelSphere = new QGridLayout(panel_sphere);
        grid_panelSphere->setSpacing(6);
        grid_panelSphere->setContentsMargins(11, 11, 11, 11);
        grid_panelSphere->setObjectName(QString::fromUtf8("grid_panelSphere"));
        value_sphere_yaw = new QLabel(panel_sphere);
        value_sphere_yaw->setObjectName(QString::fromUtf8("value_sphere_yaw"));
        sizePolicy3.setHeightForWidth(value_sphere_yaw->sizePolicy().hasHeightForWidth());
        value_sphere_yaw->setSizePolicy(sizePolicy3);
        value_sphere_yaw->setMinimumSize(QSize(50, 0));
        value_sphere_yaw->setMaximumSize(QSize(80, 16777215));

        grid_panelSphere->addWidget(value_sphere_yaw, 0, 5, 1, 1);

        label_sphere_x = new QLabel(panel_sphere);
        label_sphere_x->setObjectName(QString::fromUtf8("label_sphere_x"));

        grid_panelSphere->addWidget(label_sphere_x, 0, 1, 1, 1);

        value_sphere_roll = new QLabel(panel_sphere);
        value_sphere_roll->setObjectName(QString::fromUtf8("value_sphere_roll"));
        sizePolicy3.setHeightForWidth(value_sphere_roll->sizePolicy().hasHeightForWidth());
        value_sphere_roll->setSizePolicy(sizePolicy3);
        value_sphere_roll->setMinimumSize(QSize(50, 0));
        value_sphere_roll->setMaximumSize(QSize(80, 16777215));

        grid_panelSphere->addWidget(value_sphere_roll, 2, 5, 1, 2);

        label_sphere_z = new QLabel(panel_sphere);
        label_sphere_z->setObjectName(QString::fromUtf8("label_sphere_z"));

        grid_panelSphere->addWidget(label_sphere_z, 2, 1, 1, 1);

        label_sphere_yaw = new QLabel(panel_sphere);
        label_sphere_yaw->setObjectName(QString::fromUtf8("label_sphere_yaw"));

        grid_panelSphere->addWidget(label_sphere_yaw, 0, 4, 1, 1);

        horizontal_spacer_right_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontal_spacer_right_2, 0, 6, 1, 1);

        label_sphere_roll = new QLabel(panel_sphere);
        label_sphere_roll->setObjectName(QString::fromUtf8("label_sphere_roll"));

        grid_panelSphere->addWidget(label_sphere_roll, 2, 4, 1, 1);

        value_sphere_y = new QLabel(panel_sphere);
        value_sphere_y->setObjectName(QString::fromUtf8("value_sphere_y"));
        sizePolicy3.setHeightForWidth(value_sphere_y->sizePolicy().hasHeightForWidth());
        value_sphere_y->setSizePolicy(sizePolicy3);
        value_sphere_y->setMinimumSize(QSize(50, 0));
        value_sphere_y->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(value_sphere_y, 1, 2, 1, 1);

        horizontal_spacer_left_2 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontal_spacer_left_2, 0, 0, 1, 1);

        label_sphere_y = new QLabel(panel_sphere);
        label_sphere_y->setObjectName(QString::fromUtf8("label_sphere_y"));

        grid_panelSphere->addWidget(label_sphere_y, 1, 1, 1, 1);

        value_sphere_pitch = new QLabel(panel_sphere);
        value_sphere_pitch->setObjectName(QString::fromUtf8("value_sphere_pitch"));
        sizePolicy3.setHeightForWidth(value_sphere_pitch->sizePolicy().hasHeightForWidth());
        value_sphere_pitch->setSizePolicy(sizePolicy3);
        value_sphere_pitch->setMinimumSize(QSize(50, 0));
        value_sphere_pitch->setMaximumSize(QSize(80, 16777215));

        grid_panelSphere->addWidget(value_sphere_pitch, 1, 5, 1, 2);

        label_sphere_pitch = new QLabel(panel_sphere);
        label_sphere_pitch->setObjectName(QString::fromUtf8("label_sphere_pitch"));

        grid_panelSphere->addWidget(label_sphere_pitch, 1, 4, 1, 1);

        value_sphere_x = new QLabel(panel_sphere);
        value_sphere_x->setObjectName(QString::fromUtf8("value_sphere_x"));
        sizePolicy3.setHeightForWidth(value_sphere_x->sizePolicy().hasHeightForWidth());
        value_sphere_x->setSizePolicy(sizePolicy3);
        value_sphere_x->setMinimumSize(QSize(50, 0));
        value_sphere_x->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(value_sphere_x, 0, 2, 1, 1);

        horizontal_spacer_middle_2 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        grid_panelSphere->addItem(horizontal_spacer_middle_2, 0, 3, 1, 1);

        value_sphere_z = new QLabel(panel_sphere);
        value_sphere_z->setObjectName(QString::fromUtf8("value_sphere_z"));
        sizePolicy3.setHeightForWidth(value_sphere_z->sizePolicy().hasHeightForWidth());
        value_sphere_z->setSizePolicy(sizePolicy3);
        value_sphere_z->setMinimumSize(QSize(50, 0));
        value_sphere_z->setMaximumSize(QSize(30, 16777215));

        grid_panelSphere->addWidget(value_sphere_z, 2, 2, 1, 1);


        grid_sphere->addWidget(panel_sphere, 1, 0, 1, 1);


        gridLayout_4->addLayout(grid_sphere, 0, 0, 1, 1);

        tab_dynamic_view->addTab(widget_sphere, QString());

        gridLayout_7->addWidget(tab_dynamic_view, 1, 0, 1, 1);

        tab_control_panel = new QTabWidget(widget);
        tab_control_panel->setObjectName(QString::fromUtf8("tab_control_panel"));
        sizePolicy1.setHeightForWidth(tab_control_panel->sizePolicy().hasHeightForWidth());
        tab_control_panel->setSizePolicy(sizePolicy1);
        tab_control_panel->setMinimumSize(QSize(0, 380));
        tab_control_panel->setMaximumSize(QSize(600, 16777215));
        tab_control_panel->setFocusPolicy(Qt::NoFocus);
        tab_control_panel->setLayoutDirection(Qt::LeftToRight);
        tab_control_panel->setUsesScrollButtons(false);
        widget_control_panel = new QWidget();
        widget_control_panel->setObjectName(QString::fromUtf8("widget_control_panel"));
        gridLayout_5 = new QGridLayout(widget_control_panel);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, -1, -1, 0);
        value_wifi = new QLabel(widget_control_panel);
        value_wifi->setObjectName(QString::fromUtf8("value_wifi"));
        sizePolicy3.setHeightForWidth(value_wifi->sizePolicy().hasHeightForWidth());
        value_wifi->setSizePolicy(sizePolicy3);
        value_wifi->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_wifi, 0, 4, 1, 3);

        take_off_button = new QToolButton(widget_control_panel);
        take_off_button->setObjectName(QString::fromUtf8("take_off_button"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(take_off_button->sizePolicy().hasHeightForWidth());
        take_off_button->setSizePolicy(sizePolicy5);
        take_off_button->setMinimumSize(QSize(90, 0));
        take_off_button->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setPointSize(10);
        take_off_button->setFont(font);
        take_off_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/airplane-takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        take_off_button->setIcon(icon);
        take_off_button->setPopupMode(QToolButton::MenuButtonPopup);
        take_off_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(take_off_button, 9, 0, 1, 1);

        label_flying_time = new QLabel(widget_control_panel);
        label_flying_time->setObjectName(QString::fromUtf8("label_flying_time"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_flying_time->sizePolicy().hasHeightForWidth());
        label_flying_time->setSizePolicy(sizePolicy6);

        gridLayout_5->addWidget(label_flying_time, 2, 0, 1, 2);

        line = new QFrame(widget_control_panel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 5, 0, 1, 7);

        label_sel_vehicle = new QLabel(widget_control_panel);
        label_sel_vehicle->setObjectName(QString::fromUtf8("label_sel_vehicle"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_sel_vehicle->sizePolicy().hasHeightForWidth());
        label_sel_vehicle->setSizePolicy(sizePolicy7);
        label_sel_vehicle->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_sel_vehicle, 6, 0, 1, 2);

        selection_vehicle = new QComboBox(widget_control_panel);
        selection_vehicle->setObjectName(QString::fromUtf8("selection_vehicle"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(selection_vehicle->sizePolicy().hasHeightForWidth());
        selection_vehicle->setSizePolicy(sizePolicy8);
        selection_vehicle->setMinimumSize(QSize(0, 25));
        selection_vehicle->setMaximumSize(QSize(185, 370));
        selection_vehicle->setFocusPolicy(Qt::NoFocus);
        selection_vehicle->setLayoutDirection(Qt::LeftToRight);
        selection_vehicle->setInsertPolicy(QComboBox::InsertAtTop);
        selection_vehicle->setFrame(true);

        gridLayout_5->addWidget(selection_vehicle, 6, 4, 1, 3);

        value_errors = new QLabel(widget_control_panel);
        value_errors->setObjectName(QString::fromUtf8("value_errors"));
        sizePolicy3.setHeightForWidth(value_errors->sizePolicy().hasHeightForWidth());
        value_errors->setSizePolicy(sizePolicy3);
        value_errors->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_errors, 4, 4, 1, 3);

        land_button = new QToolButton(widget_control_panel);
        land_button->setObjectName(QString::fromUtf8("land_button"));
        sizePolicy5.setHeightForWidth(land_button->sizePolicy().hasHeightForWidth());
        land_button->setSizePolicy(sizePolicy5);
        land_button->setMinimumSize(QSize(65, 0));
        land_button->setMaximumSize(QSize(60, 16777215));
        land_button->setFont(font);
        land_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/airplane-landing.png"), QSize(), QIcon::Normal, QIcon::Off);
        land_button->setIcon(icon1);
        land_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(land_button, 9, 2, 1, 1);

        selection_mode = new QComboBox(widget_control_panel);
        selection_mode->setObjectName(QString::fromUtf8("selection_mode"));
        sizePolicy8.setHeightForWidth(selection_mode->sizePolicy().hasHeightForWidth());
        selection_mode->setSizePolicy(sizePolicy8);
        selection_mode->setMinimumSize(QSize(0, 25));
        selection_mode->setMaximumSize(QSize(185, 300));
        selection_mode->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(selection_mode, 7, 4, 1, 3);

        line_2 = new QFrame(widget_control_panel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 8, 0, 1, 7);

        label_battery_2 = new QLabel(widget_control_panel);
        label_battery_2->setObjectName(QString::fromUtf8("label_battery_2"));
        sizePolicy6.setHeightForWidth(label_battery_2->sizePolicy().hasHeightForWidth());
        label_battery_2->setSizePolicy(sizePolicy6);

        gridLayout_5->addWidget(label_battery_2, 1, 0, 1, 3);

        emergency_stop_button = new QPushButton(widget_control_panel);
        emergency_stop_button->setObjectName(QString::fromUtf8("emergency_stop_button"));
        sizePolicy5.setHeightForWidth(emergency_stop_button->sizePolicy().hasHeightForWidth());
        emergency_stop_button->setSizePolicy(sizePolicy5);
        emergency_stop_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        emergency_stop_button->setIcon(icon2);
        emergency_stop_button->setAutoRepeat(true);
        emergency_stop_button->setAutoDefault(true);
        emergency_stop_button->setDefault(true);

        gridLayout_5->addWidget(emergency_stop_button, 10, 0, 1, 7);

        value_battery = new QLabel(widget_control_panel);
        value_battery->setObjectName(QString::fromUtf8("value_battery"));
        sizePolicy3.setHeightForWidth(value_battery->sizePolicy().hasHeightForWidth());
        value_battery->setSizePolicy(sizePolicy3);
        value_battery->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_battery, 1, 4, 1, 3);

        yaw_zero_button = new QToolButton(widget_control_panel);
        yaw_zero_button->setObjectName(QString::fromUtf8("yaw_zero_button"));
        sizePolicy5.setHeightForWidth(yaw_zero_button->sizePolicy().hasHeightForWidth());
        yaw_zero_button->setSizePolicy(sizePolicy5);
        yaw_zero_button->setMinimumSize(QSize(65, 0));
        yaw_zero_button->setMaximumSize(QSize(60, 16777215));
        yaw_zero_button->setFont(font);
        yaw_zero_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        yaw_zero_button->setIcon(icon3);
        yaw_zero_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(yaw_zero_button, 9, 4, 1, 1);

        label_current_goal = new QLabel(widget_control_panel);
        label_current_goal->setObjectName(QString::fromUtf8("label_current_goal"));
        sizePolicy7.setHeightForWidth(label_current_goal->sizePolicy().hasHeightForWidth());
        label_current_goal->setSizePolicy(sizePolicy7);
        label_current_goal->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_current_goal, 3, 0, 1, 2);

        value_currentGoal = new QLabel(widget_control_panel);
        value_currentGoal->setObjectName(QString::fromUtf8("value_currentGoal"));
        sizePolicy3.setHeightForWidth(value_currentGoal->sizePolicy().hasHeightForWidth());
        value_currentGoal->setSizePolicy(sizePolicy3);
        value_currentGoal->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(value_currentGoal, 3, 4, 1, 3);

        label_errors = new QLabel(widget_control_panel);
        label_errors->setObjectName(QString::fromUtf8("label_errors"));
        sizePolicy7.setHeightForWidth(label_errors->sizePolicy().hasHeightForWidth());
        label_errors->setSizePolicy(sizePolicy7);
        label_errors->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_errors, 4, 0, 1, 2);

        label_wifi = new QLabel(widget_control_panel);
        label_wifi->setObjectName(QString::fromUtf8("label_wifi"));
        sizePolicy7.setHeightForWidth(label_wifi->sizePolicy().hasHeightForWidth());
        label_wifi->setSizePolicy(sizePolicy7);
        label_wifi->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_wifi, 0, 0, 1, 2);

        label_control_mode = new QLabel(widget_control_panel);
        label_control_mode->setObjectName(QString::fromUtf8("label_control_mode"));
        sizePolicy7.setHeightForWidth(label_control_mode->sizePolicy().hasHeightForWidth());
        label_control_mode->setSizePolicy(sizePolicy7);
        label_control_mode->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(label_control_mode, 7, 0, 1, 2);

        value_fligth_time = new QLabel(widget_control_panel);
        value_fligth_time->setObjectName(QString::fromUtf8("value_fligth_time"));
        sizePolicy3.setHeightForWidth(value_fligth_time->sizePolicy().hasHeightForWidth());
        value_fligth_time->setSizePolicy(sizePolicy3);
        value_fligth_time->setMinimumSize(QSize(100, 0));
        value_fligth_time->setAutoFillBackground(false);

        gridLayout_5->addWidget(value_fligth_time, 2, 4, 1, 3);

        hover_button = new QToolButton(widget_control_panel);
        hover_button->setObjectName(QString::fromUtf8("hover_button"));
        sizePolicy5.setHeightForWidth(hover_button->sizePolicy().hasHeightForWidth());
        hover_button->setSizePolicy(sizePolicy5);
        hover_button->setMinimumSize(QSize(60, 0));
        hover_button->setMaximumSize(QSize(60, 70));
        hover_button->setFont(font);
        hover_button->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/air_plane_airport_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        hover_button->setIcon(icon4);
        hover_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_5->addWidget(hover_button, 9, 6, 1, 1);

        tab_control_panel->addTab(widget_control_panel, QString());
        label_wifi->raise();
        value_wifi->raise();
        label_battery_2->raise();
        value_battery->raise();
        label_flying_time->raise();
        value_fligth_time->raise();
        label_current_goal->raise();
        value_currentGoal->raise();
        label_errors->raise();
        value_errors->raise();
        line->raise();
        label_sel_vehicle->raise();
        selection_vehicle->raise();
        label_control_mode->raise();
        selection_mode->raise();
        line_2->raise();
        emergency_stop_button->raise();
        take_off_button->raise();
        land_button->raise();
        yaw_zero_button->raise();
        hover_button->raise();

        gridLayout_7->addWidget(tab_control_panel, 0, 0, 1, 1);

        splitter->addWidget(widget);
        tab_manager = new QTabWidget(splitter);
        tab_manager->setObjectName(QString::fromUtf8("tab_manager"));
        tab_manager->setEnabled(true);
        sizePolicy.setHeightForWidth(tab_manager->sizePolicy().hasHeightForWidth());
        tab_manager->setSizePolicy(sizePolicy);
        tab_manager->setMinimumSize(QSize(0, 0));
        tab_manager->setMaximumSize(QSize(32909, 1501));
        tab_manager->setSizeIncrement(QSize(0, 0));
        tab_manager->setBaseSize(QSize(0, 0));
        tab_manager->setFocusPolicy(Qt::NoFocus);
        tab_manager->setTabShape(QTabWidget::Rounded);
        tab_manager->setElideMode(Qt::ElideNone);
        tab_manager->setUsesScrollButtons(false);
        tab_manager->setDocumentMode(false);
        tab_parameters = new QWidget();
        tab_parameters->setObjectName(QString::fromUtf8("tab_parameters"));
        gridLayout_8 = new QGridLayout(tab_parameters);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 0, -1, -1);
        grid_parameters = new QGridLayout();
        grid_parameters->setSpacing(6);
        grid_parameters->setObjectName(QString::fromUtf8("grid_parameters"));
        grid_parameters->setHorizontalSpacing(0);

        gridLayout_8->addLayout(grid_parameters, 0, 0, 1, 1);

        tab_manager->addTab(tab_parameters, QString());
        tab_camera_view = new QWidget();
        tab_camera_view->setObjectName(QString::fromUtf8("tab_camera_view"));
        gridLayout = new QGridLayout(tab_camera_view);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        save_image_button = new QPushButton(tab_camera_view);
        save_image_button->setObjectName(QString::fromUtf8("save_image_button"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/ .svg"), QSize(), QIcon::Normal, QIcon::Off);
        save_image_button->setIcon(icon5);

        gridLayout->addWidget(save_image_button, 0, 2, 1, 1);

        widget_cam_options = new QWidget(tab_camera_view);
        widget_cam_options->setObjectName(QString::fromUtf8("widget_cam_options"));
        sizePolicy2.setHeightForWidth(widget_cam_options->sizePolicy().hasHeightForWidth());
        widget_cam_options->setSizePolicy(sizePolicy2);
        widget_cam_options->setMaximumSize(QSize(270, 75));
        gridLayout_10 = new QGridLayout(widget_cam_options);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 0, -1, -1);
        main_camera_button = new QPushButton(widget_cam_options);
        main_camera_button->setObjectName(QString::fromUtf8("main_camera_button"));
        sizePolicy2.setHeightForWidth(main_camera_button->sizePolicy().hasHeightForWidth());
        main_camera_button->setSizePolicy(sizePolicy2);
        main_camera_button->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/multiplecameraview.png"), QSize(), QIcon::Normal, QIcon::Off);
        main_camera_button->setIcon(icon6);
        main_camera_button->setIconSize(QSize(70, 35));

        gridLayout_10->addWidget(main_camera_button, 1, 1, 1, 1);

        four_camera_button = new QPushButton(widget_cam_options);
        four_camera_button->setObjectName(QString::fromUtf8("four_camera_button"));
        sizePolicy2.setHeightForWidth(four_camera_button->sizePolicy().hasHeightForWidth());
        four_camera_button->setSizePolicy(sizePolicy2);
        four_camera_button->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/ic_view_stream_24px.png"), QSize(), QIcon::Normal, QIcon::Off);
        four_camera_button->setIcon(icon7);
        four_camera_button->setIconSize(QSize(40, 40));

        gridLayout_10->addWidget(four_camera_button, 1, 2, 1, 1);

        label_display_options = new QLabel(widget_cam_options);
        label_display_options->setObjectName(QString::fromUtf8("label_display_options"));

        gridLayout_10->addWidget(label_display_options, 0, 0, 1, 3);

        one_camera_button = new QPushButton(widget_cam_options);
        one_camera_button->setObjectName(QString::fromUtf8("one_camera_button"));
        sizePolicy2.setHeightForWidth(one_camera_button->sizePolicy().hasHeightForWidth());
        one_camera_button->setSizePolicy(sizePolicy2);
        one_camera_button->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/ic_image_24px.svg"), QSize(), QIcon::Normal, QIcon::Off);
        one_camera_button->setIcon(icon8);
        one_camera_button->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(one_camera_button, 1, 0, 1, 1);


        gridLayout->addWidget(widget_cam_options, 0, 0, 1, 1);

        horizontal_spacer = new QSpacerItem(747, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontal_spacer, 0, 1, 1, 1);

        grid_camera = new QGridLayout();
        grid_camera->setSpacing(0);
        grid_camera->setObjectName(QString::fromUtf8("grid_camera"));

        gridLayout->addLayout(grid_camera, 1, 0, 1, 3);

        tab_manager->addTab(tab_camera_view, QString());
        tab_performance = new QWidget();
        tab_performance->setObjectName(QString::fromUtf8("tab_performance"));
        gridLayout_11 = new QGridLayout(tab_performance);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(-1, 0, -1, -1);
        grid_performance = new QGridLayout();
        grid_performance->setSpacing(6);
        grid_performance->setObjectName(QString::fromUtf8("grid_performance"));

        gridLayout_11->addLayout(grid_performance, 0, 0, 1, 1);

        tab_manager->addTab(tab_performance, QString());
        splitter->addWidget(tab_manager);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(central_widget);
        menu_bar = new QMenuBar(MainWindow);
        menu_bar->setObjectName(QString::fromUtf8("menu_bar"));
        menu_bar->setGeometry(QRect(0, 0, 1382, 25));
        menu_bar->setDefaultUp(false);
        menu_bar->setNativeMenuBar(false);
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_view = new QMenu(menu_bar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        menu_settings = new QMenu(menu_bar);
        menu_settings->setObjectName(QString::fromUtf8("menu_settings"));
        menu_help = new QMenu(menu_bar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menu_bar);
        status_bar = new QStatusBar(MainWindow);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        MainWindow->setStatusBar(status_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_bar->addAction(menu_view->menuAction());
        menu_bar->addAction(menu_settings->menuAction());
        menu_bar->addAction(menu_help->menuAction());
        menu_file->addAction(actionOpen_perception_configuration);
        menu_view->addAction(action_cameras);
        menu_view->addSeparator();
        menu_view->addAction(actionParameter_Temporal_Series);
        menu_view->addSeparator();
        menu_view->addAction(actionProcess_Monitor);
        menu_view->addAction(actionSystem_Status);
        menu_view->addSeparator();
        menu_view->addAction(action3D_Perception_View);
        menu_settings->addAction(actionNew_connection);
        menu_settings->addAction(actionCommunication_Console);
        menu_help->addAction(actionContents);
        menu_help->addAction(actionAbout_Human_Machine_Interface);
        menu_help->addAction(actionUser_Commands_Manual);

        retranslateUi(MainWindow);

        tab_dynamic_view->setCurrentIndex(0);
        tab_control_panel->setCurrentIndex(0);
        tab_manager->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen_perception_configuration->setText(QApplication::translate("MainWindow", "Open perception config file ", 0, QApplication::UnicodeUTF8));
        actionNew_connection->setText(QApplication::translate("MainWindow", "New Connection ", 0, QApplication::UnicodeUTF8));
        action_cameras->setText(QApplication::translate("MainWindow", "Cameras", 0, QApplication::UnicodeUTF8));
        actionParameter_Temporal_Series->setText(QApplication::translate("MainWindow", "Parameter Temporal Series", 0, QApplication::UnicodeUTF8));
        actionProcess_Monitor->setText(QApplication::translate("MainWindow", "Process Monitor", 0, QApplication::UnicodeUTF8));
        actionSystem_Status->setText(QApplication::translate("MainWindow", "System Status", 0, QApplication::UnicodeUTF8));
        action3D_Perception_View->setText(QApplication::translate("MainWindow", "3D Perception View", 0, QApplication::UnicodeUTF8));
        actionContents->setText(QApplication::translate("MainWindow", "Contents", 0, QApplication::UnicodeUTF8));
        actionAbout_Human_Machine_Interface->setText(QApplication::translate("MainWindow", "About Human Machine Interface", 0, QApplication::UnicodeUTF8));
        actionUser_Commands_Manual->setText(QApplication::translate("MainWindow", "User Commands Manual", 0, QApplication::UnicodeUTF8));
        actionCommunication_Console->setText(QApplication::translate("MainWindow", "Communication Console", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tab_dynamic_view->setStatusTip(QApplication::translate("MainWindow", "Shows the rotation angles and the current position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        value_vehicle_yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_vehicle_x->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        value_vehicle_roll->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_vehicle_z->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_vehicle_yaw->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        label_vehicle_roll->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        value_vehicle_y->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        value_vehicle_pitch->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        value_vehicle_x->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_vehicle_y->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_vehicle_pitch->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        value_vehicle_z->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        vehicle_scene->setText(QString());
        sphere_scene->setText(QString());
        value_sphere_yaw->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_sphere_x->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        value_sphere_roll->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_sphere_z->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_sphere_yaw->setText(QApplication::translate("MainWindow", "Yaw:", 0, QApplication::UnicodeUTF8));
        label_sphere_roll->setText(QApplication::translate("MainWindow", "Roll:", 0, QApplication::UnicodeUTF8));
        value_sphere_y->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_sphere_y->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        value_sphere_pitch->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_sphere_pitch->setText(QApplication::translate("MainWindow", "Pitch:", 0, QApplication::UnicodeUTF8));
        value_sphere_x->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        value_sphere_z->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        tab_dynamic_view->setTabText(tab_dynamic_view->indexOf(widget_sphere), QApplication::translate("MainWindow", "Sphere Dynamics", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_control_panel->setToolTip(QApplication::translate("MainWindow", "Panel Control", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tab_control_panel->setStatusTip(QApplication::translate("MainWindow", "Shows the current state of the vehicle and basic control commands", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        value_wifi->setText(QApplication::translate("MainWindow", "Disconnected", 0, QApplication::UnicodeUTF8));
        take_off_button->setText(QApplication::translate("MainWindow", "Take Off", 0, QApplication::UnicodeUTF8));
        label_flying_time->setText(QApplication::translate("MainWindow", "Flying Time :", 0, QApplication::UnicodeUTF8));
        label_sel_vehicle->setText(QApplication::translate("MainWindow", "Selected Vehicle :", 0, QApplication::UnicodeUTF8));
        selection_vehicle->clear();
        selection_vehicle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "UAV_1", 0, QApplication::UnicodeUTF8)
        );
        value_errors->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        land_button->setText(QApplication::translate("MainWindow", "Land", 0, QApplication::UnicodeUTF8));
        selection_mode->clear();
        selection_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Autonomous", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manual Position", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manual Altitude", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manual Speed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Visual Servoing", 0, QApplication::UnicodeUTF8)
        );
        label_battery_2->setText(QApplication::translate("MainWindow", "Battery Charge :", 0, QApplication::UnicodeUTF8));
        emergency_stop_button->setText(QApplication::translate("MainWindow", "Emergency Stop", 0, QApplication::UnicodeUTF8));
        value_battery->setText(QApplication::translate("MainWindow", "0%", 0, QApplication::UnicodeUTF8));
        yaw_zero_button->setText(QApplication::translate("MainWindow", "Yaw Zero", 0, QApplication::UnicodeUTF8));
        label_current_goal->setText(QApplication::translate("MainWindow", "Current Status :", 0, QApplication::UnicodeUTF8));
        value_currentGoal->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label_errors->setText(QApplication::translate("MainWindow", "Detected Errors :", 0, QApplication::UnicodeUTF8));
        label_wifi->setText(QApplication::translate("MainWindow", "Wifi Connection :", 0, QApplication::UnicodeUTF8));
        label_control_mode->setText(QApplication::translate("MainWindow", "Control Mode :", 0, QApplication::UnicodeUTF8));
        value_fligth_time->setText(QApplication::translate("MainWindow", "0:00", 0, QApplication::UnicodeUTF8));
        hover_button->setText(QApplication::translate("MainWindow", "Hover", 0, QApplication::UnicodeUTF8));
        tab_control_panel->setTabText(tab_control_panel->indexOf(widget_control_panel), QApplication::translate("MainWindow", "Control Panel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tab_manager->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tab_manager->setTabText(tab_manager->indexOf(tab_parameters), QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        save_image_button->setText(QString());
        main_camera_button->setText(QString());
        four_camera_button->setText(QString());
        label_display_options->setText(QApplication::translate("MainWindow", "Display Options:", 0, QApplication::UnicodeUTF8));
        one_camera_button->setText(QString());
        tab_manager->setTabText(tab_manager->indexOf(tab_camera_view), QApplication::translate("MainWindow", "Camera Views", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_performance), QApplication::translate("MainWindow", "Performance Monitor", 0, QApplication::UnicodeUTF8));
        menu_file->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menu_view->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menu_settings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menu_help->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
