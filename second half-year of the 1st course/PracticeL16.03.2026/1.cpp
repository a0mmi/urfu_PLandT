#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    uint64_t* sieve = new uint64_t[n >> 6 + 1];
    for (int i = 0; i < n >> 6 + 1; i++) {
        sieve[i] = 0;
    }

    auto get = [&](int x)->bool {
        int idx = x >> 6;
        int bit = x & 63;
        return (sieve[idx] & (1ULL << bit)) != 0;
    };

    auto set_bit = [&](int x) {
        int idx = x >> 6;
        int bit = x & 63;
        sieve[idx] |= (1ULL << bit);
    };

    for (int i = 2; (long long)i * i <= n; ++i) {
        if (!get(i)) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                set_bit((int)j);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!get(i)) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}