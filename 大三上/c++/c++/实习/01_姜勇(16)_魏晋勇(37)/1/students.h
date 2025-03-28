#ifndef STUDENTS_H
#define STUDENTS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class students;
}

class students : public QDialog
{
    Q_OBJECT

public:
    explicit students(QWidget *parent = nullptr);
    ~students();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::students *ui;
    QSqlTableModel *model;
};

#endif // STUDENTS_H
