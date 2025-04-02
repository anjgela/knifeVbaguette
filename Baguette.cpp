#include "Baguette.h"
Baguette::Baguette(Knife* knife) : enemy(knife) {
    posx = 7;
    posy = 5;
    shape.setSize(sf::Vector2f(50.f, 50.f));    //every node consists of 50 pixels
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);  //top left corner of the object

    shape.setFillColor(sf::Color::Green);
}
Baguette::~Baguette() {
    delete enemy;
}

void Baguette::moveRight(Graph* map) {
    if (map->getNode(posx+1, posy)->getID() == TILE) {
        posx += 1;
        shape.setPosition(posx*50.f, shape.getPosition().y);
        enemy->move(posx, posy, map);
    }

}
void Baguette::moveLeft(Graph* map) {
    if (map->getNode(posx - 1, posy)->getID() == TILE) {
        posx -= 1;
        shape.setPosition(posx*50.f, shape.getPosition().y);
        enemy->move(posx, posy, map);
    }
}
void Baguette::moveUp(Graph* map) {
    if (map->getNode(posx, posy-1)->getID() == TILE) {
        posy -= 1;
        shape.setPosition(shape.getPosition().x, posy*50.f);
        enemy->move(posx, posy, map);
    }
}
void Baguette::moveDown(Graph* map) {
    if (map->getNode(posx, posy + 1)->getID() == TILE) {
        posy += 1;
        shape.setPosition(shape.getPosition().x, posy*50.f);
        enemy->move(posx, posy, map);
    }
}