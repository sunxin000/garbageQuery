#ifndef MENUWIDGE_H
#define MENUWIDGE_H

#include <QWidget>
#include "query.h"
#include "addgarbage.h"
#include "modify.h"
#include "deletegarbage.h"


namespace Ui {
class MenuWidge;
}

class MenuWidge : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidge(QWidget *parent = nullptr);
    ~MenuWidge();

private slots:
    void on_QueryButton_clicked();
    void on_BrowserButton_clicked();
    void on_AddButton_clicked();
    void on_ModifyButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::MenuWidge *ui;
};

#endif // MENUWIDGE_H
