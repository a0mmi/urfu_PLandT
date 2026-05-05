#include "Include/Graph.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "input.txt error" << endl;
        return 1;
    }

    int n;
    in >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n]();
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }
    
    in.close();

    Graph g(n);
    g.loadFromMatrix(matrix, n);
    
    cout << "Adjacency matrix:" << endl;
    cout << "     ";
    for (int j = 0; j < n; j++) {
        cout << j << "  ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i << " [ ";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << "]" << endl;
    }
    
    cout << endl << "Adjacency lists (after loading from matrix):" << endl;
    g.print(cout);
    
    int result = g.countIsolated();
    cout << endl << "Number of isolated vertices: " << result << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}