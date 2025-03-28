#include "students.h"
#include "ui_students.h"
#include <QStandardItemModel>
students::students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::students)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this); // 创建一个新的 QSqlTableModel 对象，并将其赋值给变量 model
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);// 设置编辑策略为手动提交模式
    ui->tableView->setModel(model);; // 将表格视图的模型设置为刚刚创建的 model
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(false);
}

students::~students()
{
    delete ui;
}

void students::on_pushButton_clicked()
{
    ui->tableView->setVisible(true);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(false);
    ui->tableView_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(false);
    QSqlQuery query;

    QStandardItemModel *model = new QStandardItemModel(this);//管理二维表格的数据结构

    model->setHorizontalHeaderLabels(QStringList()<< "学号"  << "姓名" << "电话"<< "电子邮箱");
    query.exec("SELECT * FROM user_2 WHERE id = 16");

    if (query.next())
    {
        QString id = query.value("id").toString();
        QString name = query.value("name").toString();
        QString phone = query.value("phone").toString();
        QString email = query.value("e-mail").toString();

        // 创建一个名为items的列表，该列表用于存储指向QStandardItem对象的指针。
        QList<QStandardItem *> items;

        items << new QStandardItem(id)<< new QStandardItem(name) << new QStandardItem(phone)  << new QStandardItem(email);
        model->appendRow(items);


        ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox::information(this, "提示", "未找到个人信息");
    }

}


void students::on_pushButton_2_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(true);
    ui->tableView_3->setVisible(false);
    ui->tableView_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(false);
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
                   "s_c_info.c_number = c_info.c_number "
                   " WHERE user_2.id = 16;;"))
    {
        // 使用QSqlQueryModel来存储查询结果
        QSqlQueryModel *model = new QSqlQueryModel;//来自数据库查询的结果
        model->setQuery(query);//将查询条件应用到模型对象上
        model->setHeaderData(0, Qt::Horizontal, tr("姓名"));
        model->setHeaderData(1, Qt::Horizontal, tr("课程名称"));
        model->setHeaderData(2, Qt::Horizontal, tr("课程号"));
        model->setHeaderData(3, Qt::Horizontal, tr("课程学分"));
        model->setHeaderData(4, Qt::Horizontal, tr("成绩"));
        ui->tableView_2->setModel(model);
        ui->tableView_2->show();
    }
}

void students::on_pushButton_4_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(true);
    ui->tableView_4->setVisible(false);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_7->setVisible(false);

    model=new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_3->setModel(model);
    model->setTable("c_info");
     model->setHeaderData(0, Qt::Horizontal, tr("课程号"));
    model->setHeaderData(1, Qt::Horizontal, tr("课程名"));
    model->setHeaderData(2, Qt::Horizontal, tr("授课教师"));
    model->setHeaderData(3, Qt::Horizontal, tr("总学时"));
    model->setHeaderData(4, Qt::Horizontal, tr("学分"));
    model->setHeaderData(5, Qt::Horizontal, tr("类型"));
    model->select();
}


void students::on_pushButton_5_clicked()
{
// 获取当前学号
QString currentStudentId = "16";

// 用户当前选中的第一行的索引，并将其存储在selectedIndex变量中。
QModelIndex selectedIndex = ui->tableView_3->selectionModel()->selectedRows()[0];//数据模型中项的索引的类

// 获取选中行的数据
QString c_number = ui->tableView_3->model()->data(selectedIndex, 0).toString();
QString credit = ui->tableView_3->model()->data(selectedIndex, 4).toString();
QString score ="";

int ok=QMessageBox::warning(this,"提示","确定选择此课程吗？",QMessageBox::Yes,QMessageBox::No);
if(ok==QMessageBox::Yes)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM s_c_info WHERE id = ? AND c_number = ?");
    query.addBindValue(currentStudentId);
    query.addBindValue(c_number);
    if (query.exec()) {
        if (query.next()) {
            QMessageBox::information(nullptr, "提示", "您已经选过这门课了");
        } else {

            QSqlQuery query;
            query.prepare("INSERT INTO s_c_info (id, c_number, credit,score) VALUES (?, ?, ?,?)");
            query.addBindValue(currentStudentId);
            query.addBindValue(c_number);
            query.addBindValue(credit);
            query.addBindValue(score);

            if (query.exec()) {
                QMessageBox::information(nullptr, "成功", "选课成功");
            } else {

                qDebug() << "选课失败 " << query.lastError().text();
            }
        }
    } else {

        qDebug() << "查询失败 " << query.lastError().text();
    }
}else
{
    return;
}


}


void students::on_pushButton_6_clicked()
{
    ui->tableView->setVisible(false);
    ui->tableView_2->setVisible(false);
    ui->tableView_3->setVisible(false);
    ui->tableView_4->setVisible(true);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(true);

    QSqlQuery query;
    if (query.exec("SELECT s_c_info.c_number, c_name, teacher, total, s_c_info.credit, c_type FROM s_c_info, c_info WHERE s_c_info.c_number = c_info.c_number AND s_c_info.id = 16"))
    {
        // 使用QSqlQueryModel来存储查询结果
        QSqlQueryModel *model1 = new QSqlQueryModel;
        model1->setQuery(query);
        model1->setHeaderData(0, Qt::Horizontal, tr("课程号"));
        model1->setHeaderData(1, Qt::Horizontal, tr("课程名称"));
        model1->setHeaderData(2, Qt::Horizontal, tr("授课教师"));
        model1->setHeaderData(3, Qt::Horizontal, tr("总学时"));
        model1->setHeaderData(4, Qt::Horizontal, tr("课程学分"));
        model1->setHeaderData(5, Qt::Horizontal, tr("课程类型"));
        ui->tableView_4->setModel(model1);
        ui->tableView_4->show();
    }else
    {
        qDebug() << "查询数据失败~！ " << query.lastError().text();
    }
}


void students::on_pushButton_7_clicked()
{
    int currow = ui->tableView_4->currentIndex().row();
    if (currow >= 0) {

    QModelIndex currentIndex = ui->tableView_4->model()->index(currow, 0);
    QString courseNumber = ui->tableView_4->model()->data(currentIndex).toString();

   int ok=QMessageBox::warning(this,"警告","确定退选此课程吗？",QMessageBox::Yes,QMessageBox::No);

    if(ok==QMessageBox::Yes)
   {
    QSqlQuery query;
    QString a = "DELETE FROM s_c_info WHERE c_number = '" + courseNumber + "'";
    query.prepare(a);

    if (query.exec()) {
            QMessageBox::information(nullptr, "成功", "退课成功");
        } else {
            QMessageBox::critical(nullptr, "警告", "退课失败 " + query.lastError().text());
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


void students::on_pushButton_3_clicked()
{
    close();
}



