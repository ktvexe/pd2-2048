#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}

void result::on_pushButton_clicked()
{
    exit(0);
}

void result::on_pushButton_2_clicked()
{

}
