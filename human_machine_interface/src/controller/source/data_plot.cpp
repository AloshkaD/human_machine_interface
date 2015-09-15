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
        setTrackerMode(AlwaysOn);
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
    odomReceiver=odometryReceiver;
    connectStatus=false;
    QObject::connect( node, SIGNAL( parameterReceived( )), this, SLOT( onParameterReceived( )));

    dataCount=0;
    posicionBuffer=PLOT_SIZE;
    plotColors <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray" <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray";

    iteratorColors=0;
    stopPressed=false;
    alignScales();
    setAutoReplot(false);

    parameterList = setCurveLabels(*list);
    current_min_limit=0;
    current_max_limit=0;


    // LeftButton for the zooming
    // MidButton for the panning
    // RightButton: zoom out by 1
    // Ctrl+RighButton: zoom out to full size

    QwtPlotZoomer* zoomer = new MyZoomer(canvas());
#if QT_VERSION < 0x040000
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
                            Qt::RightButton, Qt::ControlButton);
#else
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
                            Qt::RightButton, Qt::ControlModifier);
#endif
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
                            Qt::RightButton);

    QwtPlotPanner *panner = new QwtPlotPanner(canvas());
    panner->setAxisEnabled(QwtPlot::yRight, false);
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
    for(unsigned int i = 0; i < parameterList.size(); i = i + 1)
    {
      curves.insert(parameterList.at(i).c_str(),new QwtPlotCurve(parameterList.at(i).c_str()));
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
        QString color= plotColors.at(iteratorColors);
        iteratorColors++;
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
    QIcon whiteIcon(pixmap);
    iconChange.insert(id,2);
    item->setIcon(0, whiteIcon);
}

