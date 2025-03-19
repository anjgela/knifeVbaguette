#ifndef LABPRO_NODE_H
#define LABPRO_NODE_H

#include <unordered_map>

enum {TILE, OBSTACLE};

class Node {
public:
    Node(int id);
    Node(int id, int x, int y);

    void setCost();

    int getID();
    int getX();
    int getY();
    float getCost();

    std::unordered_map<Node*, float> neighbours; //adjacency list for neighbours paired with the cost of the edge to reach them
private:
    int ID;
    int x;
    int y;
    float cost; //calculated by A* algorithm (f=g+h)
    std::unordered_map<Node*, float> neighbours; //adjacency list for neighbours paired with the cost of the edge to reach them

};


#endif //LABPRO_NODE_H
