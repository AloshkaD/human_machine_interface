#include "../include/human_machine_interface/cameraoneoption.h"
#include "../../human_machine_interface-build/ui_cameraoneoption.h"

cameraoneoption::cameraoneoption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cameraoneoption)
{
    ui->setupUi(this);
}

cameraoneoption::~cameraoneoption()
{
    delete ui;
}
