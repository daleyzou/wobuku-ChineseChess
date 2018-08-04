/*
 * userNameDialog类的作用：
 *      用户进入游戏之前的停顿窗口
 *      用户可在此窗口中进入游戏或者修改个人信息
*/
#ifndef USERNAMEDIALOG_H
#define USERNAMEDIALOG_H

#include <QWidget>
#include "infoModel.h"
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include "MainWnd.h"

class userNameDialog : public QDialog
{
    Q_OBJECT
public:
    explicit userNameDialog(QWidget *parent = 0);
    ~userNameDialog();
private:
    bool pd;                    //确定更改信息框是隐藏还是显示状态
    int _t;                     //标记登录的用户序号
    infoModel* modify;          //实例化infoModel来实现代码的复用
    QPushButton* enter_button;  //进入游戏按钮
    QPushButton* code_button;   //修改信息按钮
    QPushButton* close_button;  //退出按钮
    QPushButton* finish_button;
    QGroupBox* passWD_group;     //修改个人信息框
    QLabel* nickName_label;
    QLabel* oldPwd_label;
    QLabel* newPwd_label;
    QLabel* configPwd_label;
    QLineEdit* nickName_edit;
    QLineEdit* oldPwd_edit;
    QLineEdit* newPwd_edit;
    QLineEdit* configPwd_edit;
    MainWnd* w;
protected:
    void closeEvent(QCloseEvent *);
signals:
    void hasleave();              //点击关闭按钮发射该信号，由主窗口关闭程序
    void beginAnimation(int);
private slots:
    void changeData();         //处理修改密码下拉框的函数
    void newFileData();        //将修改写入文件的函数
    void beginTheGame();       //开始进入游戏
    void looking(int);         //记录登录的用户信号
};

#endif // USERNAMEDIALOG_H
/**************************************************
 * userNameDialog的功能：
       在用户在登录后可以修改自己的个人信息或者进入游戏
**************************************************/
