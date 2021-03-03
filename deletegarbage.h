#ifndef DELETEGARBAGE_H
#define DELETEGARBAGE_H

#include <QWidget>

namespace Ui {
class DeleteGarbage;
}

class DeleteGarbage : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteGarbage(QWidget *parent = nullptr);
    ~DeleteGarbage();
signals:
    void DeleteGarbageBack();
private slots:
    void on_DeleteBackBt_clicked();

    void on_pushButton_clicked();

private:
    Ui::DeleteGarbage *ui;
};

#endif // DELETEGARBAGE_H
