#include "myplayer.h"
#include "bullets.h"

#include "enemy.h"
#include <QObject>




myplayer::myplayer(int x, int y)
{
viewx = x;
viewy = y;

bulletsound = new QMediaPlayer(this);
bulletsound ->setMedia(QUrl("qrc:/sounds/pewpew.wav"));

// set graphic
setPixmap(QPixmap(":/images/player.png"));


}

void myplayer::keyPressEvent(QKeyEvent * event)
{

if(event->key() == Qt::Key_Left){
    if(pos().x() > 0){
    setPos(x()-10,y());
    qDebug()<<"Move left";
}}
else if(event->key() == Qt::Key_Right){
    if(pos().x()+pixmap().width() < viewx ){
    setPos(x()+10,y());
    qDebug()<<"Move right";
}}
else if(event->key() == Qt::Key_Space){
    // create a bullet
    bullets * bulletti = new bullets();
    bulletti->setPos(x()+pixmap().width()/4,y());
    scene()->addItem(bulletti);

    // play the sound
    bulletsound->setPosition(0);
    bulletsound->play();
    // could also use if conditional bulletsound->state() == QMediaPlayer::PlayingState)
    // and QMediaplayer::StoppedState to compare
        // and then setPos to 0, but why not just setPos anyway
}
}


void myplayer::spawn()
{
    // create an enemy
    enemy * enemies = new enemy(viewx,viewy);
    scene()->addItem(enemies);  // add to scene !
}
