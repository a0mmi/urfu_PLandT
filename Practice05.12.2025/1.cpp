#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(const int *a, int i, int len) {
    if (i >= len - 1) return true;
    if (!(a[i] > a[i + 1])) return false;
    return check(a, i + 1, len);
}

int main() {
    ll n;
    cin >> n;

    string s = to_string(n);

    int len = (int)s.size();
    int *arr = new int[len];
    for (int i = 0; i < len; ++i) arr[i] = s[i] - '0';
    bool ans = check(arr, 0, len);
    cout << (ans ? "YES" : "NO") << '\n';
    delete[] arr;

    return 0;
}