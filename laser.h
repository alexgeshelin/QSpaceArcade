#ifndef LASER_H
#define LASER_H

#include "spaceitem.h"
#include "spacescene.h"

class Laser : public SpaceItem
{
public:
    Laser(float x, float y);
    virtual ~Laser();
    virtual void advance(int phase);
    virtual void checkBounds();

private:
    Laser();
    Laser(Laser const &laser);
    Laser & operator=(Laser const &laser);

};

#endif // LASER_H
