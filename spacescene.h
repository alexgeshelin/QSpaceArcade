#ifndef SPACESCENE_H
#define SPACESCENE_H

#include <QGraphicsScene>

class SpaceScene : public QGraphicsScene {
public:
    SpaceScene();
    ~SpaceScene();

private:
	SpaceScene(SpaceScene const &scene);
	SpaceScene &operator=(SpaceScene const &scene);

};

#endif // SPACESCENE_H
