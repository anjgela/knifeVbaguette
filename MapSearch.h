//class to represent a position (x,y) on the map
#include <iostream>
#include "Graph.h"
#include "stlastar.h"
#include <cstdlib>  //abs
#include <unordered_map>

#ifndef LABPRO_MAPSEARCH_H
#define LABPRO_MAPSEARCH_H

class MapSearch {
public:
    MapSearch() : x(0), y(0), graph(nullptr) {}
    MapSearch(int x, int y, Graph* graph) : x(x), y(y), graph(graph) {}

    float GoalDistanceEstimate(const MapSearch &nodeGoal) const;
    size_t hash() const;

    bool IsGoal(MapSearch &nodeGoal);
    bool IsSameState(const MapSearch &node) const;

    int getX() const;
    int getY() const;
    float GetCost(const MapSearch &successor) const;
    bool getSuccessors(AStarSearch<MapSearch>* astarsearch, MapSearch* parent);

private:
    int x;
    int y;
    Graph* graph;

};


#endif //LABPRO_MAPSEARCH_H
