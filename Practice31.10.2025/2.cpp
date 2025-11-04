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
using vs = vector<string>;

const int MIN = -2147483647 - 1;

vi f(vi& arr) {
    int n = arr.size();
    if (n == 0) return {};
    if (n == 1) return {arr[0]};
    if (n == 2) {
        return (arr[0] > arr[1]) ? 
               vector<int>{arr[0], arr[1]} : 
               vector<int>{arr[1], arr[0]};
    }
    
    int fst = MIN, sec = MIN, thrd = MIN;
    
    for (int x : arr) {
        if (x > fst) {
            thrd = sec;
            sec = fst;
            fst = x;
        } else if (x > sec) {
            thrd = sec;
            sec = x;
        } else if (x > thrd) {
            thrd = x;
        }
    }
    
    vi res = {fst};
    if (n >= 2) res.pb(sec);
    if (n >= 3) res.pb(thrd);
    return res;
}