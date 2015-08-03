#include "../include/human_machine_interface/gridcameraoption.h"
#include "../../human_machine_interface-build/ui_gridcameraoption.h"

gridCameraOption::gridCameraOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gridCameraOption)
{
    ui->setupUi(this);
}

gridCameraOption::~gridCameraOption()
{
    delete ui;
}
