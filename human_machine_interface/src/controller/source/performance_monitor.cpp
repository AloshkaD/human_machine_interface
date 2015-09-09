/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/performance_monitor.h"
#include "../.././../../../src-build/human_machine_interface/ui_processmonitor.h"
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
    node=collector;

    errorCounter=0;

    QObject::connect( node, SIGNAL( supervisorStateReceived( )), this, SLOT( initProcessViewerTable( )));
     QObject::connect( node, SIGNAL( errorInformerReceived( )), this, SLOT( onSupervisorStateReceived( )));
    // ESTRUCTURA DE VISUALIZACIÓN

    listProcess << "trajectory_planner_example" << "perception_system_example";
    QStringList mission_planner;
    mission_planner << "trajectory_planner_example";
    QStringList computer_vision;
    computer_vision << "perception_system_example";
    int pid=2000;
    processList.insert("mission_planner",mission_planner);//pos1
    processList.insert("computer_vision",computer_vision);//pos2

    QTableWidgetItem *qtablewidgetitem8 = new QTableWidgetItem();
    ui->tableWidget->setItem(0, 2, qtablewidgetitem8);
    //updateTableInfo();
   // this->initTree(processList,ui->treeWidget);
    initProcessViewerTable();

   // setSignalHandlers();
    initializedTable=false;
    row=0;

}
/*
QToolButton *b = new QToolButton(this);
QIcon *ico = new QIcon();
ico->addPixmap(QPixmap("on.jpg"),QIcon::Normal,QIcon::On);
ico->addPixmap(QPixmap("off.jpg"),QIcon::Normal,QIcon::Off);
b->setIcon(*ico);
b->setCheckable(true);
*/

/*void processMonitor::setSignalHandlers()
{
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this, SLOT(onTextFilterChange(QString)));
    connect(ui->treeWidget,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(onCustomContextMenuRequested(const QPoint&)));
}

// TODO
void processMonitor::updateTableInfo()
{

}
*/
void PerformanceMonitor::onCustomContextMenuRequested(const QPoint& pos) {
 /*   QTreeWidgetItem* item = ui->treeWidget->itemAt(pos);
    qDebug() << item->text(0);
    if (item) {
        // Map the point to global from the viewport to account for the header.
        showContextMenu(item, ui->treeWidget->viewport()->mapToGlobal(pos));
    }*/
}

void PerformanceMonitor::showContextMenu(QTreeWidgetItem* item, const QPoint& globalPos) {
    QMenu menu;
    menu.addAction("Stop");
    menu.addAction("Start");
    menu.addAction("Record");
    menu.exec(globalPos);
}

void PerformanceMonitor::initProcessViewerTable()
{
    int rowProcessViewer=0;

    // Loop the list to create table items
    for(unsigned int i = 0; i < node->listProcessState.process_list.size(); i = i + 1)
    {
        node_container= node->listProcessState.process_list.at(i);


        if(!initializedTable){
            if (ui->tableProcessViewer->rowCount() < rowProcessViewer)
                ui->tableProcessViewer->setRowCount(rowProcessViewer);
            ui->tableProcessViewer->insertRow(rowProcessViewer);
        }
        ui->tableProcessViewer->setItem(rowProcessViewer,0,new QTableWidgetItem(QString(node_container.name.c_str())));

        switch(node_container.current_state.state)
        {
        case droneMsgsROS::ProcessState::Initializing:
            std::cout<<"Process Status: Initializing"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Initializing"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Initializing (Dead)"));
            break;

        case droneMsgsROS::ProcessState::NotStarted:
            std::cout<<"Process Status: NotStarted"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Not Started"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Not Started (Dead)"));
            break;

        case droneMsgsROS::ProcessState::Recovering:
            std::cout<<"Process Status: Recovering"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering (Dead)"));
            break;

        case droneMsgsROS::ProcessState::Running:
            std::cout<<"Process Status: Running"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Running"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Running (Dead)"));
            break;

        case droneMsgsROS::ProcessState::Sleeping:
            std::cout<<"Process Status: Sleeping"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Sleeping"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Sleeping (Dead)"));
            break;

        case droneMsgsROS::ProcessState::Started:
            std::cout<<"Process Status: Started"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Started"));
            if(!node_container.is_alive){
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Started (Dead)"));
            }
            break;

        case droneMsgsROS::ProcessState::Stopping:
            std::cout<<"Process Status: Stopping"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Stopping"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Stopping (Dead)"));
            break;

        case droneMsgsROS::ProcessState::Waiting:
            std::cout<<"Process Status: Waiting"<<std::endl;
            ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Waiting"));
            if(!node_container.is_alive)
                ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Waiting (Dead)"));
            break;
        }
        if(!node_container.is_alive){
            ui->tableWidget->selectRow(rowProcessViewer);
            ui->tableProcessViewer->setItem(rowProcessViewer,3,new QTableWidgetItem(QString::number(node_container.last_signal.toSec())));
        }
        rowProcessViewer++;
    }

    initializedTable=true;
}

