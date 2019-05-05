#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QFont>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include "paddle.h"
#include "healthscore.h"
#include "score.h"
#include "aboutg.h"

class Game: public QGraphicsView{
public:
    Game(QWidget* parent=NULL);

    // public methods
    void start();
    void createBlockCol(double x);
    void creatBlockGrid();
    void createBlockCol_2(double x);
    void creatBlockGrid_2();
    void EndGame(bool);
    //void keyPressEvent(QKeyEvent *event);
    // public attributes
    QGraphicsScene* scene;
    Paddle *paddle;
    HealthScore *health1;
    Score *score1;
    AboutG *text;
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
public slots:

};

#endif // GAME_H
//
