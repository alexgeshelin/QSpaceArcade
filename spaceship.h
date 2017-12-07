#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "game.h"
#include "spaceitem.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Spaceship : public SpaceItem
{
public:
    Spaceship();
    virtual ~Spaceship();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void advance(int phase);
    virtual void checkBounds();

private:
	Spaceship(Spaceship const &spaceship);
	Spaceship & operator=(Spaceship const &spaceship);
	
    bool directionUp;
    bool directionDown;
    bool directionLeft;
    bool directionRight;

};

#endif // SPACESHIP_H
