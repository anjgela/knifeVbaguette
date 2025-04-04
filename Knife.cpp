#include "Knife.h"
Knife::Knife() : currentPathIndex(0) {
    posx = 0;
    posy = 0;
    shape.setSize(sf::Vector2f(50.f,50.f)); //every node consists of 50 pixels
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);  //top left corner of the object
    shape.setFillColor(sf::Color::Red);
    clock.restart();
}
Knife::~Knife() {
}
void Knife::move(int x, int y, Graph* map) {
    MapSearch start(getPosX(),getPosY(),map); //starting node
    MapSearch goal(x,y, map);  //goal
    path.clear();

    std::cout << "START: " <<start.GetX() << ", " << start.GetY() << std::endl;
    std::cout << "GOAL: " << goal.GetX() << ", " << goal.GetY() << std::endl;

    AStarSearch<MapSearch> astarsearch;                     //A* algorithm to find path
    astarsearch.SetStartAndGoalStates(start, goal);
    unsigned int searchState;   //keeping track of search state
    do {
        searchState = astarsearch.SearchStep();
    } while (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SEARCHING);

    if (searchState == AStarSearch<MapSearch>::SEARCH_STATE_SUCCEEDED) {
        MapSearch* node = astarsearch.GetSolutionStart();
        std::cout << "CURRENT NODE : " << node->GetX() << ", " << node->GetY() << std::endl;
        while (node != nullptr) {
            path.push_back(*node);
            node = astarsearch.GetSolutionNext();
        }
        std::cout << "Path found with " << path.size() << " nodes." << std::endl;
    } else {
        std::cout << "path not found" << std::endl;
    }
    astarsearch.FreeSolutionNodes();    //free allocated memory for the solution nodes

    currentPathIndex = 0;
}

void Knife::update(Graph* map) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        if (currentPathIndex < path.size()) {
            posx = path[currentPathIndex].GetX();
            posy = path[currentPathIndex].GetY();
            shape.setPosition(posx * 50.f, posy * 50.f);
            currentPathIndex++;
        }
        clock.restart();
    }

    std::cout << "Knife position: " << posx << ", " << posy << std::endl;
}


sf::RectangleShape Knife::getShape() {
    return shape;
}