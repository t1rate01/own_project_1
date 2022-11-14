#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsSimpleTextItem>
#include <QFont>

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
