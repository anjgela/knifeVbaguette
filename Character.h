#ifndef LABPRO_CHARACTER_H
#define LABPRO_CHARACTER_H

#include <string>
#include "MapSearch.h"
#include "Graph.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Character {
public:
    Character() : posx(0), posy(0) {}
    virtual ~Character();

    /*    CHANGE MOVE: ARGUMENTS ONLY MAP:
     * BAGUETTE GETS DESTINATION FROM KEYBORD
     * KNIFE GETS DESTINATION FROM BAGUETTES POSITION
     */


    int getPosX();
    int getPosY();

    void setPosX(int x);
    void setPosY(int y);

protected:
    int posx;
    int posy;
    sf::RectangleShape shape;

};


#endif //LABPRO_CHARACTER_H
