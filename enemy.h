#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <stdlib.h>



class enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemy(int,int,int,int);
    int enemyx, enemyy, viewx, viewy;
public slots:
    void moveEnemy();
};

#endif // ENEMY_H
