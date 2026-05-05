#include "Include/Graph.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "input.txt error" << endl;
        return 1;
    }

    string line;
    getline(in, line);
    int n = stoi(line);

    Graph g(n);
    for (int i = 0; i < n; i++) {
        string line;
        getline(in, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            g.addEdge(i, neighbor);
        }
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