#include "Paddle.h"
#include <QBrush>

Paddle::Paddle(QGraphicsItem *parent){
    // nkarel uxxankyun
    setRect(0,0,150,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}
double Paddle::getCenterX(){
    //rect-i kentrony berum a x,y/2 i vra
    return x()+rect().width()/2;
}

void Paddle::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"Void Func";
    if(event->key() == Qt::Key_Right)
    {
      //  qDebug()<<"Key Presses";
        setPos(x()+10,y());
        update();
    }
    if(event->key() == Qt::Key_Left)
    {
        //qDebug()<<"Key Pressed uisdgfuikg";
        setPos(x()-10,y());
        update();
    }
    if(pos().x()>660)
    {
        setPos(655,y());
    }
    if(pos().x()<0)
    {
        setPos(3,y());
    }
}

//void Paddle::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
//    // sharjvi mkniki het
//    double mouseX = mapToScene(event->pos()).x();
//    setPos(mouseX,y());
//    if(pos().x()>660)
//    {
//        setPos(655,y());
//    }
//}
