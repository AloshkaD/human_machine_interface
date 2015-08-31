

#include "../include/human_machine_interface/glwidget.h"

GLWidget::GLWidget(QWidget *parent): QGLWidget(parent), glt(this)
{
    setAutoBufferSwap(true);
    resize(820, 240);
    this->doneCurrent();
}
void GLWidget::startRendering(){
    glt.start(); // it call to the run method
}
void GLWidget::stopRendering(){
    glt.stop();
    glt.wait();
}

void GLWidget::resizeEvent(QResizeEvent *evt){
    glt.resizeViewport(evt->size());
}
void GLWidget::paintEvent(QPaintEvent *){
    // Handled by the GLThread.
}
void GLWidget::closeEvent(QCloseEvent *evt){
    stopRendering();
    QGLWidget::closeEvent(evt);
}

