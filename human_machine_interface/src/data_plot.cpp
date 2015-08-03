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
#include "../include/human_machine_interface/data_plot.h"

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

DataPlot::DataPlot(QWidget *parent, telemetryStateReceiver* collector, odometryStateReceiver* odometryReceiver,QMap<QString, QStringList> *list):QwtPlot(parent),d_interval(0),d_timerId(-1)
{
    node=collector;
    odomReceiver=odometryReceiver;
    connectStatus=false;
    QObject::connect( node, SIGNAL( parameterReceived( )), this, SLOT( onParameterReceived( )));

    dataCount=0;
    posicionBuffer=PLOT_SIZE;
    plotColors <<"red"<<"blue"<<"green"<<"black"<<"yellow"<<"magenta"<<"cyan"<<"gray"<<"darkCyan"<<"darkMagenta"<<"darkYellow"<<"darkGray"<<"darkRed"<<"darkBlue"<<"darkGreen"<<"lightGray";

    iteratorColors=0;
    highRateOption = false;
    stopPressed=false;
    alignScales();
    setAutoReplot(false);

    parameterList=list;

    TelposYaw ="Telemetry/yaw";
    TelposPitch ="Telemetry/pitch";
    TelposRoll ="Telemetry/roll";
    Telaltitude="Telemetry/altitude";
    TelaltitudeSpeed="Telemetry/altitudeSpeed";
    TelgroundSpeedX="Telemetry/groundSpeed.X";
    TelgroundSpeedY="Telemetry/groundSpeed.Y";

    ArucoPosX ="Ext.Kallman Filter/pos.x";
    ArucoPosY ="Ext.Kallman Filter/pos.y";
    ArucoPosZ ="Ext.Kallman Filter/pos.z";
    ArucoYaw ="Ext.Kallman Filter/yaw";
    ArucoPitch="Ext.Kallman Filter/pitch";
    ArucoRoll="Ext.Kallman Filter/roll";
    Arucodx="Ext.Kallman Filter/dx";
    Arucody="Ext.Kallman Filter/dy";
    Arucodz="Ext.Kallman Filter/dz";
    Arucodyaw="Ext.Kallman Filter/dyaw";
    Arucodpitch="Ext.Kallman Filter/dpitch";
    Arucodroll="Ext.Kallman Filter/droll";

    ControllerPosX ="Controller/xci";
    ControllerPosY ="Controller/yci";
    ControllerPosZ ="Controller/zci";
    ControllerYaw ="Controller/yawci";
    ControllerPitch="Controller/pitchci";
    ControllerRoll="Controller/rollci";
    Controllerdx="Controller/vxfi";
    Controllerdy="Controller/vyfi";
    Controllerdz="Controller/vzfi";
    Controllerdyaw="Controller/dyawfi";




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


    initAxisX();

    initAxisY();

    initCurves();


    setTimerInterval(1000);// 1 second = 1000
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
       curves.insert(TelposYaw,new QwtPlotCurve(TelposYaw));
       curves.insert(TelposPitch,new QwtPlotCurve(TelposPitch));
       curves.insert(TelposRoll,new QwtPlotCurve(TelposRoll));
       curves.insert(Telaltitude,new QwtPlotCurve(Telaltitude));
       curves.insert(TelaltitudeSpeed,new QwtPlotCurve(TelaltitudeSpeed));
       curves.insert(TelgroundSpeedX,new QwtPlotCurve(TelgroundSpeedX));
       curves.insert(TelgroundSpeedY,new QwtPlotCurve(TelgroundSpeedY));
       curves.insert(ArucoPosX,new QwtPlotCurve(ArucoPosX));
       curves.insert(ArucoPosY,new QwtPlotCurve(ArucoPosY));
       curves.insert(ArucoPosZ,new QwtPlotCurve(ArucoPosZ));
       curves.insert(ArucoYaw,new QwtPlotCurve(ArucoYaw));
       curves.insert(ArucoPitch,new QwtPlotCurve(ArucoPitch));
       curves.insert(ArucoRoll,new QwtPlotCurve(ArucoRoll));
       curves.insert(Arucodx,new QwtPlotCurve(Arucodx));
       curves.insert(Arucody,new QwtPlotCurve(Arucody));
       curves.insert(Arucodz,new QwtPlotCurve(Arucodz));
       curves.insert(Arucodyaw,new QwtPlotCurve(Arucodyaw));
       curves.insert(Arucodpitch,new QwtPlotCurve(Arucodpitch));
       curves.insert(Arucodroll,new QwtPlotCurve(Arucodroll));

       curves.insert(ControllerPosX,new QwtPlotCurve(ControllerPosX));
       curves.insert(ControllerPosY,new QwtPlotCurve(ControllerPosY));
       curves.insert(ControllerPosZ,new QwtPlotCurve(ControllerPosZ));
       curves.insert(ControllerYaw,new QwtPlotCurve(ControllerYaw));
       curves.insert(ControllerPitch,new QwtPlotCurve(ControllerPitch));
       curves.insert(ControllerRoll,new QwtPlotCurve(ControllerRoll));


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
    qDebug() << "System Uptime" << "=" << hour << ":" << min << ":" << sec << endl;
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
    if(colors[id]==NULL){
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
        qDebug() << text; // the item is checked, insert in checked items.
        QString id;
        if(item->parent()!=NULL){
            id = item->parent()->text(0) + "/" + text;
            qDebug()<< id;
        }else
            id=item->text(colum);
        if(!selectedItems.contains(id)){ // if item is not in checked items.
            qDebug()<< "insert";
            selectedItems << id;
            qDebug()<< selectedItems;
            items.insert(id,item);
            iconChange.insert(id,1);
            assignColorIcon(id,item);
            // if(curves[id]==NULL){
            //}
        }else{// if item is in list checked items. detach plot and icon white.
            if(iconChange[id]==NULL){ //notChange.
                qDebug()<< "remove";
                eraseColorIcon(id,item);
                if(curves[id]!=NULL){
                qDebug()<< "detach curve";
                qDebug()<< id;
                curves[id]->setVisible(false);
                selectedItems.removeAll(id);
                items[id]->setText(1,"");

                }
            }
        }
        //Restore flags
        iconChange[id]=NULL;
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



/*  QVariant var;

  param6[0] =node->DronePoseMsgs.x;// save in buffer the last value


QString param;
 QMapIterator<QString,QStringList> i(*parameterList);
 while (i.hasNext()) {
     i.next();
     qDebug() << i.key();
     for(int v =0;v<i.value().size();++v){
       param = i.key() + "/" +  i.value().at(v);
     msgs.insert(param,&param6[0]);
     if(selectedItems.contains(param)&&items[param]!=NULL){
         curves[param]->setPen(QPen(colors[param]));
         curves[param]->setRawSamples(d_x,msgs[param],dataCount);
         curves[param]->attach(this);
         curves[param]->setVisible(true);
      }
   }
 }*/

// Read incoming connections
// frecuency < topic rate. 1FPS
void DataPlot::timerEvent(QTimerEvent *e)
{
    if(connectStatus){
    // fill the values.
      for ( int i = dataCount; i > 0; i-- )
      {
          param6[i] = param6[i-1];
          param3[i] = param3[i-1];
          param2[i] = param2[i-1];
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


      }

      QVariant var;

      param6[0] = node->RotationAnglesMsgs.vector.z;// we put the last value
      msgs.insert(TelposYaw,param6);
      if(selectedItems.contains(TelposYaw)&&items[TelposYaw]!=NULL){
          var.setValue(((double)((int)(node->RotationAnglesMsgs.vector.z*100)))/100);
          curves[TelposYaw]->setPen(QPen(colors[TelposYaw]));
          curves[TelposYaw]->setRawSamples(d_x,msgs[TelposYaw],dataCount);
          curves[TelposYaw]->attach(this);
          curves[TelposYaw]->setVisible(true);
          items[TelposYaw]->setText(1,QString::number(((double)((int)(node->RotationAnglesMsgs.vector.z*100)))/100));
      }


      QVariant var2;

      param3[0] = node->RotationAnglesMsgs.vector.y;
      msgs.insert(TelposPitch,param3);
      if(selectedItems.contains(TelposPitch)&&items[TelposPitch]!=NULL){
          var2.setValue(node->RotationAnglesMsgs.vector.y);
          curves[TelposPitch]->setPen(QPen(colors[TelposPitch]));
          curves[TelposPitch]->setRawSamples(d_x,msgs[TelposPitch],dataCount);
          curves[TelposPitch]->attach(this);
          curves[TelposPitch]->setVisible(true);
          items[TelposPitch]->setText(1,QString::number(((double)((int)(node->RotationAnglesMsgs.vector.y*100)))/100));
      }


      QVariant var3;

      param2[0] = node->RotationAnglesMsgs.vector.x;
      msgs.insert(TelposRoll,param2);
      if(selectedItems.contains(TelposRoll)&&items[TelposRoll]!=NULL){
          var3.setValue(node->RotationAnglesMsgs.vector.x);
          curves[TelposRoll]->setPen(QPen(colors[TelposRoll]));
          curves[TelposRoll]->setRawSamples(d_x,msgs[TelposRoll],dataCount);
          curves[TelposRoll]->attach(this);
          curves[TelposRoll]->setVisible(true);
          items[TelposRoll]->setText(1,QString::number(((double)((int)(node->RotationAnglesMsgs.vector.x*100)))/100));
      }


      QVariant var4;

      param11[0] = node->AltitudeMsgs.altitude_speed;// we put the last value
      msgs.insert(TelaltitudeSpeed,param11);
      if(selectedItems.contains(TelaltitudeSpeed)&&items[TelaltitudeSpeed]!=NULL){
          var4.setValue(node->AltitudeMsgs.altitude_speed);
          curves[TelaltitudeSpeed]->setPen(QPen(colors[TelaltitudeSpeed]));
          curves[TelaltitudeSpeed]->setRawSamples(d_x,msgs[TelaltitudeSpeed],dataCount);
          curves[TelaltitudeSpeed]->attach(this);
          curves[TelaltitudeSpeed]->setVisible(true);
          items[TelaltitudeSpeed]->setText(1,QString::number(((double)((int)(node->AltitudeMsgs.altitude_speed*100)))/100));
      }


      QVariant var5;
      param12[0] = node->AltitudeMsgs.altitude;
      msgs.insert(Telaltitude,param12);
      if(selectedItems.contains(Telaltitude)&&items[Telaltitude]!=NULL){
          var5.setValue(node->AltitudeMsgs.altitude);
          curves[Telaltitude]->setPen(QPen(colors[Telaltitude]));
          curves[Telaltitude]->setRawSamples(d_x,msgs[Telaltitude],dataCount);
          curves[Telaltitude]->attach(this);
          curves[Telaltitude]->setVisible(true);
          items[Telaltitude]->setText(1,QString::number(((double)((int)(node->AltitudeMsgs.altitude*100)))/100));
      }


      QVariant var6;
      param13[0] = node->GroundSpeedMsgs.vector.x;
      msgs.insert(TelgroundSpeedX,param13);
      if(selectedItems.contains(TelgroundSpeedX)&& items[TelgroundSpeedX]!=NULL){
          var6.setValue(node->GroundSpeedMsgs.vector.x);
          curves[TelgroundSpeedX]->setPen(QPen(colors[TelgroundSpeedX]));
          curves[TelgroundSpeedX]->setRawSamples(d_x,msgs[TelgroundSpeedX],dataCount);
          curves[TelgroundSpeedX]->attach(this);
          curves[TelgroundSpeedX]->setVisible(true);
          items[TelgroundSpeedX]->setText(1,QString::number(((double)((int)(node->GroundSpeedMsgs.vector.x*100)))/100));
      }

      QVariant var7;
      param14[0] = node->GroundSpeedMsgs.vector.y;
      msgs.insert(TelgroundSpeedY,param14);
      if(selectedItems.contains(TelgroundSpeedY)&& items[TelgroundSpeedY]!=NULL){
          var7.setValue(node->GroundSpeedMsgs.vector.y);
          curves[TelgroundSpeedY]->setPen(QPen(colors[TelgroundSpeedY]));
          curves[TelgroundSpeedY]->setRawSamples(d_x,msgs[TelgroundSpeedY],dataCount);
          curves[TelgroundSpeedY]->attach(this);
          curves[TelgroundSpeedY]->setVisible(true);
           items[TelgroundSpeedY]->setText(1,QString::number(((double)((int)(node->GroundSpeedMsgs.vector.y*100)))/100));
      }

      QVariant var20;
      param15[0] = odomReceiver->DronePoseMsgs.x;
      msgs.insert(ArucoPosX,param15);
      if(selectedItems.contains(ArucoPosX)&& items[ArucoPosX]!=NULL){
          var20.setValue(odomReceiver->DronePoseMsgs.x);
          curves[ArucoPosX]->setPen(QPen(colors[ArucoPosX]));
          curves[ArucoPosX]->setRawSamples(d_x,msgs[ArucoPosX],dataCount);
          curves[ArucoPosX]->attach(this);
          curves[ArucoPosX]->setVisible(true);
           items[ArucoPosX]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.x*100)))/100));
      }

      QVariant var8;
      param16[0] = odomReceiver->DronePoseMsgs.y;
      msgs.insert(ArucoPosY,param16);
      if(selectedItems.contains(ArucoPosY)&& items[ArucoPosY]!=NULL){
          var8.setValue(odomReceiver->DronePoseMsgs.y);
          curves[ArucoPosY]->setPen(QPen(colors[ArucoPosY]));
          curves[ArucoPosY]->setRawSamples(d_x,msgs[ArucoPosY],dataCount);
          curves[ArucoPosY]->attach(this);
          curves[ArucoPosY]->setVisible(true);
           items[ArucoPosY]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.y*100)))/100));
      }

      QVariant var9;
      param17[0] = odomReceiver->DronePoseMsgs.z;
      msgs.insert(ArucoPosZ,param17);
      if(selectedItems.contains(ArucoPosZ)&& items[ArucoPosZ]!=NULL){
          var9.setValue(odomReceiver->DronePoseMsgs.z);
          curves[ArucoPosZ]->setPen(QPen(colors[ArucoPosZ]));
          curves[ArucoPosZ]->setRawSamples(d_x,msgs[ArucoPosZ],dataCount);
          curves[ArucoPosZ]->attach(this);
          curves[ArucoPosZ]->setVisible(true);
           items[ArucoPosZ]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.z*100)))/100));
      }

      QVariant var10;
      param18[0] = odomReceiver->DronePoseMsgs.yaw;
      msgs.insert(ArucoYaw,param18);
      if(selectedItems.contains(ArucoYaw)&& items[ArucoYaw]!=NULL){
          var10.setValue(odomReceiver->DronePoseMsgs.yaw);
          curves[ArucoYaw]->setPen(QPen(colors[ArucoYaw]));
          curves[ArucoYaw]->setRawSamples(d_x,msgs[ArucoYaw],dataCount);
          curves[ArucoYaw]->attach(this);
          curves[ArucoYaw]->setVisible(true);
           items[ArucoYaw]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.yaw*100)))/100));
      }

      QVariant var11;
      param19[0] = odomReceiver->DronePoseMsgs.pitch;
      msgs.insert(ArucoPitch,param19);
      if(selectedItems.contains(ArucoPitch)&& items[ArucoPitch]!=NULL){
          var11.setValue(odomReceiver->DronePoseMsgs.pitch);
          curves[ArucoPitch]->setPen(QPen(colors[ArucoPitch]));
          curves[ArucoPitch]->setRawSamples(d_x,msgs[ArucoPitch],dataCount);
          curves[ArucoPitch]->attach(this);
          curves[ArucoPitch]->setVisible(true);
           items[ArucoPitch]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.pitch*100)))/100));
      }

      QVariant var12;
      param19[0] = odomReceiver->DronePoseMsgs.roll;
      msgs.insert(ArucoRoll,param19);
      if(selectedItems.contains(ArucoRoll)&& items[ArucoRoll]!=NULL){
          var12.setValue(odomReceiver->DronePoseMsgs.roll);
          curves[ArucoRoll]->setPen(QPen(colors[ArucoRoll]));
          curves[ArucoRoll]->setRawSamples(d_x,msgs[ArucoRoll],dataCount);
          curves[ArucoRoll]->attach(this);
          curves[ArucoRoll]->setVisible(true);
           items[ArucoRoll]->setText(1,QString::number(((double)((int)(odomReceiver->DronePoseMsgs.roll*100)))/100));
      }

      QVariant var13;
      param20[0] = odomReceiver->DroneSpeedsMsgs.dx;
      msgs.insert(Arucodx,param20);
      if(selectedItems.contains(Arucodx)&& items[Arucodx]!=NULL){
          var13.setValue(odomReceiver->DroneSpeedsMsgs.dx);
          curves[Arucodx]->setPen(QPen(colors[Arucodx]));
          curves[Arucodx]->setRawSamples(d_x,msgs[Arucodx],dataCount);
          curves[Arucodx]->attach(this);
          curves[Arucodx]->setVisible(true);
           items[Arucodx]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.dx*100)))/100));
      }

      QVariant var14;
      param21[0] = odomReceiver->DroneSpeedsMsgs.dy;
      msgs.insert(Arucody,param21);
      if(selectedItems.contains(Arucody)&& items[Arucody]!=NULL){
          var14.setValue(odomReceiver->DroneSpeedsMsgs.dy);
          curves[Arucody]->setPen(QPen(colors[Arucody]));
          curves[Arucody]->setRawSamples(d_x,msgs[Arucody],dataCount);
          curves[Arucody]->attach(this);
          curves[Arucody]->setVisible(true);
           items[Arucody]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.dy*100)))/100));
      }


      QVariant var15;
      param22[0] = odomReceiver->DroneSpeedsMsgs.dz;
      msgs.insert(Arucodz,param22);
      if(selectedItems.contains(Arucodz)&& items[Arucodz]!=NULL){
          var15.setValue(odomReceiver->DroneSpeedsMsgs.dz);
          curves[Arucodz]->setPen(QPen(colors[Arucodz]));
          curves[Arucodz]->setRawSamples(d_x,msgs[Arucodz],dataCount);
          curves[Arucodz]->attach(this);
          curves[Arucodz]->setVisible(true);
           items[Arucodz]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.dz*100)))/100));
      }

      QVariant var16;
      param23[0] = odomReceiver->DroneSpeedsMsgs.dyaw;
      msgs.insert(Arucodyaw,param23);
      if(selectedItems.contains(Arucodyaw)&& items[Arucodyaw]!=NULL){
          var16.setValue(odomReceiver->DroneSpeedsMsgs.dyaw);
          curves[Arucodyaw]->setPen(QPen(colors[Arucodyaw]));
          curves[Arucodyaw]->setRawSamples(d_x,msgs[Arucodyaw],dataCount);
          curves[Arucodyaw]->attach(this);
          curves[Arucodyaw]->setVisible(true);
           items[Arucodyaw]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.dyaw*100)))/100));
      }

      QVariant var17;
      param24[0] = odomReceiver->DroneSpeedsMsgs.dpitch;
      msgs.insert(Arucodpitch,param24);
      if(selectedItems.contains(Arucodpitch)&& items[Arucodpitch]!=NULL){
          var17.setValue(odomReceiver->DroneSpeedsMsgs.dpitch);
          curves[Arucodpitch]->setPen(QPen(colors[Arucodpitch]));
          curves[Arucodpitch]->setRawSamples(d_x,msgs[Arucodpitch],dataCount);
          curves[Arucodpitch]->attach(this);
          curves[Arucodpitch]->setVisible(true);
           items[Arucodpitch]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.dpitch*100)))/100));
      }

      QVariant var18;
      param25[0] = odomReceiver->DroneSpeedsMsgs.droll;
      msgs.insert(Arucodroll,param25);
      if(selectedItems.contains(Arucodroll)&& items[Arucodroll]!=NULL){
          var18.setValue(odomReceiver->DroneSpeedsMsgs.droll);
          curves[Arucodroll]->setPen(QPen(colors[Arucodroll]));
          curves[Arucodroll]->setRawSamples(d_x,msgs[Arucodroll],dataCount);
          curves[Arucodroll]->attach(this);
          curves[Arucodroll]->setVisible(true);
           items[Arucodroll]->setText(1,QString::number(((double)((int)(odomReceiver->DroneSpeedsMsgs.droll*100)))/100));
      }



      QVariant var19;
      param26[0] = odomReceiver->DroneControllerPoseMsgs.x;
      msgs.insert(ControllerPosX,param26);
      if(selectedItems.contains(ControllerPosX)&& items[ControllerPosX]!=NULL){
          var19.setValue( odomReceiver->DroneControllerPoseMsgs.x);
          curves[ControllerPosX]->setPen(QPen(colors[ControllerPosX]));
          curves[ControllerPosX]->setRawSamples(d_x,msgs[ControllerPosX],dataCount);
          curves[ControllerPosX]->attach(this);
          curves[ControllerPosX]->setVisible(true);
           items[ControllerPosX]->setText(1,QString::number(((double)((int)( odomReceiver->DroneControllerPoseMsgs.x*100)))/100));
      }

      param27[0] = odomReceiver->DroneControllerPoseMsgs.y;
      msgs.insert(ControllerPosY,param27);
      if(selectedItems.contains(ControllerPosY)&& items[ControllerPosY]!=NULL){
          curves[ControllerPosY]->setPen(QPen(colors[ControllerPosY]));
          curves[ControllerPosY]->setRawSamples(d_x,msgs[ControllerPosY],dataCount);
          curves[ControllerPosY]->attach(this);
          curves[ControllerPosY]->setVisible(true);
      }
      QVariant var21;
      param26[0] = odomReceiver->DroneControllerPoseMsgs.z;
      msgs.insert(ControllerPosZ,param26);
      if(selectedItems.contains(ControllerPosZ)&& items[ControllerPosZ]!=NULL){
          var21.setValue(odomReceiver->DroneControllerPoseMsgs.z);
          curves[ControllerPosZ]->setPen(QPen(colors[ControllerPosZ]));
          curves[ControllerPosZ]->setRawSamples(d_x,msgs[ControllerPosZ],dataCount);
          curves[ControllerPosZ]->attach(this);
          curves[ControllerPosZ]->setVisible(true);
           items[ControllerPosZ]->setText(1,QString::number(((double)((int)(odomReceiver->DroneControllerPoseMsgs.z*100)))/100));
      }

      QVariant var22;
      param27[0] = odomReceiver->DroneControllerPoseMsgs.yaw;
      msgs.insert(ControllerYaw,param27);
      if(selectedItems.contains(ControllerYaw)&& items[ControllerYaw]!=NULL){
          var22.setValue(odomReceiver->DroneControllerPoseMsgs.yaw);
          curves[ControllerYaw]->setPen(QPen(colors[ControllerYaw]));
          curves[ControllerYaw]->setRawSamples(d_x,msgs[ControllerYaw],dataCount);
          curves[ControllerYaw]->attach(this);
          curves[ControllerYaw]->setVisible(true);
           items[ControllerYaw]->setText(1,QString::number(((double)((int)(odomReceiver->DroneControllerPoseMsgs.yaw*100)))/100));
      }

      QVariant var23;
      param28[0] = odomReceiver->DroneControllerPoseMsgs.pitch;
      msgs.insert(ControllerPitch,param28);
      if(selectedItems.contains(ControllerPitch)&& items[ControllerPitch]!=NULL){
          var23.setValue(odomReceiver->DroneControllerPoseMsgs.pitch);
          curves[ControllerPitch]->setPen(QPen(colors[ControllerPitch]));
          curves[ControllerPitch]->setRawSamples(d_x,msgs[ControllerPitch],dataCount);
          curves[ControllerPitch]->attach(this);
          curves[ControllerPitch]->setVisible(true);
           items[ControllerPitch]->setText(1,QString::number(((double)((int)(odomReceiver->DroneControllerPoseMsgs.pitch*100)))/100));
      }

      QVariant var24;
      param28[0] = odomReceiver->DroneControllerPoseMsgs.roll;
      msgs.insert(ControllerRoll,param28);
      if(selectedItems.contains(ControllerRoll)&& items[ControllerRoll]!=NULL){
          var24.setValue(odomReceiver->DroneControllerPoseMsgs.roll);
          curves[ControllerRoll]->setPen(QPen(colors[ControllerRoll]));
          curves[ControllerRoll]->setRawSamples(d_x,msgs[ControllerRoll],dataCount);
          curves[ControllerRoll]->attach(this);
          curves[ControllerRoll]->setVisible(true);
           items[ControllerRoll]->setText(1,QString::number(((double)((int)(odomReceiver->DroneControllerPoseMsgs.roll*100)))/100));
      }

      /*QString Controllerdx;
      QString Controllerdy;
      QString Controllerdz;
      QString Controllerdyaw;
      QString Controllerdpitch;
      QString Controllerdroll;

      QVariant var25;
      param29[0] = odomReceiver->DroneControllerPoseMsgs.roll;
      msgs.insert(ControllerRoll,param29);
      if(selectedItems.contains(ControllerRoll)&& items[ControllerRoll]!=NULL){
          var25.setValue(odomReceiver->DroneControllerPoseMsgs.roll);
          curves[ControllerRoll]->setPen(QPen(colors[ControllerRoll]));
          curves[ControllerRoll]->setRawSamples(d_x,msgs[ControllerRoll],dataCount);
          curves[ControllerRoll]->attach(this);
          curves[ControllerRoll]->setVisible(true);
           items[ControllerRoll]->setText(1,QString::number(((double)((int)(odomReceiver->DroneControllerPoseMsgs.roll*100)))/100));
      }*/

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



}

// TODO> Checking if is NULL when user select
/*void DataPlot::setDataCurve(double param, QString curve_id, double data_msg)
{
    QVariant var7;
    param[0] = data_msg;
    msgs.insert(curve_id,param);
    if(selectedItems.contains(curve_id)&& items[curve_id]!=NULL){
        var7.setValue(data_msg);
        curves[curve_id]->setPen(QPen(colors[curve_id]));
        curves[curve_id]->setRawSamples(d_x,msgs[curve_id],dataCount);
        curves[curve_id]->attach(this);
        curves[curve_id]->setVisible(true);
         items[curve_id]->setText(1,QString::number(((double)((int)(data_msg*100)))/100));
    }
}*/

void DataPlot::resizeAxisXScale(int ms)
{
    setAxisScale(QwtPlot::xBottom, 0, ms);
    replot();
}
void DataPlot::resizeAxisYScale(int ms)
{
    setAxisScale(QwtPlot::yLeft, -20,ms);
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
