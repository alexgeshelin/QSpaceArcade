#ifndef SPACESCENE_H
#define SPACESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "spaceship.h"
#include "asteroid.h"
#include "laser.h"
#include <ctime>
#include <cstdlib>

class Spaceship;
class Laser;

class SpaceScene : public QGraphicsScene {
Q_OBJECT
public:
    explicit SpaceScene(int width, int height, QObject *parent);
    virtual ~SpaceScene();
    void deleteLaser(Laser *laser);
    void startShooting();
    void stopShooting();

public slots:
    void startGame();
    void advance();

private slots:
    void addLaser();
    void generateEnemies();
    void increaseDifficulty();

private:
	SpaceScene();
	SpaceScene(SpaceScene const &scene);
	SpaceScene &operator=(SpaceScene const &scene);

	void handleCollisions();
    void spaceshipCollisions();
    void laserCollisions();

    QList<Laser*> lasers;
    Spaceship *spaceship;
	QTimer *globalTimer;
	QTimer *enemyGenTimer;
	QTimer *difficultyTimer;
    QTimer *shootingTimer;
	QGraphicsView *view;
	int numberOfAsteroids;
	int asteroidGenerationHeight;
    int shootingDelay;

};

#endif // SPACESCENE_H
