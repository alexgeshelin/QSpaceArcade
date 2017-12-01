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
#include "spacescene.h"

class Game : public QWidget
{
Q_OBJECT
public:
    explicit Game();
    void makeMainMenu();

public slots:
    void initGame();
    void exitGame();

private:
    static const int gameWidth;
    static const int gameHeight;
    QWidget *mainMenu;
    SpaceScene *scene;
    QTimer *timer;
    QGraphicsView *view;


};

#endif // GAME_H
