#ifndef ADD_SCORE_H
#define ADD_SCORE_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class add_score;
}

class add_score : public QDialog
{
    Q_OBJECT

public:
    explicit add_score(QWidget *parent = nullptr);
    ~add_score();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::add_score *ui;
    QSqlTableModel *model;
};

#endif // ADD_SCORE_H
