#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> n >> k;

    vector<int> a;
    for (int i = 0; i < n; i++) {   
        cin >> a[i];
    }

    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}