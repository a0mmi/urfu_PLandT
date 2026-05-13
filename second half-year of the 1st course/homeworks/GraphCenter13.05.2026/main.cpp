// Я ленивая жопа и не хочу писать многофайловик
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
 
int main() {
    int n;
    cin >> n;
 
    int** dist = new int*[n];
    for (int i = 0; i < n; i++)
        dist[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (i == j) dist[i][j] = 0;
            else if (a == 1) dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }
 
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
 
    int* ecc = new int[n];
    int radius = INF;
 
    for (int i = 0; i < n; i++) {
        ecc[i] = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] > ecc[i])
                ecc[i] = dist[i][j];
        if (ecc[i] < radius)
            radius = ecc[i];
    }
 
    cout << "Center: { ";
    for (int i = 0; i < n; i++)
        if (ecc[i] == radius)
            cout << i + 1 << " ";
    cout << "}" << endl;
 
    for (int i = 0; i < n; i++)
        delete[] dist[i];
    delete[] dist;
    delete[] ecc;
 
    return 0;
}
 