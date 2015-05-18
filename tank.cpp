#include "tank.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Tank::Tank( Vrsta igrac = Vrsta::PRVI, Orijentacija ori = Orijentacija::GORE, qreal x=0, qreal y=0):
    mSlika((igrac == Vrsta::PRVI)?":/img/player1_tank.png":(igrac == Vrsta::DRUGI)?
                                      ":/img/player2_tank.png" : ":/img/bot.png"),
    mOrij(ori)
{
    mSpeed = 10; //pikseli po sekundi
    isMoving = false;
    isAlive = true;
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    setPos(x,y);

}

Tank::~Tank()
{

}

QRectF Tank::boundingRect() const{

    qreal a=mSlika.rect().width();
    qreal s=mSlika.rect().height();
    return QRectF(-a/2, -s/2 -2, a, s);
}


void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    int x = mSlika.rect().width();
    int y = mSlika.rect().height();
 this->setFocus();
    painter->drawPixmap(-x/2,-y/2, mSlika);

}

void Tank::keyPressEvent(QKeyEvent *event)
{

    int key = event->key();
    switch (key) {
    case Qt::Key_W:
        mOrij=Orijentacija::GORE;
        moveBy(0,-mSpeed);
        setRotation(0);
        break;
    case Qt::Key_A:
        mOrij=Orijentacija::LEVO;
        moveBy(-mSpeed,0);
        setRotation(-90);
        break;
    case Qt::Key_D:
        mOrij=Orijentacija::DESNO;
        moveBy(mSpeed,0);
        setRotation(90);
        break;
    case Qt::Key_S:
        mOrij=Orijentacija::DOLE;
        moveBy(0,mSpeed);
        setRotation(180);
        break;
    default:

        break;
    }

    update();
    QGraphicsItem::keyPressEvent(event);
}

void Tank::advance(int step)
{
    if(step == 0)
        return;


    //   moveBy(4, 0);

}