void PerformanceMonitor::onSupervisorStateReceived()
{
    ui->tableWidget->verticalScrollBar()->setSliderPosition( ui->tableWidget->verticalScrollBar()->maximum());

    if (ui->tableWidget->rowCount() < row)
        ui->tableWidget->setRowCount(row);

    ui->tableWidget->insertRow(row);
    QTableWidgetItem *itemMessage = new QTableWidgetItem(node->description);
    QTableWidgetItem *itemProcess = new QTableWidgetItem(node->node_name);
    QTableWidgetItem *itemHostname = new QTableWidgetItem(node->hostname);
    QTableWidgetItem *itemErrorLocation = new QTableWidgetItem(node->location);
    QTableWidgetItem *itemErrorType = new QTableWidgetItem(node->error_type);
    QTableWidgetItem *itemSeverity= new QTableWidgetItem("Fatal");

    ui->tableWidget->setItem(row,0,itemMessage);
    ui->tableWidget->setItem(row,1,itemErrorLocation);
    ui->tableWidget->setItem(row,2,itemErrorType);
    ui->tableWidget->setItem(row,3,itemProcess);
    ui->tableWidget->setItem(row,4,itemHostname);
    ui->tableWidget->setItem(row,5,itemSeverity);
    row++;

    errorCounter++;
}

void PerformanceMonitor::onTextFilterChange(const QString &arg1){
    /*QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->treeWidget->blockSignals(true);
    ui->treeWidget->clear();

    QMapIterator<QString,QStringList> i(processList);
    while (i.hasNext()) {
        i.next();
         qDebug() << ui->treeWidget->isFirstItemColumnSpanned(ui->treeWidget->itemAt(0,0));
        this->addRootTree(i.key(),i.value().filter(regExp), ui->treeWidget);
        qDebug() << "filter data" << i.value().filter(regExp);
    }
    //ui->treeWidget->blockSignals(false);
    qDebug() << "connect";*/
}



PerformanceMonitor::~PerformanceMonitor()
{
    delete ui;
}

/*
void processMonitor::initTree(QMap<QString,QStringList> algorithmsList, QTreeWidget *tree){
    QMapIterator<QString,QStringList> i(algorithmsList);
    while (i.hasNext()) {
        i.next();
        //qDebug() << i.key();
        this->addRootTree(i.key(),i.value(), tree);
    }
}

void processMonitor::addRootTree(QString name, QStringList list, QTreeWidget *tree){
    QTreeWidgetItem  *itm = new QTreeWidgetItem(tree);
    itm->setText(0,name);
    tree->addTopLevelItem(itm);
    addChildTree(itm,list,"");
}

void processMonitor::addChildTree(QTreeWidgetItem *parent,  QStringList list, QString description){

    std::stringstream ss;
    for(int i =0;i<list.size();++i){
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0,list.at(i));
        itm->setText(1,"running");
        if(i==2){
        itm->setText(1,"running");
        pid=pid+3;
        }
        if(i==1){
        itm->setText(1,"recovering");
        pid=pid+1;
        }
        ss << pid;
        itm->setText(2,QString::number(pid));
        if(i%2!=0)
        itm->setText(3,"16:48:02");
        if(i==0)
        itm->setText(3,"16:48:01");
        if(i==2)
        itm->setText(3,"16:48:05");
        parent->addChild(itm);
        pid=pid+23;
    }
}
*/
