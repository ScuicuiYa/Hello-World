#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("cloud");
    db.setUserName("root");
    db.setPassword("CNPcnxcyldaj520.");
    bool ok = db.open();
        if(!ok)
        {
            qDebug("数据库连接失败");
        }
        else
        {
           QMessageBox::warning(this,"成功",db.lastError().text());
       }
       db.exec("SET NAMES 'GBK'");
        QSqlQuery query;
           query.exec("create table user(id int primary key auto_increment, name varchar(255), age int, score int);");
           query.prepare("insert into user( name, age, score) values(:name,:age,:score);");
            QVariantList nameList;
            QVariantList ageList;
            QVariantList scoreList;
            //给字段绑定
            query.bindValue(":name",nameList);
            query.bindValue(":score",scoreList);
            query.bindValue(":age",ageList);
            query.execBatch();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    dialog= new Dialog(this);

//    //modal属性决定了show（）应该将弹出的dialog设置为模态还是非模态
//    dialog->setModal(false);    //默认情况下该属性为false并且shou（）弹出的窗口是非模态的
//    dialog->show();              //把这个属性设置为true就相当于设置QWidge::windowModality为Qt::ApplicationModal
//                                //执行exec()忽略modal这个属性，并且把弹出的dialog设置为横态的

       this->hide();//主界面关闭
       Dialog *dialog = new Dialog(this);//新建子界面
       connect(dialog,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
       dialog->show();//子界面出现
}
void MainWindow::reshow()
{
    this->show();
}
