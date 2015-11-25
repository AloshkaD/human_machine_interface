/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/behaviour_manager_viewer.h"
#include "ui_pbehaviourmanager.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qscrollbar.h>
#include <string>
#include <sstream>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qtablewidget.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

BehaviourManagerViewer::BehaviourManagerViewer(QWidget *parent, RosGraphReceiver *collector, UserCommander *usercommander) :
    QWidget(parent),
    ui(new Ui::BehaviourManagerViewer)
{
    ui->setupUi(this);

}
void BehaviourManagerViewer::clearFocus()
{
    std::cout<<"Editing line finished" <<std::endl;
    ui->line_edit->clearFocus();
}

void BehaviourManagerViewer::updateBehaviourViewerTable()
{

}

void BehaviourManagerViewer::updateBehaviourState() ////////////cambiar por TASK????
{

}


void BehaviourManagerViewer::onBehaviourStateReceived()
{

}

void BehaviourManagerViewer::onTextFilterChange(const QString &arg1)
{

}

void BehaviourManagerViewer::onCustomContextMenuRequested(const QPoint& pos) {

}

void BehaviourManagerViewer::showContextMenu(QTableWidgetItem* item, const QPoint& globalPos){

}

void BehaviourManagerViewer::menuSelection(QAction* action){

}

BehaviourManagerViewer::~BehaviourManagerViewer()
{
    delete ui;
}
