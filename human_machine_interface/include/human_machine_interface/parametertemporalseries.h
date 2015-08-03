#ifndef PARAMETERTEMPORALSERIES_H
#define PARAMETERTEMPORALSERIES_H

#include <QDockWidget>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QTreeWidget>
#include <QString>
#include "data_plot.h"
#include "telemetryStateReceiver.h"
#include "odometryStateReceiver.h"

namespace Ui {
class parameterTemporalSeries;
}

class parameterTemporalSeries : public QWidget
{
    Q_OBJECT

    void initTree(QMap<QString, QStringList> algorithmsList, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);
    void setSignalHandlers();

public:
    explicit parameterTemporalSeries(QWidget *parent = 0, telemetryStateReceiver *telemetryReceiver=0,odometryStateReceiver* odometryReceiver=0);
    void resizeEvent(QResizeEvent * event);
    ~parameterTemporalSeries();

    QStringList telemetry;
    QStringList ekf;
    QStringList controller;
    QStringList arucoSlam;

public Q_SLOTS:
    void onTextFilterChange(const QString &arg1);
    void onShowUnits(bool click);
    void onStopButton();
    void updateParametersValue();

private:
    Ui::parameterTemporalSeries *ui;
    DataPlot *plot;
    QStringList paramsTelemetry;
    telemetryStateReceiver* telemReceiver;
    odometryStateReceiver* odomReceiver;
    QMap<QString,QStringList> parameters;
};

#endif // PARAMETERTEMPORALSERIES_H
