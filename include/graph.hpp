#pragma once

#include <iostream>
#include <vector>

#include "matrice.hpp"


class Graph {
private:
    Matrice m;
    int nodeCount;
    
public:
    Graph();
    Graph(int nCount);
    Graph(const Graph &other);
    ~Graph();

    Graph operator=(const Graph &other);

    void setEdge(int src, int dst, int weight=1);
    void removeEdge(int src, int dst);

    vector<int> getAdjacentNode(int node) const;
    vector<int> getNonAdjacentNode(int node) const;

    vector<int> getNextNode(int node) const;
    vector<int> getPreviousnode(int node) const;

    int getWeight(int src, int dst);
    int getNodeCount();

    void print();
};