/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/behaviour_viewer.h"
#include "ui_behaviourviewer.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qscrollbar.h>
#include <string>
#include <sstream>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qtablewidget.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

/*****************************************************************************
** Implementation
*****************************************************************************/

BehaviourViewer::BehaviourViewer(QWidget *parent, RosGraphReceiver *collector, UserCommander *usercommander) :
    QWidget(parent),
    ui(new Ui::BehaviourViewer)
{
    ui->setupUi(this);
    initializeBehaviourViewerTable();
    connect(collector,SIGNAL(stateBehaviorReceived(droneMsgsROS::BehaviorsList* list_behavior_state)),this,SLOT(onBehaviourStateReceived(droneMsgsROS::BehaviorsList *list_behavior_state)));

}

void BehaviourViewer::clearFocus()
{
    std::cout<<"Editing line finished" <<std::endl;
    ui->line_edit->clearFocus();
}

void BehaviourViewer::initializeBehaviourViewerTable(){ //int num_behaviours como parámetro [en el futuro]
	
    //behaviour_vector(1,18);
	behaviour_vector[0].behaviour = "selfPositioningByArucoMarkers";
	behaviour_vector[0].started = false;
	behaviour_vector[1].behaviour = "detectingObstaclesByArucoMarkers";
	behaviour_vector[1].started = false;
	behaviour_vector[2].behaviour = "avoidingObstacles";
	behaviour_vector[2].started = false;
	behaviour_vector[3].behaviour = "droneObstacleProcessor";
	behaviour_vector[3].started = false;
	behaviour_vector[4].behaviour = "droneObstacleDistanceCalculator";
	behaviour_vector[4].started = false;
	behaviour_vector[5].behaviour = "recognizingArucoMarkers";
	behaviour_vector[5].started = false;
	behaviour_vector[6].behaviour = "droneArucoEyeROSModule";
	behaviour_vector[6].started = false;
	behaviour_vector[7].behaviour = "recognizingVisualMarkers";
	behaviour_vector[7].started = false;
	behaviour_vector[8].behaviour = "recognizingQRCodes";
	behaviour_vector[8].started = false;
	behaviour_vector[9].behaviour = "recognizingColors";
	behaviour_vector[9].started = false;
	behaviour_vector[10].behaviour = "recognizingLines";
	behaviour_vector[10].started = false;
	behaviour_vector[11].behaviour = "memorizingImages";
	behaviour_vector[11].started = false;
	behaviour_vector[12].behaviour = "trackingMemorizedImage";
	behaviour_vector[12].started = false;
	behaviour_vector[13].behaviour = "open_tld_translator";
	behaviour_vector[13].started = false;
	behaviour_vector[14].behaviour = "trackerEye";
	behaviour_vector[14].started = false;
	behaviour_vector[15].behaviour = "ibvsController";
	behaviour_vector[15].started = false;
	behaviour_vector[16].behaviour = "handlingPayload";
	behaviour_vector[16].started = false;
	behaviour_vector[17].behaviour = "sayingOutLoudCurrentTask";
	behaviour_vector[17].started = false;



	/*selfPositioningByArucoMarkers
	detectingObstaclesByArucoMarkers
	avoidingObstacles
	droneObstacleProcessor
	droneObstacleDistanceCalculator
	recognizingArucoMarkers
	droneArucoEyeROSModule
	recognizingVisualMarkers
	recognizingQRCodes
	recognizingColors
	recognizingLines
	memorizingImages
	trackingMemorizedImage
	open_tld_translator
	trackerEye
	ibvsController
	handlingPayload
	sayingOutLoudCurrentTask*/
}

/*void BehaviourViewer::updateBehaviourViewerTable()//(behvaiour_t new_beh)
{
	//std::vector<behvaiour_t> behaviour_vector(1,num_behaviours);  

	void insert_behaviour(new_beh){
	int i=0;
	while(behaviour_vector.back()!=0){
	i++;
	if (i == behaviour_vector.size())
	  break;
	}
behaviour_vector.push_back(behaviour_t new_beh);

}*/

void BehaviourViewer::updateBehaviourState(const droneMsgsROS::BehaviorDescriptor *behavior_container, int row_behavior_viewer)
{
    switch(behavior_container->current_state.state)
    {
    case droneMsgsROS::BehaviorState::not_requested:
        ui->table_process_viewer->setItem(row_behavior_viewer,1,new QTableWidgetItem("Not Requested"));
        break;

    case droneMsgsROS::BehaviorState::requested:
        ui->table_process_viewer->setItem(row_behavior_viewer,1,new QTableWidgetItem("Requested"));
        break;
     }
}

void BehaviourViewer::onBehaviourStateReceived(droneMsgsROS::BehaviorsList *list_behavior_state)
{
  int row_behavior_viewer=0;

  std::cout << "Loop the list to create the items in the table"   << std::endl;
  for(unsigned int i = 0; i < list_behavior_state->behavior_list.size(); i++)
  {
      behavior_containter= list_behavior_state->behavior_list.at(i);

      if(!initialized_table){
          if (ui->table_process_viewer->rowCount() < row_behavior_viewer)
              ui->table_process_viewer->setRowCount(row_behavior_viewer);
          ui->table_process_viewer->insertRow(row_behavior_viewer);
      }
      ui->table_process_viewer->setItem(row_behavior_viewer,0,new QTableWidgetItem(QString(behavior_containter.name.c_str())));

      updateBehaviourState(&behavior_containter,row_behavior_viewer);
      row_behavior_viewer++;
  }
  initialized_table=true;
}

void BehaviourViewer::onTextFilterChange(const QString &arg1)
{

}

void BehaviourViewer::onCustomContextMenuRequested(const QPoint& pos) {

}

void BehaviourViewer::showContextMenu(QTableWidgetItem* item, const QPoint& globalPos){

}

void BehaviourViewer::menuSelection(QAction* action){

}

BehaviourViewer::~BehaviourViewer()
{
    delete ui;
}

