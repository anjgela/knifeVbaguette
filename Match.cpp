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
    static int counter = 0;
    if (!paused) {
        Match::pollEvents();
        knife->update(map);
        std::cerr << "Test " << counter++ << std::endl;
    } else {
        pollPauseEvents();
    }
    Match::updateMousePosWindow();
}

void Match::render() {
    window->clear(sf::Color::Blue);
    //draw map
    //draw characters
    window->draw(baguette->getShape());
    window->draw(knife->getShape());
    if (paused) {
        window->draw(pauseVeil);
        window->draw(resumeShape);
        window->draw(resumeText);
        window->draw(exitShape);
        window->draw(exitText);
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
    window->pollEvent(ev);
    switch (ev.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape) {
                window->close();
                break;
            }
            if (ev.key.code == sf::Keyboard::Space) {
                togglePause();
            }
            if (ev.key.code == (sf::Keyboard::Left)) {
                if ((baguette->getPosX() - 1) * 50.f >= 0) {
                    baguette->moveLeft(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::A)) {
                if ((baguette->getPosX() - 1) * 50.f >= 0) {
                    baguette->moveLeft(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::Right)) {
                if ((baguette->getPosX() + 1) * 50.f <= window->getSize().x-50.f) {
                    baguette->moveRight(map);
                }
            } else if (ev.key.code == (sf::Keyboard::D)) {
                if ((baguette->getPosX() + 1) * 50.f <= window->getSize().x-50.f) {
                    baguette->moveRight(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::Up))
                if ((baguette->getPosY() - 1) * 50.f >= 0) {
                    baguette->moveUp(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::W)) {
                if ((baguette->getPosY() - 1) * 50.f >= 0) {
                    baguette->moveUp(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::Down)) {
                if ((baguette->getPosY() + 1) * 50.f <= window->getSize().y-50.f) {
                    baguette->moveDown(map);
                }
            }
            if (ev.key.code == (sf::Keyboard::S)) {
                if ((baguette->getPosY() + 1) * 50.f <= window->getSize().y-50.f) {
                    baguette->moveDown(map);
                }
            }
}

void Match::pollPauseEvents() {
    window->pollEvent(ev);
        switch (ev.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {
                    window->close();
                    break;
                }
                if (ev.key.code == sf::Keyboard::Space) {
                    togglePause();
                    break;
                }
            case sf::Event::MouseButtonPressed:
                if (ev.mouseButton.button == sf::Mouse::Button::Left) {
                    if (mousePosWindow.x > resumeShape.getPosition().x
                    && mousePosWindow.x < (resumeShape.getPosition().x + resumeShape.getSize().x)
                    && mousePosWindow.y > resumeShape.getPosition().y
                    && mousePosWindow.y < (resumeShape.getPosition().y + resumeShape.getSize().y)) {
                        togglePause();
                        break;
                    } else if (mousePosWindow.x > exitShape.getPosition().x
                    && mousePosWindow.x < (exitShape.getPosition().x + exitShape.getSize().x)
                    && mousePosWindow.y > exitShape.getPosition().y
                    && mousePosWindow.y < (exitShape.getPosition().y + exitShape.getSize().y)) {
                        window->close();
                    }
                }
                break;
        }
}


void Match::initVariables() {
    knife = new Knife();
    baguette = new Baguette(knife);
    map = new Graph();

    //pause variables
    font.loadFromFile("Hot Food.otf");
    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    pauseVeil.setSize(sf::Vector2f(1366.f, 768.f));
    pauseVeil.setFillColor(sf::Color(0, 0, 0, 150));

    resumeShape.setSize(sf::Vector2f(300.f, 150.f));
    resumeShape.setPosition(250.f, 200.f);
    resumeShape.setFillColor(sf::Color::Green);
    resumeText = sf::Text("RESUME GAME", font, 25);
    resumeText.setFillColor(sf::Color::Black);
    resumeText.setPosition(resumeShape.getPosition().x + 50.f, resumeShape.getPosition().y + 50.f);

    exitShape.setSize(sf::Vector2f(300.f, 150.f));
    exitShape.setPosition(250.f, 600.f);
    exitShape.setFillColor(sf::Color::Red);
    exitText = sf::Text("EXIT GAME", font, 25);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(exitShape.getPosition().x + 50.f, exitShape.getPosition().y + 50.f);
}

void Match::initWindow() {
    videoMode.width = 1366;
    videoMode.height = 768;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "knifeVbaguette:MENU",
                                  sf::Style::Default | sf::Style::Fullscreen); //default: titlebar, resize, close
    window->setFramerateLimit(60);
}

void Match::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}