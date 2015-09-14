/*
  Camera view - displays multiple cameras
  @author  Yolanda de la Hoz Simón
  @date    06-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/camera_display_option.h"
#include "../.././../../../hmi_cvg_stack /human_machine_interface-build/ui_cameradisplayoption.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qpushbutton.h>
#include <qt4/Qt/qtextdocument.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qbuffer.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4//Qt/qsignalmapper.h>

/*****************************************************************************
** Implementation
*****************************************************************************/


CameraDisplayOption::CameraDisplayOption(QWidget *parent, ImagesReceiver *imgReceiver) :
    QWidget(parent),
    ui(new Ui::cameraDisplayOption)
{
    ui->setupUi(this);
    imageReceiver=imgReceiver;
    current_camera=0; // Widget clicked.
    mainCamera=1; // Main widget as main camera image.

    QSignalMapper* signalMapper = new QSignalMapper(this);

    connect(ui->imageCamera1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->imageCamera2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->imageCamera3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->imageCamera4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->imageCamera5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->imageCamera6, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->imageCamera1,1);
    signalMapper->setMapping(ui->imageCamera2,2);
    signalMapper->setMapping(ui->imageCamera3,3);
    signalMapper->setMapping(ui->imageCamera4,4);
    signalMapper->setMapping(ui->imageCamera5,5);
    signalMapper->setMapping(ui->imageCamera6,6);

    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(changeCameraPosition(int)));

    createPixmapsButton();

    connect(imageReceiver,SIGNAL(Update_Image(const QPixmap*,int)),this,SLOT(updateImage(const QPixmap*,int)));

    connect(parent, SIGNAL(saveImage(const int)), this, SLOT(saveCameraImages(const int)));

}


void CameraDisplayOption::saveCameraImages(const int camera_view_manager)
{
    QPixmap current_pix;
    if(camera_view_manager==0){
        if(mainCamera==1&&!pixmap1.isNull())
            current_pix=pixmap1;
        if(mainCamera==2&&!pixmap2.isNull())
            current_pix=pixmap2;
        if(mainCamera==3&&!pixmap3.isNull())
            current_pix=pixmap3;
        if(mainCamera==4&&!pixmap4.isNull())
            current_pix=pixmap4;

        QImage imageObject = current_pix.toImage();
        QByteArray bytes;
        QBuffer buffer(&bytes);
        buffer.open(QIODevice::WriteOnly);
        current_pix.save(&buffer, "PNG"); // writes pixmap into bytes in PNG format
        QString imagePath = QFileDialog::getSaveFileName(
                    this,
                    tr("Save File"),
                    "",
                    tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                    );

        imageObject.save(imagePath);
    }
}

void CameraDisplayOption::updateImage(const QPixmap* image,int id_camera)
{
    switch(id_camera)
    {
    case 1:{
        pixmap1= *image;
        pixmap1.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon ButtonIcon1(pixmap1);
        if(!image->isNull()){
            ui->imageCamera1->setIcon(ButtonIcon1);
            ui->imageCamera1->setIconSize(pixmap1.rect().size());
            ui->imageCamera1->setFixedSize(pixmap1.rect().size());
        }
        break;
    }
    case 2:{
        pixmap2= *image;
        pixmap2.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon ButtonIcon2(pixmap2);
        if(!image->isNull()){
            ui->imageCamera2->setIcon(ButtonIcon2);
            ui->imageCamera2->setIconSize(pixmap2.rect().size());
            ui->imageCamera2->setFixedSize(pixmap2.rect().size());
        }
        break;
    }
    case 3:{
        pixmap3= *image;
        pixmap3.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon ButtonIcon3(pixmap3);
        if(!image->isNull()){
            ui->imageCamera3->setIcon(ButtonIcon3);
            ui->imageCamera3->setIconSize(pixmap3.rect().size());
            ui->imageCamera3->setFixedSize(pixmap3.rect().size());
        }
        break;
    }
    case 4:{
        pixmap4= *image;
        pixmap4.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon ButtonIcon4(pixmap4);
        if(!image->isNull()){
            ui->imageCamera4->setIcon(ButtonIcon4);
            ui->imageCamera4->setIconSize(pixmap4.rect().size());
            ui->imageCamera4->setFixedSize(pixmap4.rect().size());
        }
        break;
    }
    }

}

void CameraDisplayOption::changeCameraPosition(int id_camera)
{
    QString titleToSwap;
    switch(id_camera)
    {
    case 1:{
        titleToSwap = "Camera 1";
        this->swapWidgets(ui->imageCamera1,titleToSwap);
        mainCamera=1;
        break;
    }
    case 2:{
        titleToSwap = "Camera 2";
        this->swapWidgets(ui->imageCamera2,titleToSwap);
        mainCamera=2;
        break;
    }
    case 3:{
        titleToSwap = "Camera 3";
        this->swapWidgets(ui->imageCamera3,titleToSwap);
        mainCamera=3;
        break;
    }
    case 4:{
        titleToSwap = "Camera 4";
        this->swapWidgets(ui->imageCamera4,titleToSwap);
        mainCamera=4;
        break;
    }
    case 5:{
        titleToSwap = "Camera 5";
        this->swapWidgets(ui->imageCamera5,titleToSwap);
        mainCamera=5;
        break;
    }
    case 6:{
        titleToSwap = "Camera 6";
        this->swapWidgets(ui->imageCamera6,titleToSwap);
        mainCamera=6;
        break;
    }
    }
}

void CameraDisplayOption::swapWidgets(QPushButton* imageToSwap, QString titleToSwap)
{

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
        mainTitle="Camera 1";
        ui->gridLayout->addWidget(ui->imageCamera1,row,col,row_span,col_span); // Swap main widget in the widget position clicked.
        break;
    }
    case 2:{
        mainTitle="Camera 2";
        ui->gridLayout->addWidget(ui->imageCamera2,row,col,row_span,col_span);
        break;
    }
    case 3:{
        mainTitle="Camera 3";
        ui->gridLayout->addWidget(ui->imageCamera3,row,col,row_span,col_span);
        break;
    }
    case 4:{
        mainTitle="Camera 4";
        ui->gridLayout->addWidget(ui->imageCamera4,row,col,row_span,col_span);
        break;
    }
    case 5:{
        mainTitle="Camera 5";
        ui->gridLayout->addWidget(ui->imageCamera5,row,col,row_span,col_span);
        break;
    }
    case 6:{
        mainTitle="Camera 6";
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

void CameraDisplayOption::createPixmapsButton()
{
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

int CameraDisplayOption::heightForWidth( int width ) const
{
    return ((qreal)pix.height()*width)/pix.width();
}

QSize CameraDisplayOption::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

CameraDisplayOption::~CameraDisplayOption()
{
    delete ui;
}
