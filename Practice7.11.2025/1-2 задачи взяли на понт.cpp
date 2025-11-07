#include <bits/stdc++.h>
#include "DynamicArray.h"
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

string arabicToRoman(const int* digits, size_t n) {
    int num = 0;
    for (size_t i = 0; i < n; ++i) {
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

bool isMirrorCopy(const int* arr1, const int* arr2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        size_t j = n - 1 - i;
        int num = arr2[j];

        int reversed = 0;
        int temp = num;
        while (temp != 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        if (reversed != arr1[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    {
        DynamicArray<int> arr;
        arr.push_back(1);
        arr.push_back(9);
        arr.push_back(9);
        arr.push_back(4);
        
        string res = arabicToRoman(arr.get_data(), arr.get_size());
        cout << "res: " << res << endl;
    }

    {
        DynamicArray<int> a;
        a.push_back(1);
        a.push_back(23);
        a.push_back(456);
        
        DynamicArray<int> b;
        b.push_back(654);
        b.push_back(32);
        b.push_back(1);
        
        cout << "res 1: " 
             << (isMirrorCopy(a.get_data(), b.get_data(), a.get_size()) ? "YES" : "NO") << endl; // YES

        DynamicArray<int> c;
        c.push_back(456);
        c.push_back(23);
        c.push_back(1);
        
        cout << "res 2: " 
             << (isMirrorCopy(a.get_data(), c.get_data(), a.get_size()) ? "YES" : "NO") << endl; // NO
    }
    return 0;
}