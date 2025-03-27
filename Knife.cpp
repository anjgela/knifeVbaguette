#include "Knife.h"
Knife::Knife() {
    posx = 0;
    posy = 0;
    shape.setSize(sf::Vector2f(50.f,50.f)); //every node consists of 50 pixels
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);  //top left corner of the object
    shape.setFillColor(sf::Color::Red);
}
Knife::~Knife() {
}
void Knife::move(int x, int y, Graph* map) {
    MapSearch start(getPosX(),getPosY(),map); //starting node
    MapSearch goal(x,y, map);  //goal
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

    posx = x;
    posy = y;
    shape.setPosition(posx*shape.getSize().x, posy*shape.getSize().y);

    /*std::cout << " knife has moved to (" << posX << ", " << posY << ") through this path: "<< std::endl;
    for (const auto &node : path) {
        std::cout << "(" << node.GetX() << ", " << node.GetY() << ") -> ";
    }*/
}

sf::RectangleShape Knife::getShape() {
    return shape;
}