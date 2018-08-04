/*
 * MainWind类的作用：
 *      由游戏部分（SingleGame）和悔棋、用户昵称（CtrlPanel）两部分组成
 *      用户在这里进行游戏
*/
#ifndef MAINWND_H
#define MAINWND_H

#include <QWidget>
#include <QSplashScreen>
#include <QLabel>
//#include "Board.h"
#include "CtrlPanel.h"
#include "infoModel.h"
#include "SingleGame.h"

class MainWnd : public QWidget
{
    Q_OBJECT
public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

signals:

private:
    QLabel *label;
    SingleGame* game;//游戏部分
    CtrlPanel* panel;//悔棋部分
    QSplashScreen *splash;//用来实现程序启动动画
    int _go;
    QString str;
    infoModel* getNickName;//用来获取用户的昵称
    QLabel* black_label;
    QLabel* red_label;

private slots:
    void intoGame(int);
    void showWin();
    void showFail();
};

#endif // MAINWND_H
