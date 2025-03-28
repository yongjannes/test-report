#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this); // 创建一个新的 QSqlTableModel 对象，并将其赋值给变量 model
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);// 设置编辑策略为手动提交模式
    ui->tableView->setModel(model);// 将表格视图的模型设置为刚刚创建的 model
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    add a;
    a.exec();
}


void admin::on_pushButton_3_clicked()
{
    model->setTable("user");
    model->select();
}


void admin::on_pushButton_2_clicked()
{
    int currow=ui->tableView->currentIndex().row();//获取当前选中行的行号（currow）。
    if(currow>=0)
    {
    model->removeRow(currow);//从模型（model）中移除当前选中的行。
    int ok=QMessageBox::warning(this,"警告","确定删除？",QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No)
       model->revertAll();//撤销所有更改
     else
       model->submitAll();//提交所有更改
    }
    else
    {
      QMessageBox::warning(this,"警告","请选中一个用户");
    }
}


void admin::on_pushButton_4_clicked()
{
    model->database().transaction();// 开始一个数据库事务
    if(model->submitAll())// 提交所有数据库操作。如果所有操作都成功，则进入if分支。
    {
        model->database().commit();  // 提交事务，将所有更改保存到数据库中
        QMessageBox::information(this,"提示","修改成功");
    }
    else
    {
        model->database().rollback();// 如果提交操作失败，回滚事务，撤销所有未保存的更改
        QMessageBox::warning(this,"警告",model->lastError().text());
    }
    model->select();
}

