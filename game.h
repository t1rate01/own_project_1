#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QGraphicsScene>
#include "myplayer.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "health.h"

class game : public QGraphicsView
{
    Q_OBJECT
public:
    game();
    void show();
    int windowx, windowy, rectx, recty, bulletx, bullety, enemyx, enemyy;
    QGraphicsScene * scene;
    myplayer * player;
    score * scores;
    health * healths;
};

#endif // GAME_H
