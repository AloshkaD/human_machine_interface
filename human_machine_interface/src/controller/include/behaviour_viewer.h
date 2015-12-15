/*!*******************************************************************************************
 *  \file       behaviour_viewer.h
 *  \brief      BehaviourManagerViewer definition file.
 *  \details    This file includes the BehaviourManagerViewer class declaration. To obtain more
 *              information about it's definition consult the performance_monitor.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef BEHAVIOURVIEWER_H
#define BEHAVIOURVIEWER_H

#include <QWidget>
#include <QDockWidget>

#include <QTableWidgetItem>
#include <QString>
#include <QTime>
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptor.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "droneMsgsROS/BehaviorsList.h"
#include "droneMsgsROS/BehaviorState.h"
#include "ros_graph_receiver.h"
#include "user_commander.h"
#include <vector>
#include <iostream>

namespace Ui {
class BehaviourViewer;
}

class BehaviourViewer : public QWidget
{
    Q_OBJECT

    int row;
    int error_counter;
    bool initialized_table;
    bool is_display_stopped;

public:
    explicit BehaviourViewer(QWidget *parent = 0, RosGraphReceiver *collector=0,UserCommander *usercommander=0);
    void setSignalHandlers();
    void updateBehaviourState();
    droneMsgsROS::BehaviorsList behavior_list;

    ~BehaviourViewer();
    droneMsgsROS::BehaviorDescriptor behavior_containter;
struct behaviour_t {
    std::string behaviour;
    bool started;
};
    int num_behaviours;
    std::vector<behaviour_t> behaviour_vector;


public Q_SLOTS:
    void onBehaviourStateReceived();
    void updateBehaviourState(const droneMsgsROS::BehaviorDescriptor *behavior_container, int row_behavior_viewer);
    void initializeBehaviourViewerTable();
    void onTextFilterChange(const QString &arg1);
    void onCustomContextMenuRequested(const QPoint &pos);
    void showContextMenu(QTableWidgetItem *item, const QPoint& globalPos);
    void menuSelection(QAction* action);
    void clearFocus();


private:
    Ui::BehaviourViewer *ui;
    RosGraphReceiver* behavior_receiver;

};

#endif // BEHAVIOURVIEWER
