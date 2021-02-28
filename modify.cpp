#include "modify.h"
#include "ui_modify.h"

Modify::Modify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_ModifyBackBt_clicked()
{
    this->close();
    emit this->ModifyBack();
}

void Modify::on_ModifyButton_clicked()
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" ""){
            QMessageBox::about(NULL, "反馈", "存在空项");
            return;
        }
        QVector<GarbageInfo> allGarbageInfo;    //数据类型为GarbageInfo的QVector容器
        QFile file("C:/Users/sunxin/Documents/garbage-query/garbage.txt");

        file.open(QIODevice::ReadOnly|QIODevice::Text);
        //以只读 的方式打开文本文件
        if(!file.isOpen()){ //如果数据文件没有打开，弹出对话框提示用户
            QMessageBox::about(NULL, "反馈", "数据文件打开失败");
            return;
        }
        //QIODevice::Truncate在写入时会从文件开始处写入，覆盖原有内容
        QTextStream inp(&file);
        //以file建立一个QT的文本流
        while(!inp.atEnd()){
            QString name,classification;
            inp >> name >> classification;
            allGarbageInfo.push_back(GarbageInfo(name, classification));
            //调用之前建立的构造函数实例化一个GarbageInfo对象并将其加入allGarbageInfo
        }
        allGarbageInfo.pop_back();  //文件最后会多读一个无用数据，将其拿出
        file.close();
        QString classification = ui->lineEdit_2->text();
        QString name = ui->lineEdit->text();

        bool flag = false;
        for(QVector<GarbageInfo>::iterator it = allGarbageInfo.begin(); it != allGarbageInfo.end(); it++){
            if(it->getName() == name){
                it->setClass(classification);
                flag = true;
            }
        }
        if(flag){   //如果进行过修改，弹出对话框并更新文件
            QMessageBox::about(NULL, "反馈", "修改成功");
            file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
            //以只写覆盖的方式打开文本文件
            if(!file.isOpen()){ //如果数据文件没有打开，弹出对话框提示用户
                QMessageBox::about(NULL, "反馈", "数据文件打开失败");
                return;
            }
            QTextStream out(&file);
            for(auto i : allGarbageInfo){
                out << i.getName() << " " << i.getClass() << endl;
            }
            file.close();
        }else{
            //如果没有进行修改，弹出不存在对话框
             QMessageBox::about(NULL, "反馈", "垃圾种类不存在！");
        }
        //关闭文件
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        //清空所有输入框
}
