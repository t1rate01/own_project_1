#include <QApplication>
#include "game.h"
/*
My first C++ game following and improvising/developing further from a tutorial in youtube by username "Abdullah"
and his series called "C++ QT game tutorial"
- Tero Rantanen
*/

game * newgame;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   newgame = new game;
   newgame->show();

    return a.exec();
}
