#include "Graph.h"
#include <iostream>
Graph::Graph() {
    width = sf::VideoMode::getDesktopMode().width / 50;
    height = sf::VideoMode::getDesktopMode().height / 50;
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);
    std::srand(std::time(nullptr));
    generateRandomNodes();
}

void Graph::generateRandomNodes() {
    nodes.resize(width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int n = x + y * width;
            sf::Vertex* quad = &vertices[n*4]; //vertex associated with the node

            if (std::rand() % 100 < 15) {   //percentage of nodes which are obstacles
                nodes[n] = new Node(OBSTACLE, x, y, quad);
            } else {
                nodes[n] = new Node(TILE, x, y, quad);
            }

            //vertex array
            quad[0] = sf::Vector2f(x*50.f, y*50.f);
            quad[1] = sf::Vector2f((x+1)*50.f, y*50.f);
            quad[2] = sf::Vector2f((x+1)*50.f, (y+1)*50.f);
            quad[3] = sf::Vector2f(x*50.f, (y+1)*50.f);

            sf::Color color = (nodes[n]->getID() == TILE) ? sf::Color(181, 225, 245) : sf::Color(91,91,91);
            quad[0].color = color;
            quad[1].color = color;
            quad[2].color = color;
            quad[3].color = color;
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

bool Graph::isWalkable(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }
    Node* node = nodes[x + y * width];
    return node->getID() == TILE; // Check if the node is walkable
}

int Graph::getWidth() const {
    return width;
}
void Graph::setWidth(int width) {
    Graph::width = width;
}
int Graph::getHeight() const {
    return height;
}
void Graph::setHeight(int height) {
    Graph::height = height;
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

std::vector<Node*> Graph::getNodes() const {
    return nodes;
}

void Graph::display(sf::RenderWindow& window) {
    window.draw(vertices);
}