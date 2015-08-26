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
    pix = *image;

    ui->mainImage->setPixmap(pix);
    ui->mainImage->setScaledContents( true );

}

int cameraoneoption::heightForWidth( int width ) const
{
    return ((qreal)pix.height()*width)/pix.width();
}

QSize cameraoneoption::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}


// TODO:: si hay mas de una cámara añadir botón para pasar imagen.
cameraoneoption::~cameraoneoption()
{
    delete ui;
}
