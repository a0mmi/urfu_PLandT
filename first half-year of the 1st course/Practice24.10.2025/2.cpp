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

int main () {
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5};
    forn (i, 0, n - 1) {
        if (a[i] > a[i + 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}