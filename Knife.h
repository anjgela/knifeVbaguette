#ifndef LABPRO_KNIFE_H
#define LABPRO_KNIFE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Knife : public Character{
public:
    Knife();
    virtual ~Knife();

    void move(int x, int y, Graph* map);
    //everytime Baguette moves, its position becomes Knife's goal and its move method must be updated

    sf::RectangleShape getShape();


};


#endif //LABPRO_KNIFE_H
