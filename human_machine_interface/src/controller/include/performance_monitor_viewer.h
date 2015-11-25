/*!*******************************************************************************************
 *  \file       performance_monitor_viewer.h
 *  \brief      UserCommander definition file.
 *  \details    This file includes the PerformanceMonitorViewer class declaration. To obtain more
 *              information about it's definition consult the performance_monitor.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef PERFORMANCEMONITORVIEWER_H
#define PERFORMANCEMONITORVIEWER_H

#include <QWidget>
#include <QDockWidget>

#include <QTableWidgetItem>
#include <QString>
#include <QTime>
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptor.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "ros_graph_receiver.h"
#include "user_commander.h"

namespace Ui {
class PerformanceMonitorViewer;
}

class PerformanceMonitorViewer : public QWidget
{
    Q_OBJECT

    int row;
    int error_counter;
    bool initialized_table;
    bool is_display_stopped;

public:
    explicit PerformanceMonitorViewer(QWidget *parent = 0, RosGraphReceiver *collector=0,UserCommander *usercommander=0);
    void setSignalHandlers();
    char* getProcessName(const char* process_name);
    void updateProcessState(droneMsgsROS::ProcessDescriptor node_container, int rowProcessViewer);
    void onStartModuleClicked();
    void onStopModuleClicked();
    droneMsgsROS::ProcessDescriptor node_container;
    enum processMonitorStates {
        Start,
        Stop,
        Reset
    };

    ~PerformanceMonitorViewer();

public Q_SLOTS:
    /*
    void filterTableInfo();
    */
    void onSupervisorStateReceived();
    void updateProcessViewerTable();
    void onTextFilterChange(const QString &arg1);
    void onCustomContextMenuRequested(const QPoint &pos);
    void showContextMenu(QTableWidgetItem *item, const QPoint& globalPos);
    void onStopClicked();
    void menuSelection(QAction* action);
    void clearFocus();


private:
    Ui::PerformanceMonitorViewer *ui;
    QMap<QString,QStringList> processList;
    QStringList listProcess;
    UserCommander* user_command;
    RosGraphReceiver* supervisor_receiver;
};

#endif // PERFORMANCEMONITORVIEWER_H

