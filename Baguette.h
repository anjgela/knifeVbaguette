#ifndef LABPRO_BAGUETTE_H
#define LABPRO_BAGUETTE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include "SFML/Graphics.hpp"
#include "Knife.h"

class Baguette : public Character {
public:
    Baguette() = default;
    Baguette(Knife* knife, Graph* map);
    virtual ~Baguette() override;

    void update(Graph* map) override;
    void moveEnemy(Graph* map);

private:
    void moveRight(Graph* map);
    void moveLeft(Graph* map);
    void moveUp(Graph* map);
    void moveDown(Graph* map);

private:
    Knife* enemy;
    sf::Clock clock;
};


#endif //LABPRO_BAGUETTE_H
