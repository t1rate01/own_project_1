#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsSimpleTextItem>
#include <QFont>

// Keep track of all game score variables

class score : public QGraphicsTextItem
{
public:
    score(QGraphicsItem * parent=0);
    void increasescore();

    int getscore();

private:
    int scorecount;

};

#endif // SCORE_H
