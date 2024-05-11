#pragma once

#include <iostream>
#include <vector>

#include "matrice.hpp"


class Graph {
private:
    Matrice m;
    
public:
    Graph();
    Graph(int nCount);
    Graph(const Graph &other);
    ~Graph();

    Graph operator=(const Graph &other);

    void setEdge(int src, int dst, int weight = 1);
    void setUndirectedEdge(int a, int b, int weight = 1);

    void print();
};