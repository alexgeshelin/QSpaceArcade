#include "spaceship.h"

Spaceship::Spaceship() :
    SpaceItem(QPixmap(QString(":/resources/spaceship.png")), 240, 450)
{
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setScale(0.5);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setHP(100);
    setAttack(10);
    setSpeed(1);
    directionDown = false;
    directionLeft = false;
    directionRight = false;
    directionUp = false;
}

Spaceship::~Spaceship() {}

void Spaceship::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
        directionUp = true;
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
        directionDown = true;
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        directionRight = true;
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        directionLeft = true;
}

void Spaceship::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
        directionUp = false;
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
        directionDown = false;
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        directionRight = false;
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        directionLeft = false;
}

void Spaceship::advance(int phase) {
    if (phase) {
        if (directionRight && !directionLeft &&
         !(directionDown ^ directionUp)) {
            x += 1;
        }
        else if (directionUp && !directionDown &&
         !(directionRight ^ directionLeft)) {
            y -= 1;
        }
        else if (directionDown && !directionUp &&
         !(directionRight ^ directionLeft)) {
            y += 1;
        }
        else if (directionLeft && !directionRight 
        	&& !(directionDown ^ directionUp)) {
            x -= 1;
        }
        else if (directionUp && directionRight && 
        	!directionLeft && !directionDown) {
            y -= 0.7071;
            x += 0.7071;
        }
        else if (directionDown && directionRight && 
        	!directionLeft && !directionUp) {
            y += 0.7071;
            x += 0.7071;
        }
        else if (directionDown && directionLeft && 
        	!directionRight && !directionUp) {
            y += 0.7071;
            x -= 0.7071;
        }
        else if (directionUp && directionLeft && 
        	!directionRight && !directionDown)  {
            y -= 0.7071;
            x -= 0.7071;
        }
        checkBounds();
        setPos(x, y);
    }
}

void Spaceship::takeDamage(int damage) {
    SpaceItem::takeDamage(damage);
    if (getHP() <= 0)
        QApplication::instance()->exit(0);
}

void Spaceship::checkBounds() {
    if (x > Game::gameWidth - 30)
        x = Game::gameWidth - 30;
    if (x < 0)
        x = 0;
    if (y > Game::gameHeight - 40)
        y = Game::gameHeight - 40;
    if (y < 0)
        y = 0;
}

Spaceship::Spaceship(Spaceship const &spaceship) {}

Spaceship & Spaceship::operator=(Spaceship const &spaceship) {
    return (*this);
}
