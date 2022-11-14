#include "score.h"


score::score(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    scorecount = 0;

    // draw the score to text

    setPlainText("Score : " + QString::number(scorecount));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void score::increasescore()
{
    scorecount ++;
    setPlainText("Score :" + QString::number(scorecount));

}


int score::getscore()
{
    return scorecount;
}

