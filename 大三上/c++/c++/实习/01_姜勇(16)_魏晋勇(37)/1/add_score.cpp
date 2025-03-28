#include "add_score.h"
#include "ui_add_score.h"

add_score::add_score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_score)
{
    ui->setupUi(this);

}

add_score::~add_score()
{
    delete ui;
}




void add_score::on_pushButton_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();//操作数据库表的类

    // 设置数据表
    model->setTable("S_C_INFO");
    QStringList headerLabels;//存储和操作字符串列表
    headerLabels << "学号" << "课程号" << "学分"<<"成绩"; // 自定义表头标签
    model->setHeaderData(0, Qt::Horizontal, headerLabels[0]);//设置模型头部的数据。
    model->setHeaderData(1, Qt::Horizontal, headerLabels[1]);
    model->setHeaderData(2, Qt::Horizontal, headerLabels[2]);
    model->setHeaderData(3, Qt::Horizontal, headerLabels[3]);

    // 设置编辑策略，允许在表格中进行编辑
    model->setEditStrategy(QSqlTableModel::OnFieldChange);


    // 选择数据
    model->select();

    // 将QSqlTableModel设置给tableView
    ui->tableView->setModel(model);
}


void add_score::on_pushButton_2_clicked()
{
    close();
}

