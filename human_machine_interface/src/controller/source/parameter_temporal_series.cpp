/*
  2D Parameter temporal series window
  Plotting of odometer parameters selected in real time.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

#include "../include/parameter_temporal_series.h"
#include "../.././../../../hmi_cvg_stack-build/human_machine_interface/ui_parametertemporalseries.h"


#include <qwt/qwt.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <cmath>

#include <qt4/Qt/qlabel.h>
#include <qt4/Qt/qlayout.h>
#include <qt4/Qt/qdockwidget.h>
#include <qt4/Qt/qwidget.h>
#include <qt4/Qt/qcheckbox.h>
#include <qt4/Qt/qvariant.h>
#include <list>
#include <qt4/Qt/qmap.h>
#include <qt4/Qt/qiterator.h> //QMapIterator>
#include <qt4/Qt/qregexp.h>
#include <qt4/Qt/qtreewidget.h>  //QTreeWidget>


ParameterTemporalSeries::ParameterTemporalSeries(QWidget *parent, TelemetryStateReceiver* telemetry_receiver,OdometryStateReceiver* odometry_receiver):
    QWidget(parent),
    ui(new Ui::parameterTemporalSeries)
{
    ui->setupUi(this);
    telem_receiver=telemetry_receiver;
    odometry=odometry_receiver;

    // ESTRUCTURA DE VISUALIZACIÓN
    telemetry << "yaw" << "pitch" << "roll"  << "IMU.angular.vel.x"  << "IMU.angular.vel.y"  << "IMU.angular.vel.z"  << "IMU.accel.x"  << "IMU.accel.y"   << "IMU.accel.z" << "IMU.roll" << "IMU.pitch" << "IMU.yaw" << "IMU.yawPitch" << "altitude" << "altitudeSpeed" <<  "mag.X"<< "mag.Y"<< "mag.Z" << "groundSpeed.X"<< "groundSpeed.Y"<<"temperature"<<"pressure";
    controller << "xci" << "yci" << "zci" << "yawci" << "pitchci" << "rollci" << "vxfi" << "vyfi"<< "vzfi" << "dyawfi";
    ekf << "pos.x" << "pos.y" << "pos.z" << "yaw" << "pitch" << "roll" << "dx" << "dy" << "dz" << "dyaw" << "dpitch" << "droll";

    parameters.insert("Telemetry",telemetry);//pos1
    parameters.insert("Ext.Kallman Filter",ekf);//pos3
    parameters.insert("Controller",controller);//pos2

    plot = new DataPlot(ui->plot_widget,telem_receiver,odometry,&parameters);

    ui->plot_widget->resize(1200,430);

    printf ("height: %d \n",ui->plot_widget->size().height());
    printf ("width: %d \n",ui->plot_widget->size().width());
    plot->setCanvasBackground(QBrush(Qt::white));

    this->initTree(parameters,ui->tree_widget);

    setSignalHandlers();

    updateParametersValue();

}

void ParameterTemporalSeries::setSignalHandlers()
{
    connect(ui->tree_widget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),plot,SLOT(clickToPlot(QTreeWidgetItem*, int)));
    connect(ui->spin_box_min_axis, SIGNAL(valueChanged(int)),plot, SLOT(resizeAxisYMinLimit(int)) );
    connect(ui->spin_box_max_axis, SIGNAL(valueChanged(int)),plot, SLOT(resizeAxisYMaxLimit(int)) );
    connect(ui->save_plot_button, SIGNAL(clicked()),plot, SLOT(saveAsSVG()) );
    connect(telem_receiver, SIGNAL( parameterReceived( )), this, SLOT(updateParametersValue( )));
    //  connect(ui->lineEdit,SIGNAL(textChanged(QString)),
    //         this, SLOT(onTextFilterChange(QString)));
    //connect(ui->checkBox_4,SIGNAL(clicked(bool)),this, SLOT(onShowUnits(bool)));
    connect(ui->stop_button,SIGNAL(clicked()),this, SLOT(onStopButton()));
}

void ParameterTemporalSeries::resizeEvent(QResizeEvent * event)
{
    plot->resize(ui->plot_widget->size());
}

void ParameterTemporalSeries::initParameterList(QStringList list, QTreeWidget *tree){

    ui->tree_widget->setIndentation(15);
    for(int i =0;i<list.size();++i){
        QTreeWidgetItem  *itm = new QTreeWidgetItem(ui->tree_widget);
        QPixmap pixmap(15,40);
        pixmap.fill(QColor("white"));
        QIcon red_icon(pixmap);
        itm->setIcon(0, red_icon);
        itm->setText(0,list.at(i));
        itm->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );
        itm->setCheckState(0,Qt::Unchecked);
        ui->tree_widget->addTopLevelItem(itm);
    }
}


void ParameterTemporalSeries::initTree(QMap<QString,QStringList> topic_list, QTreeWidget *tree){
    QMapIterator<QString,QStringList> i(topic_list);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key();
        this->addRootTree(i.key(),i.value(), tree);
    }
}

void ParameterTemporalSeries::addRootTree(QString name, QStringList list, QTreeWidget *tree){
    QTreeWidgetItem  *itm = new QTreeWidgetItem(tree);
    itm->setText(0,name);
    tree->addTopLevelItem(itm);
    tree->setIndentation(15);
    addChildTree(itm,list,"");

}

void ParameterTemporalSeries::addChildTree(QTreeWidgetItem *parent,  QStringList list, QString description)
{
    for(int i =0;i<list.size();++i){
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        QPixmap pixmap(15,40);
        pixmap.fill(QColor("white"));
        QIcon red_icon(pixmap);
        itm->setIcon(0, red_icon);
        itm->setText(0,list.at(i));
        itm->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );
        itm->setCheckState(0,Qt::Unchecked);
        parent->addChild(itm);
    }
}

void ParameterTemporalSeries::onTextFilterChange(const QString &arg1){
    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->tree_widget->blockSignals(true);
    ui->tree_widget->clear();

    QMapIterator<QString,QStringList> i(parameters);
    while (i.hasNext()) {
        i.next();
        qDebug() << ui->tree_widget->isFirstItemColumnSpanned(ui->tree_widget->itemAt(0,0));
        this->addRootTree(i.key(),i.value().filter(regExp), ui->tree_widget);
        qDebug() << "filter data" << i.value().filter(regExp);
    }
    //ui->treeWidget->blockSignals(false);
    qDebug() << "connect";
}

void ParameterTemporalSeries::onShowUnits(bool click){
    QStringList headers;
    if(click){
        headers << "Parameters" << "Value" << "Unit";
        QMapIterator<QString,QStringList> i(parameters);
        QStringList list;
        while (i.hasNext()) {
            i.next();
            list=i.value();
            QString itemName;
            for(int j =0;j<list.size();++j){
                itemName=i.key() + "/" + list.at(j);
                if(plot->selected_items.contains(itemName)){
                    QTreeWidgetItem* itemList = plot->items[itemName];
                    itemList->setText(2,"float");
                }
            }
        }
        ui->tree_widget->setColumnCount(3);
    }else{
        headers << "Parameters" << "Value";
        ui->tree_widget->setColumnCount(2);
    }
    ui->tree_widget->setHeaderLabels(headers);
}


void ParameterTemporalSeries::onStopButton(){
    if(plot->is_stop_pressed)
        plot->is_stop_pressed = false;
    else
        plot->is_stop_pressed = true;
}


void ParameterTemporalSeries::updateParametersValue(){
    QTreeWidgetItem * EKF = ui->tree_widget->topLevelItem(1);
    QTreeWidgetItem * telemetryItem =ui->tree_widget->topLevelItem(2);
    QTreeWidgetItem * controllerItem=ui->tree_widget->topLevelItem(0);


    controllerItem->child(0)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.x*100)))/100)+ "  m"); //xci
    controllerItem->child(1)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.y*100)))/100)+ "  m"); //yci
    controllerItem->child(2)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.z*100)))/100)+ "  m"); //zci
    controllerItem->child(3)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.yaw*100)))/100)+ "  deg"); //yawci
    controllerItem->child(4)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.pitch*100)))/100)+ "  deg"); //pitchci
    controllerItem->child(5)->setText(1,QString::number(((double)((int)(odometry->DroneControllerPoseMsgs.roll*100)))/100)+ "  deg"); //rollci
    controllerItem->child(6)->setText(1,QString::number(((double)((int)(odometry->DroneControllerSpeedsMsgs.dx*100)))/100)+ "  m/s"); //vxci
    controllerItem->child(7)->setText(1,QString::number(((double)((int)(odometry->DroneControllerSpeedsMsgs.dy)))/100)+ "  m/s"); //vyci
    controllerItem->child(8)->setText(1,QString::number(((double)((int)(odometry->DroneControllerSpeedsMsgs.dz)))/100)+ "  m/s"); //vzci
    controllerItem->child(9)->setText(1,QString::number(((double)((int)(odometry->DroneControllerSpeedsMsgs.dyaw)))/100)+ "  m/s"); //dyawfi

    EKF->child(0)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.x*100)))/100) + "  m"); //x
    EKF->child(1)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.y*100)))/100) + "  m"); //y
    EKF->child(2)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.z*100)))/100) + "  m"); //z
    EKF->child(3)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.yaw*100)))/100) + "  deg"); //yaw
    EKF->child(4)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.pitch*100)))/100) + "  deg"); //pitch
    EKF->child(5)->setText(1,QString::number(((double)((int)(odometry->drone_pose_msgs.roll*100)))/100) + "  deg"); //roll
    EKF->child(6)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.dx*100)))/100) + "  m/s"); //dx
    EKF->child(7)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.dy*100)))/100) + "  m/s"); //dy
    EKF->child(8)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.dz*100)))/100) + "  m/s"); //dz
    EKF->child(9)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.dyaw*100)))/100) + "  m/s"); //dyaw
    EKF->child(10)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.dpitch*100)))/100) + "  m/s"); //dpitch
    EKF->child(11)->setText(1,QString::number(((double)((int)(odometry->DroneSpeedsMsgs.droll*100)))/100) + "  m/s");  //droll


    telemetryItem->child(0)->setText(1,QString::number(((double)((int)(telem_receiver->rotation_angles_msgs.vector.z*100)))/100) + "  deg");//yaw
    telemetryItem->child(1)->setText(1,QString::number(((double)((int)(telem_receiver->rotation_angles_msgs.vector.y*100)))/100) + "  deg");//pitch
    telemetryItem->child(2)->setText(1,QString::number(((double)((int)(telem_receiver->rotation_angles_msgs.vector.x*100)))/100) + "  deg");//roll
    telemetryItem->child(3)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.angular_velocity.x*100)))/100)  + "  m/s");//IMU angular vel.x
    telemetryItem->child(4)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.angular_velocity.y*100)))/100)  + "  m/s");//IMU angular vel.y
    telemetryItem->child(5)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.angular_velocity.z*100)))/100)  + "  m/s");//IMU angular vel.z
    telemetryItem->child(6)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.linear_acceleration.x*100)))/100) + "  deg");//IMU accel.x
    telemetryItem->child(7)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.linear_acceleration.y*100)))/100) + "  deg");//IMU accel.y
    telemetryItem->child(8)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.linear_acceleration.z*100)))/100) + "  deg");//IMU accel.z
    telemetryItem->child(9)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.orientation.x*100)))/100) + "  deg");//IMU roll
    telemetryItem->child(10)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.orientation.y*100)))/100) + "  deg");//IMU pitch
    telemetryItem->child(11)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.orientation.z*100)))/100) + "  deg");//IMU yaw
    telemetryItem->child(12)->setText(1,QString::number(((double)((int)(telem_receiver->imu_msgs.orientation.w*100)))/100) + "  deg");//IMU yawPitch
    telemetryItem->child(13)->setText(1,QString::number(((double)((int)(telem_receiver->altitude_msgs.altitude*100)))/100) + "  m");//altitude
    telemetryItem->child(14)->setText(1,QString::number(((double)((int)(telem_receiver->altitude_msgs.altitude_speed*100)))/100) + "  m/s");//altitudeSpeed
    telemetryItem->child(15)->setText(1,QString::number(((double)((int)(telem_receiver->magnetometer_msgs.vector.x*100)))/100));//mag.X
    telemetryItem->child(16)->setText(1,QString::number(((double)((int)(telem_receiver->magnetometer_msgs.vector.y*100)))/100));//mag.Y
    telemetryItem->child(17)->setText(1,QString::number(((double)((int)(telem_receiver->magnetometer_msgs.vector.z*100)))/100));//mag.Z
    telemetryItem->child(18)->setText(1,QString::number(((double)((int)(telem_receiver->ground_speed_msgs.vector.x*100)))/100) + "  m/s");//groundSpeed.x
    telemetryItem->child(19)->setText(1,QString::number(((double)((int)(telem_receiver->ground_speed_msgs.vector.y*100)))/100) + "  m/s");//groundSpeed.y
    telemetryItem->child(20)->setText(1,QString::number(((double)((int)(telem_receiver->temperature.temperature*100)))/100)+ " deg");//temperature
    telemetryItem->child(21)->setText(1,QString::number(((double)((int)(telem_receiver->fluid_pressure.fluid_pressure*100)))/100) + " Pa");//fluidPressure
}


ParameterTemporalSeries::~ParameterTemporalSeries()
{
    delete ui;
}