// Hash colors -> text, color.
// Hash curves -> text, curves.
// Hash iconChange -> text, iconChange. iconChange flags: 0(ChangeWhite),1(ChangeColor),3(notChange)
void DataPlot::clickToPlot(QTreeWidgetItem* item, int colum)
{
    if(colum==0){ // handle only signals in colum 0
        QString text = item->text(colum);
        QString id;
        if(item->parent()!=NULL)
            id = item->parent()->text(0) + "/" + text;
        else
            id=item->text(colum);
        if(!selectedItems.contains(id))// if item is not in checked items.
        {
            selectedItems << id;
            items.insert(id,item);
            iconChange.insert(id,1);
            assignColorIcon(id,item);
        }
        else // if item is in list checked items. detach plot and icon white.
        {
            if(iconChange[id]==3){ //notChange.
                eraseColorIcon(id,item);
                if(curves[id]!=NULL)
                {
                    curves[id]->setVisible(false);
                    selectedItems.removeAll(id);
                    items[id]->setText(1,"");
                }
            }
        }//Restore flags
        iconChange[id]=3;
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
        QwtScaleWidget *scaleWidget = (QwtScaleWidget *)axisWidget(i);
        if ( scaleWidget )
            scaleWidget->setMargin(0);

        QwtScaleDraw *scaleDraw = (QwtScaleDraw *)axisScaleDraw(i);
        if ( scaleDraw )
            scaleDraw->enableComponent(QwtAbstractScaleDraw::Backbone, false);
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
    if(selectedItems.contains(curve_id)&& items[curve_id]!=NULL){
        curves[curve_id]->setPen(QPen(colors[curve_id]));
        curves[curve_id]->setRawSamples(d_x,d_y[curve_id],dataCount);
        curves[curve_id]->attach(this);
        curves[curve_id]->setVisible(true);
         items[curve_id]->setText(1,QString::number(((double)((int)(data_msg*100)))/100));
    }
}

// Read incoming connections
// frecuency < topic rate. 1FPS
void DataPlot::timerEvent(QTimerEvent *e)
{
    if(connectStatus){
    // fill the values.
      for ( int i = dataCount; i > 0; i-- )
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

      this->setDataCurve(param1,parameterList.at(0).c_str(),odomReceiver->DroneControllerPoseMsgs.x);
      this->setDataCurve(param2,parameterList.at(1).c_str(), odomReceiver->DroneControllerPoseMsgs.y);
      this->setDataCurve(param3,parameterList.at(2).c_str(), odomReceiver->DroneControllerPoseMsgs.z);
      this->setDataCurve(param4,parameterList.at(3).c_str(),odomReceiver->DroneControllerPoseMsgs.yaw);
      this->setDataCurve(param5,parameterList.at(4).c_str(),odomReceiver->DroneControllerPoseMsgs.pitch);
      this->setDataCurve(param6,parameterList.at(5).c_str(),odomReceiver->DroneControllerPoseMsgs.roll);
      this->setDataCurve(param7,parameterList.at(6).c_str(), odomReceiver->DroneControllerSpeedsMsgs.dx);
      this->setDataCurve(param8,parameterList.at(7).c_str(),odomReceiver->DroneControllerSpeedsMsgs.dy);
      this->setDataCurve(param9,parameterList.at(8).c_str(),odomReceiver->DroneControllerSpeedsMsgs.dz);
      this->setDataCurve(param10,parameterList.at(9).c_str(),odomReceiver->DroneControllerSpeedsMsgs.dyaw);


      /* Ext.Kallman Filter*/

      this->setDataCurve(param11,parameterList.at(10).c_str(),odomReceiver->DronePoseMsgs.x);
      this->setDataCurve(param12,parameterList.at(11).c_str(), odomReceiver->DronePoseMsgs.y);
      this->setDataCurve(param13,parameterList.at(12).c_str(), odomReceiver->DronePoseMsgs.z);
      this->setDataCurve(param14,parameterList.at(13).c_str(),odomReceiver->DronePoseMsgs.yaw);
      this->setDataCurve(param15,parameterList.at(14).c_str(),odomReceiver->DronePoseMsgs.pitch);
      this->setDataCurve(param16,parameterList.at(15).c_str(),odomReceiver->DronePoseMsgs.roll);
      this->setDataCurve(param17,parameterList.at(16).c_str(), odomReceiver->DroneSpeedsMsgs.dx);
      this->setDataCurve(param18,parameterList.at(17).c_str(),odomReceiver->DroneSpeedsMsgs.dy);
      this->setDataCurve(param19,parameterList.at(18).c_str(),odomReceiver->DroneSpeedsMsgs.dz);
      this->setDataCurve(param20,parameterList.at(19).c_str(),odomReceiver->DroneSpeedsMsgs.dyaw);
      this->setDataCurve(param21,parameterList.at(20).c_str(),odomReceiver->DroneSpeedsMsgs.dpitch);
      this->setDataCurve(param22,parameterList.at(21).c_str(),odomReceiver->DroneSpeedsMsgs.droll);


      /* Telemetry*/

      this->setDataCurve(param23,parameterList.at(22).c_str(),node->rotationAnglesMsgs.vector.z);
      this->setDataCurve(param24,parameterList.at(23).c_str(),node->rotationAnglesMsgs.vector.y);
      this->setDataCurve(param25,parameterList.at(24).c_str(),node->rotationAnglesMsgs.vector.x);
      this->setDataCurve(param26,parameterList.at(25).c_str(),node->imuMsgs.angular_velocity.x);
      this->setDataCurve(param27,parameterList.at(26).c_str(),node->imuMsgs.angular_velocity.y);
      this->setDataCurve(param28,parameterList.at(27).c_str(),node->imuMsgs.angular_velocity.z);
      this->setDataCurve(param29,parameterList.at(28).c_str(),node->imuMsgs.linear_acceleration.x);
      this->setDataCurve(param30,parameterList.at(29).c_str(),node->imuMsgs.linear_acceleration.y);
      this->setDataCurve(param31,parameterList.at(30).c_str(),node->imuMsgs.linear_acceleration.z);
      this->setDataCurve(param32,parameterList.at(31).c_str(),node->imuMsgs.orientation.x);
      this->setDataCurve(param33,parameterList.at(32).c_str(),node->imuMsgs.orientation.y);
      this->setDataCurve(param34,parameterList.at(33).c_str(),node->imuMsgs.orientation.z);
      this->setDataCurve(param35,parameterList.at(34).c_str(),node->imuMsgs.orientation.w);
      this->setDataCurve(param36,parameterList.at(35).c_str(),node->altitudeMsgs.altitude);
      this->setDataCurve(param37,parameterList.at(36).c_str(),node->altitudeMsgs.altitude_speed);
      this->setDataCurve(param38,parameterList.at(37).c_str(),node->magnetometerMsgs.vector.x);
      this->setDataCurve(param39,parameterList.at(38).c_str(),node->magnetometerMsgs.vector.y);
      this->setDataCurve(param40,parameterList.at(39).c_str(),node->magnetometerMsgs.vector.z);
      this->setDataCurve(param41,parameterList.at(40).c_str(),node->groundSpeedMsgs.vector.x);
      this->setDataCurve(param42,parameterList.at(41).c_str(),node->groundSpeedMsgs.vector.y);
      this->setDataCurve(param43,parameterList.at(42).c_str(),node->temperature.temperature);
      this->setDataCurve(param44,parameterList.at(43).c_str(),node->fluidPressure.fluid_pressure);


     }
      for ( int j = 0; j < PLOT_SIZE; j++ )
          d_x[j]++;

      setAxisScale(QwtPlot::xBottom,
                   d_x[PLOT_SIZE - 1],d_x[0]);

      if(dataCount<PLOT_SIZE)
          dataCount++;

      if(!stopPressed)
          replot();// Update the plot 1fps

}

// Read incoming connections
// Change the text. frecuency = topic rate
void DataPlot::onParameterReceived()
{
    connectStatus=true;
    initAxisX();
    initAxisY();
    initCurves();
    setTimerInterval(1000);// 1 second = 1000
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
}
