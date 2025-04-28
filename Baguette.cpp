#include "Baguette.h"

//public
Baguette::Baguette(Knife* knife, Graph* map) : enemy(knife) {
    posx = 7;
    posy = 5;
    if (!texture.loadFromFile("./res/BplayingR.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(50.f, 50.f));    //every node consists of 50 pixels
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);  //top left corner of the object
    enemy->move(posx, posy, map);
}
Baguette::~Baguette() {
    delete enemy;
}


void Baguette::update(Graph* map) {
    if (clock.getElapsedTime().asSeconds() > 0.05f) {
        if (right) {
            if (!texture.loadFromFile("./res/BplayingR.png")) {
                std::cerr << "Error loading texture" << std::endl;
            }
            shape.setTexture(&texture);
            moveRight(map);
        }
        if (left) {
            if (!texture.loadFromFile("./res/BplayingL.png")) {
                std::cerr << "Error loading texture" << std::endl;
            }
            shape.setTexture(&texture);
            moveLeft(map);
        }
        if (up) {
            moveUp(map);
        }
        if (down) {
            moveDown(map);
        }
        clock.restart();
    }
}

void Baguette::moveEnemy(Graph* map) {
    enemy->move(posx, posy, map);
}

//private methods
void Baguette::moveRight(Graph* map) {
    if (map->isWalkable(getPosX()+1, getPosY())) {
        if (map->getNode(posx+1, posy)->getID() == TILE) {
            posx += 1;
            shape.move(50.f, 0);
            enemy->move(posx, posy, map);
        }
    }

}
void Baguette::moveLeft(Graph* map) {
    if (map->isWalkable(getPosX()-1, getPosY())) {
        if (map->getNode(posx - 1, posy)->getID() == TILE) {
            posx -= 1;
            shape.move(-50.f, 0);
            enemy->move(posx, posy, map);
        }
    }
}
void Baguette::moveUp(Graph* map) {
    if (map->isWalkable(getPosX(), getPosY()-1)) {
        if (map->getNode(posx, posy-1)->getID() == TILE) {
            posy -= 1;
            shape.move(0, -50.f);
            enemy->move(posx, posy, map);
        }
    }
}
void Baguette::moveDown(Graph* map) {
    if (map->isWalkable(getPosX(), getPosY()+1)) {
        if (map->getNode(posx, posy + 1)->getID() == TILE) {
            posy += 1;
            shape.move(0, 50.f);
            enemy->move(posx, posy, map);
        }
    }
}