#ifndef LABPRO_GRAPH_H
#define LABPRO_GRAPH_H

#include <vector>
#include <unordered_map>
#include "Node.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>

class Graph {
public:
    Graph();
    virtual ~Graph();

    bool isWalkable(int x, int y) const;

    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);

    Node* getNode(int x, int y) const;
    Node* getLeft(Node* node) const;
    Node* getRight(Node* node) const;
    Node* getTop(Node* node) const;
    Node* getDown(Node* node) const;

    std::vector<Node*> getNodes() const;
    void display(sf::RenderWindow& window);


private:
    void generateRandomNodes();

private:
    int width;
    int height;
    std::vector<Node*> nodes;
    sf::VertexArray vertices;


};


#endif //LABPRO_GRAPH_H
