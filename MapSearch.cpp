#include "MapSearch.h"
#include "stlastar.h"

float MapSearch::GoalDistanceEstimate(const MapSearch &nodeGoal) const {
    return static_cast<float>( abs(x - nodeGoal.x) + abs(y - nodeGoal.y) );
}

bool MapSearch::IsGoal(MapSearch &nodeGoal) {
    return (x==nodeGoal.x and y==nodeGoal.y);
}

float MapSearch::GetCost(const MapSearch &successor) const {
    return graph->getNode(successor.getX(), successor.getY())->getCost();
}

bool MapSearch::IsSameState (const MapSearch &node) const {
    return (x == node.x && y == node.y);
}

bool MapSearch::getSuccessors(AStarSearch<MapSearch>* astarsearch, MapSearch* parent) {
    int parentX = -1;
    int parentY = -1;
    if (parent) {
        parentX = parent->getX();
        parentY = parent->getY();
    }
    MapSearch newNode;
    if (graph->isWalkable(x-1, y) && !(x-1 == parentX && y == parentY)) {
        newNode = MapSearch(x-1, y, graph);
        astarsearch->AddSuccessor(newNode);
    }
    if (graph->isWalkable(x+1, y) && !(x+1 == parentX && y == parentY)) {
        newNode = MapSearch(x+1, y, graph);
        astarsearch->AddSuccessor(newNode);
    }
    if (graph->isWalkable(x, y-1) && !(x == parentX && y-1 == parentY)) {
        newNode = MapSearch(x, y-1, graph);
        astarsearch->AddSuccessor(newNode);
    }
    if (graph->isWalkable(x, y+1) && !(x == parentX && y+1 == parentY)) {
        newNode = MapSearch(x, y+1, graph);
        astarsearch->AddSuccessor(newNode);
    }
    return true;
}

size_t MapSearch::hash() const {   //unique value based on x, y
    return static_cast<size_t>(x + y * graph->getWidth());
}

int MapSearch::getX() const {
    return x;
}

int MapSearch::getY() const {
    return y;
}