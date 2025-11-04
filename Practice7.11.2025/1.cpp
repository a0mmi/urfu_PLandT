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

struct pis {
    int num;
    string ch;
};

string arabicToRoman(const int* digits, int n) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num = num * 10 + digits[i];
    }
    
    if (num <= 0 || num > 3999) {
        return "";
    }

    const int mapSize = 13;
    const pis romanMap[mapSize] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result;
    for (int i = 0; i < mapSize; ++i) {
        while (num >= romanMap[i].num) {
            result += romanMap[i].ch;
            num -= romanMap[i].num;
        }
    }
    return result;
}

int main() {
    const int n = 2;
    const int arr[n] = {1, 0};

    string res = arabicToRoman(arr, n);
    cout << "res: " << res << endl;
    return 0;
}