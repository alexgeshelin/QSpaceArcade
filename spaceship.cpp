#include "spaceship.h"

Spaceship::Spaceship() : QGraphicsPixmapItem(QPixmap(/*QDir::currentPath() +*/
                                                     QString("C://Projects//QSpaceArcade//resources//spaceship.png")))
{
    this->setShapeMode(QGraphicsPixmapItem::MaskShape);
    this->setScale(0.5);
    this->setPos(0, 0);

}
