#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QFile>
#include<QDateTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_buttonSure_clicked();

    void on_buttonExit_clicked();

signals:
    void sendsignal();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
