#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include "mainwindow.h"
#include "c_add.h"
#include "add_score.h"
#include "find.h"
namespace Ui {
class teacher;
}

class teacher : public QDialog
{
    Q_OBJECT

public:
    explicit teacher(QWidget *parent = nullptr);
    ~teacher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::teacher *ui;
    QSqlTableModel *model;
};

#endif // TEACHER_H
