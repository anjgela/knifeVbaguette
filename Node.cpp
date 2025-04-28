#include "Node.h"

//public
Node::Node(NodeType id) : ID(id), x(0), y(0) {
    setCost();
    vertex = nullptr;
    shape.setSize(sf::Vector2f(50.f, 50.f));
    updateGraphics();
}
Node::Node(NodeType id, int x, int y, sf::Vertex* vertex) : ID(id), x(x), y(y), vertex(vertex) {
    setCost();
    updateGraphics();
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
    setCost();
    updateGraphics();
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

//private
void Node::updateGraphics() {
    if (vertex) {
        sf::Color color = (ID == TILE) ? sf::Color(181, 225, 245) : sf::Color(91, 91, 91);
        for (int i = 0; i < 4; ++i) {
            vertex[i].color = color;
        }
    }
}