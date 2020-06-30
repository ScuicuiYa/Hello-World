#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include"QSqlDatabase"
#include"QMessageBox"
#include"QSqlError"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,1);
      qDebug()<<"构造了dialog窗口"<<endl;
      qDebug()<<QSqlDatabase::drivers();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonExit_clicked()
{
    emit sendsignal();
        this->close();
}

void Dialog::on_buttonSure_clicked()
{
    QString str = ui->textEdit->toHtml();
    qDebug()<<str;

    QDateTime time = QDateTime::currentDateTime();
    QString str_1 = time.toString("yyyy-MM-dd");
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QFile data(str_1+".txt");
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out<<ui->textEdit->toPlainText();
    }
    data.close();

    if (!data.open(QIODevice::ReadOnly | QIODevice::Text))
       {
            qDebug()<<"Can't open the file!"<<endl;
            return;
       }
       QTextStream in(&data);  //文件流
       QString line = in.readLine() ;   //读取一行
       while (!line.isNull())
       {
           line = in.readLine();
           QList<QString> list=line.split(",");
  //截取的每一个操作

       }




    ui->textEdit->clear();

}















