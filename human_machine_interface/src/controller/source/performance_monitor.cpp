/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/process_monitor.h"
#include "../../view/ui_processmonitor.h"
#include <QDebug>
#include <QScrollBar>
#include <string>
#include <sstream>
#include <QMenu>
/*****************************************************************************
** Implementation
*****************************************************************************/

ProcessMonitor::ProcessMonitor(QWidget *parent, RosGraphReceiver *collector) :
    QWidget(parent),
    ui(new Ui::processMonitor)
{
    ui->setupUi(this);
    node=collector;
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
void processMonitor::onCustomContextMenuRequested(const QPoint& pos) {
    QTreeWidgetItem* item = ui->treeWidget->itemAt(pos);
    qDebug() << item->text(0);
    if (item) {
        // Note: We must map the point to global from the viewport to
        // account for the header.
        showContextMenu(item, ui->treeWidget->viewport()->mapToGlobal(pos));
    }
}

void processMonitor::showContextMenu(QTreeWidgetItem* item, const QPoint& globalPos) {
    QMenu menu;
    menu.addAction("Stop");
    menu.addAction("Start");
    menu.addAction("Record");
    menu.exec(globalPos);
}*/

void ProcessMonitor::initProcessViewerTable()
{
    int rowProcessViewer=0;

    // Recorrer la lista para crear los items de la tabla

    for(unsigned int i = 0; i < node->listProcessState.process_list.size(); i = i + 1)
    {
     node_container= node->listProcessState.process_list.at(i);


     if(!initializedTable){
     if (ui->tableProcessViewer->rowCount() < rowProcessViewer)
        ui->tableProcessViewer->setRowCount(rowProcessViewer);
     ui->tableProcessViewer->insertRow(rowProcessViewer);
     }
     ui->tableProcessViewer->setItem(rowProcessViewer,0,new QTableWidgetItem(QString(node_container.name.c_str())));
     if(1==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Initializing"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Initializing - Dead"));
     }

     if(8==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Not Started"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Not Started - Dead"));
     }

     if(6==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering - Dead"));
     }

     if(3==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Sleeping"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Recovering - Dead"));
     }

     if(2==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Running"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Running - Dead"));
     }

     if(7==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Started"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Started - Dead"));
     }

     if(5==node_container.current_state.state){
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Stopping"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Stopping - Dead"));
     }

     if(4==node_container.current_state.state){
      ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Waiting"));
     if(!node_container.is_alive)
     ui->tableProcessViewer->setItem(rowProcessViewer,1,new QTableWidgetItem("Waiting - Dead"));
     }

     rowProcessViewer++;
     }

     initializedTable=true;
}

void ProcessMonitor::onSupervisorStateReceived()
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
}

/*
//TODO
void processMonitor::filterTableInfo()
{

}

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

void processMonitor::onTextFilterChange(const QString &arg1){
    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
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
    qDebug() << "connect";
}*/

ProcessMonitor::~ProcessMonitor()
{
    delete ui;
}
