#ifndef LABPRO_BAGUETTE_H
#define LABPRO_BAGUETTE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include "SFML/Graphics.hpp"
#include "Knife.h"

class Baguette : public Character {
public:
    Baguette() : enemy(nullptr) {}
    Baguette(Knife* enemy) : enemy(enemy) {}
    virtual ~Baguette();

    void move(Graph* map) override;

private:
    sf::RectangleShape shape;
    Knife* enemy;
};


#endif //LABPRO_BAGUETTE_H
