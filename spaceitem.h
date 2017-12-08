#ifndef SPACEITEM_H
#define SPACEITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class SpaceItem : public QGraphicsPixmapItem 
{
public:
	SpaceItem(QPixmap pix, float x, float y);
	virtual ~SpaceItem();
	virtual void takeDamage(int damage);
	virtual void checkBounds() = 0;
	void setHP(int hp);
	void setAttack(int attack);
	void setSpeed(float speed);
	int getHP() const;
	int getAttack() const;
	float getSpeed() const;
	float getX() const;
	float getY() const;

protected:
	float x;
    float y;
    SpaceItem();

private:

	SpaceItem(SpaceItem const &spaceitem);
	SpaceItem &operator=(SpaceItem const &spaceitem);

	int HP;
	int attack;
	float speed;

};

#endif
