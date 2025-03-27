#include "Match.h"

//public
Match::Match() {
    Match::initVariables();
    Match::initWindow();
}
Match::~Match() {
    delete window;
    delete baguette;
    delete knife;
    delete map;
}
void Match::update() {
    if (!paused) {
        Match::pollEvents();
    }
    else {
        pollPauseEvents();
    }
    Match::updateMousePosWindow();
}
void Match::render() {
    window->clear(sf::Color::Black);
    //draw map
    /*for (auto node : map->getNodes()) {
        if (node->getID() == OBSTACLE) {
            window->draw(node->getShape());
        }
    }*/
    //draw characters
    window->draw(baguette->getShape());
    window->draw(knife->getShape());
    if (paused) {
        window->draw(pauseVeil);
        window->draw(resumeShape);
        window->draw(resumeText);
    }
    window->display();
}
bool Match::isWindowOpen() const {
    return window->isOpen();
}
//private
bool Match::isPaused() const {
    return paused;
}
void Match::togglePause() {
    paused = !paused;
}
void Match::pollEvents() {
    while(window->isOpen()) {
        while(window->pollEvent(ev)) {
            switch(ev.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Space) {
                        togglePause();
                    }
                    if (ev.key.code == (sf::Keyboard::Left) || ev.key.code == (sf::Keyboard::A)) {
                        baguette->moveLeft(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Right) || ev.key.code == (sf::Keyboard::D)) {
                        baguette->moveRight(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Up) || ev.key.code == (sf::Keyboard::W)){
                        baguette->moveUp(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Down) || ev.key.code == (sf::Keyboard::S)){
                        baguette->moveDown(map);
                    }
                        break;
            }
        }
    }
}
void Match::pollPauseEvents() {
    while (window->isOpen()) {
        while (window->pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape) {
                        window->close();
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (ev.mouseButton.button == sf::Mouse::Button::Left) {
                        if (mousePosWindow.x > resumeShape.getPosition().x
                        && mousePosWindow.x < (resumeShape.getPosition().x + resumeShape.getSize().x)
                        && mousePosWindow.y > resumeShape.getPosition().y
                        && mousePosWindow.y < (resumeShape.getPosition().y + resumeShape.getSize().y)) {
                            togglePause();
                        }
                        else if (mousePosWindow.x > exitShape.getPosition().x
                        && mousePosWindow.x < (exitShape.getPosition().x + exitShape.getSize().x)
                        && mousePosWindow.y > exitShape.getPosition().y
                        && mousePosWindow.y < (exitShape.getPosition().y + exitShape.getSize().y)) {
                            window->close();
                        }
                    }
                    break;
            }
        }
    }
}
void Match::initVariables() {
    knife = new Knife();
    baguette = new Baguette(knife);
    map = new Graph();

    //pause variables
    pauseVeil.setSize(sf::Vector2f(800.f,600.f));
    pauseVeil.setFillColor(sf::Color(0,0,0,150));

    resumeShape.setSize(sf::Vector2f(400.f, 250.f));
    resumeShape.setPosition(350.f,350.f);
    resumeShape.setFillColor(sf::Color::Green);
    font.loadFromFile("Hot Food.otf");
    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    resumeText = sf::Text("RESUME GAME", font, 25);
    resumeText.setFillColor(sf::Color::Black);
    resumeText.setPosition(resumeShape.getPosition().x+50.f, resumeShape.getPosition().y+50.f);

    exitShape.setSize(sf::Vector2f(400.f,250.f));
    exitShape.setPosition(350.f,450.f);
    exitShape.setFillColor(sf::Color::Red);
    exitText = sf::Text("EXIT GAME", font, 25);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(exitShape.getPosition().x+50.f, exitShape.getPosition().y+50.f);
}
void Match::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "knifeVbaguette:MENU", sf::Style::Default | sf::Style::Fullscreen); //default: titlebar, resize, close
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
}
void Match::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}