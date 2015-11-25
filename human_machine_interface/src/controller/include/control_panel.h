/*!*******************************************************************************************
 *  \file       control_panel.h
 *  \brief      Control_panel definition file.
 *  \details    This file includes the Control_panel class declaration.
 *  \author     Yolanda de la Hoz Simon, Laura García García
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <qt4/QtOpenGL/QGLWidget>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtCore/QTime>
#include <qt4/QtCore/QTimer>
#include <qt4/Qt/qtoolbutton.h>
#include <QWidget>
#include <QAction>
#include "../include/connection.h"
#include "ui_controlpanel.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // For exit
#include <unistd.h>
#include <cstring>
#include <string>

/*!********************************************************************************************************************
 *  \class      ControlPanel
 *  \brief      This is the class that allows having, in the main window of the HMI, the control panel.
 *  \details    Here is the declaration of every class that will be used in the .cpp file.
 *
 *********************************************************************************************************************/


namespace Ui {
class ControlPanel;
}


class ControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent,Connection* connection);
    ~ControlPanel();



public Q_SLOTS:

    void updateStatusPanel(); /// -> status bar
    void onTakeOffButton();
    void onYawZeroButton();
    void onLandButton();
    void onResetCommandButton();
    void onHoverButton();
    void onEmergencyStopButton();
    void onLoopButton();
    void testConnection();
   // void keyPressEvent(QKeyEvent *e);
    void showNoMasterMessage();
    void showConnectionEstablished();
    void flightTime();
    void incrementErrorsCounter();
    void onControlModeChange(int key);
    void setInitialControlMode();
    //void showContextMenu(const QPoint& globalPos);
    void initContextMenuTakeOff();
    void setTimerInterval(double ms);

Q_SIGNALS:
    void parameterReceived();



private:

    void setSignalHandlers();
    int current_control_mode;
    char* getProcessName(const char* process_name_temp);
    std::vector<std::string> checkListToTakeOff();
    bool isInAutonomousMode();
    bool is_takenOff;
    bool land;
    bool is_autonomous;

    void setCurrentUAV();

    enum control_modes{
        autonomous,
        position,
        altitude,
        speed,
        visual_servoing
    };

  
    bool is_init_takeoff_context_menu;
 
    bool is_initial_controlmode;


    QTimer *flight_timer;

    QList<QAction*> menu_takeoff_actions;
    droneMsgsROS::ProcessDescriptor node_container;
  
    QTimer *timer;
    QTime *current_time;
    int error_counter;

    Ui::ControlPanel *ui;

    int d_interval; // timer in ms
    int d_timerId;
    Connection* connect;
};

#endif // CONTROLPANEL_H
