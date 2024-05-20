#include "graph.hpp"

Graph::Graph():
    m(0),
    nodeCount(0)
{}

Graph::Graph(int nCount):
    m(nCount),
    nodeCount(nCount)
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
    this->nodeCount = other.nodeCount;

    return *this;
}

void Graph::setEdge(int src, int dst, int weight) {
    if (src < 0 || src >= nodeCount) 
        throw std::out_of_range("invalid index");
    
    if (dst < 0 || dst >= nodeCount) 
        throw std::out_of_range("invalid index");

    m.at(dst, src) = weight;
}

void Graph::removeEdge(int src, int dst) {
    if (src < 0 || src >= nodeCount) 
        throw std::out_of_range("invalid index");
    
    if (dst < 0 || dst >= nodeCount) 
        throw std::out_of_range("invalid index");

    m.at(dst, src) = 0;
}

vector<int> Graph::getAdjacentNode(int node) const {
    if (node < 0 || node >= nodeCount) 
        throw std::out_of_range("invalid index");

    vector<int> adjNode;
    vector<int> nextNode = getNextNode(node);
    vector<int> previousNode = getPreviousnode(node);

    for (int i=0; i < nodeCount; i++) {
        if (i == node)
            continue;
        
        if (nextNode.at(i) || previousNode.at(i))
            adjNode.push_back(i);
    }

    return adjNode;
}

vector<int> Graph::getNonAdjacentNode(int node) const {
    if (node < 0 || node >= nodeCount) 
        throw std::out_of_range("invalid index");

    vector<int> nonAdjNode;
    vector<int> nextNode = getNextNode(node);
    vector<int> previousNode = getPreviousnode(node);

    for (int i=0; i<nodeCount; i++) {
        if (i == node)
            continue;
        
        if (!nextNode.at(i) && !previousNode.at(i))
            nonAdjNode.push_back(i);
    }

    return nonAdjNode;
}

vector<int> Graph::getNextNode(int node) const {
    if (node < 0 || node >= nodeCount) 
        throw std::out_of_range("invalid index");
    
    vector<int> nextNode;

    for (int i=0; i<nodeCount; i++) {
        if (i == node)
            continue;
        
        if (m.at(i, node))
            nextNode.push_back(i);
    }

    return nextNode;
}

vector<int> Graph::getPreviousnode(int node) const {
    if (node < 0 || node >= nodeCount) 
        throw std::out_of_range("invalid index");
    
    vector<int> previousNode;

    for (int i=0; i<nodeCount; i++) {
        if (i == node)
            continue;
        
        if (m.at(node, i))
            previousNode.push_back(i);
    }

    return previousNode;
}

int Graph::getWeight(int src, int dst) {
    return m.at(dst, src);
}

int Graph::getNodeCount() {
    return nodeCount;
}

void Graph::print() {
    m.print();
}
