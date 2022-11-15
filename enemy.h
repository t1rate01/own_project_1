#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <stdlib.h>



class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy(int,int);
    ~enemy();
    int viewx, viewy;
public slots:
    void moveEnemy();
};

#endif // ENEMY_H
