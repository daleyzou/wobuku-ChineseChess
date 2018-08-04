/*
 * Login类的作用：
 *      用户可以登录或者是注册
 *       登录成功-》usernameDialog进入游戏界面
 *       注册按钮-》registerDialog开始注册
*/
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDir>
#include <QTextStream>
#include "adminDialog.h"
#include "infoDelegate.h"
#include "infoModel.h"
#include "userNameDialog.h"
#include "registerDialog.h"


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void reLoad();   //让用户重新输入用户名和密码


    void on_registButton_clicked();

private:
    Ui::Login *ui;
    userNameDialog* gameEntrance;
    QList<QString> userNames;
    QList<QString> passWords;
    adminDialog* admin;
    registerDialog* re;
    void getInfo();  //从文件中获取用户名和密码
    void login();    //判断输入的用户名和密码是否正确
signals:
    void findUserName(int);
};

#endif // LOGIN_H
