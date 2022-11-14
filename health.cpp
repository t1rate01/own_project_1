#include "health.h"

health::health(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
  hp = 5;
  // draw the health
  setPlainText("Health : " + QString::number(hp));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",16));
}

void health::decreasehealth()
{
 hp --;
 setPlainText("Health : " + QString::number(hp));
}

int health::gethealth()
{
    return hp;
}
