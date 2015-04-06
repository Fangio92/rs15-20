#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QRect>
#include <QGraphicsPixmapItem>


class GameWindow : public QWidget
{
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();



private:
    QGraphicsScene * scene;
    QGraphicsView  * view;
    int sceneWidth;

    static const int numberOfFields = 13;
    QGraphicsPixmapItem * level[numberOfFields][numberOfFields];


};

#endif // GAMEWINDOW_H
