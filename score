#ifndef SCORE_H
#define SCORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Score(QGraphicsTextItem *parent = nullptr);
    void increaseScore();
    int getScore();
    void PaintScore();
private:
    int score;
};
#endif // SCORE_H
