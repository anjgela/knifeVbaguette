#include <iostream>
#include "Character.h"
#include "Graph.h"
#include "MapSearch.h"
#include <vector>

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

