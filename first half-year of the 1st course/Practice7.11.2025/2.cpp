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
using pis = pair<int, string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using db = double;
using vdb = vector<double>;
using vs = vector<string>;

bool isMirrorCopy(vi& arr1, vi& arr2) {
    if (arr1.size() != arr2.size()) {
        return false;
    }
    int n = arr1.size();
    for (int i = 0; i < n; ++i) {
        int j = n - 1 - i; 
        int num = arr2[j];

        int rvsrd = 0;
        int temp = num;
        while (temp != 0) {
            rvsrd = rvsrd * 10 + temp % 10;
            temp /= 10;
        }
        if (rvsrd != arr1[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vi a(n, 0), b(n, 0);
    forn (i, 0, n) cin >> a[i];
    forn (i, 0, n) cin >> b[i];

    cout << ((isMirrorCopy(a, b)) ? "YES" : "NO");
}