#ifndef LABPRO_MENU_H
#define LABPRO_MENU_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Match.h"

class Menu {
public:
    Menu();
    virtual ~Menu();
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

    sf::RectangleShape title;
    sf::RectangleShape playShape;
    sf::Font font;
    sf::Text playText;

    Match* game;


};


#endif //LABPRO_MENU_H
