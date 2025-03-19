#ifndef LABPRO_CHARACTER_H
#define LABPRO_CHARACTER_H

#include <string>
#include "MapSearch.h"
#include "Graph.h"
#include <vector>

class Character {
public:
    Character() : posx(0), posy(0) {}
    virtual ~Character();

    virtual void move(int x, int y, Graph* map);
    virtual void move(Node* node, Graph* map);

    int getPosX();
    int getPosY();

    void setPosX(int x);
    void setPosY(int y);

private:
    int posx;
    int posy;

};


#endif //LABPRO_CHARACTER_H
