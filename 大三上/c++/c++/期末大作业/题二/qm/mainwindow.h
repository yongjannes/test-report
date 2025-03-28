#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlTableModel>
#include<QDebug>
#include<QMessageBox>
#include<QFile>
#include <QFileDialog>
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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actiontycuhu_triggered();

    void on_actionba_triggered();

    void on_actiona_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
