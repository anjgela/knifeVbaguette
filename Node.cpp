#include "Node.h"

Node::Node(int id) : ID(id), x(0), y(0) {
    setCost();
    shape.setSize(sf::Vector2f(50.f, 50.f));
}
Node::Node(int id, int x, int y) : ID(id), x(x), y(y) {
    setCost();
}

void Node::setCost() {
    if (ID == TILE) {
        cost = 1.0f;
    }
    else if (ID == OBSTACLE) {
        cost = 25.0f;
    }
}

unsigned int Node::getID() {
    return ID;
}
int Node::getX() {
    return x;
}
int Node::getY() {
    return y;
}
float Node::getCost() {
    return cost;
}

sf::RectangleShape Node::getShape() const {
    return shape;
}
