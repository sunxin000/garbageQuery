#include "query.h"
#include "ui_query.h"

query::query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::query)
{
    ui->setupUi(this);
}

query::~query()
{
    delete ui;
}



void query::on_QueryBackBt_clicked()
{
    this->close();
    emit this->QueryBack();
}

void query::on_QueryButton_clicked()
{
    if(ui->garbageEdit->text() == ""){
        QMessageBox::about(NULL, "反馈", "垃圾名称不能为空");
        return;
    }
    QFile file("C:/Users/sunxin/Documents/garbage-query/garbage.txt");

    //以只读的方式打开文本文件
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){ //文件打开失败
        QMessageBox::about(NULL, "反馈", "文件打开失败");
        return;
    }
    QTextStream inp(&file);
    //以file作为Qt文本流
    QVector<GarbageInfo> allGarbageInfo;
    //数据类型为StudentInfo的QVector容器
    while(!inp.atEnd()){ //读到文件结尾
        QString name;
        QString classfication;
        inp >> name >> classfication;
        allGarbageInfo.push_back(GarbageInfo(name, classfication));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allGarbageInfo.pop_back();
    //扔掉最后的无用数据
    file.close();
    //关闭文件
    QString name = ui->garbageEdit->text();
    bool flag = false;
    for(auto i : allGarbageInfo){
        if(i.getName() == name){
            ui->ClassLabel->setText(i.getClass());
            flag = true;
            break;
        }
    }
    if(!flag){
       QMessageBox::about(NULL, "反馈", "未找到该垃圾！");
    }
    ui->garbageEdit->clear();
}


