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
    string n;
    cin >> n;

    vi rem(10, 0);
    for (char ch : n) {
        rem[ch - '0']++;
    }
    for (int i = 9; i > 0; i--) {
        for (int j = 0; j < rem[i]; j++) {
            cout << i;
        }
    }
}