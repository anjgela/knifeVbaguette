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
    window->clear();
    //draw menu objects here
    window->draw(title);
    window->draw(playShape);
    window->draw(playText);
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
    }
}
void Menu::initVariables() {
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
    playShape.setSize(sf::Vector2f(400.f, 250.f));
    playShape.setPosition(350.f,350.f);
    playShape.setFillColor(sf::Color::Magenta);
    font.loadFromFile("Hot Food.otf");
    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    };
    playText = sf::Text("PLAY", font, 25);
    playText.setFillColor(sf::Color::Black);
    playText.setPosition(playShape.getPosition().x+50.f,playShape.getPosition().y+50.f);
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