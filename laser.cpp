#include "laser.h"

Laser::Laser(float x, float y) :
    SpaceItem(QPixmap(QString(":/resources/laser.png")), x, y)
{
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    setScale(0.5);
    setHP(1);
    setAttack(10);
    setSpeed(1);
}

void Laser::advance(int phase) {
    if (phase) {
        y -= 2;
        setPos(x, y);
        checkBounds();
    }
}

void Laser::checkBounds() {
    if (y < -10)
        static_cast<SpaceScene*>(scene())->deleteLaser(this);
}

Laser::~Laser() {}

Laser::Laser() {}

Laser::Laser(Laser const &laser) {}

Laser & Laser::operator=(Laser const &laser) {
    return (*this);
}
