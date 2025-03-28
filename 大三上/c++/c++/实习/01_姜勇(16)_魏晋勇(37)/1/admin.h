#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <mainwindow.h>
#include "add.h"
#include <QSqlRecord>
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::admin *ui;
    QSqlTableModel *model;
};

#endif // ADMIN_H
