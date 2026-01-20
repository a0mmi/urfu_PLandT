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
using ull = unsigned long long;

const int MAX = 1e3 + 5;
const int INF = 1e9 + 7;

int main(){
    int tmp[MAX], a[MAX], b[MAX], sum[MAX];
    ll prod[MAX * 2];
    int n,m;
    cin >> n >> m;
    forn (i, 0, n + 1) cin >> tmp[i];
    forn (i, 0, n + 1) a[i] = tmp[n - i];
    forn (i, 0, m + 1) cin >> tmp[i];
    forn (i, 0, m + 1) b[i] = tmp[m - i];

    int s = (n > m ? n : m);
    forn (i, 0, s + 1){
        int va = (i <= n ? a[i] : 0);
        int vb = (i <= m ? b[i] : 0);
        sum[i] = va + vb;
    }
    while (s > 0 && sum[s] == 0) --s;
    cout << s;
    for (int i = s; i >= 0; i--) cout<<' '<<sum[i];
    cout << endl;

    int p = n + m;
    forn (i, 0, p + 1) prod[i] = 0;
    forn (i, 0, n + 1)
        forn (j, 0, m + 1)
            prod[i + j] += (ll)a[i] * (ll)b[j];

    while (p > 0 && prod[p] == 0) --p;
    cout << p;
    for (int i = p; i >= 0; i--) cout << ' ' << prod[i];
    cout << endl;
    return 0;
}
