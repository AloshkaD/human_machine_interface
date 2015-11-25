#ifndef MOCKROSNODE_H
#define MOCKROSNODE_H
#include <QTime>
#include <sstream>
#include <QObject>

class mockROSnode : public QObject
{
     Q_OBJECT
public:
    explicit mockROSnode( QObject *parent = 0);

    struct message {
      std::string text;
      std::string process;
      std::string topic;
      int severity;
    } supervisorMessage;


public Q_SLOTS:
    void setTimerInterval(double ms);

protected:
     virtual void timerEvent(QTimerEvent *e);

private:
    int d_interval; // timer in ms
    int d_timerId;

};

#endif // MOCKROSNODE_H



