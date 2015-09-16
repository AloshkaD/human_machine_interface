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
#include "../.././../../../hmi_cvg_stack-build/human_machine_interface/ui_cameradisplayoption.h"
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


CameraDisplayOption::CameraDisplayOption(QWidget *parent, ImagesReceiver *img_receiver) :
    QWidget(parent),
    ui(new Ui::cameraDisplayOption)
{
    ui->setupUi(this);
    image_receiver=img_receiver;
    current_camera=0; // Widget clicked.
    main_camera=1; // Main widget as main camera image.

    QSignalMapper* signalMapper = new QSignalMapper(this);

    connect(ui->image_camera1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->image_camera2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->image_camera3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->image_camera4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->image_camera5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->image_camera6, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->image_camera1,1);
    signalMapper->setMapping(ui->image_camera2,2);
    signalMapper->setMapping(ui->image_camera3,3);
    signalMapper->setMapping(ui->image_camera4,4);
    signalMapper->setMapping(ui->image_camera5,5);
    signalMapper->setMapping(ui->image_camera6,6);

    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(changeCameraPosition(int)));

    createPixmapsButton();

    connect(image_receiver,SIGNAL(Update_Image(const QPixmap*,int)),this,SLOT(updateImage(const QPixmap*,int)));

    connect(parent, SIGNAL(saveImage(const int)), this, SLOT(saveCameraImages(const int)));

}


void CameraDisplayOption::saveCameraImages(const int camera_view_manager)
{
    QPixmap current_pix;
    if(camera_view_manager==0){
        if(main_camera==1&&!pixmap1.isNull())
            current_pix=pixmap1;
        if(main_camera==2&&!pixmap2.isNull())
            current_pix=pixmap2;
        if(main_camera==3&&!pixmap3.isNull())
            current_pix=pixmap3;
        if(main_camera==4&&!pixmap4.isNull())
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
        QIcon button_icon1(pixmap1);
        if(!image->isNull()){
            ui->image_camera1->setIcon(button_icon1);
            ui->image_camera1->setIconSize(pixmap1.rect().size());
            ui->image_camera1->setFixedSize(pixmap1.rect().size());
        }
        break;
    }
    case 2:{
        pixmap2= *image;
        pixmap2.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon button_icon2(pixmap2);
        if(!image->isNull()){
            ui->image_camera2->setIcon(button_icon2);
            ui->image_camera2->setIconSize(pixmap2.rect().size());
            ui->image_camera2->setFixedSize(pixmap2.rect().size());
        }
        break;
    }
    case 3:{
        pixmap3= *image;
        pixmap3.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon button_icon3(pixmap3);
        if(!image->isNull()){
            ui->image_camera3->setIcon(button_icon3);
            ui->image_camera3->setIconSize(pixmap3.rect().size());
            ui->image_camera3->setFixedSize(pixmap3.rect().size());
        }
        break;
    }
    case 4:{
        pixmap4= *image;
        pixmap4.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QIcon button_icon4(pixmap4);
        if(!image->isNull()){
            ui->image_camera4->setIcon(button_icon4);
            ui->image_camera4->setIconSize(pixmap4.rect().size());
            ui->image_camera4->setFixedSize(pixmap4.rect().size());
        }
        break;
    }
    }

}

void CameraDisplayOption::changeCameraPosition(int id_camera)
{
    QString title_to_swap;
    switch(id_camera)
    {
    case 1:{
        title_to_swap = "Camera 1";
        this->swapWidgets(ui->image_camera1,title_to_swap);
        main_camera=1;
        break;
    }
    case 2:{
        title_to_swap = "Camera 2";
        this->swapWidgets(ui->image_camera2,title_to_swap);
        main_camera=2;
        break;
    }
    case 3:{
        title_to_swap = "Camera 3";
        this->swapWidgets(ui->image_camera3,title_to_swap);
        main_camera=3;
        break;
    }
    case 4:{
        title_to_swap = "Camera 4";
        this->swapWidgets(ui->image_camera4,title_to_swap);
        main_camera=4;
        break;
    }
    case 5:{
        title_to_swap = "Camera 5";
        this->swapWidgets(ui->image_camera5,title_to_swap);
        main_camera=5;
        break;
    }
    case 6:{
        title_to_swap = "Camera 6";
        this->swapWidgets(ui->image_camera6,title_to_swap);
        main_camera=6;
        break;
    }
    }
}

