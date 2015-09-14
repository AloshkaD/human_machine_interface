/*
  Camera view - Shows the camera views displayed in full screen 
  @author  Yolanda de la Hoz Simón
  @date    06-2015
  @version 1.0
*/
  
/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/camera_main_option.h"
#include "../.././../../../hmi_cvg_stack -build/human_machine_interface/ui_cameramainoption.h"
#include <qt4/Qt/qframe.h>
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qbuffer.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4//Qt/qsignalmapper.h>
/*****************************************************************************
** Implementation
*****************************************************************************/

CameraMainOption::CameraMainOption(QWidget *parent,ImagesReceiver* imgReceiver) :
    QWidget(parent),
    ui(new Ui::cameraMainOption)
{
    ui->setupUi(this);
    imageReceiver=imgReceiver;
    current_image=1;

    QSignalMapper* signalMapper = new QSignalMapper(this);
    connect(ui->rightButton, SIGNAL(clicked()),signalMapper, SLOT(map()));
    connect(ui->rightButton, SIGNAL(clicked()),signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->rightButton,1);
    signalMapper->setMapping(ui->leftButton,2);
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(changeCurrentCamera(int)));

    //connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
    connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
    connect(parent, SIGNAL(saveImage(const int)), this, SLOT(saveCameraImages(const int)));
}

int CameraMainOption::heightForWidth( int width ) const
{
    return ((qreal)pix.height()*width)/pix.width();
}


QSize CameraMainOption::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

void CameraMainOption::saveCameraImages(const int camera_view_manager){
    if(camera_view_manager==0){
       QImage imageObject = pix.toImage();
       QByteArray bytes;
       QBuffer buffer(&bytes);
       buffer.open(QIODevice::WriteOnly);
       pix.save(&buffer, "PNG"); // writes pixmap into bytes in PNG format
       QString imagePath = QFileDialog::getSaveFileName(
                       this,
                       tr("Save File"),
                       "",
                       tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                       );

       imageObject.save(imagePath);
    }
}

void CameraMainOption::changeCurrentCamera(int direction) //TODO:Change label title
{
    if(direction==1)
        current_image++;
    else
        current_image--;

    switch(current_image)
    {
    case 1:
        if(direction==1) //Right direction
            connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
        else{
            disconnect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
        }
        break;

    case 2:
        if(direction==1){
            disconnect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
        }else{
            disconnect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
        }
        break;

    case 3:
        if(direction==1){
            disconnect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
        }else{
            disconnect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
        }
        break;

    case 4:
        if(direction==1){
            disconnect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
        }else{
            disconnect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
        }

        break;

    case 5:
        if(direction==1){
            disconnect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
        }else{
            disconnect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
        }

        break;

    case 6:
        if(direction==1){
            disconnect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
            connect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
        }else{
            connect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
        }
        break;

    }


}

void CameraMainOption::updateImage1(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 1 is activated" << std::endl;
    }else
        std::cout << "The camera 1 is disactivated" << std::endl;
}


void CameraMainOption::updateImage2(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 2 is activated" << std::endl;
    }else
        std::cout << "The camera 2 is disactivated" << std::endl;

}

void CameraMainOption::updateImage3(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 3 is activated" << std::endl;
    }else
        std::cout << "The camera 3 is disactivated" << std::endl;

}

void CameraMainOption::updateImage4(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 4 is activated" << std::endl;
    }else
        std::cout << "The camera 4 is disactivated" << std::endl;
}

void CameraMainOption::updateImage5(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 5 is activated" << std::endl;
    }else
        std::cout << "The camera 5 is disactivated" << std::endl;

}

void CameraMainOption::updateImage6(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
        ui->mainImage->setPixmap(pix);
        ui->mainImage->setScaledContents( true );
        std::cout << "The camera 6 is activated" << std::endl;
    }else
        std::cout << "The camera 6 is disactivated" << std::endl;

}


CameraMainOption::~CameraMainOption()
{
    delete ui;
}
