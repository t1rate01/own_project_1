#ifndef BULLETS_H
#define BULLETS_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>



class bullets :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullets(int, int);
public slots:
    void movebullet();

};

#endif // BULLETS_H
