#include "healthscore.h"
#include <QFont>

HealthScore::HealthScore(QGraphicsTextItem *parent) :QGraphicsTextItem(parent)
{
    health=3;
    setPlainText(QString("կյանք: ")+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void HealthScore::decreaseLife()
{
    health--;
}

int HealthScore::getHealth()
{
    return health;
}

void HealthScore::Print()
{
    setPlainText(QString("կյանք: ")+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
