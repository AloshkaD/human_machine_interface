/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/performance_monitor_viewer.h"
#include "ui_performancemonitorviewer.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qscrollbar.h>
#include <string>
#include <sstream>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qtablewidget.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

PerformanceMonitorViewer::PerformanceMonitorViewer(QWidget *parent, RosGraphReceiver *collector, UserCommander *usercommander) :
    QWidget(parent),
    ui(new Ui::PerformanceMonitorViewer)
{
    ui->setupUi(this);
    ui->table_process_viewer->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->table_widget->setColumnWidth(0,640);

    supervisor_receiver=collector;
    user_command=usercommander;
    error_counter=0;
    is_display_stopped=false;

    connect(supervisor_receiver, SIGNAL( supervisorStateReceived( )), this, SLOT( updateProcessViewerTable( )));
    connect(supervisor_receiver, SIGNAL( errorInformerReceived( )), this, SLOT( onSupervisorStateReceived( )));
    connect(ui->line_edit, SIGNAL(textChanged(QString)), this, SLOT( onTextFilterChange(const QString )));
    connect(ui->table_process_viewer,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(onCustomContextMenuRequested(const QPoint&)));
    connect(ui->stop_display_button,SIGNAL(clicked()),this,SLOT(onStopClicked()));
    connect(ui->line_edit, SIGNAL( editingFinished( )), this, SLOT( clearFocus( )));

    QTableWidgetItem *qtablewidgetitem8 = new QTableWidgetItem();
    ui->table_widget->setItem(0, 2, qtablewidgetitem8);

    updateProcessViewerTable();

    initialized_table=false;
    row=0;

}
void PerformanceMonitorViewer::clearFocus()
{
    std::cout<<"Editing line finished" <<std::endl;
    ui->line_edit->clearFocus();
}

void PerformanceMonitorViewer::updateProcessViewerTable()
{
    int row_process_viewer=0;

    // Loop the list to create the items in the table
    for(unsigned int i = 0; i < supervisor_receiver->list_process_state.process_list.size(); i++)
    {
        node_container= supervisor_receiver->list_process_state.process_list.at(i);

        if(!initialized_table){
            if (ui->table_process_viewer->rowCount() < row_process_viewer)
                ui->table_process_viewer->setRowCount(row_process_viewer);
            ui->table_process_viewer->insertRow(row_process_viewer);
        }

        char* process_name = getProcessName(node_container.name.c_str());
        ui->table_process_viewer->setItem(row_process_viewer,0,new QTableWidgetItem(QString(process_name)));

        updateProcessState(node_container,row_process_viewer);
        row_process_viewer++;
    }
    initialized_table=true;
}

void PerformanceMonitorViewer::updateProcessState(droneMsgsROS::ProcessDescriptor node_container, int row_process_viewer)
{
    switch(node_container.current_state.state)
    {
    case droneMsgsROS::ProcessState::Initializing:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Initializing"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem(" Dead  (Last state: Initializing)"));
        break;

    case droneMsgsROS::ProcessState::NotStarted:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Not Started"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem(" Dead (Last state: Not Started)"));
        break;

    case droneMsgsROS::ProcessState::Recovering:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Recovering"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Recovering)"));
        break;

    case droneMsgsROS::ProcessState::Running:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Running"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Running)"));
        break;

    case droneMsgsROS::ProcessState::Sleeping:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Sleeping"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Sleeping)"));
        break;

    case droneMsgsROS::ProcessState::Started:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Started"));
        if(!node_container.is_alive){
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Started)"));
        }
        break;

    case droneMsgsROS::ProcessState::Stopping:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Stopping"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Stopping)"));
        break;

    case droneMsgsROS::ProcessState::Waiting:
        ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Waiting"));
        if(!node_container.is_alive)
            ui->table_process_viewer->setItem(row_process_viewer,1,new QTableWidgetItem("Dead (Last state: Waiting)"));
        break;
    }
    /*if(!node_container.is_alive){
        ui->tableWidget->selectRow(rowProcessViewer);
        ui->tableProcessViewer->setItem(rowProcessViewer,3,new QTableWidgetItem(QString::number(node_container.last_signal.sec)));
    }

    if(!initializedTable&&node_container.is_alive){
        ui->tableWidget->selectRow(rowProcessViewer);
        ui->tableProcessViewer->setItem(rowProcessViewer,2,new QTableWidgetItem(QString::number(node_container.last_signal.sec)));
    }*/
}

