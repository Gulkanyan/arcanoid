#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QPaintEvent>
#include <QMainWindow>
#include <QObject>

class Block: public QGraphicsRectItem{
public:
    // constructors
    Block(QGraphicsItem* parent=NULL);

};

#endif

