/*
 * CtrlPanel类的作用：
 *      在游戏窗口旁添加一个窗口，显示用户昵称和悔棋的按钮
 *      用户点击back按钮实现悔棋
*/
#ifndef CTRLPANEL_H
#define CTRLPANEL_H

#include <QWidget>
#include <QPushButton>

class CtrlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CtrlPanel(QWidget *parent = 0);
    ~CtrlPanel();

    QPushButton* _back;

signals:
    void sigBack();

public slots:
};

#endif // CTRLPANEL_H