char* PerformanceMonitorViewer::getProcessName(const char* process_name_temp)//TODO::Comprobar si existe namespace.
{
    char output[10012];
    strncpy(output, process_name_temp, sizeof(output));
    output[sizeof(output) - 1] = 0;
    char* process_name = strtok(output, "/");
    process_name = strtok(NULL, "/");
    return process_name;
}

void PerformanceMonitorViewer::onSupervisorStateReceived()
{
    if(initialized_table&&!is_display_stopped){
        ui->table_widget->verticalScrollBar()->setSliderPosition( ui->table_widget->verticalScrollBar()->maximum());

        if (ui->table_widget->rowCount() < row)
            ui->table_widget->setRowCount(row);

        ui->table_widget->insertRow(row);
        QTableWidgetItem *itemMessage = new QTableWidgetItem(supervisor_receiver->description);
        QTableWidgetItem *itemProcess = new QTableWidgetItem(supervisor_receiver->node_name);
        QTableWidgetItem *itemHostname = new QTableWidgetItem(supervisor_receiver->hostname);
        QTableWidgetItem *itemErrorType = new QTableWidgetItem(supervisor_receiver->error_type);

        ui->table_widget->setItem(row,0,itemMessage);
        ui->table_widget->setItem(row,1,itemErrorType);
        ui->table_widget->setItem(row,2,itemProcess);
        ui->table_widget->setItem(row,3,itemHostname);
        row++;

        error_counter++;
    }
}

void PerformanceMonitorViewer::onTextFilterChange(const QString &arg1)
{
    if(initialized_table){
        QString filter = arg1;
        for( int i = 0; i < ui->table_process_viewer->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 0; j < ui->table_process_viewer->columnCount(); ++j )
            {
                QTableWidgetItem *item = ui->table_process_viewer->item( i, j );
                if( item->text().contains(filter) )
                {
                    match = true;
                    break;
                }
            }
            ui->table_process_viewer->setRowHidden( i, !match );
        }
    }
}

void PerformanceMonitorViewer::onCustomContextMenuRequested(const QPoint& pos) {
    if(initialized_table){
        QTableWidgetItem* item = ui->table_process_viewer->itemAt(pos);
        if(ui->table_process_viewer->column(item)==0){
            if (item) {
                // Map the point to global from the viewport to account for the header.
                showContextMenu(item,  ui->table_process_viewer->viewport()->mapToGlobal(pos));
            }
        }
    }
}

void PerformanceMonitorViewer::showContextMenu(QTableWidgetItem* item, const QPoint& globalPos){
    QMenu menu;
    menu.addAction("Stop");
    menu.addAction("Start");
    menu.addAction("Reset");
    menu.addAction("Record(Not implemented)");
    connect(&menu, SIGNAL(triggered(QAction*)), this, SLOT(menuSelection(QAction*)));
    menu.exec(globalPos);
}

void PerformanceMonitorViewer::menuSelection(QAction* action){
    std::cout<<"Action clicked:" + action->text().toStdString() <<std::endl;

    QModelIndexList selection = ui->table_process_viewer->selectionModel()->selectedRows();

    // Multiple rows can be selected
    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        QTableWidgetItem *item = ui->table_process_viewer->item( index.row(), 0 );
        std::cout<< item->text().toStdString() <<std::endl;
        if(action->text().toStdString().compare("Stop")==0)
         user_command->processMonitorCommander(item->text().toStdString(),processMonitorStates::Stop);
        if(action->text().toStdString().compare("Start")==0)
         user_command->processMonitorCommander(item->text().toStdString(),processMonitorStates::Start);
        if(action->text().toStdString().compare("Reset")==0)
         user_command->processMonitorCommander(item->text().toStdString(),processMonitorStates::Reset);
    }
}

void PerformanceMonitorViewer::onStartModuleClicked(){
    std::cout<<"Start module clicked"<<std::endl;
}

void PerformanceMonitorViewer::onStopClicked(){
    is_display_stopped = true;
}
PerformanceMonitorViewer::~PerformanceMonitorViewer()
{
    delete ui;
}
