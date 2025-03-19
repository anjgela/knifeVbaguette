#include <iostream>
#include "Character.h"
#include "Graph.h"
#include "MapSearch.h"
#include <vector>

void Character::move(int x, int y, Graph* map){}

int Character::getPosX() {
    return posx;
}
int Character::getPosY() {
    return posy;
}

void Character::setPosX(int x) {
    posx = x;
}
void Character::setPosY(int y) {
    posy = y;
}

