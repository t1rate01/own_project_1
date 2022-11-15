#include "enemy.h"
#include <QObject>
#include "myplayer.h"
#include "game.h"
extern game * newgame;

enemy::enemy(int x, int y)
{
    viewx=x;
    viewy=y;
    //set random pos
    setPos(rand()%viewx-pixmap().width(),0);

 setPixmap(QPixmap(":/images/ufo.png"));
 QTimer * enemytimer = new QTimer();
 connect(enemytimer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
 enemytimer->start(25);

}

enemy::~enemy()
{
qDebug()<< "enemy destructor";
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
    if(pos().y() > viewy){
        newgame->healths->decreasehealth();
        scene()->removeItem(this);
        delete this;       
    }
    else
setPos(x(),y()+1);

}
