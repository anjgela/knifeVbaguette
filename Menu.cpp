#include "Menu.h"

//public methods
Menu::Menu() {
    Menu::initWindow();
    Menu::initVariables();
}
Menu::~Menu(){
    delete window;
    delete game;
}
void Menu::update() {
    Menu::pollEvents();
    Menu::updateMousePosWindow();
}
void Menu::render() {
    window->clear();
    //draw menu objects here
    window->draw(titleShape);
    window->draw(titleText);
    window->draw(playShape);
    window->draw(playText);
    window->display();
}
bool Menu::isWindowOpen() const {
    return window->isOpen();
}

//private methods
void Menu::pollEvents() {
    window->pollEvent(ev);
    switch (ev.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape) {
                window->close();
            }
            break;
        case sf::Event::MouseButtonPressed: //init game
             if (ev.mouseButton.button == sf::Mouse::Button::Left) {
                if (mousePosWindow.x > playShape.getPosition().x
                && mousePosWindow.x < (playShape.getPosition().x + playShape.getSize().x)
                && mousePosWindow.y > playShape.getPosition().y
                && mousePosWindow.y < (playShape.getPosition().y + playShape.getSize().y)) {
                    window->close();
                    game = new Match();
                    while (game->isWindowOpen()) {
                        game->update();
                        game->render();
                    }
                }
             }
             break;
    }
}
void Menu::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "knifeVbaguette:MENU", sf::Style::Default); //default: titlebar, resize, close
    window->setFramerateLimit(60);
}
void Menu::initVariables() {
    //font
    font.loadFromFile("Hot Food.otf");
    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    //title
    titleShape.setSize(sf::Vector2f(770.f,200.f));
    titleShape.setPosition((videoMode.width/2) - (titleShape.getSize().x/2), videoMode.height/7);
    titleShape.setFillColor(sf::Color::Red);

    titleText = sf::Text("KNIFE V BAGUETTE", font, 120);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(titleShape.getPosition().x + titleShape.getSize().x/2 - titleText.getLocalBounds().width/2,
                          titleShape.getPosition().y + titleShape.getSize().y/3 - titleText.getLocalBounds().height/2);

    //button
    playShape.setSize(sf::Vector2f(400.f, 200.f));
    playShape.setPosition((videoMode.width/2) - (playShape.getSize().x/2), videoMode.height*3/5);
    playShape.setFillColor(sf::Color::Green);

    playText = sf::Text("PLAY", font, 150);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(playShape.getPosition().x + playShape.getSize().x/2 - playText.getLocalBounds().width/2,
                         playShape.getPosition().y + playShape.getSize().y/3 - playText.getLocalBounds().height/2);

    //game window
    game = nullptr;
}

void Menu::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}