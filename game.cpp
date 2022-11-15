#include "game.h"

game::game()
{

}

void game::show()
{
    // these values should move all the way down the pipe in constructors
    int windowx=800, windowy=600;
    // new scene
    QGraphicsScene * scene = new QGraphicsScene;
    scene->setBackgroundBrush(QBrush(QImage(":/images/space.jpg")));

    // player to put in the scene
    myplayer * player = new myplayer(windowx,windowy);


    // put the player in to the scene
    scene->addItem(player);

    // only one can be responsive to keyevents, the focused item
    // make focuseable
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // focus on the item
    player->setFocus();

    // new score
    scores = new score;
    scene->addItem(scores);

    // new health
    healths = new health;
    healths->setPos(healths->x(),healths->y()+25);
    scene->addItem(healths);


    // add a view to "see" the concept of scene
    QGraphicsView * view = new QGraphicsView(scene);
    // disable scroll bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setScene(t h e s c e n e );
    view->show();
    view->setFixedSize(windowx,windowy);
    scene->setSceneRect(0,0,windowx,windowy);
    player->setPos(view->width()/2-player->pixmap().width()/2,view->height()-player->pixmap().height());

    // enemy spawner

    QObject::connect(enemyspawner,SIGNAL(timeout()),player,SLOT(spawn()));
    enemyspawner->start(2000);
    // game timer / watching HP for game end
    QObject::connect(gametime,SIGNAL(timeout()),this,SLOT(gametimer()));
    gametime->start(1000);

    // play backgroundmusic
    backgroundmusic = new QMediaPlayer(this);
    backgroundmusic->setMedia(QUrl("qrc:/sounds/backgroundtoon.wav"));
    backgroundmusic->setVolume(7);
    backgroundmusic->play();
}

void game::gameover()
{
    enemyspawner->stop();
// ---------------------------------------- add game over -----------------------------------------------------------

}

void game::gametimer()
{
    if(healths->gethealth()==0){
        gameover();
    }
}
