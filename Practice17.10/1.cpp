#include<bits/stdc++.h>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vi rem(10, 0);
    for(char ch : s) {
        int d = ch - '0';
        for(int k = 1; k <= 9; ++k) {
            rem[k] = (rem[k] * 10 + d) % k;
        }
    }

    bool ok = false;
    for(char ch : s) {
        int d = ch - '0';
        if(d == 0) continue;
        if(rem[d] == 0) { ok = true; break; }
    }

    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}
