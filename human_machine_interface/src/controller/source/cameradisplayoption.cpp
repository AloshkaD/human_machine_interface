#include "../include/cameradisplayoption.h"
#include "../.././../../human_machine_interface-build/ui_cameradisplayoption.h"
#include <QDebug>
#include <qt4/Qt/qpushbutton.h>
#include <qt4/Qt/qtextdocument.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qbuffer.h>
#include <qt4/Qt/qfiledialog.h>



cameradisplayoption::cameradisplayoption(QWidget *parent, imagesReceiver *imgReceiver) :
    QWidget(parent),
    ui(new Ui::cameradisplayoption)
{

       ui->setupUi(this);
       imageReceiver=imgReceiver;
       currentCamera=0; // Widget clicked.
       mainCamera=1; // Main widget as main camera image.

       connect(ui->imageCamera1, SIGNAL(clicked()), this, SLOT(changeCamera1()));
       connect(ui->imageCamera2, SIGNAL(clicked()), this, SLOT(changeCamera2()));
       connect(ui->imageCamera3, SIGNAL(clicked()), this, SLOT(changeCamera3()));
       connect(ui->imageCamera4, SIGNAL(clicked()), this, SLOT(changeCamera4()));
       connect(ui->imageCamera5, SIGNAL(clicked()), this, SLOT(changeCamera5()));
       connect(ui->imageCamera6, SIGNAL(clicked()), this, SLOT(changeCamera6()));

       createPixmapsButton();

       connect(imageReceiver,SIGNAL(Update_Image1(const QPixmap*)),this,SLOT(updateImage1(const QPixmap*)));
       connect(imageReceiver,SIGNAL(Update_Image2(const QPixmap*)),this,SLOT(updateImage2(const QPixmap*)));
       connect(imageReceiver,SIGNAL(Update_Image3(const QPixmap*)),this,SLOT(updateImage3(const QPixmap*)));
       connect(imageReceiver,SIGNAL(Update_Image4(const QPixmap*)),this,SLOT(updateImage4(const QPixmap*)));
       connect(imageReceiver,SIGNAL(Update_Image5(const QPixmap*)),this,SLOT(updateImage5(const QPixmap*)));
       connect(imageReceiver,SIGNAL(Update_Image6(const QPixmap*)),this,SLOT(updateImage6(const QPixmap*)));

       connect(parent, SIGNAL(saveImage(const int)), this, SLOT(saveCameraImages(const int)));

}

