#include <bits/stdc++.h>
#include "Include/HashTable.hpp"

using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    HashTable freqS;
    HashTable freqT;

    for (char c : s) freqS.insert(c);
    for (char c : t) freqT.insert(c);

    for (int i = 0; i < 128; ++i) {
        char ch = (char)i;
        if (freqS.getCount(ch) != freqT.getCount(ch)) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    if (isAnagram(s, t)) cout << 1 << endl;
    else cout << 0 << endl;
    
    return 0;
}
