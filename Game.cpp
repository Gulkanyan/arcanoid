#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
extern AboutG *g;

Game::Game(QWidget *parent): QGraphicsView(parent){
    scene = new QGraphicsScene(0,0,800,620);
    setScene(scene);
    setFixedSize(835,640);
    setMouseTracking(true);
    health1 = new HealthScore();
    scene->addItem(health1);
    health1->setPos(650,600);
    score1 = new Score();
    scene->addItem(score1);
    score1->setPos(450,600);
    scene->setBackgroundBrush(QBrush(QImage("C:/Users/acer/Desktop/arcanoid/space.jpg")));
    QApplication::setOverrideCursor(Qt::BlankCursor);
}
void Game::start(){
    //stexcenq gndak@
    Ball* ball = new Ball();//
    ball->setPos(425,320);
    scene->addItem(ball);

    //stexcenq hartutyuny
    paddle = new Paddle();
    paddle->setPos(150,575);
    scene->addItem(paddle);
    paddle->grabKeyboard();
    //paddle->grabMouse();
    creatBlockGrid();
}
//gcenq syunery
void Game::createBlockCol(double x){
    for (size_t i = 0, n = 3; i < n; ++i){
        Block* block = new Block();
        block->setPos(x,i*40);
        scene->addItem(block);
    }
}

//gcenq toxer@
void Game::creatBlockGrid(){
    for (size_t i = 0; i < 10; ++i){
        createBlockCol(i*80);
    }
}
void Game::createBlockCol_2(double x){
    for (size_t i = 0, n = 3; i < n; ++i){
        Block* block = new Block();
        block->setPos(x,i*80);
        scene->addItem(block);
    }
}
void Game::creatBlockGrid_2(){
    for (size_t i = 0; i < 10; ++i){
        createBlockCol(i*160);
    }
}
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::EndGame(bool flag)
{
    //Game Over/ GameWin Box
    QApplication::restoreOverrideCursor();
    if(flag)
    {
        drawPanel(50,50,700,500,Qt::green,0.65);
        drawPanel(75,75,650,450,Qt::white,0.75);
        text = new AboutG();
        text->SetBoolTrue();
        scene->addItem(text);
        text->setPos(110,225);
        text->Print();
        g->SetBoolTrue();
    }
    if(!flag)
    {
        drawPanel(50,50,700,500,Qt::red,0.65);
        drawPanel(75,75,650,450,Qt::white,0.75);
        text = new AboutG();
        text->SetBoolFalse();
        scene->addItem(text);
        text->setPos(110,225);
        text->Print();
        g->SetBoolFalse();
    }
}
