#include "Include/graph.hpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    graph g;
    cout << g.countIsolatedVertices(n, matrix) << '\n';

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}