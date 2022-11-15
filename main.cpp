#include <QApplication>
#include "game.h"
/*
My first C++ game following and improvising/developing further from a tutorial in youtube by username "Abdullah"
and his series called "C++ QT game tutorial"
- Tero Rantanen
*/

/*Note to self -> To use QMediaPlayer you have to edit the .pro file and add "\"  "multimedia" to be able
to include the player.
2 Objects for displaying graphics. QPixmap and QImage. QImage is more efficient for input and output and single pixle
manipulation. */

game * newgame;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   newgame = new game;
   newgame->show();

    return a.exec();
}
