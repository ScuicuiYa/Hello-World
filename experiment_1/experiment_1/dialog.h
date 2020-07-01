#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
    void on_backbutton_clicked();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_textEdit_copyAvailable(bool b);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
