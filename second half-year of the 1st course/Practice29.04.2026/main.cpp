#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Матрица смежности
    bool** adj = new bool*[n + 1];
    for (int i = 1; i <= n; ++i) { // Типа вообще нет рёбер
        adj[i] = new bool[n + 1];
        for (int j = 1; j <= n; ++j) {
            adj[i][j] = false;
        }
    }

    // список смежности
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int t = 0; t < k; ++t) {
            int v;
            cin >> v;
            if (v >= 1 && v <= n && v != i) {
                adj[i][v] = true;
                adj[v][i] = true; // раз граф то неорентированный
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (!adj[i][j]) { // петель нет && ребра нет -> в дополнении
                ++cnt;
            }
        }

        cout << cnt;
        for (int j = 1; j <= n; ++j) {
            if (!adj[i][j]) {
                cout << ' ' << j;
            }
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}