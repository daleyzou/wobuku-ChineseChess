/*
 * userNameDialog类的作用：
 *      在用户开始游戏之前（即进入游戏之前）可以更改昵称、密码
 *       点击开始游戏可以进入MainWnd开始游戏（也就是可以再来一次游戏的功能）
 *
*/
#include "userNameDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDialog>

userNameDialog::userNameDialog(QWidget *parent) : QDialog(parent), pd(true), _t(-1)
{
    modify = new infoModel(this);
    w = new MainWnd();
    enter_button = new QPushButton("进入游戏");
    enter_button->setFixedSize(500, 100);
    enter_button->setStyleSheet("QPushButton{font-family:'Microsoft YaHei';font-size:50px;color:blue;background:white}");
    code_button = new QPushButton("更改信息");
    finish_button = new QPushButton("完成");
    close_button = new QPushButton("关闭");
    passWD_group = new QGroupBox("更改信息");
    oldPwd_label = new QLabel("原密码");
    newPwd_label = new QLabel("新密码");
    configPwd_label = new QLabel("确认新密码");
    nickName_label = new QLabel("昵称");
    nickName_edit = new QLineEdit;
    oldPwd_edit = new QLineEdit;
    oldPwd_edit->setEchoMode(QLineEdit::Password);

    newPwd_edit = new QLineEdit;
    newPwd_edit->setEchoMode(QLineEdit::Password);

    configPwd_edit = new QLineEdit;
    configPwd_edit->setEchoMode(QLineEdit::Password);
    //垂直布局
    //label标签列
    QVBoxLayout* label_layout = new QVBoxLayout;
    label_layout->addWidget(nickName_label);
    label_layout->addWidget(newPwd_label);
    label_layout->addWidget(oldPwd_label);
    label_layout->addWidget(configPwd_label);

    //LineEdit输入框列
    QVBoxLayout* edit_layout = new QVBoxLayout;
    edit_layout->addWidget(nickName_edit);
    edit_layout->addWidget(newPwd_edit);
    edit_layout->addWidget(oldPwd_edit);
    edit_layout->addWidget(configPwd_edit);

    QVBoxLayout* finish_layout = new QVBoxLayout;
    finish_layout->addStretch();
    finish_layout->addWidget(finish_button);

    QHBoxLayout* group_layout = new QHBoxLayout;
    group_layout->addLayout(label_layout);
    group_layout->addStretch();
    group_layout->addLayout(edit_layout);

    QHBoxLayout* passWD_layout = new QHBoxLayout;
    passWD_layout->addLayout(group_layout);
    passWD_layout->addLayout(finish_layout);
    passWD_group->setLayout(passWD_layout);

    QHBoxLayout* button_layout = new QHBoxLayout;
    button_layout->addStretch();
    button_layout->addWidget(code_button);
    button_layout->addWidget(close_button);

    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->addWidget(enter_button);
    main_layout->addStretch();
    main_layout->addLayout(button_layout);
    main_layout->addWidget(passWD_group);
    passWD_group->hide();
    //信号与槽
    connect(enter_button, SIGNAL(clicked()), this, SLOT(beginTheGame()));
    connect(code_button, SIGNAL(clicked()), this, SLOT(changeData()));
    connect(close_button, SIGNAL(clicked()), this, SLOT(close()));
    connect(finish_button, SIGNAL(clicked()), this, SLOT(newFileData()));
    connect(this, SIGNAL(beginAnimation(int)),w, SLOT(intoGame(int)));

    setLayout(main_layout);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);
}

userNameDialog::~userNameDialog()
{

}

void userNameDialog::changeData()
{
    if (pd == true)
    {
        modify->showData();
        QString str = modify->nickName.at(_t);
        nickName_edit->setText(str);
        code_button->setText("取消更改");
        passWD_group->show();
        pd = false;
    }
    else if (pd == false)
    {
        code_button->setText("修改密码");
        passWD_group->hide();
        oldPwd_edit->clear();
        newPwd_edit->clear();
        configPwd_edit->clear();
        pd = true;
    }
}

void userNameDialog::newFileData()
{
    if (nickName_edit->text().isEmpty())
    {
        QMessageBox::warning(this, "waring", "昵称不能为空", QMessageBox::Ok);
        return;
    }
    if (newPwd_edit->text().isEmpty())
    {
        QMessageBox::warning(this, "waring", "新密码不能为空", QMessageBox::Ok);
        return;
    }
    if (newPwd_edit->text() != configPwd_edit->text())
    {
        QMessageBox::warning(this, "waring", "两次输入密码不一致，请重新输入", QMessageBox::Ok);
        newPwd_edit->clear();
        configPwd_edit->clear();
        return;
    }
    if (oldPwd_edit->text() != modify->password.at(_t))
    {
        QMessageBox::warning(this, "waring", "原密码输入错误", QMessageBox::Ok);
        oldPwd_edit->clear();
        return;
    }
    modify->modifyData(nickName_edit->text() ,newPwd_edit->text(), _t);
    modify->writeData();
    pd = false;
    this->changeData();
    QMessageBox::information(this, "修改密码成功", "您的密码已经修改成功啦！去game一把吧！", QMessageBox::Ok);
}
void userNameDialog::beginTheGame()
{
    emit beginAnimation(_t);                //传递登录的用户序号，方便MainWind显示昵称
    w->setWindowTitle("我的中国象棋小程序");
    w->show();
    return;
}

void userNameDialog::closeEvent(QCloseEvent *)
{
    emit hasleave();
    hide();
}

void userNameDialog::looking(int pi)
{
    _t = pi;
}

