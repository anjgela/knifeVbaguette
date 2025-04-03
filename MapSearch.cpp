#include "MapSearch.h"
#include "stlastar.h"

bool MapSearch::GetSuccessors(AStarSearch<MapSearch>* astarsearch, MapSearch* parent) {
    /*Node *current = graph->getNode(x, y);
    if (!current) {     //no more nodes
        return false;
    }
    //generating successor for each adjacent node
    for (const auto &neighbourMap: current->neighbours) {
        Node *current = graph->getNode(x, y);
        if (!current)
            return false;
        //iterating  neighbours
        for (const auto &entry: current->neighbours) {
            Node *neighbour = entry.first;
            MapSearch newNode(neighbour->getX(), neighbour->getY(), graph);
            astarsearch->AddSuccessor(newNode);
        }
    }
    return true;*/

    int parentX = -1;
    int parentY = -1;
    if (parent) {
        parentX = parent->GetX();
        parentY = parent->GetY();
    }
    MapSearch newNode;
    if (graph->isWalkable(x-1, y) && !(x-1 == parentX && y == parentY)) {
        newNode = MapSearch(x-1, y, graph);
        astarsearch->AddSuccessor(newNode);
        std::cout << "Added successor: (" << x-1 << ", " << y << ")" << std::endl;
    }
    if (graph->isWalkable(x+1, y) && !(x+1 == parentX && y == parentY)) {
        newNode = MapSearch(x+1, y, graph);
        astarsearch->AddSuccessor(newNode);
        std::cout << "Added successor: (" << x+1 << ", " << y << ")" << std::endl;
    }
    if (graph->isWalkable(x, y-1) && !(x == parentX && y-1 == parentY)) {
        newNode = MapSearch(x, y-1, graph);
        astarsearch->AddSuccessor(newNode);
        std::cout << "Added successor: (" << x << ", " << y-1 << ")" << std::endl;
    }
    if (graph->isWalkable(x, y+1) && !(x == parentX && y+1 == parentY)) {
        newNode = MapSearch(x, y+1, graph);
        astarsearch->AddSuccessor(newNode);
        std::cout << "Added successor: (" << x << ", " << y+1 << ")" << std::endl;
    }
    return true;
}

