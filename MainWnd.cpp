#include "MainWnd.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>


MainWnd::MainWnd(QWidget *parent) : QWidget(parent), _go(-1)
{
    setFixedSize(750, 640);
    game = new SingleGame;
    panel = new CtrlPanel;
    getNickName = new infoModel();
    splash = new QSplashScreen;
    black_label = new QLabel("傻强");
    red_label = new QLabel;

    QVBoxLayout* vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(black_label);
    vLay->addStretch();
    vLay->addWidget(panel);
    vLay->addStretch();
    vLay->addWidget(red_label);
    vLay->addStretch();

    QHBoxLayout* hLay = new QHBoxLayout(this);
    hLay->addWidget(game, 1);
    hLay->addStretch();
    hLay->addLayout(vLay);

    connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
    connect(game, SIGNAL(Fail()), this, SLOT(showFail()));
    connect(game, SIGNAL(Win()), this, SLOT(showWin()));
}

MainWnd::~MainWnd()
{

}
void MainWnd::intoGame(int data)
{
    getNickName->showData();
    str = getNickName->nickName.at(data);
    _go = data;
    red_label->setText(str);
    red_label->setStyleSheet("color:red");
    black_label->setStyleSheet("color:black");
    QFont ft;
    ft.setPointSize(33);
    red_label->setFont(ft);
    black_label->setFont(ft);
}
void MainWnd::showFail()
{

    label = new QLabel;
    label->setStyleSheet("background-image:url(:/images/fail.jpg)");
    label->setFixedSize(750, 640);
    label->show();
    for (int i = 0; i < 100; i++)
    {
        game->slotBack();
    }
    close();
}

void MainWnd::showWin()
{
    label = new QLabel;
    label->setStyleSheet("background-image:url(:/images/win.jpg)");
    label->setFixedSize(750, 640);
    label->show();
    for (int i = 0; i < 100; i++)
    {
        game->slotBack();
    }
    close();
}

