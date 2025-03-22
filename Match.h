#ifndef LABPRO_MATCH_H
#define LABPRO_MATCH_H

#include <SFML/Graphics.hpp>
#include "Baguette.h"
#include "Knife.h"

class Match {
public:
    Match();
    virtual ~Match();

    void update();
    void render();
    bool isWindowOpen() const;
private:
    void pollEvents();
    void initVariables();
    void initWindow();
    void updateMousePosWindow();
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Vector2i mousePosWindow;

    Baguette* baguette;
    Knife* knife;
    Graph* map;
};


#endif //LABPRO_MATCH_H
