#include "bullets.h"
#include <QObject>
#include "enemy.h"
#include "game.h"

extern game * newgame;   // there is an external global pointer/object "newgame"

bullets::bullets()
{

    // draw the bullet graphics
    setPixmap(QPixmap(":/images/bullet.png"));
    setTransformOriginPoint(18,18);
    setRotation(270);
   // connect with timer
    QTimer * bullettimer = new QTimer();
    connect(bullettimer,SIGNAL(timeout()),this,SLOT(movebullet()));

    bullettimer->start(10);
}

bullets::~bullets()
{
qDebug()<<"Bullet destructor";
}

void bullets::movebullet()
{
    // check for collision, if yes destroy both -> QGraphicsitem has colliding items member function
    QList<QGraphicsItem *> colliding_bullet = collidingItems();
    for (int i = 0, n = colliding_bullet.size(); i < n; ++i){
        if (typeid(*(colliding_bullet[i])) == typeid(enemy)){
            // incr score
            newgame->scores->increasescore();   // note to self : use the declared object names
            //remove both, first the enemy then the bullet
            scene()->removeItem(colliding_bullet[i]);
            scene()->removeItem(this);
            delete colliding_bullet[i];
            delete this;
        }
    }

    // check if bullet has room to move within scene window
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
    else
    // move bullet
 setPos(x(),y()-2);
}
