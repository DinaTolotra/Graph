#include <iostream>
#include <vector>
#include <set>

#include "include/graph.hpp"

using namespace std;

void DFS(const Graph &g, int node, set<int> &visited);

int main(int argc, char const *argv[]) {
    int edgeCount;
    int startingNode;
    int verticeCount;

    cin >> verticeCount
        >> startingNode
        >> edgeCount;

    Graph g(verticeCount);

    for (int i=0; i<edgeCount; i++) {
        int src, dst;
        cin >> src >> dst;
        g.setEdge(src, dst);
    }

    set<int> s;
    DFS(g, startingNode, s);

    return 0;
}

void DFS(const Graph &g, int node, set<int> &visited) {
    visited.insert(node);
    cout << node <<  endl;

    for (int i: g.getNextNode(node)) {
        if (visited.find(i) != visited.end())
            continue;
        
        DFS(g, i, visited);
    }
}
