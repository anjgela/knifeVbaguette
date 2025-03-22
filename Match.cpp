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
}
void Match::update() {
    Match::pollEvents();
    Match::updateMousePosWindow();

}
void Match::render() {
    window->clear(sf::Color::White);
    //draw game objects here
    window->draw(baguette->getShape());
    window->draw(knife->getShape());
    window->display();
}
bool Match::isWindowOpen() const {
    return window->isOpen();
}
//private
void Match::pollEvents() {
    while(isWindowOpen()) {
        while(window->pollEvent(ev)) {
            switch(ev.type) {
                case sf::Event::KeyPressed:
                    if (ev.key.code == (sf::Keyboard::Left || sf::Keyboard::A)) {
                        baguette->moveLeft(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Right || sf::Keyboard::D)) {
                        baguette->moveRight(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Up || sf::Keyboard::W)){
                        baguette->moveUp(map);
                    }
                    else if (ev.key.code == (sf::Keyboard::Down || sf::Keyboard::S)){
                        baguette->moveDown(map);
                    }
                        break;
            }
        }
    }
}
void Match::initVariables() {
    window = nullptr;
    knife = new Knife();
    baguette = new Baguette(knife);
}
void Match::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "knifeVbaguette:MENU", sf::Style::Default || sf::Style::Fullscreen); //default: titlebar, resize, close
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);
}
void Match::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}
