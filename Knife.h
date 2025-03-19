#ifndef LABPRO_KNIFE_H
#define LABPRO_KNIFE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include <vector>

class Knife : public Character{
public:
    Knife();
    virtual ~Knife() override;

    void move(int x, int y, Graph* map) override;
    void move(Node* node, Graph* map) override;



};


#endif //LABPRO_KNIFE_H
