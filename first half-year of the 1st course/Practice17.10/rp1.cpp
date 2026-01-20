#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int x;
    cin >> x;

    int p = 0, cn = 0;
    while (n > 0) {
        p += exp(n * log(x)) * a[cn];
        cn++; n--;
    }
    cout << p;
}   