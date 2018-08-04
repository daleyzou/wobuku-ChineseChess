/*
 * Step类的作用：
 *      定义一颗棋子的全部属性（从哪里来，到哪里去，要杀死那颗棋子）
 *      这样做是为了方便悔棋
*/
#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step : public QObject
{
    Q_OBJECT
public:
    explicit Step(QObject *parent = 0);
    ~Step();

    int _moveid;
    int _killid;
    int _rowFrom;
    int _colFrom;
    int _rowTo;
    int _colTo;

signals:

public slots:
};

#endif // STEP_H
