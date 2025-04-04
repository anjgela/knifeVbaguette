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
        sf::Time elapsed = playingTime + timer.getElapsedTime();
        if (checkGameStatus() == PLAYING) {
            if (elapsed.asSeconds() > 60) {
                timer.restart();
                playingTime = sf::Time::Zero;
                status = WIN;
            }
            Match::pollEvents();
            baguette->update(map);
            knife->update(map);
        } else {
            pollEndEvents();
        }
    } else {
        pollPauseEvents();
    }
    Match::updateMousePosWindow();
}

void Match::render() {
    if (checkGameStatus() == GAME_OVER) {
        window->clear(sf::Color::Red);
        window->draw(gameOverShape);
        window->draw(gameOverText);
    } else if (checkGameStatus() == WIN) {
        window->clear(sf::Color::Green);
        window->draw(winShape);
        window->draw(winText);
    }
    if (checkGameStatus() != PLAYING) {
        window->draw(playAgainShape);
        window->draw(playAgainText);
        window->draw(exitShape);
        window->draw(exitText);
    } else {
        window->clear(sf::Color::Black);
        //draw map
        map->display(*window);
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
    if (paused) {
        timer.restart();
    } else {
        playingTime += timer.getElapsedTime();
    }
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
                    baguette->left = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::A)) {
                if ((baguette->getPosX() - 1) * 50.f >= 0) {
                    baguette->left = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::Right)) {
                if ((baguette->getPosX() + 1) * 50.f <= window->getSize().x - 50.f) {
                    baguette->right = true;
                }
            } else if (ev.key.code == (sf::Keyboard::D)) {
                if ((baguette->getPosX() + 1) * 50.f <= window->getSize().x - 50.f) {
                    baguette->right = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::Up))
                if ((baguette->getPosY() - 1) * 50.f >= 0) {
                    baguette->up = true;
                }
            if (ev.key.code == (sf::Keyboard::W)) {
                if ((baguette->getPosY() - 1) * 50.f >= 0) {
                    baguette->up = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::Down)) {
                if ((baguette->getPosY() + 1) * 50.f <= window->getSize().y - 50.f) {
                    baguette->down = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::S)) {
                if ((baguette->getPosY() + 1) * 50.f <= window->getSize().y - 50.f) {
                    baguette->down = true;
                }
            }
            break;
        case sf::Event::KeyReleased:
            if (ev.key.code == sf::Keyboard::Left) {
                baguette->left = false;
            }
            if (ev.key.code == sf::Keyboard::A) {
                baguette->left = false;
            }
            if (ev.key.code == sf::Keyboard::Right) {
                baguette->right = false;
            }
            if (ev.key.code == sf::Keyboard::D) {
                baguette->right = false;
            }
            if (ev.key.code == sf::Keyboard::Up) {
                baguette->up = false;
            }
            if (ev.key.code == sf::Keyboard::W) {
                baguette->up = false;
            }
            if (ev.key.code == sf::Keyboard::Down) {
                baguette->down = false;
            }
            if (ev.key.code == sf::Keyboard::S) {
                baguette->down = false;
            }
            break;
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

void Match::pollEndEvents() {
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
        case sf::Event::MouseButtonPressed:
            if (ev.mouseButton.button == sf::Mouse::Button::Left) {
                if (mousePosWindow.x > playAgainShape.getPosition().x
                && mousePosWindow.x < (playAgainShape.getPosition().x + playAgainShape.getSize().x)
                && mousePosWindow.y > playAgainShape.getPosition().y
                && mousePosWindow.y < (playAgainShape.getPosition().y + playAgainShape.getSize().y)) {
                    knife = new Knife();
                    baguette = new Baguette(knife);
                    map = new Graph();
                    status = PLAYING;
                    break;
                } else if (mousePosWindow.x > exitShape.getPosition().x
                && mousePosWindow.x < (exitShape.getPosition().x + exitShape.getSize().x)
                && mousePosWindow.y > exitShape.getPosition().y
                && mousePosWindow.y < (exitShape.getPosition().y + exitShape.getSize().y)) {
                    window->close();
                    break;
                }
            }
            break;
    }
}

void Match::initVariables() {
    knife = new Knife();
    baguette = new Baguette(knife);
    map = new Graph();
    std::cout << "MAP DIMENSIONS: " << map->getHeight() << ", " << map->getWidth() << std::endl;
    std::cout << "NODES: " << map->getNodes().size() << std::endl;
    timer.restart();

    font.loadFromFile("Hot Food.otf");
    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    //pause variables
    pauseVeil.setSize(sf::Vector2f(1366.f, 768.f));
    pauseVeil.setFillColor(sf::Color(0, 0, 0, 150));

    resumeShape.setSize(sf::Vector2f(300.f, 150.f));
    resumeShape.setPosition(250.f, 200.f);
    resumeShape.setFillColor(sf::Color::Green);
    resumeText = sf::Text("RESUME GAME", font, 25);
    resumeText.setFillColor(sf::Color::Black);
    resumeText.setPosition(resumeShape.getPosition().x + 50.f, resumeShape.getPosition().y + 50.f);

    //game over variable
    gameOverShape.setSize(sf::Vector2f(300.f, 150.f));
    gameOverShape.setPosition(250.f, 50.f);
    gameOverShape.setFillColor(sf::Color::Magenta);
    gameOverText = sf::Text("GAME OVER", font, 25);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(gameOverShape.getPosition().x + 50.f, gameOverShape.getPosition().y + 50.f);

    //win variable
    winShape.setSize(sf::Vector2f(300.f, 150.f));
    winShape.setPosition(250.f, 50.f);
    winShape.setFillColor(sf::Color::Yellow);
    winText = sf::Text("YOU WIN", font, 25);
    winText.setFillColor(sf::Color::Black);
    winText.setPosition(winShape.getPosition().x + 50.f, winShape.getPosition().y + 50.f);

    playAgainShape.setSize(sf::Vector2f(300.f, 150.f));
    playAgainShape.setPosition(250.f, 300.f);
    playAgainShape.setFillColor(sf::Color::Green);
    playAgainText = sf::Text("PLAY AGAIN", font, 25);
    playAgainText.setFillColor(sf::Color::Black);
    playAgainText.setPosition(playAgainShape.getPosition().x + 50.f, playAgainShape.getPosition().y + 50.f);

    exitShape.setSize(sf::Vector2f(300.f, 150.f));
    exitShape.setPosition(250.f, 600.f);
    exitShape.setFillColor(sf::Color::Red);
    exitText = sf::Text("EXIT GAME", font, 25);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(exitShape.getPosition().x + 50.f, exitShape.getPosition().y + 50.f);
}

void Match::initWindow() {
    videoMode.width = sf::VideoMode::getDesktopMode().width;
    videoMode.height = sf::VideoMode::getDesktopMode().height;
    window = new sf::RenderWindow(sf::VideoMode(videoMode.width, videoMode.height),"knifeVbaguette:GAME",
                                  sf::Style::Default | sf::Style::Fullscreen); //default: titlebar, resize, close
    window->setFramerateLimit(60);
}

void Match::updateMousePosWindow() {
    mousePosWindow = sf::Mouse::getPosition(*window);
}

unsigned int Match::checkGameStatus() {
    if (knife->getShape().getPosition() == baguette->getShape().getPosition()) {
        status = GAME_OVER;
    }
    return status;
}