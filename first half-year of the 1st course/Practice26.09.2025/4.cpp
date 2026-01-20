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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    db a, R;
    cin >> a >> R;

    const db PI = acos(-1.0);
    db h = a / 2.0;
    db r = a / sqrt(2.0);
    db S;

    if (R <= h) {
        S = PI * R * R;
    } else if (R >= r) {
        S = a * a;
    } else {
        db x0 = sqrt(R * R - h * h);
        S = 4 * h * x0 + 4 * R * R * asin(h / R) - PI * R * R;
    }

    cout << S;
    return 0;
}