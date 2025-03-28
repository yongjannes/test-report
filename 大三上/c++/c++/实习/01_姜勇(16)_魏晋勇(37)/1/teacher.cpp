#include "teacher.h"
#include "ui_teacher.h"
#include<QStandardItemModel>
#include <find.h>
teacher::teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher)
{
    ui->setupUi(this);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->tableView_4->setVisible(false);
}

teacher::~teacher()
{
    delete ui;
}

void teacher::on_pushButton_clicked()
{
    ui->tableView->setVisible(true);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(false);
     ui->pushButton_3->setVisible(false);
     ui->pushButton_4->setVisible(false);
      ui->pushButton_6->setVisible(false);
      ui->pushButton_7->setVisible(false);
      ui->label->setVisible(false);
       ui->lineEdit->setVisible(false);
      ui->pushButton_10->setVisible(false);
       ui->tableView_4->setVisible(false);
    QSqlQuery query;
    // 创建一个QStandardItemModel对象
    QStandardItemModel *model = new QStandardItemModel(this);

    // 设置表头
    model->setHorizontalHeaderLabels(QStringList()<< "工号"  << "姓名" << "电话"<< "电子邮箱");
    query.exec("SELECT * FROM user_2 WHERE id = 40");

    if (query.next())
    {
        QString id = query.value("id").toString();
        QString name = query.value("name").toString();
        QString phone = query.value("phone").toString();
        QString email = query.value("e-mail").toString();

        // 使用查询到的值创建QStandardItem对象，并将它们添加到模型中
        QList<QStandardItem *> items;
        items << new QStandardItem(id)<< new QStandardItem(name) << new QStandardItem(phone)  << new QStandardItem(email);
        model->appendRow(items);

        // 将模型设置为tableView的模型
        ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox::information(this, "提示", "未找到个人信息");
    }
}


void teacher::on_pushButton_2_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(true);
    ui->tableView_3->setVisible(false);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->tableView_4->setVisible(false);
    model=new QSqlTableModel(this); // 创建一个新的 QSqlTableModel 对象，并将其赋值给变量 model
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);// 设置编辑策略为手动提交模式
    ui->tableView_2->setModel(model);; // 将表格视图的模型设置为刚刚创建的 model

    model->setTable("c_info");
    model->setHeaderData(0, Qt::Horizontal, tr("课程号"));
    model->setHeaderData(1, Qt::Horizontal, tr("课程名"));
    model->setHeaderData(2, Qt::Horizontal, tr("授课教师"));
    model->setHeaderData(3, Qt::Horizontal, tr("总学时"));
    model->setHeaderData(4, Qt::Horizontal, tr("学分"));
    model->setHeaderData(5, Qt::Horizontal, tr("类型"));
    model->select();

}


void teacher::on_pushButton_4_clicked()
{
    int currow = ui->tableView_2->currentIndex().row();
    if (currow >= 0) {
        // 获取当前选中行的数据
    QModelIndex currentIndex = ui->tableView_2->model()->index(currow, 0);
    QString courseNumber = ui->tableView_2->model()->data(currentIndex).toString();

   int ok=QMessageBox::warning(this,"警告","确定删除此课程吗？",QMessageBox::Yes,QMessageBox::No);

    if(ok==QMessageBox::Yes)
   {
    QSqlQuery query;
    QString a = "DELETE FROM c_info WHERE c_number = '" + courseNumber + "'";
    query.prepare(a);

    if (query.exec()) {
            QMessageBox::information(nullptr, "成功", "删除成功");
        } else {
            QMessageBox::critical(nullptr, "警告", "删除失败 " + query.lastError().text());
        }
    }else
    {
        return;
    }
    }
    else {
    QMessageBox::warning(nullptr, "提示", "请选择一门课");
    }
}


void teacher::on_pushButton_3_clicked()
{
    c_add c;
    c.exec();
}


void teacher::on_pushButton_5_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(true);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_6->setVisible(true);
     ui->pushButton_7->setVisible(true);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
     ui->pushButton_10->setVisible(false);
     ui->tableView_4->setVisible(false);

    QSqlQuery query;
    if (query.exec("SELECT user_2.name,"
                   " c_info.c_name,"
                   " s_c_info.c_number,"
                   " s_c_info.credit, "
                   "s_c_info.score"
                   " FROM user_2   "
                   "INNER JOIN s_c_info ON"
                   " user_2.id = s_c_info.ID   "
                   "INNER JOIN c_info ON "
                   "s_c_info.c_number = c_info.c_number "))
    {
    // 使用QSqlQueryModel来存储查询结果
    model=new QSqlTableModel(this); // 创建一个新的 QSqlTableModel 对象，并将其赋值给变量 model
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);// 设置编辑策略为手动提交模式
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(1, Qt::Horizontal, tr("课程名称"));
    model->setHeaderData(2, Qt::Horizontal, tr("课程号"));
    model->setHeaderData(3, Qt::Horizontal, tr("课程学分"));
    model->setHeaderData(4, Qt::Horizontal, tr("成绩"));
    ui->tableView_3->setModel(model);
    ui->tableView_3->show();
    }
}


void teacher::on_pushButton_6_clicked()
{
    add_score a;
    a.exec();
}


void teacher::on_pushButton_7_clicked()
{
QSqlQuery query;
if (query.exec("SELECT AVG(TRY_CAST(score AS DECIMAL)) FROM s_c_info"))
{
    if (query.next())
    {
        double averageScore = query.value(0).toDouble();
        QString message = QString("班级平均分为: %1").arg(averageScore);
        QMessageBox::information(this, "平均分", message);
    }
}
else
{
    qDebug() << query.lastError();
}
}


void teacher::on_pushButton_8_clicked()
{
    close();
}


void teacher::on_pushButton_9_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->label->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->pushButton_10->setVisible(true);
    ui->tableView_4->setVisible(true);

}


void teacher::on_pushButton_10_clicked()
{
 // 获取输入的姓名
    QString name = ui->lineEdit->text();

        // 执行模糊查询
        QSqlQuery query;
        query.prepare("SELECT * FROM user_2 WHERE name LIKE ? AND type='students'");
        query.addBindValue("%" + name + "%");
        if (!query.exec()) {
            qDebug() << "查询失败：" << query.lastError().text();
            return;
        }

        // 设置表格视图的数据模型
        QStandardItemModel *model = new QStandardItemModel(0, 3, ui->tableView_4);
        model->setHorizontalHeaderLabels({"姓名", "年龄", "电话","邮箱","类型"});
        while (query.next()) {
            QList<QStandardItem *> items;
            items << new QStandardItem(query.value(0).toString())
                  << new QStandardItem(query.value(1).toString())
                  << new QStandardItem(query.value(2).toString())
                  << new QStandardItem(query.value(3).toString())
                   << new QStandardItem(query.value(4).toString());
            model->appendRow(items);
        }
        ui->tableView_4->setModel(model);
}

