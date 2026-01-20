#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;

Matrix<int> generatePattern(int n) {
    if (n <= 1) return Matrix<int>(0,0);
    int sz = n - 1;
    Matrix<int> M(sz, sz);
    int mod = sz;
    forn(i, 0, sz) {
        forn(j, 0, sz) {
            M[i][j] = ((j - i + mod) % mod) + 1; // ((j + i) % m) + 1 - влево, если желание есть (k = (j − i) % m)
        }
    }
    return M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Matrix<int> pattern = generatePattern(n);
    
    pattern.print();
    cout << '\n';
    return 0;
}