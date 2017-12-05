#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
#include <QDir>
#include <QKeyEvent>

class Spaceship : public QGraphicsPixmapItem
{
public:
    Spaceship();
    //void takeDamage();
    virtual void keyPressEvent(QKeyEvent *event);
    //void move();

private:
    float x;
    float y;

};

#endif // SPACESHIP_H
