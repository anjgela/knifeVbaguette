#include "Menu.h"

//public methods
Menu::Menu() {
    Menu::initVariables();
    Menu::initWindow();
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
    window->clear(sf::Color::Black);
    //draw menu objects here
    window->draw(title);
    window->draw(play.shape);
    window->draw(play.text);
    window->display();
}
bool Menu::isWindowOpen() const {
    return window->isOpen();
}

//private methods
void Menu::pollEvents() {
    while (isWindowOpen()) {
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
                case sf::Event::MouseButtonPressed: //init game
                    if (ev.mouseButton.button == sf::Mouse::Button::Left) {
                        if (mousePosWindow.x > play.shape.getPosition().x
                            && mousePosWindow.x < (play.shape.getPosition().x + play.shape.getSize().x)
                            && mousePosWindow.y > play.shape.getPosition().y
                            && mousePosWindow.y < (play.shape.getPosition().y + play.shape.getSize().y)) {
                            window->close();
                            game = new Match();
                        }
                    }
                    break;
            }
        }
    }
}
void Menu::initVariables() {
    //window
    window = nullptr;


    //title
    title.setSize(sf::Vector2f(300.f,100.f));
    title.setPosition(350.f, 250.f);
    /*
    sf::Texture texture;
    if (!texture.loadFromFile("")) {    //ELEFANTE: PROBLEMS WITH LOADING FILE
        std::cerr << "Error loading texture!" << std::endl;
    }
    title.setTexture(&texture);
    */
    title.setFillColor(sf::Color::Yellow);

    //button
    playFont.loadFromFile("Hot Food.otf");
    if (!playFont.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    };
    play = Button("PLAY", playFont, 25, sf::Color::Magenta, sf::Vector2f(400.f,250.f), sf::Vector2i(350,350));
    game = nullptr;
}
void Menu::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "knifeVbaguette:MENU", sf::Style::Default); //default: titlebar, resize, close
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);   //synchronize application refresh rate w/ vertical frequency of the monitor
}
void Menu::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}