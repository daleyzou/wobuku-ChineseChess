#include "registerDialog.h"
#include "ui_registerDialog.h"
#include <QFile>
#include <QMessageBox>

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::on_registerButton_clicked()
{
    if (ui->userNameLineEdit->text().isEmpty())
    {
        QMessageBox::warning(0, "waring", "昵称不能为空！", QMessageBox::Yes);
        return;
    }

    if (ui->pwdLineEdit_1->text().isEmpty())
    {
        QMessageBox::warning(0, "waring", "密码不能为空！", QMessageBox::Yes);
        return;
    }

    if (ui->pwdLineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(0, "waring", "密码不能为空！", QMessageBox::Yes);
        return;
    }

    if (!inputJudge(ui->userNameLineEdit->text(), "123"))
    {
        ui->userNameLineEdit->clear();
        return;
    }

    if (!inputJudge("很开心", ui->pwdLineEdit_1->text()))
    {
        ui->pwdLineEdit_1->clear();
        return;
    }

    if (ui->pwdLineEdit_1->text() != ui->pwdLineEdit_2->text())
    {
        QMessageBox::warning(0, "waring", "两次输入密码不一致，请重新输入！", QMessageBox::Yes);
        ui->pwdLineEdit_1->clear();
        ui->pwdLineEdit_2->clear();
        return;
    }
    else
    {
        if (!ui->pwdLineEdit_1->text().isEmpty() and !ui->userNameLineEdit->text().isEmpty())
        {
            infoModel w;
            w.showData();
            w.addNewData(ui->userNameLineEdit->text(), ui->pwdLineEdit_1->text(),ui->sexBox->currentText(), ui->ageBox->value());
            w.writeData();
            hide();
            return;
        }
    }

}



void registerDialog::on_closeButton_clicked()
{
    close();
}
