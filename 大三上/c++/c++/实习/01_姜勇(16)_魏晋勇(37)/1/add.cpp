#include "add.h"
#include "ui_add.h"
#include "mainwindow.h"
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()
{
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT a_name FROM [user] WHERE a_name = ?");
    QString username=ui->lineEdit->text();
    selectQuery.addBindValue(username);
    selectQuery.exec();

    if (selectQuery.next()) {
        QMessageBox::warning(this, "警告", "账号已存在");
        return;
    }else
    {
        QSqlQuery query;
        query.prepare("insert into [user] (a_name, a_password,power)values(?,?,?)");
        QString name=ui->lineEdit->text();
        QString pass=ui->lineEdit_2->text();
        QString type=ui->lineEdit_3->text();
        QStringList types = {"students", "teacher"};

        if(name==""||pass == ""||type=="")
        {
            QMessageBox::information(this,"提示","请输入完整的信息");
            return;
        }else if (type == "admin")
        {
            QMessageBox::information(this, "提示", "不能添加admin类型的账号");
            clearline();
        } else
        {
            if (!types.contains(type)) {
                QMessageBox::information(this,"提示","请输入正确的权限（students或teacher）");
                return;
            }
            query.addBindValue(name);
            query.addBindValue(pass);
            query.addBindValue(type);
        if(query.exec())
            {
           QMessageBox::information(this, "提示", "添加账号成功");
            clearline();
            }
            else
            {
           QMessageBox::warning(this, "警告", "添加账号失败: " + query.lastError().text());
            }
        }
}
}
void add::clearline()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void add::on_pushButton_2_clicked()
{
    close();
}

