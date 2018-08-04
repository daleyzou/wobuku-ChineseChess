/*
 * registerDialog类的作用：
 *      显示用户注册窗口，并把合乎规定的数据写入文件中
*/
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "infoModel.h"
#include "globalfunction.h"

namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = 0);
    ~registerDialog();

private slots:
    void on_registerButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::registerDialog *ui;
};

#endif // REGISTERDIALOG_H
