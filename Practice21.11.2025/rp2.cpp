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
using ld = long double;
using db = double;
using vdb = vector<double>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll *a = new long long[n];
    forn (i, 0, n) cin >> a[i];

    int m;
    cin >> m;
    ll *b = new ll[m];
    forn (i, 0, m) cin >> b[i];
    
    int j = 0;
    forn (i, 0, n && j < m)
        if(a[i] == b[j]) ++j;
    cout << (j == m ? "YES\n" : "NO\n");
    delete[] a;
    delete[] b;
    return 0;
}
