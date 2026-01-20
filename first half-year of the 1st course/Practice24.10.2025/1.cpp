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
    int a, b;
    cin >> a >> b;

    string res = "0.";
    ll r = a;
    map<ll, int> rempos;
    string fctl;

    while (r != 0) {
        if (rempos.find(r) != rempos.end()) {
            int pos = rempos[r];
            fctl = fctl.substr(0, pos) + "(" + fctl.substr(pos) + ")";
            cout << res << fctl << endl;
            return 0;
        }
        rempos[r] = fctl.size();
        r *= 10;
        int digit = r / b;
        r = r % b;
        fctl += ('0' + digit);
    }

    cout << res << fctl << endl;
    return 0;
}