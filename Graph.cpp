//
// Created by Utente on 24/02/2025.
//

#include "Graph.h"

Graph::Graph(int width, int height) : width(width), height(height) {
    nodes.resize(width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int n = x + y * width;
            nodes[n] = new Node(TILE, x, y);    //FIXME: WHEN RANDOM PLACEMENT OF OBSTACLES: CHANGING COST OF NODES
        }
    }
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int n = x + y * width;
            if (x > 0) {  //left neighbour
                int left = (x - 1) + y * width;
                nodes[n]->neighbours[nodes[left]] = 1.0f;
            }
            if (x < width - 1) { //right neighbour
                int right = (x + 1) + y * width;
                nodes[n]->neighbours[nodes[right]] = 1.0f;
            }
            if (y > 0) { //up neighbour
                int up = x + (y - 1) * width;
                nodes[n]->neighbours[nodes[up]] = 1.0f;
            }
            if (y < height - 1) { //down neighbour
                int down = x + (y + 1) * width;
                nodes[n]->neighbours[nodes[down]] = 1.0f;
            }
        }
    }
}

Graph::~Graph() {
    for (Node* node : nodes) {
        delete node;
    }
}


int Graph::getWidth() const {
    return width;
}
int Graph::getHeight() const {
    return height;
}

Node* Graph::getNode(int x, int y) const{
    if (x<0 || x>=width || y<0 || y>=height) {
        return nullptr;
    }
    return nodes[x+y*width];
}
Node* Graph::getLeft(Node* node) const {
    if (node->getX() > 0) {
        int left = (node->getX() - 1) + node->getY() * width;
        auto it = node->neighbours.find(nodes[left]);
        if (it != node->neighbours.end()) {
            return it->first;
        }
    }
    return nullptr;
}
Node* Graph::getRight(Node* node) const {
    if (node->getX() < width) {
        int right = (node->getX() + 1) + node->getY() * width;
        auto it = node->neighbours.find(nodes[right]);
        if (it != node->neighbours.end()) {
            return it->first;
        }
    }
    return nullptr;
}
Node* Graph::getTop(Node* node) const {
    if (node->getY() > 0) {
        int top = node->getX() + (node->getY() - 1) * width;
        auto it = node->neighbours.find(nodes[top]);
        if (it != node->neighbours.end()) {
            return it->first;
        }
    }
    return nullptr;
}
Node* Graph::getDown(Node *node) const {
    if (node->getY() < height) {
        int down = node->getX() + (node->getY() + 1) * width;
        auto it = node->neighbours.find(nodes[down]);
        if (it != node->neighbours.end()) {
            return it->first;
        }
    }
    return nullptr;
}

