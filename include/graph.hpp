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

    v<int> getAdjacentNode(int node) const;
    v<int> getNonAdjacentNode(int node) const;

    v<int> getNextNode(int node) const;
    v<int> getPreviousnode(int node) const;

    void print();
};