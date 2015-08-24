#include "../include/human_machine_interface/cameraoneoption.h"
#include "../../human_machine_interface-build/ui_cameraoneoption.h"
#include <qt4/Qt/qframe.h>

cameraoneoption::cameraoneoption(QWidget *parent,imagesReceiver* imgReceiver) :
    QWidget(parent),
    ui(new Ui::cameraoneoption)
{
    ui->setupUi(this);
    imageReceiver=imgReceiver;

    connect(imageReceiver,SIGNAL(Update_Image(const QPixmap*)),this,SLOT(updateImage(const QPixmap*)));
}


void cameraoneoption::updateImage(const QPixmap* image)
{
    ui->mainImage->setPixmap(*image);
}


cameraoneoption::~cameraoneoption()
{
    delete ui;
}
