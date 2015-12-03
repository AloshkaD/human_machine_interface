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

/*****************************************************************************
** Implementation
*****************************************************************************/

BehaviourViewer::BehaviourViewer(QWidget *parent, RosGraphReceiver *collector, UserCommander *usercommander) :
    QWidget(parent),
    ui(new Ui::BehaviourViewer)
{
    ui->setupUi(this);

}
void BehaviourViewer::clearFocus()
{
    std::cout<<"Editing line finished" <<std::endl;
    ui->line_edit->clearFocus();
}

void BehaviourViewer::updateBehaviourViewerTable()
{
	//std::vector<behaviour>behaviour_vector;

}

void BehaviourViewer::updateBehaviourState() ////////////cambiar por TASK????
{

}


void BehaviourViewer::onBehaviourStateReceived()
{

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
