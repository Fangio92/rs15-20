#ifndef BOTTANK_H
#define BOTTANK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tank.h"
#include "constants.h"
#include <QTime>

class BotTank: public Tank
{
public:

    BotTank(qreal x, qreal y, Orientation ori);
    ~BotTank();
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:
    QTime mTimeOfLastBullet;
    qreal mAngle;
    bool mFirstTime;

};

#endif // BOTTANK_H
