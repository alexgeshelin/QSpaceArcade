#include "spacescene.h"

SpaceScene::SpaceScene(int width, int height, QObject *parent) :
    QGraphicsScene(0, 0, width, height, parent)
{
	srand(time(NULL));

    setBackgroundBrush(QBrush(QPixmap(QString(":/resources/background.png"))));

    view = new QGraphicsView(this, dynamic_cast<QWidget*>(parent));

    globalTimer = new QTimer(this);
    connect(globalTimer, SIGNAL(timeout()),
            this, SLOT(advance()));

    enemyGenTimer = new QTimer(this);
    connect(enemyGenTimer, SIGNAL(timeout()),
            this, SLOT(generateEnemies()));

    difficultyTimer = new QTimer(this);
    connect(difficultyTimer, SIGNAL(timeout()),
            this, SLOT(increaseDifficulty()));


    shootingTimer = new QTimer(this);
    connect(shootingTimer, SIGNAL(timeout()),
            this, SLOT(addLaser()));

    numberOfAsteroids = 2;
    asteroidGenerationHeight = -30;
    shootingDelay = 750;
    spaceship = 0;
}


void SpaceScene::startGame() {
    if (!spaceship) {
        spaceship = new Spaceship();
        addItem(spaceship);
        spaceship->grabKeyboard();
    }

    globalTimer->start(1000 / 30);
    enemyGenTimer->start(1000);
	difficultyTimer->start(15000);
    view->show();
}

void SpaceScene::advance() {
    QGraphicsScene::advance();
    handleCollisions();
}

void SpaceScene::generateEnemies() {
	for (int i = 0; i < numberOfAsteroids; i++) {
        int x = rand() % static_cast<int>(width());
        while (itemAt(QPointF(x, asteroidGenerationHeight), QTransform()))
            x = rand() % static_cast<int>(width());
		Asteroid *asteroid = new Asteroid(x, asteroidGenerationHeight);
		addItem(asteroid);
	}
}

void SpaceScene::increaseDifficulty() {

}

void SpaceScene::handleCollisions() {
    spaceshipCollisions();
    laserCollisions();
}

void SpaceScene::spaceshipCollisions() {
    QList<QGraphicsItem*> items = collidingItems(spaceship);
    if (!items.isEmpty()) {
        QList<QGraphicsItem*>::iterator i;
        i = items.begin();
        spaceship->takeDamage((static_cast<SpaceItem*>(*i))->getAttack());
        removeItem(*i);
        delete *i;
        i++;
        for ( ; i != items.end(); i++) {
            spaceship->takeDamage((static_cast<SpaceItem*>(*i))->getAttack());
            removeItem(*i);
            delete *i;
        }
    }
}

void SpaceScene::laserCollisions() {
//    if (!lasers.isEmpty())
//    {
//        QList<Laser*>::iterator ilasers;
//        ilasers = lasers.begin();
//        for ( ; ilasers != items.end(); ilasers++) {
//            QList<QGraphicsItem*> items;
//            QList<QGraphicsItem*>::iterator i;
//            i =
//        }
//    }
}

void SpaceScene::addLaser() {
    Laser *laserLeft = new Laser(spaceship->getX() + 4, spaceship->getY() - 20);
    Laser *laserRight = new Laser(spaceship->getX() + 22, spaceship->getY() - 20);
    addItem(laserLeft);
    addItem(laserRight);
    lasers.append(laserLeft);
    lasers.append(laserRight);
}

void SpaceScene::deleteLaser(Laser *laser) {
    removeItem(laser);
    lasers.removeOne(laser);
}

void SpaceScene::startShooting() {
    shootingTimer->start(shootingDelay);
}

void SpaceScene::stopShooting() {
    shootingTimer->stop();
}

SpaceScene::SpaceScene() {}

SpaceScene::~SpaceScene() {}

SpaceScene::SpaceScene(const SpaceScene &scene) {}

SpaceScene & SpaceScene::operator=(SpaceScene const &scene) {
    return (*this);
}
