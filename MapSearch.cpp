#include "MapSearch.h"
#include "stlastar.h"

bool MapSearch::GetSuccessors(AStarSearch<MapSearch>* astarsearch, MapSearch* parent) {
    Node *current = graph->getNode(x, y);
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
    return true;
}

