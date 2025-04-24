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
sf::RectangleShape Character::getShape() const {
    return shape;
}

void Character::setPosX(int x) {
    posx = x;
    shape.setPosition(x * shape.getSize().x, posy * shape.getSize().y);
}
void Character::setPosY(int y) {
    posy = y;
    shape.setPosition(posx * shape.getSize().x, y * shape.getSize().y);
}

