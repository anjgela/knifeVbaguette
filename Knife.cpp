#include "Knife.h"

Knife::Knife() {
    target = Baguette(this);
    shape.setPosition(0.f, 0.f);  //top left corner of the object
    shape.setSize(sf::Vector2f(100.f,100.f));
    shape.setFillColor(sf::Color::Red);
}
Knife::~Knife() {
    delete target;  // Clean up memory
}
void Knife::move(Graph* map) {
    MapSearch start(getPosX(),getPosY(),map); //starting node
    MapSearch goal(target->getPosX(),target->getPosY(), map);  //goal
    std::vector<MapSearch> path;    //solution path

    AStarSearch<MapSearch> astarsearch;                     //A* algorithm to find path
    astarsearch.SetStartAndGoalStates(start, goal);
    unsigned int searchState;   //keeping track of search state
    do {
        searchState = astarsearch.SearchStep();
    } while (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SEARCHING);
    if (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SUCCEEDED) {
        MapSearch* node = astarsearch.GetSolutionNext();
        while ( node != nullptr) {
            path.push_back(*node);
        }
    }   else {
        std::cout << "path not found" << std::endl;
    }    astarsearch.FreeSolutionNodes();    //free allocated memory for the solution nodes

    setPosX(x);
    setPosY(y);

    std::cout << " knife has moved to (" << x << ", " << y << ") through this path: "<< std::endl;
    for (const auto &node : path) {
        std::cout << "(" << node.GetX() << ", " << node.GetY() << ") -> ";
    }
}

