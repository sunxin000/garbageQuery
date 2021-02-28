#include "menuwidge.h"
#include <QApplication> // 包含一个应用程序类的头文件
#include <QIcon>

// main程序入口，argc命令行变量的数量，argv命令行变量的数组
int main(int argc, char *argv[])
{
    // a应用程序对象，在qt中，应用程序对象有且仅有1个
    QApplication a(argc, argv);
    // 窗口对象，父类为QWidget
    //加载qss文件
    QFile qssFile("C:/Users/sunxin/Documents/garbage-query/style.qss");
    qssFile.open(QFile::ReadOnly); //以只读方式打开
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
    else
    {
        qDebug() << "无法打开文件";
    }


    MenuWidge w;
    // 窗口对象默认不会显示，必须调用show方法
    w.setWindowIcon(QIcon(":./logo.ico"));

    w.show();
    // 让a进入消息循环，不会一闪而过，让代码阻塞到这行
    return a.exec();
}
