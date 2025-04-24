#include "Match.h"
#include <iostream>
//public
Match::Match() {
    std::cout << "to be initialised" << std::endl;
    Match::initVariables();
    std::cout << "variables initialised" << std::endl;
    Match::initWindow();
    std::cout << "window initialised" << std::endl;
}

Match::~Match() {
    delete window;
    delete baguette;
    delete knife;
    delete map;
}

Baguette* Match::getBaguette() const {
    return baguette;
}

Knife* Match::getKnife() const {
    return knife;
}

void Match::update() {
    if (!paused) {
        sf::Time elapsed = playingTime + timer.getElapsedTime();
        std::stringstream ss;
        if (checkGameStatus() == PLAYING) {
            ss << "TIME: " << static_cast<int>(45-elapsed.asSeconds());
            timerText.setString(ss.str());
            if (elapsed.asSeconds() > 34) {
                timerShape.setFillColor(sf::Color(255, 0, 0, 150));
            }
            if (elapsed.asSeconds() > 45) {
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
        window->clear(sf::Color(217, 74, 74));
        //window->draw(gameOverShape);
        window->draw(gameOverText);
        window->draw(gameOverKnifeShape);
        window->draw(gameOverBaguetteShape);
    } else if (checkGameStatus() == WIN) {
        window->clear(sf::Color(94, 140, 47));
        //window->draw(winShape);
        window->draw(winText);
        window->draw(winKnifeShape);
        window->draw(winBaguetteShape);
    }
    if (checkGameStatus() != PLAYING) {
        window->draw(playAgainShape);
        window->draw(playAgainText);
        window->draw(exitShape);
        window->draw(exitText);
    } else {
        window->clear(sf::Color(181, 225, 245));
        //draw map
        map->display(*window);
        //draw characters
        window->draw(baguette->getShape());
        window->draw(knife->getShape());
        window->draw(timerShape);
        window->draw(timerText);
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

gameStatus Match::checkGameStatus() {
    if (knife->getShape().getPosition() == baguette->getShape().getPosition()) {
        status = GAME_OVER;
    }
    return status;
}
gameStatus Match::getGameStatus() const {
    return status;
}

sf::Time Match::getPlayingTime() const {
    return playingTime;
}

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


void Match::fastForwardTimer(sf::Time dt) {
    playingTime += dt;
    //timer().restart();
}
//private
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
                    baguette->up= true;
                }
            if (ev.key.code == (sf::Keyboard::W)) {
                if ((baguette->getPosY() - 1) * 50.f >= 0) {
                    baguette->up = true;
                }
            }
            if (ev.key.code == (sf::Keyboard::Down)) {
                if ((baguette->getPosY() + 1) * 50.f <= window->getSize().y - 50.f) {
                    baguette->down= true;
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
                    status = PLAYING;
                    knife = new Knife();
                    map = new Graph();
                    baguette = new Baguette(knife, map);
                    timer.restart();
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
    map = new Graph();
    baguette = new Baguette(knife, map);

    if (!font.loadFromFile("Hot Food.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    //pause variables
    pauseVeil.setSize(sf::Vector2f(1366.f, 768.f));
    pauseVeil.setFillColor(sf::Color(0, 0, 0, 150));

    resumeShape.setSize(sf::Vector2f(300.f, 150.f));
    resumeShape.setPosition(250.f, 200.f);
    resumeShape.setFillColor(sf::Color(146,210,88));
    resumeShape.setOutlineThickness(5.f);
    resumeShape.setOutlineColor(sf::Color::Black);
    resumeText = sf::Text("RESUME GAME", font, 40);
    resumeText.setFillColor(sf::Color::Black);
    resumeText.setPosition(resumeShape.getPosition().x + 50.f, resumeShape.getPosition().y + 50.f);

    //game over variables
    gameOverText = sf::Text("GAME OVER", font, 150);
    gameOverText.setFillColor(sf::Color(250,150,130));
    gameOverText.setPosition(60.f, 50.f);
    gameOverKnifeShape.setSize(sf::Vector2f(300.f, 500.f));
    gameOverKnifeShape.setPosition(1000.f,150.f);
    if(!gameOverKnifeTexture.loadFromFile("Kgameover.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    gameOverKnifeShape.setTexture(&gameOverKnifeTexture);
    gameOverBaguetteShape.setSize(sf::Vector2f(300.f,500.f));
    gameOverBaguetteShape.setPosition(sf::Vector2f(650.f, 150.f));
    if (!gameOverBaguetteTexture.loadFromFile("Bgameover.png")) {
    std::cerr << "Error loading texture" << std::endl;
    }
    gameOverBaguetteShape.setTexture(&gameOverBaguetteTexture);

    //win variables
    winText = sf::Text("YOU WIN", font, 150);
    winText.setFillColor(sf::Color(146,210,88));
    winText.setPosition(60.f, 50.f);
    winKnifeShape.setSize(sf::Vector2f(300.f, 500.f));
    winKnifeShape.setPosition(1000.f,150.f);
    if(!winKnifeTexture.loadFromFile("Kwin.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    winKnifeShape.setTexture(&winKnifeTexture);
    winBaguetteShape.setSize(sf::Vector2f(300.f,500.f));
    winBaguetteShape.setPosition(sf::Vector2f(650.f, 150.f));
    if (!winBaguetteTexture.loadFromFile("Bwin.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    winBaguetteShape.setTexture(&winBaguetteTexture);

    playAgainShape.setSize(sf::Vector2f(300.f, 150.f));
    playAgainShape.setPosition(250.f, 300.f);
    playAgainShape.setFillColor(sf::Color(146,210,88));
    playAgainShape.setOutlineThickness(5.f);
    playAgainShape.setOutlineColor(sf::Color::Black);
    playAgainText = sf::Text("PLAY AGAIN", font, 40);
    playAgainText.setFillColor(sf::Color::Black);
    playAgainText.setPosition(playAgainShape.getPosition().x + 50.f, playAgainShape.getPosition().y + 50.f);

    exitShape.setSize(sf::Vector2f(300.f, 150.f));
    exitShape.setPosition(250.f, 500.f);
    exitShape.setFillColor(sf::Color(250,150,130));
    exitShape.setOutlineThickness(5.f);
    exitShape.setOutlineColor(sf::Color::Black);
    exitText = sf::Text("EXIT GAME", font, 40);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(exitShape.getPosition().x + 50.f, exitShape.getPosition().y + 50.f);

    //timer
    timer.restart();
    timerShape.setSize(sf::Vector2f(80.f, 40.f));
    timerShape.setPosition(115.f, 15.f);
    timerShape.setFillColor(sf::Color(0, 0, 0, 150));
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setPosition(timerShape.getPosition().x+5.f, timerShape.getPosition().y+5.f);
    timerText.setFillColor(sf::Color::White);

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

void Match::setPlayingTime(const sf::Time &playingTime) {
    Match::playingTime = playingTime;
}

const sf::Clock &Match::getTimer() const {
    return timer;
}


