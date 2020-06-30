#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog.h"
#include"qwidget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include<QStringList>
#include<QVariantList>
#include<QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void reshow();
signals:
    void sendsignal();
private:
    Ui::MainWindow *ui;
    Dialog *dialog;    //添加私有成员，为一个dialog(窗口)指针
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

};
#endif // MAINWINDOW_H
