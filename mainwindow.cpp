#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "Game.h"
#include "aboutg.h"

extern Game* game;
extern AboutG *g;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("{background-color: url(D:/space.jpg);}");
    QPixmap back("C:/Users/acer/Desktop/arcanoid/back.jpg");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,back);
    this->setPalette(palette);
    setFixedSize(317,260);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    g = new AboutG();

    game = new Game();
    game->show();
    game->start();
    this->deleteLater();
}

void MainWindow::on_pushButton_2_clicked()
{
   QApplication::quit();
}
