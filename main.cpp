#include <QApplication>
#include "Game.h"
#include "aboutg.h"
#include "mainwindow.h"

Game* game;
AboutG *g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    g = new AboutG();

//    game = new Game();
//    game->show();
//    game->start();

    return a.exec();
}
