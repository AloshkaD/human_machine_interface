/*
  Reads data to draw curves in parameter view canvas
  @author  Yolanda de la Hoz Simón
  @date    04-2015
  @version 2.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include <stdlib.h>
#include <ctime>
#include <qt4/QtGui/QPrintDialog>
#include <qt4/QtGui/QPrinter>
#include <qwt/qwt_plot_renderer.h>
#include <qwt/qwt_plot_grid.h>
#include <qwt/qwt_legend.h>
#include <qwt/qwt_scale_draw.h>
#include <qwt/qwt_picker.h>
#include <qwt/qwt_math.h>
#include <qwt/qwt_scale_widget.h>
#include <qwt/qwt_scale_draw.h>
#include <qwt/qwt_plot_zoomer.h>
#include <qwt/qwt_plot_panner.h>
#include <qwt/qwt_plot_layout.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include "../include/data_plot.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

class MyZoomer: public QwtPlotZoomer
{
public:
    MyZoomer(QwtPlotCanvas *canvas):
        QwtPlotZoomer(canvas)
    {
        setTrackerMode(AlwaysOff);
    }
};


class TimeScaleDraw: public QwtScaleDraw
{
public:
    TimeScaleDraw(const QTime &base):
        baseTime(base)
    {
    }
    virtual QwtText label(double v) const
    {
        QTime upTime = baseTime.addSecs((int)v);
        return upTime.toString();

    }
private:
    QTime baseTime;
};




DataPlot::DataPlot(QWidget *parent, TelemetryStateReceiver* collector, OdometryStateReceiver* odometryReceiver,QMap<QString, QStringList> *list) :
    QwtPlot(parent),
    d_interval(0),
    d_timerId(-1)
{
    node=collector;
    odom_receiver=odometryReceiver;
    connect_status=false;
    QObject::connect( node, SIGNAL( parameterReceived( )), this, SLOT( onParameterReceived( )));

    data_count=0;
    posicionBuffer=PLOT_SIZE;
    colors_list <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray";

    iterator_colors=0;
    is_stop_pressed=false;
    alignScales();
    setAutoReplot(false);

    parameters_list = setCurveLabels(*list);
    current_min_limit=0;
    current_max_limit=0;


    QwtPlotZoomer* zoomer = new MyZoomer(canvas());


    QwtPlotPanner *panner = new QwtPlotPanner(canvas());
    panner->setAxisEnabled(QwtPlot::yRight, true);
    panner->setMouseButton(Qt::MidButton);

    // Avoid jumping when labels with more/less digits
    // appear/disappear when scrolling vertically
    const QFontMetrics fm(axisWidget(QwtPlot::yLeft)->font());
    QwtScaleDraw *sd = axisScaleDraw(QwtPlot::yLeft);
    sd->setMinimumExtent( fm.width("100.00") );

    const QColor c(Qt::darkBlue);
    zoomer->setRubberBandPen(c);
    zoomer->setTrackerPen(c);

    setGridPlot();
    initTimeData();

#if 0
    //  Insert zero line at y = 0
    QwtPlotMarker *mY = new QwtPlotMarker();
    mY->setLabelAlignment(Qt::AlignRight|Qt::AlignTop);
    mY->setLineStyle(QwtPlotMarker::HLine);
    mY->setYValue(0.0);
    mY->attach(this);
#endif

    initAxisX();
    initAxisY();
    initCurves();

    setTimerInterval(1000);// 1 second = 1000
}


std::vector<std::string> DataPlot::setCurveLabels(QMap<QString, QStringList> list)
{
    std::vector<std::string> labels;
    QMapIterator<QString,QStringList> iterator(list);
    while (iterator.hasNext())
    {
        iterator.next();
        for(int j =0;j<iterator.value().size();++j)
        {
           labels.push_back(iterator.key().toStdString() + "/" + iterator.value().at(j).toStdString());
        }
    }
   return labels;
}


// Init X axis.
void DataPlot::setGridPlot()
{
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(this);
}


void DataPlot::initTimeData()
{
    //  Initialize data
    for (int i = 0; i< PLOT_SIZE; i++)
    {
        d_x[PLOT_SIZE- 1 - i] = i;// time axis
    }
}


// Init X axis.
void DataPlot::initAxisX()
{
    //QwtText xTitle("System Uptime [h:m:s]");
    //xTitle.setFont(QFont("Ubuntu", 10));
    //setAxisTitle(QwtPlot::xBottom, xTitle);
    setAxisScaleDraw(QwtPlot::xBottom,new TimeScaleDraw(upTime()));
    setAxisScale(QwtPlot::xBottom, 0, PLOT_SIZE );
    setAxisLabelRotation(QwtPlot::xBottom, -50.0);
    setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
    QwtScaleWidget *scaleWidget = axisWidget(QwtPlot::xBottom);
    const int fmh = QFontMetrics(scaleWidget->font()).height();
    scaleWidget->setMinBorderDist(0, fmh / 2);
}


// Init Y axis.
void DataPlot::initAxisY()
{
    //QwtText yTitle("Values");
    //yTitle.setFont(QFont("Ubuntu", 10));
    //etAxisTitle(QwtPlot::yLeft,yTitle);
    setAxisScale(QwtPlot::yLeft, -20, 20);
}


void DataPlot::initCurves()
{
    for(unsigned int i = 0; i < parameters_list.size(); i = i + 1)
    {
      curves.insert(parameters_list.at(i).c_str(),new QwtPlotCurve(parameters_list.at(i).c_str()));
    }

}


QTime DataPlot::upTime() const
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    int time = hour*3600+min*60+sec-60;
    QTime t;
    t = t.addSecs(time);
    return t;
}


// Params: item identifier and treeWidgetItem structure
// assign the color to the Hash structure
void DataPlot::assignColorIcon(QString id,QTreeWidgetItem* item)
{
    QPixmap pixmap(15,40);
    if(colors[id]==NULL)
    {
        QString color= colors_list.at(iterator_colors);
        iterator_colors++;
        colors.insert(id,color);
    }
    pixmap.fill(QColor(colors[id]));
    QIcon icon(pixmap);
    item->setIcon(0, icon);
}

// Params: item identifier and treeWidgetItem structure
// erase the color to the Hash structure
void DataPlot::eraseColorIcon(QString id,QTreeWidgetItem* item)
{
    QPixmap pixmap(15,40);
    pixmap.fill(QColor("white"));
    QIcon white_icon(pixmap);
    list_colors_icon.insert(id,2);
    item->setIcon(0, white_icon);
}

// Hash colors -> text, color.
// Hash curves -> text, curves.
// Hash iconChange -> text, iconChange. iconChange flags: 0(ChangeWhite),1(ChangeColor),3(notChange)
void DataPlot::clickToPlot(QTreeWidgetItem* item, int colum)
{
    if(colum==0){ // handle only signals in colum 0
        QString id;
        QString text = item->text(colum);
        if(item->parent()!=NULL)
            id = item->parent()->text(0) + "/" + text;
        else
            id=item->text(colum);
        if(!selected_items.contains(id))// if item is not in checked items.
        {
            selected_items << id;
            items.insert(id,item);
            list_colors_icon.insert(id,1);
            assignColorIcon(id,item);
        }
        else // if item is in list checked items. detach plot and icon white.
        {
            if(list_colors_icon[id]==3){ //notChange.
                eraseColorIcon(id,item);
                if(curves[id]!=NULL)
                {
                    curves[id]->setVisible(false);
                    selected_items.removeAll(id);
                    items[id]->setText(1,"");
                }
            }
        }//Restore flags
        list_colors_icon[id]=3;
    }
}

//
//  Set a plain canvas frame and align the scales to it
//
void DataPlot::alignScales()
{

    canvas()->setFrameStyle(QFrame::Box | QFrame::Plain );
    canvas()->setLineWidth(1);

    for ( int i = 0; i < QwtPlot::axisCnt; i++ )
    {
        QwtScaleWidget *scale_widget = (QwtScaleWidget *)axisWidget(i);
        if ( scale_widget )
            scale_widget->setMargin(0);

        QwtScaleDraw *scale_draw = (QwtScaleDraw *)axisScaleDraw(i);
        if ( scale_draw )
            scale_draw->enableComponent(QwtAbstractScaleDraw::Backbone, false);
    }
}

// Set Timer interval to receive incoming connections
void DataPlot::setTimerInterval(double ms)
{
    d_interval = qRound(ms);

    if ( d_timerId >= 0 )
    {
        killTimer(d_timerId);
        d_timerId = -1;
    }
    if (d_interval >= 0 )
        d_timerId = startTimer(d_interval);
}

// TODO> Checking if is NULL when user select
void DataPlot::setDataCurve(double param[], QString curve_id, double data_msg)
{
    param[0] = data_msg;
    d_y.insert(curve_id,param);
    if(selected_items.contains(curve_id)&& items[curve_id]!=NULL){
        curves[curve_id]->setPen(QPen(colors[curve_id]));
        curves[curve_id]->setRawSamples(d_x,d_y[curve_id],data_count);
        curves[curve_id]->attach(this);
        curves[curve_id]->setVisible(true);
         items[curve_id]->setText(1,QString::number(((double)((int)(data_msg*100)))/100));
    }
}

// Read incoming connections
// frecuency < topic rate. 1FPS
void DataPlot::timerEvent(QTimerEvent *e)
{
    if(connect_status){
    // fill the values.
      for ( int i = data_count; i > 0; i-- )
      {
          param1[i] = param1[i-1];
          param2[i] = param2[i-1];
          param3[i] = param3[i-1];
          param4[i] = param4[i-1];
          param5[i] = param5[i-1];
          param6[i] = param6[i-1];
          param7[i] = param7[i-1];
          param8[i] = param8[i-1];
          param9[i] = param9[i-1];
          param10[i] = param10[i-1];
          param11[i] = param11[i-1];
          param12[i] = param12[i-1];
          param13[i] = param13[i-1];
          param14[i] = param14[i-1];
          param15[i] = param15[i-1];
          param16[i] = param16[i-1];
          param17[i] = param17[i-1];
          param18[i] = param18[i-1];
          param19[i] = param19[i-1];
          param20[i] = param20[i-1];
          param21[i] = param21[i-1];
          param22[i] = param22[i-1];
          param23[i] = param23[i-1];
          param24[i] = param24[i-1];
          param25[i] = param25[i-1];
          param26[i] = param26[i-1];
          param27[i] = param27[i-1];
          param28[i] = param28[i-1];
          param29[i] = param29[i-1];
          param30[i] = param30[i-1];
          param31[i] = param31[i-1];
          param32[i] = param32[i-1];
          param33[i] = param33[i-1];
          param34[i] = param34[i-1];
          param35[i] = param35[i-1];
          param36[i] = param36[i-1];
          param37[i] = param37[i-1];
          param38[i] = param38[i-1];
          param39[i] = param39[i-1];
          param40[i] = param40[i-1];
          param41[i] = param41[i-1];
          param42[i] = param42[i-1];
          param43[i] = param43[i-1];
          param44[i] = param44[i-1];
      }

      /* Controller*/

      this->setDataCurve(param1,parameters_list.at(0).c_str(),odom_receiver->drone_controller_pose_msgs.x);
      this->setDataCurve(param2,parameters_list.at(1).c_str(), odom_receiver->drone_controller_pose_msgs.y);
      this->setDataCurve(param3,parameters_list.at(2).c_str(), odom_receiver->drone_controller_pose_msgs.z);
      this->setDataCurve(param4,parameters_list.at(3).c_str(),odom_receiver->drone_controller_pose_msgs.yaw);
      this->setDataCurve(param5,parameters_list.at(4).c_str(),odom_receiver->drone_controller_pose_msgs.pitch);
      this->setDataCurve(param6,parameters_list.at(5).c_str(),odom_receiver->drone_controller_pose_msgs.roll);
      this->setDataCurve(param7,parameters_list.at(6).c_str(), odom_receiver->drone_controller_speeds_msgs.dx);
      this->setDataCurve(param8,parameters_list.at(7).c_str(),odom_receiver->drone_controller_speeds_msgs.dy);
      this->setDataCurve(param9,parameters_list.at(8).c_str(),odom_receiver->drone_controller_speeds_msgs.dz);
      this->setDataCurve(param10,parameters_list.at(9).c_str(),odom_receiver->drone_controller_speeds_msgs.dyaw);


      /* Ext.Kallman Filter*/

      this->setDataCurve(param11,parameters_list.at(10).c_str(),odom_receiver->drone_pose_msgs.x);
      this->setDataCurve(param12,parameters_list.at(11).c_str(), odom_receiver->drone_pose_msgs.y);
      this->setDataCurve(param13,parameters_list.at(12).c_str(), odom_receiver->drone_pose_msgs.z);
      this->setDataCurve(param14,parameters_list.at(13).c_str(),odom_receiver->drone_pose_msgs.yaw);
      this->setDataCurve(param15,parameters_list.at(14).c_str(),odom_receiver->drone_pose_msgs.pitch);
      this->setDataCurve(param16,parameters_list.at(15).c_str(),odom_receiver->drone_pose_msgs.roll);
      this->setDataCurve(param17,parameters_list.at(16).c_str(), odom_receiver->drone_speeds_msgs.dx);
      this->setDataCurve(param18,parameters_list.at(17).c_str(),odom_receiver->drone_speeds_msgs.dy);
      this->setDataCurve(param19,parameters_list.at(18).c_str(),odom_receiver->drone_speeds_msgs.dz);
      this->setDataCurve(param20,parameters_list.at(19).c_str(),odom_receiver->drone_speeds_msgs.dyaw);
      this->setDataCurve(param21,parameters_list.at(20).c_str(),odom_receiver->drone_speeds_msgs.dpitch);
      this->setDataCurve(param22,parameters_list.at(21).c_str(),odom_receiver->drone_speeds_msgs.droll);


      /* Telemetry*/

      this->setDataCurve(param23,parameters_list.at(22).c_str(),node->rotation_angles_msgs.vector.z);
      this->setDataCurve(param24,parameters_list.at(23).c_str(),node->rotation_angles_msgs.vector.y);
      this->setDataCurve(param25,parameters_list.at(24).c_str(),node->rotation_angles_msgs.vector.x);
      this->setDataCurve(param26,parameters_list.at(25).c_str(),node->imu_msgs.angular_velocity.x);
      this->setDataCurve(param27,parameters_list.at(26).c_str(),node->imu_msgs.angular_velocity.y);
      this->setDataCurve(param28,parameters_list.at(27).c_str(),node->imu_msgs.angular_velocity.z);
      this->setDataCurve(param29,parameters_list.at(28).c_str(),node->imu_msgs.linear_acceleration.x);
      this->setDataCurve(param30,parameters_list.at(29).c_str(),node->imu_msgs.linear_acceleration.y);
      this->setDataCurve(param31,parameters_list.at(30).c_str(),node->imu_msgs.linear_acceleration.z);
      this->setDataCurve(param32,parameters_list.at(31).c_str(),node->imu_msgs.orientation.x);
      this->setDataCurve(param33,parameters_list.at(32).c_str(),node->imu_msgs.orientation.y);
      this->setDataCurve(param34,parameters_list.at(33).c_str(),node->imu_msgs.orientation.z);
      this->setDataCurve(param35,parameters_list.at(34).c_str(),node->imu_msgs.orientation.w);
      this->setDataCurve(param36,parameters_list.at(35).c_str(),(-1)*node->altitude_msgs.altitude);
      this->setDataCurve(param37,parameters_list.at(36).c_str(),node->altitude_msgs.altitude_speed);
      this->setDataCurve(param38,parameters_list.at(37).c_str(),node->magnetometer_msgs.vector.x);
      this->setDataCurve(param39,parameters_list.at(38).c_str(),node->magnetometer_msgs.vector.y);
      this->setDataCurve(param40,parameters_list.at(39).c_str(),node->magnetometer_msgs.vector.z);
      this->setDataCurve(param41,parameters_list.at(40).c_str(),node->ground_speed_msgs.vector.x);
      this->setDataCurve(param42,parameters_list.at(41).c_str(),node->ground_speed_msgs.vector.y);
      this->setDataCurve(param43,parameters_list.at(42).c_str(),node->temperature.temperature);
      this->setDataCurve(param44,parameters_list.at(43).c_str(),node->fluid_pressure.fluid_pressure);


     }
      for ( int j = 0; j < PLOT_SIZE; j++ )
          d_x[j]++;

      setAxisScale(QwtPlot::xBottom,
                   d_x[PLOT_SIZE - 1],d_x[0]);

      if(data_count<PLOT_SIZE)
          data_count++;

      if(!is_stop_pressed)
          replot();// Update the plot 1fps

}

