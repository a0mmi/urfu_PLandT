#include<bits/stdc++.h>
using namespace std;

#define forn(i, l, r) for(int i = l; i < r; ++i)

struct pisi {
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
    const pisi romanMap[mapSize] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string res;
    forn (i, 0, mapSize) {
        while (num >= romanMap[i].num) {
            res += romanMap[i].ch;
            num -= romanMap[i].num;
        }
    }
    return res;
}

int main() {
    const int n = 4;
    const int arr[n] = {3, 8, 8, 8};

    string res = arabicToRoman(arr, n);
    cout << "res: " << res << endl;
    return 0;
}