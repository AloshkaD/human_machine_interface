#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include <QTime>
#include <sstream>
#include <QObject>

class supervisor : public QObject
{
     Q_OBJECT
public:
    explicit supervisor( QObject *parent = 0);

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

#endif // SUPERVISOR_H



