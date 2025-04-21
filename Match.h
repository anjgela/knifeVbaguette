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

    void setKnifePosition(float x, float y);
    void setBaguettePosition(float x, float y);

    void update();
    void render();
    bool isWindowOpen() const;
    gameStatus checkGameStatus();
    sf::Time getPlayingTime() const;
    bool isPaused() const;
    void togglePause();

private:
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

    gameStatus status = PLAYING;
    sf::Font font;
    //pause
    bool paused = false;

    sf::RectangleShape pauseVeil;
    sf::RectangleShape resumeShape;
    sf::Text resumeText;

    //game over
    sf::Text gameOverText;
    sf::RectangleShape gameOverKnifeShape;
    sf::Texture gameOverKnifeTexture;
    sf::RectangleShape gameOverBaguetteShape;
    sf::Texture gameOverBaguetteTexture;

    //win
    sf::Text winText;
    sf::RectangleShape winKnifeShape;
    sf::Texture winKnifeTexture;
    sf::RectangleShape winBaguetteShape;
    sf::Texture winBaguetteTexture;

    sf::RectangleShape exitShape;
    sf::Text exitText;
    sf::RectangleShape playAgainShape;
    sf::Text playAgainText;

    //timer
    sf::Clock timer;
    sf::Time playingTime;
    sf::RectangleShape timerShape;
    sf::Text timerText;
};


#endif //LABPRO_MATCH_H
