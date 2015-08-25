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
    std::vector<std::string>  parameterList;
    QHash<QString,QwtPlotCurve*> curves;
    QHash<QString,QString> colors;
    QHash<QString,int> iconChange;
    QHash<QString,double*> msgs;
    QHash<QString,QTreeWidgetItem*> items;






    QStringList topicFields;

    QTime upTime() const;
    void assignColorIcon(QString id,QTreeWidgetItem* item);
    void eraseColorIcon(QString id,QTreeWidgetItem* item);
    void initAxisY();
    void initAxisX();
    void initTimeData();
    void setGridPlot();
    void initCurves();
    void setDataCurve(double param[], QString curve_id, double data_msg);
    std::vector<std::string> setCurveLabels(QMap<QString, QStringList> list);

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
    double param1[PLOT_SIZE];
    double x[PLOT_SIZE];
    double param2[PLOT_SIZE];
    double xx[PLOT_SIZE];
    double param3[PLOT_SIZE];
    double xxx[PLOT_SIZE];
    double param4[PLOT_SIZE];
    double xxxx[PLOT_SIZE];
    double param5[PLOT_SIZE];
    double xxxxxx[PLOT_SIZE];
    double param6[PLOT_SIZE];
    double xxxxxxx[PLOT_SIZE];
    double param7[PLOT_SIZE];
    double xxxxxxxxx[PLOT_SIZE];
    double param8[PLOT_SIZE];
    double xxxxxxxxxxxx[PLOT_SIZE];
    double param9[PLOT_SIZE];
    double xxxxxxxxxxxxxxx[PLOT_SIZE];
    double param10[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param11[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param12[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param13[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param14[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param15[PLOT_SIZE];
    double xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx[PLOT_SIZE];
    double param16[PLOT_SIZE];
        double xsdfx[PLOT_SIZE];
    double param17[PLOT_SIZE];
        double xasdfx[PLOT_SIZE];
    double param18[PLOT_SIZE];
        double qxsdfx[PLOT_SIZE];
    double param19[PLOT_SIZE];
        double xxsdf[PLOT_SIZE];
    double param20[PLOT_SIZE];
        double xsxsdf[PLOT_SIZE];
    double param21[PLOT_SIZE];
        double sdfxx[PLOT_SIZE];
    double param22[PLOT_SIZE];
        double xxff[PLOT_SIZE];
    double param23[PLOT_SIZE];
        double xddx[PLOT_SIZE];
    double param24[PLOT_SIZE];
        double xxffd[PLOT_SIZE];
    double param25[PLOT_SIZE];
        double xdx[PLOT_SIZE];
    double param26[PLOT_SIZE];
        double xfx[PLOT_SIZE];
    double param27[PLOT_SIZE];
        double xsx[PLOT_SIZE];
    double param28[PLOT_SIZE];
        double xfddx[PLOT_SIZE];
    double param29[PLOT_SIZE];
        double xfdx[PLOT_SIZE];
    double param30[PLOT_SIZE];
        double xdfdx[PLOT_SIZE];
    double param31[PLOT_SIZE];
        double wxdfdx[PLOT_SIZE];
    double param32[PLOT_SIZE];
        double axx[PLOT_SIZE];
    double param33[PLOT_SIZE];
        double xasx[PLOT_SIZE];
    double param34[PLOT_SIZE];
        double uxx[PLOT_SIZE];
    double param35[PLOT_SIZE];
        double yxx[PLOT_SIZE];
    double param36[PLOT_SIZE];
        double yuxx[PLOT_SIZE];
    double param37[PLOT_SIZE];
        double ixx[PLOT_SIZE];
    double param38[PLOT_SIZE];
        double xvbx[PLOT_SIZE];
    double param39[PLOT_SIZE];
        double xvbvx[PLOT_SIZE];
    double param40[PLOT_SIZE];
        double vnxx[PLOT_SIZE];
    double param41[PLOT_SIZE];
        double xcx[PLOT_SIZE];
    double param42[PLOT_SIZE];
    double xcvxxx[PLOT_SIZE];


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
