/*!*******************************************************************************************
 *  \file       camera_display_option.h
 *  \brief      CameraDisplayOption definition file.
 *  \details    This file includes the CameraDisplayOption class declaration. To obtain more
 *              information about it's definition consult the camera_display_option.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef CAMERADISPLAYOPTION_H
#define CAMERADISPLAYOPTION_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "images_receiver.h"

namespace Ui {
class cameraDisplayOption;
}

class CameraDisplayOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraDisplayOption(QWidget *parent = 0,ImagesReceiver* imgReceiver=0);
    ~CameraDisplayOption();
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    QPixmap pix;
    QPixmap pixmap1;
    QPixmap pixmap2;
    QPixmap pixmap3;
    QPixmap pixmap4;
    QString getCurrentCamera(int pos);
    void swapWidgets(QPushButton* imageToSwap, QString titleToSwap);
    void createPixmapsButton();
    int current_camera;
    int main_camera;


public Q_SLOTS:
    void changeCameraPosition(int id_camera);
    void updateImage(const QPixmap* image, int id_camera);
    void saveCameraImages(const int camera_view_manager);


private:
    Ui::cameraDisplayOption *ui;
    ImagesReceiver* image_receiver;
};

#endif // CAMERADISPLAYOPTION_H
