#include "spaceship.h"

Spaceship::Spaceship() : QGraphicsPixmapItem(QPixmap(/*QDir::currentPath() +*/
                                                     QString("C://Projects//QSpaceArcade//resources//spaceship.png")))
{
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    x = 240;
    y = 450;
    setPos(x, y);
}

void Spaceship::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up)
    {
        y -= 1;
    }
    if (event->key() == Qt::Key_Down)
    {
        y += 1;
    }
    if (event->key() == Qt::Key_Right)
    {
        x += 1;
    }
    if (event->key() == Qt::Key_Left)
    {
        x -= 1;
    }
    setPos(x, y);
}
