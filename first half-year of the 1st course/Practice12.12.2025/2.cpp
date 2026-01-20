#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int maxv(int *a, int n) {
    int c = -INT_MAX;
    forn(i, n) c = max(c, a[i]);
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;

    int *r = new int[n];
    int *c = new int[m];
    forn(i, m) c[i] = INT_MAX;


    int **T = new int*[n];
    forn(i, n) T[i] = new int[m];

    forn(i, n) {
        forn(j, m){
            cin >> T[i][j];
        }
        r[i] = maxv(T[i], m);
    }

    forn(j, m) {
        forn(i, n) {
            if (T[i][j] < c[j]) {
                c[j] = T[i][j];
            }
        }
    }

    bool f = false;
    forn(i, n) {
        forn(j, m) {
            if (T[i][j] == r[i] && T[i][j] == c[j]) {
                cout << i << " " << j << endl;
                f = true;
            }
        }
    }

    forn(i, n) delete[] T[i];
    delete[] r;
    delete[] c;

    return 0;
}

// 3 4
// 4 1 4 2
// 3 4 4 5
// 4 2 4 1

// 0 2
// 2 2


// 3 3
// 7 5 6
// 4 3 2
// 8 9 1

// 0 1