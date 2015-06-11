#include "convert.h"
#include "ui_convert.h"

convert::convert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::convert)
{
    ui->setupUi(this);
}

convert::~convert()
{
    delete ui;
}
