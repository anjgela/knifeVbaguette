#include "Knife.h"
Knife::Knife() : currentPathIndex(0) {
    posx = 0;
    posy = 0;
    if (!texture.loadFromFile("KplayingR.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(50.f,50.f)); //every node consists of 50 pixels
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);  //top left corner of the object
    clock.restart();
}
Knife::~Knife() {
}
void Knife::move(int x, int y, Graph* map) {
    MapSearch start(getPosX(),getPosY(),map); //starting node
    MapSearch goal(x,y, map);  //goal
    path.clear();

    std::cout << "START: " << start.getX() << ", " << start.getY() << std::endl;
    std::cout << "GOAL: " << goal.getX() << ", " << goal.getY() << std::endl;

    AStarSearch<MapSearch> astarsearch;                     //A* algorithm to find path
    astarsearch.SetStartAndGoalStates(start, goal);
    unsigned int searchState;   //keeping track of search state
    do {
        searchState = astarsearch.SearchStep();
    } while (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SEARCHING);

    if (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SUCCEEDED) {
        MapSearch* node = astarsearch.GetSolutionStart();
        while (node != nullptr) {
            path.push_back(*node);
            node = astarsearch.GetSolutionNext();
        }
    } else {
        std::cerr << "Path not found" << std::endl;
    }
    astarsearch.FreeSolutionNodes();

    currentPathIndex = 0;
}

void Knife::update(Graph* map) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        if (currentPathIndex < path.size()) {
            int newPosx = path[currentPathIndex].getX();
            if (newPosx > posx) {
                right = true;
                left = false;
                if (!texture.loadFromFile("KplayingR.png")) {
                    std::cerr << "Error loading texture" << std::endl;
                }
            } else if (newPosx < posx) {
                left = true;
                right= false;
                if (!texture.loadFromFile("KplayingL.png")) {
                    std::cerr <<"Error loading texture" << std::endl;
                }
            }
            posx = newPosx;
            posy = path[currentPathIndex].getY();
            shape.setTexture(&texture);
            shape.setPosition(posx * 50.f, posy * 50.f);
            currentPathIndex++;
        }
        clock.restart();
    }
}


sf::RectangleShape Knife::getShape() {
    return shape;
}