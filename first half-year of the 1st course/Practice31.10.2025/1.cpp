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

vi lgarithprog(vi& arr) {
    int n = arr.size();
    if (n == 0) return {};
    if (n == 1) return arr;
    
    int mxst = 0;
    int mxln = 2;
    int currst = 0;
    int currln = 2;
    int pdiff = arr[1] - arr[0];

    for (int i = 2; i < n; ++i) {
        int currdiff = arr[i] - arr[i - 1];
        if (currdiff == pdiff) {
            currln++;
        } else {
            currln = 2;
            currst = i - 1;
        }
        pdiff = currdiff;
        
        if (currln > mxln) {
            mxln = currln;
            mxst = currst;
        }
    }
    return vi(arr.begin() + mxst, arr.begin() + mxst + mxln);
}