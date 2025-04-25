#ifndef LABPRO_KNIFE_H
#define LABPRO_KNIFE_H

#include "Character.h"
#include "MapSearch.h"
#include "Graph.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Knife : public Character{
public:
    Knife();
    ~Knife() override;

    void move(int x, int y, Graph* map);
    void update(Graph* map) override;
    std::vector<MapSearch> getPath() const;
    sf::RectangleShape getShape() const;
    sf::Clock getClock() const;

    bool pathFound() const;

private:
    std::vector<MapSearch> path;
    size_t currentPathIndex = 0;
    sf::Clock clock;




};


#endif //LABPRO_KNIFE_H
