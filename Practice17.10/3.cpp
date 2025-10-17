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

int main() {
    int f1 = 1, f2 = 1, n;
    cin >> n;
    string s = "11";

    while (s.size() < n) {
        int f3 = f1 + f2;
        s += to_string(f3);
        f1 = f2;
        f2 = f3;
    }
    cout << s[n - 1] << '\n';
    return 0;
}