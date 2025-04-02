#include <iostream>
#include "Graph.h"
#include "MapSearch.h"
#include "stlastar.h"
#include "Character.h"
#include "Game.h"
#include "Menu.h"
#include <windows.h>

int main() {
    /*
    sf::RenderWindow window(sf::VideoMode(640,800), "AAAAAA", sf::Style::Default);
    sf::Event ev;
    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
            }
        }
    }
    window.clear(sf::Color::Black);
    window.display();
*/


    Menu menu;
    while (menu.isWindowOpen()) {
        menu.update();
        menu.render();
    }
/*
    Match game;
    while (game.isWindowOpen()) {
        game.update();
        game.render();
    }
*/
    return 0;
}

//rappresentazione grafica della mappa (ostacoli e sfondo)
//SFML undefinded reference
