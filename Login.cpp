#include "Login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QWidget>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    setWindowTitle("登录");
    ui->userNameLineEdit->setFocus();
    ui->loginButton->setDefault(true);
    admin = new adminDialog();
    gameEntrance = new userNameDialog();
    re = new registerDialog();
    connect(this, SIGNAL(findUserName(int)), gameEntrance, SLOT(looking(int))); 
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    if (ui->pwdLineEdit->text().isEmpty())
    {
        QMessageBox::information(this, "请输入密码", "请先输入密码", QMessageBox::Ok);
        ui->pwdLineEdit->setFocus();
    }
    if (ui->userNameLineEdit->text().isEmpty())
    {
        QMessageBox::information(this, "请输入用户名", "请先输入用户名", QMessageBox::Ok);
        ui->userNameLineEdit->setFocus();
    }
    getInfo();
    login();
}
void Login::getInfo()
{
   QString paths = QDir::currentPath();
   QString namePath = paths + "/info/userName.txt";
   QString pwdPath = paths + "/info/passWord.txt";

   QFile nameFile(namePath);
   QFile pwdFile(pwdPath);

   QTextStream nameIO(&nameFile);
   QTextStream pwdIO(&pwdFile);

   nameFile.open(QIODevice::ReadOnly);
   pwdFile.open(QIODevice::ReadOnly);

   while (!nameIO.atEnd())
   {
       userNames.push_back(nameIO.readLine());
       passWords.push_back(pwdIO.readLine());
   }
}

void Login::login()
{
   if (ui->pwdLineEdit->text() == "admin" and ui->userNameLineEdit->text() == "admin")
   {
       admin->show();
       hide();
       close();
       return;
   }
   for (int i = 0; i < userNames.size(); i++)
   {
       if (ui->userNameLineEdit->text() == userNames.at(i) and ui->pwdLineEdit->text() == passWords.at(i))
       {
           gameEntrance->show();
           emit findUserName(i);
           hide();
           return;
       }
   }
   reLoad();
}

void Login::reLoad()
{
    ui->userNameLineEdit->clear();
    ui->pwdLineEdit->clear();
    QMessageBox::warning(this, "waring", "账号或密码错误", QMessageBox::Yes);
}

void Login::on_registButton_clicked()
{
    re->show();
    //hide();

}
