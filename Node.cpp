#include "Node.h"

Node::Node(NodeType id) : ID(id), x(0), y(0) {
    setCost();
    shape.setSize(sf::Vector2f(50.f, 50.f));
}
Node::Node(NodeType id, int x, int y) : ID(id), x(x), y(y) {
    setCost();
}

void Node::setCost() {
    if (ID == TILE) {
        cost = 1.f;
    }
    else if (ID == OBSTACLE) {
        cost = 100.f;
    }
}

void Node::setID(NodeType id) {
    ID = id;
}

NodeType Node::getID() const {
    return ID;
}
int Node::getX() const {
    return x;
}
int Node::getY() const {
    return y;
}
float Node::getCost() const {
    return cost;
}

sf::RectangleShape Node::getShape() const {
    return shape;
}
