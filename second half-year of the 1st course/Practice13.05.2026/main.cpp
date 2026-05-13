#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    // Max possible edges in undirected graph n*(n-1)/2
    int max_edges = n * (n - 1) / 2;
    int* edge_u = new int[max_edges];
    int* edge_v = new int[max_edges];
    int m = 0;

    // Read adjacency lists, collect edges only once (i < j)
    for (int i = 1; i <= n; i++) {
        int j;
        while (fin >> j && j != 0) {
            if (j > i) {
                edge_u[m] = i;
                edge_v[m] = j;
                m++;
            }
        }
    }

    // Build incidence matrix n x m (zeroed out)
    int** inc = new int*[n];
    for (int i = 0; i < n; i++) {
        inc[i] = new int[m]();
    }

    for (int e = 0; e < m; e++) {
        inc[edge_u[e] - 1][e] = 1;
        inc[edge_v[e] - 1][e] = 1;
    }

    // Write n, m and incidence matrix to output file
    fout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << inc[i][j];
            if (j < m - 1) fout << " ";
        }
        fout << endl;
    }

    cout << "Done. Vertices: " << n << ", Edges: " << m << endl;

    // Cleanup
    for (int i = 0; i < n; i++)
        delete[] inc[i];
    delete[] inc;
    delete[] edge_u;
    delete[] edge_v;

    fin.close();
    fout.close();

    return 0;
}