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

string addStr(const string &a, const string &b) {
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    string res;
    while(i >= 0 || j >= 0 || carry) {
        int da = (i >= 0 ? a[i] - '0' : 0);
        int dbt = (j >= 0 ? b[j] - '0' : 0);
        int sum = da + dbt + carry;
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
        --i; --j;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ll N;
    cin >> N;

    if(N == 0) {
        cout << '\n';
        return 0;
    }

    vs F;
    F.reserve(100000);
    F.push_back("1");
    F.push_back("1");

    ll cum = 0;
    
    forn(i, 0, F.size()) {
        cum += F[i].size();
        if(cum >= N) {
            ll prevCum = cum - F[i].size();
            ll pos = (ll)(N - prevCum - 1); 
            cout << F[i][pos] << '\n';
            return 0;
        }
    }

    ll idx = 2;
    while (cum < N) {
        string nxt = addStr(F[idx - 1], F[idx - 2]);
        F.push_back(nxt);
        cum += F[idx].size();
        if(cum >= N) {
            ll prevCum = cum - F[idx].size();
            int pos = (int)(N - prevCum - 1);
            cout << F[idx][pos] << '\n';
            return 0;
        }
        ++idx;
        
        if(F.size() > 2000000) { 
            cerr << "Большой член";
            return 0;
        }
    }
    return 0;
}
