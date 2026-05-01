#include "Include/graph.hpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* degree = new int[n];
    int** adj = new int*[n];

    for (int i = 0; i < n; i++) {
        cin >> degree[i];
        adj[i] = new int[degree[i]];
        for (int j = 0; j < degree[i]; j++) {
            cin >> adj[i][j];
        }
    }

    graph g;
    g.buildEdgeList(n, degree, adj);
    g.showEdgeList();

    for (int i = 0; i < n; i++) {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] degree;

    return 0;
}