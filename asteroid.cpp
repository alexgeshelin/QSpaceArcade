#include "asteroid.h"

Asteroid::Asteroid()
{

}

Asteroid::Asteroid(float x, float y) :
    QGraphicsPixmapItem(QPixmap(QString(":/resources/asteroid.png"))),
    x(x), y(y)
{
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setScale(0.25);
    setPos(x, y);
}

void Asteroid::advance(int phase) {
    if (phase) {
        y += 1;
        if (y > Game::gameHeight) {
            this->scene()->removeItem(this);
            delete (this);
        }
        setPos(x, y);
    }
}
