/*!*******************************************************************************************
 *  \file       main_window.h
 *  \brief      MainWindow definition file.
 *  \details    This file includes the MainWindow class declaration. To obtain more
 *              information about it's definition consult the main_window.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt4/QtOpenGL/QGLWidget>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtCore/QTime>
#include <qt4/QtCore/QTimer>
#include <qt4/Qt/qtoolbutton.h>
#include <QWidget>
#include <QAction>

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // For exit
#include <unistd.h>
#include <cstring>
#include <string>

#include <droneMsgsROS/droneManagerStatus.h>
#include <droneMsgsROS/droneStatus.h>

#include "connection.h"
#include "communication_console.h"
#include "odometry_state_receiver.h"
#include "user_commander.h"
#include "parameter_temporal_series.h"
#include "performance_monitor.h"
#include "sphere_view.h"
#include "camera_display_option.h"
#include "camera_main_option.h"
#include "camera_grid_option.h"
#include "sphere_view.h"
#include "vehicle_view.h"
#include "control_panel.h"

namespace Ui {
class MainWindow;
}

/*!********************************************************************************************************************
 *  \class      MainWindow
 *  \brief      This is the class that allows having the main window of the HMI.
 *  \details    Here is the declaration of every class that will be used in the .cpp file
 *
 *********************************************************************************************************************/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int argc, char** argv,QWidget *parent = 0);
    ~MainWindow();


    static bool uniqueApplication();

private Q_SLOTS:
    void updateDynamicView();

public Q_SLOTS:
    void on_actionNew_connection_triggered();
    void on_actionParameter_Temporal_Series_triggered();
    void on_actionAbout_Human_Machine_Interface_triggered();
    void on_actionContents_triggered();
    void on_actionCommunication_Console_triggered();
    void on_actionUser_Commands_Manual_triggered();
    void setSignalHandlers();
    void displayOneCamera();
    void displayMainGridCamera();
    void displayFourGridCamera();
    void setTimerInterval(double ms);
    void on_actionOpen_perception_configuration_triggered();
   // void keyPressEvent(QKeyEvent *e);
    void initializeCameraView();
    void closeEvent(QCloseEvent *event);
    void saveCurrentCameraView();
    void keyPressEvent(QKeyEvent *e);
    void updateDynamicsPanel();
    void disconnectDynamicsView();
    void connectDynamicsView();
    //void showContextMenu(const QPoint& globalPos);
    void close();


Q_SIGNALS:
    void loggingUpdated();
    void rosShutdown();
    void parameterReceived();
    void updateStatus();
    void saveImage(const int);

protected:
    void resizeEventDynamicView(QResizeEvent* event);

private:

    bool setLaptopDesign();
    int current_control_mode;
    char* getProcessName(const char* process_name_temp);
    std::vector<std::string> checkListToTakeOff();
    bool isInAutonomousMode();
    void setCurrentUAV();

    enum control_modes{
        autonomous,
        position,
        altitude,
        speed,
        visual_servoing
    };

    bool is_open_main_camera_view;
    bool is_open_one_camera_view;
    bool is_init_takeoff_context_menu;
    bool is_open_four_camera_view;
    bool is_laptop_design;
    bool is_initial_controlmode;

    QString file_name;
    int ignore_resize;
    int max_osg_frame;
    int num_of_auto_ops;
    int old_height;
    int resize;
    int camera_view_manager;

    QTimer *flight_timer;

    QList<QAction*> menu_takeoff_actions;
    droneMsgsROS::ProcessDescriptor node_container;

    SphereView *osg_sphere;
    VehicleView *osg_uav;
    QTimer *timer;
    QTime *current_time;
    int error_counter;

    Ui::MainWindow *ui;
    Connection *connection;
    CameraDisplayOption *mainoption;
    CameraMainOption *one_option;
    CameraGridOption *fourCamera;
    PerformanceMonitor *process_view;
    ParameterTemporalSeries *param_plot;
    CommunicationConsole *consoleView;
    ControlPanel *controlpanel;

    int d_interval; // timer in ms
    int d_timerId;




};

#endif // MAINWINDOW_H
