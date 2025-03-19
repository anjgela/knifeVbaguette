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

    float GoalDistanceEstimate(const MapSearch &nodeGoal) const {
        return static_cast<float>( abs(x - nodeGoal.x) + abs(y - nodeGoal.y) );
    }

    bool IsGoal(MapSearch &nodeGoal) {
        return (x==nodeGoal.x and y==nodeGoal.y);
    }

    bool GetSuccessors(AStarSearch<MapSearch>* astarsearch, MapSearch* parent); //FIXME: stlastar changed to AStarSearch

    float GetCost(const MapSearch &successor) const {
        return 1.0f;
    }

    bool IsSameState (const MapSearch &node) const {
        return (x == node.x && y == node.y);
    }

    void PrintNodeInfo() const {
        std::cout << "node (" << x << ", " << y << ")" << std::endl;
    }

    size_t Hash() const {   //unique value based on x, y
        return static_cast<size_t>(x + y * graph->getWidth());
    }
    int GetX() const {
        return x;
    }
    int GetY() const {
        return y;
    }
private:
    int x;
    int y;
    Graph* graph;

};


#endif //LABPRO_MAPSEARCH_H
