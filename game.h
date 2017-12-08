#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsView>
#include <QString>
#include <QLabel>
#include <QBrush>
#include "spaceship.h"
#include "spacescene.h"
#include "asteroid.h"

class SpaceScene;

class Game : public QWidget
{
Q_OBJECT
public:
    explicit Game();
    virtual ~Game();
    void makeTitle();
    void makeMainMenu();
    static const int gameWidth;
    static const int gameHeight;

public slots:
    void exitGame();

private:
    Game(Game const &game);
    Game &operator=(Game const &game);

    QWidget *mainMenu;
    SpaceScene *scene;

};

#endif // GAME_H
