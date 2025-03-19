#include <vector>
#include <unordered_map>

#ifndef LABPRO_GRAPH_H
#define LABPRO_GRAPH_H

#include "Node.h"

class Graph {
public:
    Graph(int width, int height);
    virtual ~Graph();

    int getWidth() const;
    int getHeight() const;

    Node* getNode(int x, int y) const;
    Node* getLeft(Node* node) const;
    Node* getRight(Node* node) const;
    Node* getTop(Node* node) const;
    Node* getDown(Node* node) const;


private:
    int width;
    int height;
    std::vector<Node*> nodes;
};


#endif //LABPRO_GRAPH_H
