#include <iostream>
#include <vector>

#include "include/graph.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Graph g(5);

    g.setEdge(4, 2);
    g.print();

    return 0;
}