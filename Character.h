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
    sf::RectangleShape getShape() const;

    void setPosX(int x);
    void setPosY(int y);

    virtual void update(Graph* map) = 0;

    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;


protected:
    int posx;
    int posy;
    sf::RectangleShape shape;
    sf::Texture texture;
};


#endif //LABPRO_CHARACTER_H
