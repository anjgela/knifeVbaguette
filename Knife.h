#ifndef LABPRO_KNIFE_H
#define LABPRO_KNIFE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Baguette.h"

class Knife : public Character{
public:
    Knife();
    virtual ~Knife();

    void move(Graph* map) override;
    //everytime Baguette moves, its position becomes Knife's goal and its move method must be updated

private:
    sf::RectangleShape shape;
    Baguette* target;
};


#endif //LABPRO_KNIFE_H
