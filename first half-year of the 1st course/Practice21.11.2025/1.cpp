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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int n = s.size(), i = 0, j = 0;
    while (i < n && s[i] == ' ') ++i;
    while (i < n) {
        if (s[i] != ' ') s[j++] = s[i++];
        else {
            while (i < n && s[i] == ' ') ++i;
            if (i < n) s[j++] = ' ';
        }
    }
    s.resize(j);
    cout << s;
    return 0;
}
