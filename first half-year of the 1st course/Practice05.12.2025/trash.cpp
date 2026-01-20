#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    int d;
    Node *next;
    Node(int _d): d(_d), next(nullptr) {}
};

struct DigitList {
    Node *first = nullptr;
    Node *last = nullptr;
    void push_back(int x) {
        Node *n = new Node(x);
        if (!first) first = last = n;
        else { last->next = n; last = n; }
    }
    bool check_rec(Node *cur) const {
        if (!cur || cur == last) return true;
        if (!(cur->d > cur->next->d)) return false;
        return check_rec(cur->next);
    }
};

int main() {
    ll n;
    cin >> n;

    string s = to_string(n);

    DigitList a;
    for (char c : s) a.push_back(c - '0'); 
    cout << (a.check_rec(a.first) ? "YES" : "NO") << '\n';
    return 0;
}