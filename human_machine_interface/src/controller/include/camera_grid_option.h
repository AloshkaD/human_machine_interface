/*!*******************************************************************************************
 *  \file       camera_grid_option.h
 *  \brief      CameraGridOption definition file.
 *  \details    This file includes the CameraGridOption class declaration. To obtain more
 *              information about it's definition consult the camera_grid_option.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef CAMERAGRIDOPTION_H
#define CAMERAGRIDOPTION_H

#include <QWidget>
#include "images_receiver.h"

namespace Ui {
class CameraGridOption;
}

class CameraGridOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraGridOption(QWidget *parent = 0, ImagesReceiver *imgReceiver=0);
    ~CameraGridOption();
    int current_camera;
    int mainCamera;
    QPixmap pixmap1;
    QPixmap pixmap2;
    QPixmap pixmap3;
    QPixmap pixmap4;

public Q_SLOTS:
    void updateImage(const QPixmap* image, int id_camera);

private:
    Ui::CameraGridOption *ui;
    ImagesReceiver* image_receiver;
    QPixmap pix;
};

#endif 
