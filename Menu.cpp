#include "Menu.h"

//public methods
Menu::Menu() {
    play = Button();
    Menu::initVariables();
    Menu::initWindow();

}
Menu::~Menu(){
    delete window;
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
const bool Menu::isWindowOpen() const {
    return window->isOpen();
}

//private methods


void Menu::pollEvents() {
    while(window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                /*else if(ev.key.code == sf::Keyboard::Enter) {
                    match = new Match();
                }
                break;*/
        }
    }
}
void Menu::initVariables() {
    //window
    this->window = nullptr;

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
    playFont.loadFromFile("C:/Users/Utente/Desktop/uni/primo anno/laboratorio di programmazione/labpro/cmake-build-debug/Hot Food.otf");
    if (!playFont.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    };
    play = Button("PLAY", playFont, 25, sf::Color::Magenta, sf::Vector2f(400.f,250.f), sf::Vector2f(350.f,350.f));
}
void Menu::initWindow() {
    videoMode.width = 800;
    videoMode.height = 600;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),
                                  "game window", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    window->setFramerateLimit(144);
}
void Menu::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}