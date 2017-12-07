#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "spaceitem.h"
#include "game.h"

class Asteroid : public QGraphicsPixmapItem
{
public:
    Asteroid(float x, float y);
    virtual ~Asteroid();
    virtual void advance(int phase);
    virtual void checkBounds();

private:
    Asteroid();
    Asteroid(Asteroid const &asteroid);
    Asteroid & operator=(Asteroid const &asteroid);

};

#endif // ASTEROID_H
