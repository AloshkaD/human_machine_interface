#ifndef _DATA_PLOT_H
#define _DATA_PLOT_H 1

#include <qwt_plot.h>
#include <thread>
#include <qwt/qwt_plot_curve.h>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QHash>
#include <QHashIterator>
#include <QList>
#include <QTime>
#include "telemetry_state_receiver.h"
#include "odometry_state_receiver.h"

const int PLOT_SIZE =  60;      // 0 to 200
const int BUFFER_SIZE =  120;      // 0 to 200
const int HIGHRATE_SIZE = 20;      // 0 to 200


class DataPlot : public QwtPlot
{
    Q_OBJECT

public:
    DataPlot(QWidget* = NULL, TelemetryStateReceiver *collector=0, OdometryStateReceiver* odometryReceiver=0, QMap<QString, QStringList>  *list=0);
    void alignScales();

    bool connect_status;
    QStringList selected_items;
    QStringList colors_list;
    int iterator_colors;
    bool iconColorChange; // make difference between change by checkbox and icons.
    bool iconWhiteChange;
    bool is_stop_pressed;
    int data_count;
    int current_max_limit;
    int current_min_limit;
    std::vector<std::string>  parameters_list;
    QHash<QString,QwtPlotCurve*> curves;
    QHash<QString,QString> colors;
    QHash<QString,int> list_colors_icon;
    QHash<QString,double*> d_y;
    QHash<QString,QTreeWidgetItem*> items;

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

    void isConnectionReadyThread();

public Q_SLOTS:
    void setTimerInterval(double interval);
    void clickToPlot(QTreeWidgetItem* item, int colum);
    void resizeAxisXScale(int ms);
    void resizeAxisYMinLimit(int ms);
    void resizeAxisYMaxLimit(int ms);
    void saveAsSVG();
    void onParameterReceived();
  //  void onParameterReceived(QTimerEvent *e);

protected:
    virtual void timerEvent(QTimerEvent *e);

private:
    std::thread connection_admin_thread;
    double d_x[BUFFER_SIZE];
    double param1[BUFFER_SIZE];
    double param2[BUFFER_SIZE];
    double param3[BUFFER_SIZE];
    double param4[BUFFER_SIZE];
    double param5[BUFFER_SIZE];
    double param6[BUFFER_SIZE];
    double param7[BUFFER_SIZE];
    double param8[BUFFER_SIZE];
    double param9[BUFFER_SIZE];
    double param10[BUFFER_SIZE];
    double param11[BUFFER_SIZE];
    double param12[BUFFER_SIZE];
    double param13[BUFFER_SIZE];
    double param14[BUFFER_SIZE];
    double param15[BUFFER_SIZE];
    double param16[BUFFER_SIZE];
    double param17[BUFFER_SIZE];
    double param18[BUFFER_SIZE];
    double param19[BUFFER_SIZE];
    double param20[BUFFER_SIZE];
    double param21[BUFFER_SIZE];
    double param22[BUFFER_SIZE];
    double param23[BUFFER_SIZE];
    double param24[BUFFER_SIZE];
    double param25[BUFFER_SIZE];
    double param26[BUFFER_SIZE];
    double param27[BUFFER_SIZE];
    double param28[BUFFER_SIZE];
    double param29[BUFFER_SIZE];
    double param30[BUFFER_SIZE];
    double param31[BUFFER_SIZE];
    double param32[BUFFER_SIZE];
    double param33[BUFFER_SIZE];
    double param34[BUFFER_SIZE];
    double param35[BUFFER_SIZE];
    double param36[BUFFER_SIZE];
    double param37[BUFFER_SIZE];
    double param38[BUFFER_SIZE];
    double param39[BUFFER_SIZE];
    double param40[BUFFER_SIZE];
    double param41[BUFFER_SIZE];
    double param42[BUFFER_SIZE];
    double param43[BUFFER_SIZE];
    double param44[BUFFER_SIZE];
    double hrateBuff1[HIGHRATE_SIZE];
    double hrateBuff2[HIGHRATE_SIZE];
    double hrateBuff3[HIGHRATE_SIZE];
    double hrateBuff4[HIGHRATE_SIZE];
    double hrateBuff5[HIGHRATE_SIZE];
    double hrateBuff6[HIGHRATE_SIZE];
    TelemetryStateReceiver* node;
    OdometryStateReceiver* odom_receiver;

    int posicionBuffer;
    int d_interval; // timer in ms
    int d_timerId;
};

#endif
