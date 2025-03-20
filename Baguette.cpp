#include "Baguette.h"

Baguette::~Baguette() {
    delete enemy;
}

void Baguette::move(int x, int y, Graph* map) { //ELEFANTE : SFML arrows and awsd keys to move and each corresponds to x<>, y<>
    Node* position = map->getNode(getPosX(),getPosY());
    Node* destination = nullptr;
    if (x < getPosX()) {
        destination = map->getLeft(position);
    }
    else if (x > getPosX()) {
        destination = map->getRight(position);
    }
    else {
        if (y < getPosY()) {
            destination = map->getTop(position);
        }
        else {
            destination = map->getDown(position);
        }
    }
    if (destination->getID() != OBSTACLE) {
        setPosX(x);
        setPosY(y);
        //UPDATE KNIFE'S GOAL
        enemy->move(destination, map);
    }
    else {
        //ELEFANTE: create exception when destination is not reacheable: get slowed or something???
    }


}
void Baguette::move(Node* destination, Graph* map) {
    if (destination->getID() != OBSTACLE) {
        setPosX(destination->getX());
        setPosY(destination->getY());
    }
    else {
        //ELEFANTE: create exception when destination is not reacheable: get slowed or something???
    }
}