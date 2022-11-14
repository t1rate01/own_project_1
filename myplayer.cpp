#include "myplayer.h"
#include "bullets.h"

#include "enemy.h"
#include <QObject>




myplayer::myplayer(int x, int y, int bx, int by, int ex, int ey)
{
viewx = x;
viewy = y;
bulletx = bx;
bullety = by;
enemyx = ex;
enemyy = ey;
}

void myplayer::keyPressEvent(QKeyEvent * event)
{

if(event->key() == Qt::Key_Left){
    if(pos().x() > 0){
    setPos(x()-10,y());
    qDebug()<<"Move left";
}}
else if(event->key() == Qt::Key_Right){
    if(pos().x() + rect().width() < viewx ){
    setPos(x()+10,y());
    qDebug()<<"Move right";
}}
else if(event->key() == Qt::Key_Space){
    // create a bullet
    bullets * bulletti = new bullets(bulletx,bullety);
    getwidth();
    bulletti->setPos(x()+getwidth()/2,y());
    scene()->addItem(bulletti);
    qDebug()<< "bullet created";
}
}

int myplayer::getwidth()
{
    return rect().width();
}

void myplayer::spawn()
{
    // create an enemy
    enemy * enemies = new enemy(viewx,viewy,enemyx,enemyy);
    scene()->addItem(enemies);  // add to scene !
}