// Read incoming connections
// Change the text. frecuency = topic rate
void DataPlot::onParameterReceived()
{
    connect_status=true;

}

void DataPlot::resizeAxisXScale(int ms)
{
    setAxisScale(QwtPlot::xBottom, 0, ms);
    replot();
}

void DataPlot::resizeAxisYMinLimit(int ms)
{
    current_min_limit=ms;
    setAxisScale(QwtPlot::yLeft, current_min_limit,current_max_limit);
    replot();
}

void DataPlot::resizeAxisYMaxLimit(int ms)
{
    current_max_limit=ms;
    setAxisScale(QwtPlot::yLeft,current_min_limit,current_max_limit);
    replot();
}

// Get canvas and print in the output file
void DataPlot::saveAsSVG()
{
    Q_EMIT disconnectUpdateDynamicsView();
#if 1
    QPrinter printer;
#else
    QPrinter printer(QPrinter::HighResolution);
#endif
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("iarc_simulation01.pdf");
    QPrintDialog dialog(&printer);
    if ( dialog.exec() )
    {
        QwtPlotRenderer renderer;

        renderer.setDiscardFlag(QwtPlotRenderer::DiscardBackground, false);
        renderer.setLayoutFlag(QwtPlotRenderer::KeepFrames, true);

        renderer.renderTo(this, printer);
    }
    Q_EMIT connectUpdateDynamicsView();
}
