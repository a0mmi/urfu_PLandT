#include "Include/Graph.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "input.txt error" << endl;
        return 1;
    }

    int n, m;
    in >> n >> m;
    
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        in >> from >> to;
        g.addEdge(from, to);
    }
    
    in.close();

    cout << "adjacency lists:" << endl;
    g.print(cout);
    
    EdgeList* edges = g.getEdgeList();
    cout << endl << "List of edges:" << endl;
    if (edges->empty()) {
        cout << "(The graph has no edges)" << endl;
    } else {
        edges->print(cout);
    }
    
    delete edges;
    return 0;
}