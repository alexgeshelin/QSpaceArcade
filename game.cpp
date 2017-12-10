#include "game.h"

const int Game::gameWidth = 500;
const int Game::gameHeight = 500;

Game::Game()
{
    setFixedSize(gameWidth, gameHeight);
    scene = new SpaceScene(gameWidth, gameHeight, this);
    makeMainMenu();
    makeTitle();
}

void Game::makeTitle() {
    QLabel *title = new QLabel(QString("QSpaceArcade"), mainMenu);
    title->setStyleSheet(QString("QLabel { font-size: 34pt; color: white; }"));

    title->setGeometry(\
    (gameWidth / 5), (gameHeight / 10), (gameWidth / 5) * 3, (gameHeight / 5));

    title->setAlignment(Qt::AlignCenter);
}

void Game::makeMainMenu() {
    mainMenu = new QWidget(this);
    mainMenu->setStyleSheet(QString("QPushButton { font-size: 18pt; }"));

    QPushButton *play = new QPushButton(QString("Play"), mainMenu);
    QPushButton *exit = new QPushButton(QString("Exit"), mainMenu);

    play->setGeometry(
    (gameWidth / 3), (gameHeight / 10) * 4 , (gameWidth / 3), (gameHeight / 10));
    exit->setGeometry(
    (gameWidth / 3), (gameHeight / 10) * 5 , (gameWidth / 3), (gameHeight / 10));

    QObject::connect(play, SIGNAL (pressed()),
                     scene, SLOT (startGame()));
    QObject::connect(play, SIGNAL (pressed()),
                     mainMenu, SLOT (hide()));
    QObject::connect(exit, SIGNAL (pressed()),
                     this, SLOT (exitGame()));
}

void Game::exitGame() {
    QApplication::exit();
}

Game::~Game() {}

Game::Game(Game const &game) {}

Game & Game::operator=(Game const &game) {
    return (*this);
}
