#ifndef ABOUTG_H
#define ABOUTG_H

#include <qbuttongroup.h>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QMessageBox>
class AboutG : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit AboutG(QGraphicsTextItem *parent = nullptr);
    void Print();
    void SetBoolTrue();
    void SetBoolFalse();
    bool GetBool();
    bool GameWin = true;
};
#endif // ABOUTG_H
