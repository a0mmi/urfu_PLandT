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
    db N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    
    db result;
    if(N > B){
        result = N * (1 - Y / 100.0);
    } else if(N > A) {
        result = N * (1 - X / 100.0);
    } else {
        result = N;
    }
    
    cout << result;
    return 0;
}