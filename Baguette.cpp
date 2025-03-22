#include "Baguette.h"
Baguette::Baguette(Knife* knife) : enemy(knife) {
    posx = 350;
    posy = 250;
    shape.setPosition(350.f,250.f);  //top left corner of the object
    shape.setSize(sf::Vector2f(100.f,100.f));
    shape.setFillColor(sf::Color::Green);
}
Baguette::~Baguette() {
    delete enemy;
}

void Baguette::moveRight(Graph* map) {
    if (map->getNode(posx+1, posy)->getID() == TILE) {
        posx += 1;
        enemy->move(posx, posy, map);
    }
}
void Baguette::moveLeft(Graph* map) {
    if (map->getNode(posx - 1, posy)->getID() == TILE) {
        posx -= 1;
        enemy->move(posx, posy, map);
    }
}
void Baguette::moveUp(Graph* map) {
    if (map->getNode(posx, posy-1)->getID() == TILE) {
        posy -= 1;
        enemy->move(posx, posy, map);
    }
}
void Baguette::moveDown(Graph* map) {
    if (map->getNode(posx, posy + 1)->getID() == TILE) {
        posy += 1;
        enemy->move(posx, posy, map);
    }
}