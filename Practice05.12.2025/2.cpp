#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ull = unsigned long long;
using ll = long long;

string dton(ull n, int p, const string &alph = "0123456789ABCDEF") {
    if (n < (ull)p) return string(1, alph[n]);
    return dton(n / p, p, alph) + alph[n % p];
}

int main() {
    int n, p;
    cin >> n >> p;

    cout << dton(n, p);
}