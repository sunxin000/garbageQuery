#include "deletegarbage.h"
#include "ui_deletegarbage.h"

DeleteGarbage::DeleteGarbage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteGarbage)
{
    ui->setupUi(this);
}

DeleteGarbage::~DeleteGarbage()
{
    delete ui;
}

void DeleteGarbage::on_DeleteBackBt_clicked()
{
    this->close();
    emit this->DeleteGarbageBack();
}

void DeleteGarbage::on_pushButton_clicked()
{

}
