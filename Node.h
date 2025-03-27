#ifndef LABPRO_NODE_H
#define LABPRO_NODE_H

#include <unordered_map>
#include <SFML/Graphics.hpp>

enum {TILE, OBSTACLE};

class Node {
public:
    Node(int id);
    Node(int id, int x, int y);

    void setCost();

    unsigned int getID();
    int getX();
    int getY();
    float getCost();
    sf::RectangleShape getShape() const;

    std::unordered_map<Node*, float> neighbours; //adjacency list for neighbours paired with the cost of the edge to reach them
private:
    unsigned int ID;
    int x;
    int y;
    float cost; //calculated by A* algorithm (f=g+h)

    sf::RectangleShape shape;

};


#endif //LABPRO_NODE_H
