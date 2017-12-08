#include "spaceitem.h"

SpaceItem::SpaceItem(QPixmap pix, float x, float y) :
	QGraphicsPixmapItem(pix),
	x(x),
	y(y)
{
	HP = 0;
	attack = 0;
	speed = 0;
	setPos(x, y);
}

SpaceItem::~SpaceItem() {

}

void SpaceItem::takeDamage(int damage) {
	HP -= damage;
	if (HP <= 0)
	{
		scene()->removeItem(this);
		delete this;
	}
}

void SpaceItem::setHP(int hp) {
	HP = hp;
}

void SpaceItem::setAttack(int attack) {
    this->attack = attack;
}

void SpaceItem::setSpeed(float speed) {
    this->speed = speed;
}

int SpaceItem::getHP() const {
	return (HP);
}

int SpaceItem::getAttack() const {
	return (attack);
}

float SpaceItem::getSpeed() const {
	return (speed);
}

float SpaceItem::getX() const {
	return (x);
}

float SpaceItem::getY() const {
	return (y);
}

SpaceItem::SpaceItem() {}

SpaceItem::SpaceItem(SpaceItem const &spaceitem) {}

SpaceItem &SpaceItem::operator=(SpaceItem const &spaceitem) {}
