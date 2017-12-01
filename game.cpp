#include "game.h"

const int Game::gameWidth = 500;
const int Game::gameHeight = 500;

Game::Game()
{
    this->setFixedSize(gameWidth, gameHeight);
    QLabel *title = new QLabel(QString("QSpaceArcade"), this);
    title->setStyleSheet(QString("QLabel { font-size: 34pt; }"));
    title->setGeometry(\
    gameWidth / 5, (gameHeight / 10), (gameWidth / 5) * 3, gameHeight / 5);
    title->setAlignment(Qt::AlignCenter);
    makeMainMenu();
    scene = 0;
    timer = 0;
}


void Game::makeMainMenu() {
    mainMenu = new QWidget(this);
    mainMenu->setStyleSheet(QString("QPushButton { font-size: 18pt; }"));

    QPushButton *play = new QPushButton(QString("Play"), mainMenu);
    QPushButton *exit = new QPushButton(QString("Exit"), mainMenu);

    play->setGeometry(\
    gameWidth / 3, (gameHeight / 10) * 4 , gameWidth / 3, gameHeight / 10);
    exit->setGeometry(\
    gameWidth / 3, (gameHeight / 10) * 5 , gameWidth / 3, gameHeight / 10);

    QObject::connect(play, SIGNAL (pressed()), this, SLOT (initGame()));
    QObject::connect(exit, SIGNAL (pressed()), this, SLOT (exitGame()));

}

void Game::initGame() {

    scene = new SpaceScene();
    scene->setSceneRect(0, 0, 400, 500);
    view = new QGraphicsView(scene, this);
    scene->addRect(100, 100, 50, 50);
    view->show();
}

void Game::exitGame() {
    QApplication::exit();
}
