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

int main(){
    int N;
    double X, Y;
    cin >> N >> X >> Y;

    if(Y >= X + 0.05){
        return 0;
    }
    if(Y < 1){
        return -1;
    }

    function<db(int)> rec = [&](int k) -> db{
        db avg = (N * (X + 0.05) + k) / (N + k);
        if(avg <= Y){
            return k;
        }
        return rec(k + 1);
    };

    cout << rec(0);
    return 0;
}