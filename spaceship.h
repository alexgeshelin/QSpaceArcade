#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <game.h>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QKeyEvent>

class Spaceship : public QGraphicsPixmapItem
{
public:
    Spaceship();
    //void takeDamage();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    //void move();
    virtual void advance(int phase);
    void checkBounds();

private:
    float x;
    float y;
    bool directionUp;
    bool directionDown;
    bool directionLeft;
    bool directionRight;

};

#endif // SPACESHIP_H
