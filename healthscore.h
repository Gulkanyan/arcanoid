#ifndef HEALTHSCORE_H
#define HEALTHSCORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>

class HealthScore : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit HealthScore(QGraphicsTextItem *parent = nullptr);
    void decreaseLife();
    int getHealth();
    void Print();
private:
    int health;
};

#endif // HEALTHSCORE_H
