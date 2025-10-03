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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    db x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    
    db dx = x2 - x1;
    db dy = y2 - y1;
    db lnsq = dx * dx + dy * dy;
    if (lnsq == 0) {
        db dist = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        cout << dist;
        return 0;
    }

    db t = ((x - x1) * dx + (y - y1) * dy) / lnsq;
    t = max(0.0, min(1.0, t));

    db x0 = x1 + t * dx;
    db y0 = y1 + t * dy;
    db dist = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
    cout << dist;
    return 0;
}