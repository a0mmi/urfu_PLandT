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
using vdb = vector<db>;
using bl = bool;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll m = n;
    bl ok = false;
    while (m > 0 ) {
        int d = m % 10;
        m /= 10;
        if (d != 0 && n % d == 0) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}