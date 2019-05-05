#ifndef BALL_H
#define BALL_H
#include <QGraphicsRectItem>
#include "game.h"
#include "mainwindow.h"
class Ball: public QObject, public QGraphicsEllipseItem
 {
    Q_OBJECT
public:
    Ball(QGraphicsItem* parent=NULL);
    double getCenterX();
    QTimer *timer;
    void timerStart();
public slots:
    void move();
private:
    double xVelocity;
    double yVelocity;
    double xB;
    double yB;
    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
    int bln = 30;
};

#endif
