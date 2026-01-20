#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;

int countZeroRows(const Matrix<double> &M, double eps = 1e-9) {
    int cnt = 0;
    forn(i, 0, M.r) {
        bool allZero = true;
        forn(j, 0, M.c) {
            if (fabs(M[i][j]) > eps) { allZero = false; break; }
        }
        if (allZero) ++cnt;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    Matrix<double> M(n, m);
    M.read();

    cout << countZeroRows(M) << '\n';
    return 0;
}