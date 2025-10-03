#include <bits/stdc++.h>
using namespace std;

#define forn(i, l, r) for(int i = l; i < r; ++i)
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using db = double;
using vdb = vector<double>;

#include <iostream>
using namespace std;

bool islp(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, m, y;
    cin >> d >> m >> y;
    int dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m > 2 && islp(y)) {
        dim[1] = 29;
    }
    
    int ttl = 0;
    for (int i = 0; i < m - 1; i++) {
        ttl += dim[i];
    }
    ttl += d - 1;
    cout << ttl;
    return 0;
}