/*
  Camera view - show the camera views displayed in a grid
  @author  Yolanda de la Hoz Simón
  @date    06-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/camera_grid_option.h"
#include "../.././../../../hmi_cvg_stack -build/human_machine_interface/ui_cameragridoption.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

CameraGridOption::CameraGridOption(QWidget *parent,ImagesReceiver* imgReceiver) :
    QWidget(parent),
    ui(new Ui::CameraGridOption)
{
    ui->setupUi(this);
    imageReceiver=imgReceiver;
    connect(imageReceiver,SIGNAL(Update_Image(const QPixmap*,int)),this,SLOT(updateImage(const QPixmap*,int)));
}

void CameraGridOption::updateImage(const QPixmap* image,int id_camera)
{
    switch(id_camera)
    {
    case 1:{
        pixmap1= *image;
        if(!image->isNull()){
            ui->camera1_frame->setPixmap(pix);
            ui->camera1_frame->setScaledContents( true );
            std::cout << "The camera 1 is activated" << std::endl;
        }else
            std::cout << "The camera 1 is disactivated" << std::endl;
        break;
    }
    case 2:{
        pixmap2= *image;
        if(!image->isNull()){
            ui->camera2_frame->setPixmap(pix);
            ui->camera2_frame->setScaledContents( true );
            std::cout << "The camera 2 is activated" << std::endl;
        }else
            std::cout << "The camera 2 is disactivated" << std::endl;
        break;
    }
    case 3:{
        pixmap3= *image;
        if(!image->isNull()){
            ui->camera3_frame->setPixmap(pix);
            ui->camera3_frame->setScaledContents( true );
            std::cout << "The camera 3 is activated" << std::endl;
        }else
            std::cout << "The camera 3 is disactivated" << std::endl;
        break;
    }
    case 4:{
        pixmap4= *image;
        if(!image->isNull()){
            ui->camera4_frame->setPixmap(pix);
            ui->camera4_frame->setScaledContents( true );
            std::cout << "The camera 4 is activated" << std::endl;
        }else
            std::cout << "The camera 4 is disactivated" << std::endl;
        break;
    }
    }

}

CameraGridOption::~CameraGridOption()
{
    delete ui;
}
