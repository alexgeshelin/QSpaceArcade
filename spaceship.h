#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QDir>

class Spaceship : public QGraphicsPixmapItem
{
public:
    Spaceship();
    void takeDamage();

private:
    float x;
    float y;

};

#endif // SPACESHIP_H
