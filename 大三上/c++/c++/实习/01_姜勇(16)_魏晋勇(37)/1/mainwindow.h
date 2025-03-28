#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlTableModel>
#include <QStandardItemModel>
#include<QDebug>
#include<QMessageBox>
#include "admin.h"
#include "students.h"
#include "teacher.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sqlopen();
    void sqlclose();
    int passworderror=0;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actiona_triggered();

    void on_actiond_triggered();

    void on_actionc_triggered();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QString name;
};
#endif // MAINWINDOW_H
