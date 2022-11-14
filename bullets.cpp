#include "bullets.h"
#include <QObject>
#include "enemy.h"

bullets::bullets(int bx, int by)
{
    int bulletx = bx;
    int bullety = by;
    // draw the bullet
    setRect(0,0,bulletx,bullety);
   // connect with timer
    QTimer * bullettimer = new QTimer();
    connect(bullettimer,SIGNAL(timeout()),this,SLOT(movebullet()));

    bullettimer->start(10);
}

void bullets::movebullet()
{
    // check for collision, if yes destroy both -> QGraphicsitem has colliding items member function
    QList<QGraphicsItem *> colliding_bullet = collidingItems();
    for (int i = 0, n = colliding_bullet.size(); i < n; ++i){
        if (typeid(*(colliding_bullet[i])) == typeid(enemy)){
            //remove both, first the enemy then the bullet
            scene()->removeItem(colliding_bullet[i]);
            scene()->removeItem(this);
            delete colliding_bullet[i];
            delete this;
        }
    }

    // check if bullet has room to move within scene window
    if(pos().y()+rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug()<< " bullet deleted" ;
    }
    else
 qDebug()<< "moving the bullet";
    // move bullet
 setPos(x(),y()-2);
}
