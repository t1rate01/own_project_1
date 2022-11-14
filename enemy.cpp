#include "enemy.h"
#include <QObject>
#include "myplayer.h"
#include "game.h"
extern game * newgame;

enemy::enemy(int x, int y, int ex, int ey)
{
    enemyx = ex;
    enemyy = ey;
    viewx=x;
    viewy=y;
    //set random pos
    setPos(rand()%viewx-(enemyx/2),0);

 setRect(0,0,enemyx,enemyy);
 QTimer * enemytimer = new QTimer();
 connect(enemytimer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
 enemytimer->start(25);

}

void enemy::moveEnemy()
{
    // check if player colliding with enemy
    QList<QGraphicsItem *> colliding_toplayer = collidingItems();
    for (int i = 0, n = colliding_toplayer.size(); i < n; ++i){
        if (typeid(*(colliding_toplayer[i])) == typeid(myplayer)){
            newgame->healths->decreasehealth();
            //remove enemy if collision
            scene()->removeItem(this);
            delete this;
        }
    }
    // check if enemy has room to move within view
    if(pos().y()+rect().height() > viewy){
        newgame->healths->decreasehealth();
        scene()->removeItem(this);
        delete this;
        qDebug()<< " enemy deleted" ;
    }
    else
setPos(x(),y()+1);

}
