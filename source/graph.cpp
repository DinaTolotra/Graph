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

void Graph::setUndirectedEdge(int a, int b, int weight) {
    m.at(a, b) = weight;
    m.at(b, a) = weight;
}

void Graph::print() {
    m.print();
}
