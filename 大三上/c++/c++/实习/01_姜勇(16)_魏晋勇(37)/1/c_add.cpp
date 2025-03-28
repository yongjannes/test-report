#include "c_add.h"
#include "ui_c_add.h"

c_add::c_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::c_add)
{
    ui->setupUi(this);
}

c_add::~c_add()
{
    delete ui;
}

void c_add::on_pushButton_clicked()
{
    QSqlQuery selectQuery;//执行 SQL 查询和命令
    selectQuery.prepare("SELECT c_number FROM c_info WHERE c_number = ?");
    QString nember=ui->lineEdit->text();
    selectQuery.addBindValue(nember);
    selectQuery.exec();

    if (selectQuery.next()) {//如果查询结果中有下一条记录
        QMessageBox::warning(this, "警告", "课程已存在");
        clearline();
        return;
    }else
    {
        QSqlQuery query;
        query.prepare("insert into c_info values(?,?,?,?,?,?)");
        QString number=ui->lineEdit->text();
        QString name=ui->lineEdit_2->text();
        QString teacher=ui->lineEdit_3->text();
        QString total=ui->lineEdit_4->text();
        QString credit=ui->lineEdit_5->text();
        QString type=ui->lineEdit_6->text();


        if(number==""||name == ""||teacher==""||total==""||credit==""||type=="")
        {
            QMessageBox::information(this,"提示","请输入完整的信息");
            return;
        }else
        {
            query.addBindValue(number);
            query.addBindValue(name);
            query.addBindValue(teacher);
            query.addBindValue(total);
            query.addBindValue(credit);
            query.addBindValue(type);
        if(query.exec())
            {
           QMessageBox::information(this, "提示", "添加课程成功");
            clearline();
            }
            else
            {
           QMessageBox::warning(this, "警告", "添加课程失败: " + query.lastError().text());
            clearline();
            }
        }

}
}

void c_add::clearline()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
}

void c_add::on_pushButton_2_clicked()
{
    close();
}

