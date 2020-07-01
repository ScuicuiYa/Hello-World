#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <dialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backbutton_2_clicked();

    void on_textEdit_copyAvailable(bool b);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
