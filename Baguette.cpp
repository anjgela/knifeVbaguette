#include "Baguette.h"


void Baguette::move(int x, int y, Graph* map) { //FIXME : SFML arrows and awsd keys to move and each corresponds to x<>, y<>
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
    setPosX(x);
    setPosY(y);
}