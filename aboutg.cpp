#include "aboutg.h"
#include "Game.h"
#include <QFont>
#include <QDebug>
extern AboutG *g;
extern Game *game;
AboutG::AboutG(QGraphicsTextItem *parent) :QGraphicsTextItem(parent)
{

}

void AboutG::SetBoolFalse()
{
    GameWin = false;
}

void AboutG::SetBoolTrue()
{
    GameWin = true;
}

bool AboutG::GetBool()
{
    return GameWin;
}

void AboutG::Print()
{
    if(GameWin)
    {
        setPlainText(QString("Դուք հաղթել եք"));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",50));
        QMessageBox::StandardButton check = QMessageBox::question(game,"Խաղն ավարտվեց","Սկսե՞լ նորից",QMessageBox::Yes | QMessageBox::No);
        if(check == QMessageBox::Yes)
        {
            delete game;
            game = new Game();
            game->show();
            game->start();
        }
        else {
            delete game;
        }
    }
    if(!GameWin)
    {
        setPlainText(QString("Դուք պարտվել եք"));
        setDefaultTextColor(Qt::black);
        setFont(QFont("times",50));
        QMessageBox::StandardButton check = QMessageBox::question(game,"Խաղն ավարտվեց","Սկսե՞լ նորից",QMessageBox::Yes | QMessageBox::No);
        if(check == QMessageBox::Yes)
        {
            delete game;
            game = new Game();
            game->show();
            game->start();
        }
        else {
            delete game;
        }
    }
}
