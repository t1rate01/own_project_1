#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>



class myplayer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    myplayer(int, int);
    void keyPressEvent(QKeyEvent * event);
    int viewx, viewy;
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;

};

#endif // MYPLAYER_H
