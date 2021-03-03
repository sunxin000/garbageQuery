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
    QString mention[4] = {"干垃圾即其它垃圾，指除可回收物、有害垃圾、\n\
湿垃圾以外的其它生活废弃物。包括砖瓦陶瓷、\n\
渣土、卫生间废纸、瓷器碎片等难以回收的废弃物。\n\
投放要求:尽量沥干水分。难以辨识类别的生活垃\n\
圾投入干垃圾容器内。",
                          "湿垃圾是居民日常生活及食品加工、饮食服务、\n\
单位供餐等活动中产生的垃圾，包括丢弃不用的\n\
菜叶、剩菜、剩饭、果皮、蛋壳、茶渣、骨头、\n\
动物内脏、鱼鳞、树叶、杂草等，其主要来源为\n\
家庭厨房、餐厅、饭店、食堂、市场及其他与食\n\
品加工有关的行业。",
                          "可回收物指适宜回收利用和资源化利用的生活废弃物。\n\
可回收物主要品种包括：废纸、废塑料、废金属、废\n\
包装物、废旧纺织物、废弃电器电子产品、废玻璃、\n\
废纸塑铝复合包装等。",
                          "分类投放有害垃圾时，应注意轻放。其中：废灯管等\n\
易破损的有害垃圾应该连包装或包裹后投放；废弃药\n\
品应连包装或包裏后一并投放；杀虫剂等压力罐装\n\
容器，应排空内容物后投放；公共场所产生有害垃圾\n\
且未发现对应收集容器时，应携带至有害垃圾投放点\n\
妥善投放。不可投放至其他垃圾桶。"

                         };
    QString name = ui->garbageEdit->text();
    bool flag = false;
    for(auto i : allGarbageInfo){
        if(i.getName() == name){
            //-------------------------------------------
            QString Class = i.getClass();
            if (Class == "干垃圾"){ui->label->setPixmap(QPixmap("../garbage-query/image/干垃圾.png"));ui->ClassLabel->setText(mention[0]);}
                else if (Class == "湿垃圾"){ui->label->setPixmap(QPixmap("../garbage-query/image/湿垃圾.png"));ui->ClassLabel->setText(mention[1]);}
                    else if (Class == "可回收物"){ui->label->setPixmap(QPixmap("../garbage-query/image/可回收物.png"));ui->ClassLabel->setText(mention[2]);}
                        else {ui->label->setPixmap(QPixmap("../garbage-query/image/有害垃圾.png"));ui->ClassLabel->setText(mention[3]);}
            ui->ClassLabel->adjustSize();
            ui->label->show();
            flag = true;
            break;
        }
    }
    if(!flag){
       QMessageBox::about(NULL, "反馈", "未找到该垃圾！");
    }
    ui->garbageEdit->clear();
}


