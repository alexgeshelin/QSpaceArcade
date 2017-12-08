#include "asteroid.h"

Asteroid::Asteroid(float x, float y) :
    SpaceItem(QPixmap(QString(":/resources/asteroid.png")), x, y)
{
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setScale(0.25);
    setHP(10);
    setAttack(20);
    setSpeed(1);
}

void Asteroid::advance(int phase) {
    if (phase) {
        y += 1;
        setPos(x, y);
        checkBounds();
    }
}

void Asteroid::checkBounds() {
    if (y > Game::gameHeight + 100)
    {
        scene()->removeItem(this);
        delete this;
    }
}

Asteroid::Asteroid() {}

Asteroid::~Asteroid () {}

Asteroid & Asteroid::operator=(Asteroid const &asteroid) {}
