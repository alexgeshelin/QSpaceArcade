#ifndef SPACESCENE_H
#define SPACESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "spaceship.h"
#include "asteroid.h"
#include <ctime>
#include <cstdlib>

class SpaceScene : public QGraphicsScene {
Q_OBJECT
public:
    explicit SpaceScene(int width, int height, QObject *parent);
    virtual ~SpaceScene();

public slots:
    void startGame();
    void advance();

private slots:
    void generateEnemies();
    void increaseDifficulty();

private:
	SpaceScene();
	SpaceScene(SpaceScene const &scene);
	SpaceScene &operator=(SpaceScene const &scene);

	void handleCollisions();

	QTimer *globalTimer;
	QTimer *enemyGenTimer;
	QTimer *difficultyTimer;
	QGraphicsView *view;
	int numberOfAsteroids;
	int asteroidGenerationHeight;

};

#endif // SPACESCENE_H
