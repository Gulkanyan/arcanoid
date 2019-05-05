#include "score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent) :QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Միավոր: ")+ QString::number(score));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("times",16));

}
void Score::increaseScore()
{
    score += 50;
}

int Score::getScore()
{
    return score;
}
void Score::PaintScore()
{
    setPlainText(QString("Միավոր: ")+ QString::number(score));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("times",16));
}
