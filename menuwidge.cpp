#include "menuwidge.h"
#include "ui_menuwidge.h"

MenuWidge::MenuWidge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidge)
{
    ui->setupUi(this);
}

MenuWidge::~MenuWidge()
{
    delete ui;
}

void MenuWidge::on_QueryButton_clicked()
{
       query *QueryPage = new query();//在主窗口中实例化子窗口
       this->hide();//this代表主窗口
       QueryPage->show();//显示子窗口
       connect(QueryPage,&query::QueryBack,this,[=](){
          this->show();
           });
}

void MenuWidge::on_BrowserButton_clicked()
{

}

void MenuWidge::on_AddButton_clicked()
{
    AddGarbage *AddPage = new AddGarbage();//在主窗口中实例化子窗口
    this->hide();//this代表主窗口
    AddPage->show();//显示子窗口
    connect(AddPage,&AddGarbage::AddBack,this,[=](){
       this->show();
        });
}


void MenuWidge::on_ModifyButton_clicked()
{
    Modify * ModifyPage = new Modify();//在主窗口中实例化子窗口
    this->hide();//this代表主窗口
    ModifyPage->show();//显示子窗口
    connect(ModifyPage,&Modify::ModifyBack,this,[=](){
       this->show();
        });
}
