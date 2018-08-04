/*
 * SingleGame类的作用：
 *      继承Board类，并自己添加了人机对战功能从而实现了象棋游戏的各种功能
 *       实现人机对战
*/
#ifndef SINGLEGAME_H
#define SINGLEGAME_H

#include "Board.h"

class SingleGame : public Board
{
    Q_OBJECT
public:
    SingleGame()
    {
        _level = 4;             //我让计算机搜索4步，算法还不行，搜索多了计算机直接算个几天几夜
    }

    virtual void click(int id, int row, int col);
    Step* getBestMove();

    /****************************************************
     * 函数名称：void getAllPossibleMove(QVector<Step*>& steps)
     * 函数功能：得到所有计算机可以移动的位置
     * 参数：存储步骤的容器
     * 返回值：无
    ****************************************************/
    void getAllPossibleMove(QVector<Step*>& steps);

    void fakeMove(Step* step);//尝试移动一步棋
    void unfakeMove(Step* step);//还原移动的那步棋
    int calcScore();//计算局面分

    /****************************************************
     * 函数名称：int getMinScore(int level, int curMaxScore)
     * 函数功能：得到计算机移动这一步后可以到的最小分值
     * 参数：递归中的第几次计算， 上一次计算中的最大值
     * 返回值：得到的最小分值
    ****************************************************/
    int getMinScore(int level, int curMaxScore);
    int getMaxScore(int level, int curMinScore);

    int _level;

public slots:
    void computerMove();


};

#endif // SINGLEGAME_H
