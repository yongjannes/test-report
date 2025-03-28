#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    name=ui->lineEdit->text();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sqlopen()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("score");
    db.setUserName("JY");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"数据库连接成功";
    }else
    {
        qDebug()<<"数据库连接失败"<<db.lastError();
            return;
    }
}
void MainWindow::sqlclose()
{
    if(db.open())
    {
        db.close();
        qDebug()<<"数据库连接关闭";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"提示","请联系管理员修改密码");
}


void MainWindow::on_pushButton_clicked()
{
    sqlopen();
    QSqlQuery query;
    QString sql="SELECT power,a_password FROM [user] WHERE a_name =?";
    query.prepare(sql);
    QString name=ui->lineEdit->text();
    query.addBindValue(name);
    query.exec();
    if(name=="")
    {
        QMessageBox::information(this,"提示","请输入账号");
        return;
    }
    else
    {
        QSqlQuery a;
        a.prepare("SELECT a_name FROM [user] WHERE a_name =?");
        QString sname=ui->lineEdit->text();
        a.addBindValue(sname);
        a.exec();
        if(!a.next())
        {
            QMessageBox::warning(this,"失败","没有该用户，请联系管理员添加");
            return;
        }else
        {

            if(query.next())
            {
                QString pass = ui->lineEdit_2->text();
                QString password = query.value(1).toString();

                if (password != pass) {
                    passworderror++;
                    if (passworderror > 3) {
                        QMessageBox::warning(this, "失败", "密码错误三次，页面将关闭");
                        close();
                        return;
                    }
                    QMessageBox::warning(this, "失败", "用户或密码错误");
                    return;
                }
                passworderror = 0;
                QString power = query.value(0).toString();//从查询结果中获取第一个字段的值
                QString type;
                if(power=="admin")
                {
                    type="管理员";
                }else if(power=="teacher")
                {
                    type="教师";
                }else
                {
                    type="学生";
                }
                QFont font;
                font.setFamily("微软雅黑"); // 设置字体名称
                    font.setPointSize(10); // 设置字体大小
                font.setBold(true); // 设置字体加粗
                font.setItalic(false); // 设置字体是否斜体
                font.setUnderline(false); // 设置字体是否有下划线
                QMessageBox MBox;
                MBox.setWindowTitle("恭喜");
                MBox.setStyleSheet("QMessageBox {"
                                   "    color: white;"
                                   "}"
                                   "QPushButton {"
                                   "    background-color: #d4fbff;"
                                   "    color: black;"
                                   "}"
                                   "QPushButton:hover {"
                                   "    background-color: #d3caca;"
                                   "}");

                MBox.setText(QString("系统登录成功！欢迎%2 %1").arg(sname).arg(type));
                MBox.setFont(font);
                MBox.setIconPixmap(QPixmap("://img/10.jpg"));
                QPushButton *agreeBut = MBox.addButton("确认",QMessageBox::ActionRole);//指定按钮在消息框中的位置或行为。
                if (power == "admin")
                {
                    MBox.exec();
                    admin a;
                    a.exec();

                }else if(power=="students")
                {
                    MBox.exec();
                    students s;
                    s.exec();
                }else if(power=="teacher")
                {
                    MBox.exec();
                    teacher t;
                    t.exec();
                }else
                {
                    QMessageBox::warning(this,"失败","该用户没有权限登录");
                }

            }else
            {
                QMessageBox::warning(this,"失败","用户或密码错误");
            }
        }
    }
    sqlclose();
}

void MainWindow::on_actiona_triggered()
{
    QMessageBox::information(this,"提示","该系统是一个用于管理学校教务信息的软件系统。它通常包括学生信息管理、课程管理、成绩管理、教师管理、选课管理等功能。");
}


void MainWindow::on_actiond_triggered()
{
    QMessageBox::information(this,"学生帮助","输入正确的学生账号和密码之后，登入学生页面，在页面中可以查看自己的信息，以及成绩，还可以进行在线选课和退课。");
}


void MainWindow::on_actionc_triggered()
{
    QMessageBox::information(this,"教师帮助","教师通过密码登录之后，在教务系统可以进行课程管理，添加课程和删除课程，以及对学生成绩的录入。最后发布之后，学生即可登入教务系统后查看。");
}



void MainWindow::on_lineEdit_editingFinished()
{
    ui->lineEdit_2->setFocus();
}