void cameradisplayoption::saveCameraImages(const int camera_view_manager){
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

void cameradisplayoption::createPixmapsButton(){
    QPixmap pixmap1;
    QIcon ButtonIcon1(pixmap1);
    ui->imageCamera1->setIcon(ButtonIcon1);
    ui->imageCamera1->setIconSize(ui->imageCamera1->sizeHint());

    QPixmap pixmap2;
    QIcon ButtonIcon2(pixmap2);
    ui->imageCamera2->setIcon(ButtonIcon2);
    ui->imageCamera2->setIconSize(ui->imageCamera2->sizeHint());

    QPixmap pixmap3;
    QIcon ButtonIcon3(pixmap3);
    ui->imageCamera3->setIcon(ButtonIcon3);
    ui->imageCamera3->setIconSize(ui->imageCamera3->sizeHint());

    QPixmap pixmap4;
    QIcon ButtonIcon4(pixmap4);
    ui->imageCamera4->setIcon(ButtonIcon4);
    ui->imageCamera4->setIconSize(ui->imageCamera3->sizeHint());

    QPixmap pixmap5;
    QIcon ButtonIcon5(pixmap5);
    ui->imageCamera5->setIcon(ButtonIcon5);
    ui->imageCamera5->setIconSize(ui->imageCamera3->sizeHint());

    QPixmap pixmap6;
    QIcon ButtonIcon6(pixmap6);
    ui->imageCamera6->setIcon(ButtonIcon6);
    ui->imageCamera6->setIconSize(ui->imageCamera3->sizeHint());

}

void cameradisplayoption::updateImage1(const QPixmap* image)
{
    pix= *image;
    pix.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QIcon ButtonIcon1(pix);
    if(!image->isNull()){
        ui->imageCamera1->setIcon(ButtonIcon1);
        ui->imageCamera1->setIconSize(pix.rect().size());
        ui->imageCamera1->setFixedSize(pix.rect().size());
    }

}


void cameradisplayoption::updateImage2(const QPixmap* image)
{
    QPixmap pix= *image;
    QIcon ButtonIcon2(pix);
    if(!image->isNull()){
        ui->imageCamera2->setIcon(ButtonIcon2);
        ui->imageCamera2->setIconSize(pix.rect().size());
    }

}


void cameradisplayoption::updateImage3(const QPixmap* image)
{
    QPixmap pix= *image;
    QIcon ButtonIcon3(pix);
    if(!image->isNull()){
        ui->imageCamera3->setIcon(ButtonIcon3);
        ui->imageCamera3->setIconSize(ui->imageCamera3->sizeHint());
    }

}



void cameradisplayoption::updateImage4(const QPixmap* image)
{
    QPixmap pix= *image;
    QIcon ButtonIcon4(pix);
    if(!image->isNull()){
        ui->imageCamera4->setIcon(ButtonIcon4);
        ui->imageCamera4->setIconSize(ui->imageCamera4->sizeHint());
    }

}

void cameradisplayoption::updateImage5(const QPixmap* image)
{
    QPixmap pix= *image;
    QIcon ButtonIcon5(pix);
    if(!image->isNull()){
        ui->imageCamera5->setIcon(ButtonIcon5);
        ui->imageCamera5->setIconSize(ui->imageCamera5->sizeHint());
    }

}

void cameradisplayoption::updateImage6(const QPixmap* image)
{
    QPixmap pix= *image;
    QIcon ButtonIcon6(pix);
    if(!image->isNull()){
        ui->imageCamera6->setIcon(ButtonIcon6);
        ui->imageCamera6->setIconSize(ui->imageCamera6->sizeHint());
    }

}


void cameradisplayoption::swapWidgets(QPushButton* imageToSwap, QString titleToSwap){

    QString mainTitle;
    int row, col, col_span, row_span;
    int index = ui->gridLayout->indexOf(imageToSwap); //position of the imageCamera2

    if(index != -1)
    {
        ui->gridLayout->getItemPosition(index, &row, &col, &col_span, &row_span);
        qDebug() << "Clicked Item is at:" << row << col
                 << "spanning" << row_span << col_span;
    }
    switch(mainCamera)
    {
     case 1:{
         mainTitle="Camera 1"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera1,row,col,row_span,col_span); // Swap main widget in the widget position clicked.
         break;
     }
     case 2:{
         mainTitle="Camera 2"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera2,row,col,row_span,col_span);
         break;
     }
     case 3:{
         mainTitle="Camera 3"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera3,row,col,row_span,col_span);
         break;
     }
     case 4:{
         mainTitle="Camera 4"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera4,row,col,row_span,col_span);
         break;
     }
     case 5:{
         mainTitle="Camera 5"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera5,row,col,row_span,col_span);
         break;
     }
     case 6:{
         mainTitle="Camera 6"; // main image title
         ui->gridLayout->addWidget(ui->imageCamera6,row,col,row_span,col_span);
         break;
     }

    }

    ui->gridLayout->addWidget(imageToSwap,1,0,3,2); // add the button to the main grid
    ui->titleCamera1->setText(titleToSwap);// add title to the main grid

    if(row==1 && col==0)
    ui->titleCamera1->setText(mainTitle); // add the title to the position grid
    if(row==1 && col==2)
    ui->titleCamera2->setText(mainTitle);
    if(row==3 && col==2)
    ui->titleCamera3->setText(mainTitle);
    if(row==5 && col==2)
    ui->titleCamera4->setText(mainTitle);
    if(row==5 && col==1)
    ui->titleCamera5->setText(mainTitle);
    if(row==5 && col==0)
    ui->titleCamera6->setText(mainTitle);

}

void cameradisplayoption::changeCamera1()
{
    QString titleToSwap = "Camera 1";
    this->swapWidgets(ui->imageCamera1,titleToSwap);
    mainCamera=1; // Update this camera as the main camera.
}

void cameradisplayoption::changeCamera2()
{
     QString titleToSwap = "Camera 2";
     this->swapWidgets(ui->imageCamera2,titleToSwap);
     mainCamera=2;
}

void cameradisplayoption::changeCamera3()
{
    QString titleToSwap = "Camera 3";
    this->swapWidgets(ui->imageCamera3,titleToSwap);
    mainCamera=3;
}

void cameradisplayoption::changeCamera4()
{
    QString titleToSwap = "Camera 4";
    this->swapWidgets(ui->imageCamera4,titleToSwap);
    mainCamera=4;
}
void cameradisplayoption::changeCamera5()
{
    QString titleToSwap = "Camera 5";
    this->swapWidgets(ui->imageCamera5,titleToSwap);
    mainCamera=5;
}
void cameradisplayoption::changeCamera6()
{
    QString titleToSwap = "Camera 6";
    this->swapWidgets(ui->imageCamera6,titleToSwap);
    mainCamera=6;
}

int cameradisplayoption::heightForWidth( int width ) const
{
    return ((qreal)pix.height()*width)/pix.width();
}


QSize cameradisplayoption::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

cameradisplayoption::~cameradisplayoption()
{
    delete ui;
}
