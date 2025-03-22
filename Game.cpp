#include "Game.h"

Game::Game() {
    initVariables();
    initWindow();
    initEnemies();
}
Game::~Game() {

}
void Game::update() {
    pollEvents();
    updateMousePositions();
    updateEnemies();
    //std::cout << "mouse pos: " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl; //relative to the screen
    //std::cout << "mouse pos: " << sf::Mouse::getPosition(*window).x << ", " << sf::Mouse::getPosition(*window).y << std::endl;
}
void Game::render() {
    window->clear();
    //draw game objects here
    renderEnemies();
    //window->draw(enemy);
    window->display();
}
const bool Game::windowIsOpen() const {
    return window->isOpen();
}
void Game::pollEvents() {
    while(window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                break;
        }
    }
}
void::Game::spawnEnemy() {
    enemy.setPosition(static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
                      static_cast<float>(rand() % static_cast<int>(window->getSize().y) - enemy.getSize().y));
    enemy.setFillColor((sf::Color::Red));
    enemies.push_back(enemy);
}
void Game::updateEnemies() {
    //updating timer for enemy spawning
    if (enemies.size() < maxEnemies) {
        if (enemySpawnTimer >= enemySpawnTimerMax) {
            spawnEnemy();
            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }
    //moves enemies
    for (auto &it : enemies) {
        it.move(0.f, 5.f);

    }
    //removes enemies at the edge of the screen
}
void Game::renderEnemies() {
    for (auto &it : enemies) {
        window->draw(it);
    }

}

void Game::initVariables() {
    this->window = nullptr;

    //game logic:
    points = 0;
    enemySpawnTimerMax = 1000.f;
    enemySpawnTimer = 0.f;

    maxEnemies = 5;

}
void Game::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height), "game window", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    window->setFramerateLimit(60);
}
void Game::initEnemies() {
    enemy.setPosition(350.f, 250.f);  //top left corner of the object
    enemy.setSize(sf::Vector2f(100.f,100.f));
    enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    enemy.setFillColor(sf::Color::Cyan);
    enemy.setOutlineColor(sf::Color::Magenta);
    enemy.setOutlineThickness(10.f);
}

void Game::updateMousePositions() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}

