#include <bits/stdc++.h>
#include <windows.h>
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

    SetConsoleOutputCP(CP_UTF8);

    int n;
    cin >> n;
    ll *x = new ll[n];
    ll *y = new ll[n];
    forn (i, 0, n) cin >> x[i] >> y[i];

    ld bestAngle = 0.0L;
    int bi = -1, bj = -1, bk = -1;

    forn (i, 0, n) {
        forn (j, i + 1, n) {
            forn (k, j + 1, n) {
                if ((x[i] == x[j] && y[i] == y[j]) || (x[i] == x[k] && y[i] == y[k]) || (x[j] == x[k] && y[j] == y[k])) 
                    continue;
                ll area2 = (x[j]-x[i])*(y[k]-y[i]) - (y[j]-y[i])*(x[k]-x[i]);
                if (area2 == 0) continue;

                ld dij = (ld)(x[i] - x[j])*(x[i] - x[j]) + (ld)(y[i] - y[j]) * (y[i] - y[j]);
                ld djk = (ld)(x[j] - x[k])*(x[j] - x[k]) + (ld)(y[j] - y[k]) * (y[j] - y[k]);
                ld dik = (ld)(x[i] - x[k])*(x[i] - x[k]) + (ld)(y[i] - y[k]) * (y[i] - y[k]);

                ld L2, s1, s2;
                
                if (dij >= djk && dij >= dik) {
                    L2 = dij; s1 = dik; s2 = djk;
                } else if (djk >= dij && djk >= dik) {
                    L2 = djk; s1 = dij; s2 = dik;
                } else {
                    L2 = dik; s1 = dij; s2 = djk;
                }
                if (s1 <= 0 || s2 <= 0) continue;
                
                ld denom = 2.0L * sqrtl(s1) * sqrtl(s2);
                if (denom == 0) continue;
                ld cosv = (s1 + s2 - L2) / denom;
                if (cosv > 1.0L) cosv = 1.0L;
                if (cosv < -1.0L) cosv = -1.0L;
                ld ang = acosl(cosv);
                
                if (ang > (M_PI / 2.0L) && ang > bestAngle) {
                    bestAngle = ang;
                    bi = i; bj = j; bk = k;
                }
            }
        }
    }

    if (bi == -1) {
        cout << "Тупого треугольника не найдено\n";
    } else {
        ld deg = bestAngle * 180.0L / M_PI;
        cout << "Наибольший тупой угол = " << deg << " градусов\n";
        cout << "Координаты:\n";
        cout << "(" << x[bi] << ", " << y[bi] << ")\n";
        cout << "(" << x[bj] << ", " << y[bj] << ")\n";
        cout << "(" << x[bk] << ", " << y[bk] << ")\n";
    }

    delete[] x; delete[] y;
    return 0;
}
