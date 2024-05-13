#include <iostream>
#include <vector>
#include <queue>
#include <set>

#include "include/graph.hpp"

using namespace std;

void rDFS(const Graph &g, int node, set<int> &visited);
void iBFS(const Graph &g, int startingNode);

void pushNexNode(const Graph &g, int node, queue<int> &q);
int pop(queue<int> &q);

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
    cout << "DFS: ";
    rDFS(g, startingNode, s);
    cout << "\nBFS: ";
    iBFS(g, startingNode);

    return 0;
}


void rDFS(const Graph &g, int node, set<int> &visited) {
    visited.insert(node);
    cout << node << ' ';

    for (int next: g.getNextNode(node)) {
        if (!visited.contains(next)) {
            rDFS(g, next, visited);
        }
    }
}


void iBFS(const Graph &g, int startingNode) {
    set<int> visited;
    queue<int> q;

    q.push(startingNode);

    while (!q.empty()) {
        int node = pop(q);

        if (!visited.contains(node)) {
            cout << node << ' ';
            visited.insert(node);

            pushNexNode(g, node, q);
        }
    }
}


void pushNexNode(const Graph &g, int node, queue<int> &q) {
    for (int next: g.getNextNode(node))
        q.push(next);
}


int pop(queue<int> &q) {
    int i = q.front();
    q.pop();
    return i;
}
