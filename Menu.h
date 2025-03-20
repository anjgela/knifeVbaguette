
#ifndef LABPRO_MENU_H
#define LABPRO_MENU_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Match.h"

struct Button {
    Button() {}
    Button(std::string text, sf::Font font, unsigned int charSize, sf::Color color, sf::Vector2f size, sf::Vector2f position)
    : text(text, font, charSize)  {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(color);
        this->text.setPosition(shape.getPosition().x+50.f, shape.getPosition().y+50.f);
        this->text.setFillColor(sf::Color::Black);
    }
    sf::Text text;
    sf::RectangleShape shape;
};

class Menu {
public:
    Menu();
    ~Menu();
    void update();
    void render();
    const bool isWindowOpen() const;
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
    sf::Font playFont;
    Button play;

    Match* match;


};


#endif //LABPRO_MENU_H
