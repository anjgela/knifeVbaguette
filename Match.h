#ifndef LABPRO_MATCH_H
#define LABPRO_MATCH_H

#include <SFML/Graphics.hpp>
#include "Baguette.h"
#include "Knife.h"
#include "Graph.h"

class Match {
public:
    Match();
    virtual ~Match();

    void update();
    void render();
    bool isWindowOpen() const;

private:
    bool isPaused() const;
    void togglePause();
    void pollEvents();
    void pollPauseEvents();
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

    bool paused = false;

    sf::RectangleShape pauseVeil;
    sf::RectangleShape resumeShape;
    sf::Font font;
    sf::Text resumeText;
    sf::RectangleShape exitShape;
    sf::Text exitText;
};


#endif //LABPRO_MATCH_H
