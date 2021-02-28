#ifndef MODIFY_H
#define MODIFY_H

#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include "garbageinfo.h"

namespace Ui {
class Modify;
}

class Modify : public QWidget
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = nullptr);
    ~Modify();

signals:
    void ModifyBack();
private slots:
    void on_ModifyBackBt_clicked();
    //void on_ModifyButton_clicked();

    void on_ModifyButton_clicked();

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H
