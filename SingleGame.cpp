#include "SingleGame.h"
#include <QTimer>
void SingleGame::click(int id, int row, int col)
{
    int t = 0;
    if (!this->_bRedTurn)
    {
        return;
    }
    if (_selectid != -1)
    {
        if (canMove(_selectid, id, row, col))
        {
            if (row == _s[20]._row and col == _s[20]._col)
            {
                t = 1;
            }
        }
    }
        Board::click(id, row, col);
        if (t == 1)
        {
            emit Win();
        }

    if (!this->_bRedTurn)
    {
        QTimer::singleShot(100, this, SLOT(computerMove()));//先在棋盘上移动，再让计算机去思考
    }
}

void SingleGame::computerMove()
{
    Step* step = getBestMove();
    moveStone(step->_moveid, step->_killid, step->_rowTo, step->_colTo);
    if (step->_killid == 4)
    {
        emit Fail();
    }
    delete step;
    update();
}

void SingleGame::getAllPossibleMove(QVector<Step*>& steps)
{
    int min = 16, max = 32;
    if (this->_bRedTurn)
    {
        min = 0;
        max = 16;
    }

    for (int i = min; i < max; i++)
    {
        if (_s[i]._dead)
        {
             continue;
        }
        for (int row = 0; row <= 9; row++)
        {
            for (int col = 0; col <= 8; col++)
            {
                int killid = this->getStoneId(row, col);
                if (sameColor(killid, i))
                {
                    continue;
                }
                if (canMove(i, killid, row, col))
                {
                    saveStep(i, killid, row, col, steps);
                }
            }
        }
    }
}

void SingleGame::fakeMove(Step* step)
{
    killStone(step->_killid);
    moveStone(step->_moveid, step->_rowTo, step->_colTo);
}

void SingleGame::unfakeMove(Step* step)
{
   reliveStone(step->_killid);
   moveStone(step->_moveid, step->_rowFrom, step->_colFrom);
}

int SingleGame::calcScore()
{
    int redTotalScore = 0;
    int blackTotalScore = 0;
    static int chessScore[] = {100, 50, 50, 20, 1500, 10, 10};//按照棋子初始化的顺序给棋子赋分数

    for (int i = 0; i < 16; i++)
    {
        if (_s[i]._dead)
        {
            continue;
        }
        redTotalScore += chessScore[_s[i]._type];
    }
    for (int i = 16; i < 32; i++)
    {
        if (_s[i]._dead)
        {
            continue;
        }
        blackTotalScore += chessScore[_s[i]._type];
    }
    return blackTotalScore - redTotalScore;
}

int SingleGame::getMaxScore(int level, int curMinScore)
{
    if (level == 0)
    {
        return calcScore();
    }
    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int maxScore = -100000;
    while (steps.count())
    {
        Step* step = steps.back();
        steps.removeLast();
        fakeMove(step);
        int score = getMinScore(level - 1, maxScore);
        unfakeMove(step);
        delete step;
        if (score >= curMinScore)
        {
            while (steps.count())
            {
                Step* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return score;
        }
        if (score > maxScore)
        {
           maxScore = score;
        }

    }
    return maxScore;
}

int SingleGame::getMinScore(int level, int curMaxScore)
{
    if (level == 0)
    {
        return calcScore();
    }
    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int minScore = 100000;
    while (steps.count())
    {
        Step* step = steps.back();
        steps.removeLast();
        fakeMove(step);
        int score = getMaxScore(level - 1, minScore);
        unfakeMove(step);

        delete step;
        if (score <= curMaxScore)
        {
            while (steps.count())
            {
                Step* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return score;
        }

        if (score < minScore)
        {
           minScore = score;
        }

    }
    return minScore;
}

Step* SingleGame::getBestMove()
{
   QVector<Step*> steps;
   getAllPossibleMove(steps);

   int maxScore = -1000000;
   Step* ret = NULL;
   while (steps.count())
   {
       Step* step = steps.back();
       steps.removeLast();
       fakeMove(step);
       int score = getMinScore(_level - 1, maxScore);
       unfakeMove(step);
       if (score > maxScore)
       {
           if (ret)
           {
               delete ret;
           }
           ret = step;
           maxScore = score;
       }
       else
       {
           delete step;
       }
   }

   return ret;
}


