#include "addgarbage.h"
#include "ui_addgarbage.h"

AddGarbage::AddGarbage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGarbage)
{
    ui->setupUi(this);
}

AddGarbage::~AddGarbage()
{
    delete ui;
}


void AddGarbage::on_AddBackBt_clicked()
{
        this->close();
        emit this->AddBack();
}

void AddGarbage::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString classification = ui->lineEdit_2->text();
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" ){
           //插入的五项数据都不能为空，否则在读取文件时会出现问题。
           QMessageBox::about(NULL, "反馈", "存在空项");
           return;
       }
       QFile file("C:/Users/sunxin/Documents/garbage-query/garbage.txt");
       //实例化一个QFile file为我们的数据文件student.txt
       file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
       //open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
       //QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
       //QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾
       if(!file.isOpen()){ //如果数据文件没有打开，弹出对话框提示用户
           QMessageBox::about(NULL, "反馈", "数据文件打开失败");
           return;
       }
       QTextStream out(&file);
       //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
       out<<endl << name << " " <<classification;
       //将我们刚刚获取的数据写入文件
       file.close();
       QMessageBox::about(NULL, "反馈", "插入成功");
       ui->lineEdit_2->clear();
       ui->lineEdit->clear();
       //将用户输入的数据清空
}
