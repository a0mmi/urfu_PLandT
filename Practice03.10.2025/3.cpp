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
    int h,m;
    cin >> h >> m;
    db hour = (h % 12) * 30.0 + m * 0.5;
    db minute = m * 6;
    db angle = minute - hour;
    while(angle < 0) angle += 360;
    while(angle >= 360) angle -= 360;
    cout << angle;
}
