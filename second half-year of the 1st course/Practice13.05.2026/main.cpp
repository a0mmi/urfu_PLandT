#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    // Максимальное число рёбер в неориентированном графе:
    // каждая вершина может соединяться с (n-1) другими -отсюдова-> n*(n-1) упорядоченных пар
    // но ребро (i,j) == (j,i), значит каждое посчитано дважды -> n*(n-1)/2
    int max_edges = n * (n - 1) / 2;
    // edge_u и edge_v - начало и конец каждого ребра
    int* edge_u = new int[max_edges];
    int* edge_v = new int[max_edges];
    int m = 0;

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

    // mat инциндентности вся в нулях
    int** inc = new int*[n];
    for (int i = 0; i < n; i++) {
        inc[i] = new int[m]();
    }

    for (int e = 0; e < m; e++) {
        inc[edge_u[e] - 1][e] = 1;
        inc[edge_v[e] - 1][e] = 1;
    }

    // inc в выходной
    fout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << inc[i][j];
            if (j < m - 1) fout << " ";
        }
        fout << endl;
    }

    cout << "Vertices: " << n << ", Edges: " << m << endl;

    for (int i = 0; i < n; i++)
        delete[] inc[i];
    delete[] inc;
    delete[] edge_u;
    delete[] edge_v;

    fin.close();
    fout.close();

    return 0;
}