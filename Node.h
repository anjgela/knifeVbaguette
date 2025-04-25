#ifndef LABPRO_NODE_H
#define LABPRO_NODE_H

#include <unordered_map>
#include <SFML/Graphics.hpp>

enum NodeType {TILE, OBSTACLE};

class Node {
public:
    Node(NodeType id);
    Node(NodeType id, int x, int y, sf::Vertex* vertex = nullptr);
    void setCost();
    void setID(NodeType id);

    NodeType getID() const;
    int getX() const;
    int getY() const;
    float getCost() const;
    sf::RectangleShape getShape() const;
private:
    void updateGraphics();

public:
    std::unordered_map<Node*, float> neighbours; //adjacency list for neighbours paired with the cost of the edge to reach them
private:
    NodeType ID;
    int x;
    int y;
    float cost;
    sf::Vertex* vertex;

    sf::RectangleShape shape;

};


#endif //LABPRO_NODE_H
