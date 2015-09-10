/*
  Main Qt GUI
  Initialize the GUI application
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <stdio.h>
#include <ros/ros.h>
#include "../include/main_window.h"
#include <qt4/Qt/qapplication.h>

/*****************************************************************************
** Implementation
*****************************************************************************/


int main(int argc, char *argv[])
{
    //Redirect the standard error temporally
    freopen( "standard_error.txt", "w", stderr );

    QApplication app(argc, argv);
    MainWindow w(argc,argv);

    if (w.singletonApplication()==false)
        return 1;
  

    
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

    return result;
}
