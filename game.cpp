#include "game.h"

Game::Game()
{
    this->setFixedSize(400, 500);
    menu = new QButtonGroup(this);
    QPushButton *play = new QPushButton(QString("Play"), this);
    QObject::connect(play, SIGNAL (pressed()), this, SLOT (initGame()));
    menu->addButton(play);
 /*   QPushButton *exit = new QPushButton(QString("Exit"), this);
    QObject::connect(exit, SIGNAL (pressed()), this, SLOT (exitGame()));
    menu->addButton(exit);*/
    scene = 0;
    timer = 0;
}

void Game::initGame() {

    scene = new SpaceScene();
    view = new QGraphicsView(scene, this);
    scene->addRect(100, 100, 50, 50);
    view->show();
}

void Game::exitGame() {
    QApplication::exit();
}
