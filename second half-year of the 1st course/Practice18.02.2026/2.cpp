#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long **a = new long long*[n];
    for (int i = 0; i < n; ++i) a[i] = new long long[n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    long long target = 0;
    for (int j = 0; j < n; ++j) target += a[0][j];

    for (int i = 1; i < n; ++i) {
        long long s = 0;
        for (int j = 0; j < n; ++j) s += a[i][j]; // Строки
        if (s != target) {
            cout << "NO\n";
            for (int k = 0; k < n; ++k) delete[] a[k]; 
            delete[] a;
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        long long s = 0;
        for (int i = 0; i < n; ++i) s += a[i][j]; // столбцы
        if (s != target) {
            cout << "NO\n";
            for (int k = 0; k < n; ++k) delete[] a[k];
            delete[] a;
            return 0;
        }
    }

    long long d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) { d1 += a[i][i]; d2 += a[i][n - 1 - i]; } // Диагонали

    cout << ((d1 == target && d2 == target) ? "YES\n" : "NO\n");

    for (int i = 0; i < n; ++i) delete[] a[i];
    delete[] a;
    return 0;
}

// 3
// 8 1 6
// 3 5 7
// 4 9 2

// 5
// 17 24  1  8 15
// 23  5  7 14 16
//  4  6 13 20 22
// 10 12 19 21  3
// 11 18 25  2  9

// 4
// 16  2  3 13
//  5 11 10  8
//  9  7  6 12
//  4 14 15  1
