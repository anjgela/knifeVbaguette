/*
 * class that acts as the game engine (wrapper class)
 */
#ifndef LABPRO_GAME_H
#define LABPRO_GAME_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Game {
public:
    Game();
    virtual ~Game();
    void update();
    void render();
    const bool windowIsOpen() const;
    void pollEvents();
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();


private:
    sf::RenderWindow* window;   //renderwindow ptr
    sf::VideoMode videoMode;
    sf::Event ev;   //event

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    sf::Vector2i mousePosWindow;

    void initVariables();
    void initWindow();
    void initEnemies();

    void updateMousePositions();

    //game logic:
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned int maxEnemies;



};

#endif //LABPRO_GAME_H
