#ifndef _DATA_PLOT_H
#define _DATA_PLOT_H 1

#include <qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QHash>
#include <QHashIterator>
#include <QList>
#include <QTime>
#include "telemetryStateReceiver.h"
#include "odometryStateReceiver.h"

const int PLOT_SIZE =  60;      // 0 to 200
const int HIGHRATE_SIZE = 20;      // 0 to 200


class DataPlot : public QwtPlot
{
    Q_OBJECT

public:
    DataPlot(QWidget* = NULL, telemetryStateReceiver *collector=0, odometryStateReceiver* odometryReceiver=0, QMap<QString, QStringList>  *list=0);
    void alignScales();

    bool connectStatus;
    QStringList selectedItems;
    QStringList plotColors;
    int iteratorColors;
    bool iconColorChange; // make difference between change by checkbox and icons.
    bool iconWhiteChange;
    bool stopPressed;
    int dataCount;
    bool highRateOption;
    QMap<QString, QStringList>  *parameterList;
    QHash<QString,QwtPlotCurve*> curves;
    QHash<QString,QString> colors;
    QHash<QString,int> iconChange;
    QHash<QString,double*> msgs;
    QHash<QString,QTreeWidgetItem*> items;


    QString TelposYaw;
    QString TelposPitch;
    QString TelposRoll;
    QString Telaltitude;
    QString TelaltitudeSpeed;
    QString TelgroundSpeedX;
    QString TelgroundSpeedY;
    QString ArucoPosX;
    QString ArucoPosY;
    QString ArucoPosZ;
    QString ArucoYaw;
    QString ArucoPitch;
    QString ArucoRoll;
    QString Arucodx;
    QString Arucody;
    QString Arucodz;
    QString Arucodyaw;
    QString Arucodpitch;
    QString Arucodroll;

    QString ControllerPosX;
    QString ControllerPosY;
    QString ControllerPosZ;
    QString ControllerYaw;
    QString ControllerPitch;
    QString ControllerRoll;
    QString Controllerdx;
    QString Controllerdy;
    QString Controllerdz;
    QString Controllerdyaw;
    QString Controllerdpitch;
    QString Controllerdroll;




    QStringList topicFields;

    QTime upTime() const;
    void assignColorIcon(QString id,QTreeWidgetItem* item);
    void eraseColorIcon(QString id,QTreeWidgetItem* item);
    void initAxisY();
    void initAxisX();
    void initTimeData();
    void setGridPlot();
    void initCurves();


public Q_SLOTS:
    void setTimerInterval(double interval);
    void clickToPlot(QTreeWidgetItem* item, int colum);
    void resizeAxisXScale(int ms);
    void resizeAxisYScale(int ms);
    void saveAsSVG();
    void onParameterReceived();
  //  void onParameterReceived(QTimerEvent *e);

protected:
    virtual void timerEvent(QTimerEvent *e);

private:





    double d_x[PLOT_SIZE];
    double d_y[PLOT_SIZE];
    double d_z[PLOT_SIZE];
    double param2[PLOT_SIZE];
    double param4[PLOT_SIZE];
    double param5[PLOT_SIZE];
    double param6[PLOT_SIZE];
    double param7[PLOT_SIZE];
    double param8[PLOT_SIZE];
    double param3[PLOT_SIZE];
    double param10[PLOT_SIZE];
    double paramx[PLOT_SIZE];
    double paramc[PLOT_SIZE];
    double paramY[PLOT_SIZE];
    double param11[PLOT_SIZE];
    double paramT[PLOT_SIZE];
    double paramWW[PLOT_SIZE];
    double paramEE[PLOT_SIZE];
    double paramRR[PLOT_SIZE];
    double param12[PLOT_SIZE];
    double paramTT[PLOT_SIZE];
    double paramHH[PLOT_SIZE];
    double paramJJ[PLOT_SIZE];
    double paramKK[PLOT_SIZE];
    double param13[PLOT_SIZE];
    double paramVV[PLOT_SIZE];
    double paramBB[PLOT_SIZE];
    double paramNN[PLOT_SIZE];
    double param14[PLOT_SIZE];
    double paramJJ1[PLOT_SIZE];
    double paramJJ7[PLOT_SIZE];
    double paramJJ8[PLOT_SIZE];
    double param15[PLOT_SIZE];
    double paramGGG[PLOT_SIZE];
    double paramGH[PLOT_SIZE];
    double paramGF[PLOT_SIZE];
    double param16[PLOT_SIZE];
    double paramGGa[PLOT_SIZE];
    double paramGs[PLOT_SIZE];
    double paramGd[PLOT_SIZE];
    double param17[PLOT_SIZE];
    double paramGGf[PLOT_SIZE];
    double paramGg[PLOT_SIZE];
    double paramGh[PLOT_SIZE];
    double param18[PLOT_SIZE];
    double paramGGj[PLOT_SIZE];
    double paramGk[PLOT_SIZE];
    double paramGl[PLOT_SIZE];
    double param19[PLOT_SIZE];
    double paramGGu[PLOT_SIZE];
    double paramGi[PLOT_SIZE];
    double paramGo[PLOT_SIZE];
    double param20[PLOT_SIZE];
    double paramGGc[PLOT_SIZE];
    double paramGv[PLOT_SIZE];
    double paramGb[PLOT_SIZE];
    double param21[PLOT_SIZE];
    double dsfs[PLOT_SIZE];
    double gfhf[PLOT_SIZE];
    double gfh[PLOT_SIZE];
    double param22[PLOT_SIZE];
    double k[PLOT_SIZE];
    double l[PLOT_SIZE];
    double uu[PLOT_SIZE];
    double param23[PLOT_SIZE];
    double z[PLOT_SIZE];
    double x[PLOT_SIZE];
    double v[PLOT_SIZE];
    double param24[PLOT_SIZE];
    double b[PLOT_SIZE];
    double n[PLOT_SIZE];
    double ii[PLOT_SIZE];
    double param25[PLOT_SIZE];
    double r[PLOT_SIZE];
    double t[PLOT_SIZE];
    double p[PLOT_SIZE];
    double param26[PLOT_SIZE];
    double hk[PLOT_SIZE];
    double hl[PLOT_SIZE];
    double huu[PLOT_SIZE];
    double param27[PLOT_SIZE];
    double hz[PLOT_SIZE];
    double hx[PLOT_SIZE];
    double hv[PLOT_SIZE];
    double param28[PLOT_SIZE];
    double hb[PLOT_SIZE];
    double hn[PLOT_SIZE];
    double hii[PLOT_SIZE];
    double param29[PLOT_SIZE];
    double hr[PLOT_SIZE];
    double ht[PLOT_SIZE];
    double hp[PLOT_SIZE];
    double param30[PLOT_SIZE];
    double ohr[PLOT_SIZE];
    double oht[PLOT_SIZE];
    double ohp[PLOT_SIZE];

    double hrateBuff1[HIGHRATE_SIZE];
    double hrateBuff2[HIGHRATE_SIZE];
    double hrateBuff3[HIGHRATE_SIZE];
    double hrateBuff4[HIGHRATE_SIZE];
    double hrateBuff5[HIGHRATE_SIZE];
    double hrateBuff6[HIGHRATE_SIZE];
    telemetryStateReceiver* node;
    odometryStateReceiver* odomReceiver;

    int posicionBuffer;
    int d_interval; // timer in ms
    int d_timerId;
};

#endif
