#ifndef C_ADD_H
#define C_ADD_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class c_add;
}

class c_add : public QDialog
{
    Q_OBJECT

public:
    explicit c_add(QWidget *parent = nullptr);
    ~c_add();
    void clearline();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::c_add *ui;
};

#endif // C_ADD_H
