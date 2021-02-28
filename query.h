#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include "garbageinfo.h"
namespace Ui {
class query;
}

class query : public QWidget
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = nullptr);
    ~query();
signals:
    void QueryBack();
private slots:
    void on_QueryBackBt_clicked();
    void on_QueryButton_clicked();

private:
    Ui::query *ui;
};

#endif // QUERY_H
