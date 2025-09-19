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

const db EPS = 1e-9;

int main(){
    db A, B, C;
    vdb roots;

    cin >> A >> B >> C;
    if(abs(A) > EPS){
        db D = B * B - 4 * A * C;
        if(D > EPS){
            db sqrtD = sqrt(D);
            db x1 = (-B + sqrtD) / (2 * A);
            db x2 = (-B - sqrtD) / (2 * A);
            roots.pb(x1);
            roots.pb(x2);
        } else if(abs(D) <= EPS){
            db x = -B / (2 * A);
            roots.pb(x);
        }
    } else if(abs(B) > EPS){
        db x = -C / B;
        roots.pb(x);
    }
    
    for (int i = 0; i < roots.size(); ++i){
        if(i > 0) cout << " ";
        cout << roots[i];
    }
    return 0;
}