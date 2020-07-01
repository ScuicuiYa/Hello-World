#include "widget.h"
#include "ui_widget.h"
#include <qapplication.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qapplication.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qstring.h>
#include <qtextstream.h>
#include <qfile.h>
#include <iostream>
#include<QTextEdit>
#include<QFileDialog>
#include<QDebug>
#include<QFile>
#include<QDateTime>
#include<dialog.h>
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()//浏览过往树洞，弹出dialog.ui界面
{
    Dialog *dialog=new Dialog(this);
    dialog->setModal(true);
    dialog->show();//弹出新界面

}

void Widget::on_pushButton_2_clicked()//点击后保存树洞内容至本地
{   QString str = ui->textEdit->toPlainText();
    qDebug()<<str;
    QDateTime time = QDateTime::currentDateTime();
    QString str_1 = time.toString("yyyyMMdd");
    QFile data(str_1+".txt");
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out<<ui->textEdit->toPlainText();
    }
    data.close();//被点击时创建一个新的txt文件并将文本框内容存入（没有同日期的文件时），如果有则覆盖该文件内容
}

void Widget::on_backbutton_2_clicked()//返回主界面，合并的时候写
{

}

void Widget::on_textEdit_copyAvailable(bool b)//树洞内容
{
    //提取树洞内容
//QString name = ui->textEdit->toPlainText();
}
