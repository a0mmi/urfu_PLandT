#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

bool check(const int a) {
    if (a < 10) return true;
    if ((a % 100 / 10) <= (a % 10)) return false;
    return check(a / 10);
}

int main() {
    ull n;
    cin >> n;

    string s = to_string(n);

    int len = (int)s.size();
    bool ans = check(n);
    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}