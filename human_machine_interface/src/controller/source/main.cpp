/*
  Main Qt GUI
  Initialize the GUI application
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

#include <ros/ros.h>
#include "../include/mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w(argc,argv);
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

    return result;
}
