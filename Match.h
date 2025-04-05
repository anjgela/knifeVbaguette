#ifndef LABPRO_MATCH_H
#define LABPRO_MATCH_H

#include <SFML/Graphics.hpp>
#include "Baguette.h"
#include "Knife.h"
#include "Graph.h"
#include <sstream>

enum gameStatus {
    PLAYING,
    GAME_OVER,
    WIN
};

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
    void pollEndEvents();
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

    unsigned int status = PLAYING;
    unsigned int checkGameStatus();
    sf::Font font;
    //pause
    bool paused = false;

    sf::RectangleShape pauseVeil;
    sf::RectangleShape resumeShape;
    sf::Text resumeText;

    //game over
    sf::RectangleShape gameOverShape;
    sf::Text gameOverText;

    //win
    sf::RectangleShape winShape;
    sf::Text winText;

    sf::RectangleShape exitShape;
    sf::Text exitText;
    sf::RectangleShape playAgainShape;
    sf::Text playAgainText;

    //timer
    sf::Clock timer;
    sf::Time playingTime;
    sf::Text timerText;
};


#endif //LABPRO_MATCH_H
