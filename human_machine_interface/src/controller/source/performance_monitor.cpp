/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/performance_monitor.h"
#include "../.././../../../hmi_cvg_stack -build/human_machine_interface/ui_processmonitor.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qscrollbar.h>
#include <string>
#include <sstream>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qtablewidget.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

PerformanceMonitor::PerformanceMonitor(QWidget *parent, RosGraphReceiver *collector) :
    QWidget(parent),
    ui(new Ui::performanceMonitor)
{
    ui->setupUi(this);
    ui->tableProcessViewer->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0,640);

    node=collector;
    errorCounter=0;
    is_display_stopped=false;

    connect( node, SIGNAL( supervisorStateReceived( )), this, SLOT( updateProcessViewerTable( )));
    connect( node, SIGNAL( errorInformerReceived( )), this, SLOT( onSupervisorStateReceived( )));
    connect( ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT( onTextFilterChange(const QString )));
    connect(ui->tableProcessViewer,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(onCustomContextMenuRequested(const QPoint&)));
    connect(ui->stop_display_button,SIGNAL(clicked()),this,SLOT(onStopClicked()));

    QTableWidgetItem *qtablewidgetitem8 = new QTableWidgetItem();
    ui->tableWidget->setItem(0, 2, qtablewidgetitem8);

    updateProcessViewerTable();

    initializedTable=false;
    row=0;

}

void PerformanceMonitor::updateProcessViewerTable()
{
    int rowProcessViewer=0;

    // Loop the list to create the items in the table
    for(unsigned int i = 0; i < node->listProcessState.process_list.size(); i++)
    {
        node_container= node->listProcessState.process_list.at(i);

        if(!initializedTable){
            if (ui->tableProcessViewer->rowCount() < rowProcessViewer)
                ui->tableProcessViewer->setRowCount(rowProcessViewer);
            ui->tableProcessViewer->insertRow(rowProcessViewer);
        }

        char* process_name = getProcessName(node_container.name.c_str());
        ui->tableProcessViewer->setItem(rowProcessViewer,0,new QTableWidgetItem(QString(process_name)));

        updateProcessState(node_container,rowProcessViewer);
        rowProcessViewer++;
    }
    initializedTable=true;
}

void PerformanceMonitor::updateProcessState(droneMsgsROS::ProcessDescriptor node_container, int rowProcessViewer)
{
    switch(node_container.current_state.state)
    {
    case droneMsgsROS::ProcessState::Initializing:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Initializing"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem(" Dead  (Last state: Initializing)"));
        break;

    case droneMsgsROS::ProcessState::NotStarted:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Not Started"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem(" Dead (Last state: Not Started)"));
        break;

    case droneMsgsROS::ProcessState::Recovering:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Recovering)"));
        break;

    case droneMsgsROS::ProcessState::Running:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Running"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Running)"));
        break;

    case droneMsgsROS::ProcessState::Sleeping:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Sleeping"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Sleeping)"));
        break;

    case droneMsgsROS::ProcessState::Started:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Started"));
        if(!node_container.is_alive){
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Started)"));
        }
        break;

    case droneMsgsROS::ProcessState::Stopping:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Stopping"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Stopping)"));
        break;

    case droneMsgsROS::ProcessState::Waiting:
        ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Waiting"));
        if(!node_container.is_alive)
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Dead (Last state: Waiting)"));
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

char* PerformanceMonitor::getProcessName(const char* process_name_temp)//TODO::Comprobar si existe namespace.
{
    char output[10012];
    strncpy(output, process_name_temp, sizeof(output));
    output[sizeof(output) - 1] = 0;
    char* process_name = strtok(output, "/");
    process_name = strtok(NULL, "/");
    return process_name;
}

void PerformanceMonitor::onSupervisorStateReceived()
{
    if(initializedTable&&!is_display_stopped){
        ui->tableWidget->verticalScrollBar()->setSliderPosition( ui->tableWidget->verticalScrollBar()->maximum());

        if (ui->tableWidget->rowCount() < row)
            ui->tableWidget->setRowCount(row);

        ui->tableWidget->insertRow(row);
        QTableWidgetItem *itemMessage = new QTableWidgetItem(node->description);
        QTableWidgetItem *itemProcess = new QTableWidgetItem(node->node_name);
        QTableWidgetItem *itemHostname = new QTableWidgetItem(node->hostname);
        QTableWidgetItem *itemErrorType = new QTableWidgetItem(node->error_type);

        ui->tableWidget->setItem(row,0,itemMessage);
        ui->tableWidget->setItem(row,1,itemErrorType);
        ui->tableWidget->setItem(row,2,itemProcess);
        ui->tableWidget->setItem(row,3,itemHostname);
        row++;

        errorCounter++;
    }
}

void PerformanceMonitor::onTextFilterChange(const QString &arg1)
{
    if(initializedTable){
        QString filter = arg1;
        for( int i = 0; i < ui->tableProcessViewer->rowCount(); ++i )
        {
            bool match = false;
            for( int j = 0; j < ui->tableProcessViewer->columnCount(); ++j )
            {
                QTableWidgetItem *item = ui->tableProcessViewer->item( i, j );
                if( item->text().contains(filter) )
                {
                    match = true;
                    break;
                }
            }
            ui->tableProcessViewer->setRowHidden( i, !match );
        }
    }
}

void PerformanceMonitor::onCustomContextMenuRequested(const QPoint& pos) {
    if(initializedTable){
        QTableWidgetItem* item = ui->tableProcessViewer->itemAt(pos);
        if(ui->tableProcessViewer->column(item)==0){
            if (item) {
                // Map the point to global from the viewport to account for the header.
                showContextMenu(item,  ui->tableProcessViewer->viewport()->mapToGlobal(pos));
            }
        }
    }
}

void PerformanceMonitor::showContextMenu(QTableWidgetItem* item, const QPoint& globalPos) {
    QMenu menu;
    menu.addAction("Stop");
    menu.addAction("Start");
    menu.addAction("Record");
    menu.exec(globalPos);
}

void PerformanceMonitor::onStopClicked(){
    is_display_stopped = true;
}
PerformanceMonitor::~PerformanceMonitor()
{
    delete ui;
}
