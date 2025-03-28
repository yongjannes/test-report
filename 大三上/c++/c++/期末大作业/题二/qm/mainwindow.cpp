#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sqlopen();
    model=new QSqlTableModel(this); // 创建一个新的 QSqlTableModel 对象，并将其赋值给变量 model
    ui->tableView->setModel(model);; // 将表格视图的模型设置为刚刚创建的 model

    ui->statusbar->addWidget(ui->label_4);
    ui->actionba->setStatusTip("保存");
    ui->actiona->setStatusTip("软件说明");
    ui->actiontycuhu->setStatusTip("退出");
    ui->label_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sqlopen()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("QT_book");
    db.setUserName("JY");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"数据库连接成功";
        QSqlQuery query;
        QString creatTableStr = "CREATE TABLE book ("
                                "id varchar(10) PRIMARY KEY, "
                                "name varchar(10) NULL, "
                                "sex varchar(10) NULL, "
                                "age varchar(10) NULL, "
                                "phone varchar(11) NULL,"
                                "address varchar(10) NULL);";
        query.prepare(creatTableStr);
        if(!query.exec()){
            qDebug()<<"query error :"<<query.lastError();
        }
        else{
            qDebug()<<"creat table success!";
        }
        QSqlQuery a;
        a.prepare("INSERT INTO book VALUES(16, '姜勇', '男',22,18309491407,'陇南'), (37, '魏晋勇', '女',22,987654321,'皋兰'), (003, '王五', '男',22,456123789,'广州'), (27, '孙立洋', '男',22,11011011011,'白银')");
        a.exec();
        if(!a.exec()){
            qDebug()<<"a error :"<<query.lastError();
        }
        else{
            qDebug()<<"添加成员成功!";
        }
    }
    else
    {
        qDebug()<<"数据库连接失败";
        return;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setVisible(true);
    model->setTable("book");// 设置表格模型的表名为 "students"
    model->select();// 执行查询操作，从数据库中选择所有记录
}


void MainWindow::on_pushButton_2_clicked()
{
    QString tableContent;

    // 遍历tableView的所有行和列，将每个单元格的内容添加到字符串变量中
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        for (int column = 0; column < ui->tableView->model()->columnCount(); ++column) {
            QModelIndex index = ui->tableView->model()->index(row, column);
            tableContent += ui->tableView->model()->data(index).toString() + "\t";
        }
        tableContent += "\n ";
    }

    // 使用QFileDialog打开一个文件对话框，让用户选择要保存的文件路径和名称
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

    // 如果用户选择了文件，将字符串变量的内容写入到用户选择的文件中
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << tableContent;
            file.close();
        }
    }
}

void MainWindow::on_actiontycuhu_triggered()
{
    close();
}


void MainWindow::on_actionba_triggered()
{
    on_pushButton_2_clicked();
}


void MainWindow::on_actiona_triggered()
{
    QMessageBox::information(this,"帮助","该软件显示班级的通讯信息，然后可以将通讯信息保存下来");
}

