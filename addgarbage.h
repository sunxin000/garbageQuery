#ifndef ADDGARBAGE_H
#define ADDGARBAGE_H

#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include "garbageinfo.h"

namespace Ui {
class AddGarbage;
}

class AddGarbage : public QWidget
{
    Q_OBJECT

public:
    explicit AddGarbage(QWidget *parent = nullptr);
    ~AddGarbage();

signals:
    void AddBack();

private slots:
    void on_AddBackBt_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddGarbage *ui;
};

#endif // ADDGARBAGE_H
