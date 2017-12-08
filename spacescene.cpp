#include "spacescene.h"

SpaceScene::SpaceScene(int width, int height, QObject *parent) :
	QGraphicsScene(0, 0, width, height, parent)
{
	srand(time(NULL));

    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    view = new QGraphicsView(this);
    view->show();

    globalTimer = new QTimer(this);
    connect(globalTimer, SIGNAL(timeout()), this, SLOT(advance()));

    enemyGenTimer = new QTimer(this);
    connect(enemyGenTimer, SIGNAL(timeout()), this, SLOT(generateEnemies()));

    difficultyTimer = new QTimer(this);
    connect(difficultyTimer, SIGNAL(timeout()), this, SLOT(increaseDifficulty()));

    numberOfAsteroids = 3;
    asteroidGenerationHeight = -50;
}


void SpaceScene::startGame() {
	Spaceship *spaceship = new Spaceship();
    addItem(spaceship);
    spaceship->grabKeyboard();

	globalTimer->start(1000 / 60);
	enemyGenTimer->start(3000);
	difficultyTimer->start(15000);
}

void SpaceScene::advance() {
    QGraphicsScene::advance();
    //handleCollisions();
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

void handleCollisions() {
	
}

SpaceScene::SpaceScene() {}

SpaceScene::~SpaceScene() {}

SpaceScene::SpaceScene(const SpaceScene &scene) {}

SpaceScene & SpaceScene::operator=(SpaceScene const &scene) {}
