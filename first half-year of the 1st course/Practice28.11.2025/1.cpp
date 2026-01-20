#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Matrix<ll> A(n, m), B(n, m);
    A.read(); 
    B.read();

    Matrix<ll> C = A + B;

    C.print();
    return 0;
}
