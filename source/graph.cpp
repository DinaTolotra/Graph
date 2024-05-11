#include "graph.hpp"

Graph::Graph():
    m(0)
{}

Graph::Graph(int nCount):
    m(nCount)
{
    m.fill(0);
}

Graph::Graph(const Graph &other) {
    *this = other;
}

Graph::~Graph() {}

Graph Graph::operator=(const Graph &other) {
    if (this == &other)
        return *this;

    this->m = other.m;

    return *this;
}

void Graph::setEdge(int src, int dst, int weight) {
    m.at(dst, src) = weight;
}

void Graph::removeEdge(int src, int dst) {
    m.at(dst, src) = 0;
}

v<int> Graph::getAdjacentNode(int node) const {
    v<int> adjNode;

    for (int i=0; i < m.getWidth(); i++) {
        if (i == node)
            continue;
        
        if (m.at(i, node))
            adjNode.push_back(i);
    }

    return adjNode;
}

v<int> Graph::getNonAdjacentNode(int node) const {
    v<int> nonAdjNode;

    for (int i=0; i<m.getWidth(); i++) {
        if (i == node)
            continue;
        
        if (!m.at(i, node))
            nonAdjNode.push_back(i);
    }

    return nonAdjNode;
}

void Graph::print() {
    m.print();
}
