#include "../include/human_machine_interface/sixcameraoption.h"
#include "../../human_machine_interface-build/ui_sixcameraoption.h"

sixCameraOption::sixCameraOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sixCameraOption)
{
    ui->setupUi(this);
}

sixCameraOption::~sixCameraOption()
{
    delete ui;
}
