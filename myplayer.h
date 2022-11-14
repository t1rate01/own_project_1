#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <QList>




class myplayer : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    myplayer(int, int, int, int, int, int);
    void keyPressEvent(QKeyEvent * event);
    int getwidth();
    int viewx, viewy, bulletx, bullety, enemyx,enemyy;
public slots:
    void spawn();

};

#endif // MYPLAYER_H
