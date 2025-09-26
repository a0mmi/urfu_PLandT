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

int main() {
    db x11, y11, x21, y21;
    db x12, y12, x22, y22;
    cin >> x11 >> y11 >> x21 >> y21;
    cin >> x12 >> y12 >> x22 >> y22;

    db rect1X1 = min(x11, x21);
    db rect1X2 = max(x11, x21);
    db rect1Y1 = min(y11, y21);
    db rect1Y2 = max(y11, y21);

    db rect2X1 = min(x12, x22);
    db rect2X2 = max(x12, x22);
    db rect2Y1 = min(y12, y22);
    db rect2Y2 = max(y12, y22);

    db l = max(rect1X1, rect2X1);
    db r = min(rect1X2, rect2X2);
    db bt = max(rect1Y1, rect2Y1);
    db tp = min(rect1Y2, rect2Y2);

    bool hcmm = (l <= r) && (bt <= tp);
    db area = 0;
    if (hcmm) {
        area = (r - l) * (tp - bt);
    }
    cout << (hcmm ? "Yes" : "No") << endl;
    cout << area;
    return 0;
}

// left = left — max v l
// right = min v r
// bot = max v bt
// top = min v top