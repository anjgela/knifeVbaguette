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
    Baguette(Knife* knife);
    virtual ~Baguette() override;

    void moveRight(Graph* map);
    void moveLeft(Graph* map);
    void moveUp(Graph* map);
    void moveDown(Graph* map);


    sf::RectangleShape getShape() const {
        return shape;
    }
private:
    void moveAux(Graph* map);
    Knife* enemy;
};


#endif //LABPRO_BAGUETTE_H
