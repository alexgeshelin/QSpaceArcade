#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsView>
#include <QString>
#include "spacescene.h"

class Game : public QWidget
{
Q_OBJECT
public:
    explicit Game();

public slots:
    void initGame();
    void exitGame();

private:
    QButtonGroup *menu;
    SpaceScene *scene;
    QTimer *timer;
    QGraphicsView *view;

};

#endif // GAME_H
