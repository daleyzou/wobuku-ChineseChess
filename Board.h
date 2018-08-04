/*
 * Board类的作用：
 *      实现象棋的基本功能（即两个人对战，下方走一步，上方走一步）
 *      已经加入了象棋的全部走棋规则
 *      将棋子和棋盘画在窗口中
*/
#ifndef BOARD_H
#define BOARD_H

#include <QFrame>
#include "Stone.h"
#include "Step.h"
#include <QVector>

class Board : public QFrame
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    ~Board();
    /* game data */
    Stone _s[32];                 //32颗棋子
    int _r;                       //棋子半径
    QPoint _off;
    bool _bSide;                  //棋盘下方
    QVector<Step*> _steps;        //记录棋子移动的容器，方便悔棋

    /* game status */
    int _selectid;                //选择的棋子id
    bool _bRedTurn;               //红色的棋子走棋

    /****************************************************
     * 函数名称：void init(bool bRedSide)
     * 函数功能：Board的入口
     * 参数：是否为红棋
     * 返回值：无
    ****************************************************/
    void init(bool bRedSide);

    /* draw functions */
    void paintEvent(QPaintEvent *);
    void drawPlate(QPainter& p);
    void drawPlace(QPainter& p);

    void drawStone(QPainter& p);
    /****************************************************
     * 函数名称：void drawStone(QPainter& p, int id)
     * 函数功能：画棋子
     * 参数：画笔，棋子的ID
     * 返回值：无
    ****************************************************/
    void drawStone(QPainter& p, int id);

    /****************************************************
     * 函数名称：QPoint center(int row, int col);
     * 函数功能：将数学模型中的点转换为计算机能懂的点
     * 参数：数学模型中的行，数学模型中的列
     * 返回值：计算机能懂的点
    ****************************************************/
    QPoint center(int row, int col);
    QPoint center(int id);
    /****************************************************
     * 函数名称：QPoint topLeft(int row, int col)
     * 函数功能：得到棋子左上角的坐标
     * 参数：棋子的横坐标，棋子的列坐标
     * 返回值：棋子左上角的坐标
    ****************************************************/
    QPoint topLeft(int row, int col);
    QPoint topLeft(int id);

    /****************************************************
     * 函数名称：QRect cell(int row, int col)
     * 函数功能：定义一个能写字的方框
     * 参数：棋子的横坐标，棋子的列坐标
     * 返回值：一个方框
    ****************************************************/
    QRect cell(int row, int col);
    QRect cell(int id);

    bool getClickRowCol(QPoint pt, int& row, int& col);

    /* help function */
    QString name(int id);
    bool red(int id);
    bool sameColor(int id1, int id2);
    int getStoneId(int row, int col);
    void killStone(int id);
    void reliveStone(int id);
    void moveStone(int moveid, int row, int col);
    bool isDead(int id);

    /* move stone */
    void mouseReleaseEvent(QMouseEvent *);//鼠标释放的事件
    void click(QPoint pt);
    virtual void click(int id, int row, int col);
    /****************************************************
     * 函数名称：void trySelectStone(int id)
     * 函数功能：选定要移动的棋子
     * 参数：想选定棋子的ID
     * 返回值：无
    ****************************************************/
    void trySelectStone(int id);
    void tryMoveStone(int killid, int row, int col);
    void moveStone(int moveid, int killid, int row, int col);
    void saveStep(int moveid, int killid, int row, int col, QVector<Step*>& steps);
    void backOne();//悔棋函数
    void back(Step* step);
    virtual void back();

    /* rule */
    bool canMove(int moveid, int killid, int row, int col);
    bool canMoveChe(int moveid, int killid, int row, int col);
    bool canMoveMa(int moveid, int killid, int row, int col);
    bool canMovePao(int moveid, int killid, int row, int col);
    bool canMoveBing(int moveid, int killid, int row, int col);
    bool canMoveJiang(int moveid, int killid, int row, int col);
    bool canMoveShi(int moveid, int killid, int row, int col);
    bool canMoveXiang(int moveid, int killid, int row, int col);

    bool canSelect(int id);

    /* rule helper */
    /****************************************************
     * 函数名称：int getStoneCountAtLine(int row1, int col1, int row2, int col2)
     * 函数功能：得到选定棋子和将要移动到位置之间的棋子个数
     * 参数：选定棋子和将要移动到位置的横坐标，列坐标
     * 返回值：棋子个数
    ****************************************************/
    int getStoneCountAtLine(int row1, int col1, int row2, int col2);

    //relation:移动棋子应满足的数学条件
    int relation(int row1, int col1, int row, int col);
    bool isBottomSide(int id);//是不是棋盘下方

    //GetRowCol:得到moveid的横坐标和列坐标
    void GetRowCol(int &row, int &col, int moveid);

signals:
    void Win();     //玩家赢的信号
    void Fail();    //玩家输的信号

public slots:
    void slotBack();        //悔棋

};

#endif // BOARD_H