void CameraDisplayOption::swapWidgets(QPushButton* image_to_swap, QString title_to_swap)
{

    QString main_title;
    int row, col, col_span, row_span;
    int index = ui->gridLayout->indexOf(image_to_swap); //position of the imageCamera2

    if(index != -1)
    {
        ui->gridLayout->getItemPosition(index, &row, &col, &col_span, &row_span);
        qDebug() << "Clicked Item is at:" << row << col
                 << "spanning" << row_span << col_span;
    }
    switch(main_camera)
    {
    case 1:{
        main_title="Camera 1";
        ui->gridLayout->addWidget(ui->image_camera1,row,col,row_span,col_span); // Swap main widget in the widget position clicked.
        break;
    }
    case 2:{
        main_title="Camera 2";
        ui->gridLayout->addWidget(ui->image_camera2,row,col,row_span,col_span);
        break;
    }
    case 3:{
        main_title="Camera 3";
        ui->gridLayout->addWidget(ui->image_camera3,row,col,row_span,col_span);
        break;
    }
    case 4:{
        main_title="Camera 4";
        ui->gridLayout->addWidget(ui->image_camera4,row,col,row_span,col_span);
        break;
    }
    case 5:{
        main_title="Camera 5";
        ui->gridLayout->addWidget(ui->image_camera5,row,col,row_span,col_span);
        break;
    }
    case 6:{
        main_title="Camera 6";
        ui->gridLayout->addWidget(ui->image_camera6,row,col,row_span,col_span);
        break;
    }

    }

    ui->gridLayout->addWidget(image_to_swap,1,0,3,2); // add the button to the main grid
    ui->title_camera1->setText(title_to_swap);// add title to the main grid

    if(row==1 && col==0)
        ui->title_camera1->setText(main_title); // add the title to the position grid
    if(row==1 && col==2)
        ui->title_camera2->setText(main_title);
    if(row==3 && col==2)
        ui->title_camera3->setText(main_title);
    if(row==5 && col==2)
        ui->title_camera4->setText(main_title);
    if(row==5 && col==1)
        ui->title_camera5->setText(main_title);
    if(row==5 && col==0)
        ui->title_camera6->setText(main_title);

}

void CameraDisplayOption::createPixmapsButton()
{
    QPixmap pixmap1;
    QIcon button_icon1(pixmap1);
    ui->image_camera1->setIcon(button_icon1);
    ui->image_camera1->setIconSize(ui->image_camera1->sizeHint());

    QPixmap pixmap2;
    QIcon button_icon2(pixmap2);
    ui->image_camera2->setIcon(button_icon2);
    ui->image_camera2->setIconSize(ui->image_camera2->sizeHint());

    QPixmap pixmap3;
    QIcon button_icon3(pixmap3);
    ui->image_camera3->setIcon(button_icon3);
    ui->image_camera3->setIconSize(ui->image_camera3->sizeHint());

    QPixmap pixmap4;
    QIcon ButtonIcon4(pixmap4);
    ui->image_camera4->setIcon(ButtonIcon4);
    ui->image_camera4->setIconSize(ui->image_camera3->sizeHint());

    QPixmap pixmap5;
    QIcon button_icon5(pixmap5);
    ui->image_camera5->setIcon(button_icon5);
    ui->image_camera5->setIconSize(ui->image_camera3->sizeHint());

    QPixmap pixmap6;
    QIcon button_icon6(pixmap6);
    ui->image_camera6->setIcon(button_icon6);
    ui->image_camera6->setIconSize(ui->image_camera3->sizeHint());

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
