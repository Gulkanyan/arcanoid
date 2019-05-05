#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

class Paddle: public QGraphicsRectItem{
public:
    // constructors
    Paddle(QGraphicsItem* parent=NULL);

    // public methods
    double getCenterX();

    // events
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // PADDLE_H
