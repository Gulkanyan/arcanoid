#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include "Game.h"
#include "Paddle.h"
#include "Block.h"
extern Game* game;
extern AboutG *g;
Ball::Ball(QGraphicsItem *parent): QGraphicsEllipseItem(parent), QObject(){
   setRect(0,0,35,35);
   QBrush brush;
   brush.setStyle(Qt::SolidPattern);
   brush.setColor(Qt::red);
   setBrush(brush);
   xVelocity = 0;
   yVelocity = -5;
   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   timer->start(19);
}
double Ball::getCenterX(){
   return x() + rect().width()/2;
}
void Ball::move(){
   reverseVelocityIfOutOfBounds();
   //sharjumy kaxvac te vortex e paddlein dipchum
   handlePaddleCollision();
   // blok+ball=delete(block)
   handleBlockCollision();
   moveBy(xVelocity,yVelocity);

}
void Ball::reverseVelocityIfOutOfBounds(){
   if(this->pos().x() < 0)
   {
       xVelocity *= -1;
   }
   if(this->pos().x() > 750 )
   {
       xVelocity*=-1;
   }
   if(this->pos().y()<0)
   {
       yVelocity*=-1;
   }
   if(this->pos().y()>910)
   {
       this->setPos(420,300);
       game->paddle->setPos(400,575);
       game->health1->decreaseLife();
       game->health1->Print();
   }
   if(game->health1->getHealth() == 0)
   {
      // Game over
       timer->stop();
       game->EndGame(false);
   }

}
void Ball::timerStart()
{
   timer->start();
}
void Ball::handlePaddleCollision(){
   QList<QGraphicsItem*> cItems = collidingItems();
   for (size_t i = 0; i < cItems.size(); ++i){
       Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
       if (paddle){
           yVelocity = -1 * yVelocity;
           double ballX = getCenterX();
           double paddleX = paddle->getCenterX();
           double dvx = ballX - paddleX;
           xVelocity = (xVelocity + dvx)/15;

           return;
       }
   }
}
void Ball::handleBlockCollision(){
   QList<QGraphicsItem*> cItems = collidingItems();
   for (size_t i = 0, n = cItems.size(); i < n; ++i){
       Block* block = dynamic_cast<Block*>(cItems[i]);
       if (block){
           double yPad = 15;
           double xPad = 15;
           double ballx = pos().x();
           double bally = pos().y();
           double blockx = block->pos().x();
           double blocky = block->pos().y();
           if (bally > blocky + yPad && yVelocity < 0){
               yVelocity = -1 * yVelocity;
           }
           if (blocky > bally + yPad && yVelocity > 0 ){
               yVelocity = -1 * yVelocity;
           }
           if (ballx > blockx + xPad && xVelocity < 0){
               xVelocity = -1 * xVelocity;
           }
           if (blockx > ballx + xPad && xVelocity > 0){
               xVelocity = -1 * xVelocity;
           }
           bln--;
           game->scene->removeItem(block);
           game->score1->increaseScore();
           game->score1->PaintScore();
           delete block;
       }
       if(!bln)
       {
          timer->stop();
          game->EndGame(true);
       }
   }

}
