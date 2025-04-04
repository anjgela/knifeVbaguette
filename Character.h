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

    int getPosX();
    int getPosY();

    void setPosX(int x);
    void setPosY(int y);

    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;

protected:
    int posx = 0;
    int posy = 0;
    sf::RectangleShape shape;
    sf::Texture texture;
};


#endif //LABPRO_CHARACTER_H
