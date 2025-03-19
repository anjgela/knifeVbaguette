#ifndef LABPRO_BAGUETTE_H
#define LABPRO_BAGUETTE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include "SFML/Graphics.hpp"

class Baguette : public Character {
public:
    Baguette();
    virtual ~Baguette() override;

    void move(int x, int y, Graph* map) override;
    void move(Node* node, Graph* map) override;
};


#endif //LABPRO_BAGUETTE_H
