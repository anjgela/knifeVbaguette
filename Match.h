#ifndef LABPRO_MATCH_H
#define LABPRO_MATCH_H

#include <SFML/Graphics.hpp>

class Match {
public:
    Match();
    void update();
    void render();
private:
    void initVariables();
    void initWindow();
private:
    sf::RenderWindow* window;
};


#endif //LABPRO_MATCH_H
