/*
  Main Qt GUI
  Initialize the GUI application
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

#include <ros/ros.h>
#include "../include/human_machine_interface/mainwindow.h"
#include <qt4/QtGui/QApplication>
#include <qt4/QtOpenGL/QtOpenGL>
#include <GL/glut.h>
#include "../include/human_machine_interface/glwidget.h"
#include <X11/Xlib.h>

int main(int argc, char *argv[])
{

    XInitThreads();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    QApplication app(argc, argv);

    MainWindow w(argc,argv);
    w.show();

    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();



 /*   QGLContext*glContext=new QGLContext (QGLFormat::defaultFormat());
    glContext->create();// create() always fail without painter device
    QGLWidget* openGLQt = new QGLWidget(glContext,this);*/


    QWorkspace *workspace = new QWorkspace(this);
    setCentralWidget(workspace);
    QWidgetList windows = workspace->windowList();
    GLWidget *widget_GL= new GLWidget(workspace);
    workspace->addWindow(widget_GL);
    widget_GL->setWindowTitle("Thread #" + QString::number(windows.count() + 1));
    widget_GL->show();
     widget_GL->startRendering();

    return result;
}
