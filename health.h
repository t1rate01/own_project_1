#ifndef HEALTH_H
#define HEALTH_H
#include <QFont>
#include <QGraphicsTextItem>


class health : public QGraphicsTextItem
{
public:
    health(QGraphicsItem * parent = 0);
    void decreasehealth();
    int gethealth();
private:
    int hp;
};

#endif // HEALTH_H
