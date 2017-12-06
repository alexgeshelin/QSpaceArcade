#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "game.h"

class Asteroid : public QGraphicsPixmapItem
{

public:
    Asteroid(float x, float y);
    virtual void advance(int phase);

private:
    Asteroid();
    float x;
    float y;

};

#endif // ASTEROID_H
