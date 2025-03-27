#ifndef LABPRO_CHARACTER_H
#define LABPRO_CHARACTER_H

#include <string>
#include "MapSearch.h"
#include "Graph.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Character {
public:
    Character() = default;
    virtual ~Character() = default;

    /*    CHANGE MOVE: ARGUMENTS ONLY MAP:
     * BAGUETTE GETS DESTINATION FROM KEYBORD
     * KNIFE GETS DESTINATION FROM BAGUETTES POSITION
     */


    int getPosX();
    int getPosY();

    void setPosX(int x);
    void setPosY(int y);

protected:
    int posx = 0;
    int posy = 0;
    sf::RectangleShape shape;

};


#endif //LABPRO_CHARACTER_H
