#ifndef BULLETS_H
#define BULLETS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>



class bullets :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullets();
    ~bullets();
public slots:
    void movebullet();

};

#endif // BULLETS_H
