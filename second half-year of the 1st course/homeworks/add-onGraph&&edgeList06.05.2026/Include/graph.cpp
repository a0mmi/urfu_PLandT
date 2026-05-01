#include "graph.hpp"
#include <bits/stdc++.h>

using namespace std;

graph::graph(int hashSize) {
    table.init(hashSize);
}

graph::~graph() {
}

long long graph::encodeEdge(int u, int v) {
    if (u > v) swap(u, v);
    return (((long long)u) << 32) | (unsigned int)v;
}

void graph::buildEdgeList(int n, int* degree, int** adj) {
    table.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < degree[i]; j++) {
            int u = i;
            int v = adj[i][j];

            if (u > v) swap(u, v);

            long long key = encodeEdge(u, v);
            if (!table.find(key)) {
                table.add(key, 1);
            }
        }
    }
}

void graph::showEdgeList() {
    int m = 0;
    Node* curr = table.first();

    while (curr != nullptr) {
        m++;
        curr = curr->nextAll;
    }

    cout << m << '\n';

    curr = table.first();
    while (curr != nullptr) {
        int u = (int)(curr->key >> 32);
        int v = (int)(curr->key & 0xffffffff);
        cout << u << " " << v << '\n';
        curr = curr->nextAll;
    }
}

int graph::countIsolatedVertices(int n, int** matrix) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        bool isolated = true;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                isolated = false;
                break;
            }
        }

        if (isolated) ans++;
    }

    return ans;
}