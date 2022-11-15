#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QGraphicsScene>
#include "myplayer.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QImage>


class game : public QGraphicsView
{
    Q_OBJECT
public:
    game();
    void show();
    void gameover();
    int windowx, windowy;
    QGraphicsScene * scene;
    QTimer * enemyspawner = new QTimer;
    QTimer * gametime = new QTimer;
    QMediaPlayer * backgroundmusic;
    myplayer * player;
    score * scores;
    health * healths;
public slots:
    void gametimer();
};

#endif // GAME_H
