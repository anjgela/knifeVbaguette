#include "Node.h"

Node::Node(int id) : ID(id), x(0), y(0) {
    setCost();
}
Node::Node(int id, int x, int y) : ID(id), x(x), y(y) {
    setCost();
}

void Node::setCost() {
    if (ID == TILE) {
        cost = 1.0f;
    }
    else if (ID == OBSTACLE) {
        cost = 5.0f;
    }
}

int Node::getID() {
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
