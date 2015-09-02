#include "../include/camera_main_option.h"
#include "../../../../human_machine_interface-build/ui_cameramainoption.h"
#include <qt4/Qt/qframe.h>
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qbuffer.h>
#include <qt4/Qt/qfiledialog.h>

CameraOneOption::CameraOneOption(QWidget *parent,ImagesReceiver* imgReceiver) :
    QWidget(parent),
    ui(new Ui::cameraMainOption)
{
    ui->setupUi(this);
    imageReceiver=imgReceiver;
    current_image=1;

   connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
   //connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
   connect(ui->rightButton, SIGNAL(clicked()),this, SLOT(changeRightImage()));
   connect(ui->leftButton, SIGNAL(clicked()),this, SLOT(changeLeftImage()));
   connect(parent, SIGNAL(saveImage(const int)), this, SLOT(saveCameraImages(const int)));
}

void CameraOneOption::saveCameraImages(const int camera_view_manager){
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

void CameraOneOption::changeRightImage() //TODO:Change label title
{
  current_image++;
  switch(current_image)
  {
    case 1:
     connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
    break;

    case 2:
     disconnect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
     connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
    break;

    case 3:
      disconnect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
    break;

    case 4:
      disconnect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
    break;

    case 5:
      disconnect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
    break;

    case 6:
      disconnect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
    break;

  }


}


void CameraOneOption::changeLeftImage()
{
    current_image--;
    switch(current_image)
    {
    case 1:
     disconnect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
     connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
    break;

    case 2:
     disconnect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
     connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
    break;

    case 3:
      disconnect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
    break;

    case 4:
      disconnect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
    break;

    case 5:
      disconnect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
      connect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
    break;

    case 6:
      connect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));
    break;

    }

}


void CameraOneOption::updateImage1(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}


void CameraOneOption::updateImage2(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}

void CameraOneOption::updateImage3(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}

void CameraOneOption::updateImage4(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}

void CameraOneOption::updateImage5(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}

void CameraOneOption::updateImage6(const QPixmap* image)
{
    pix = *image;

    if(!image->isNull()){
    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );
    }

}

int CameraOneOption::heightForWidth( int width ) const
{
    return ((qreal)pix.height()*width)/pix.width();
}


QSize CameraOneOption::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}


CameraOneOption::~CameraOneOption()
{
    delete ui;
}
