#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << '\n';
}

// Объединение (отсртированное, уникальные)
vector<int> union_sorted(vector<int>& a, vector<int>& b) {
    set<int> s(a.begin(), a.end());
    s.insert(b.begin(), b.end());
    return vector<int>(s.begin(), s.end());
}

// Пересечение (отсортированное, уникальные)
vector<int> intersection_sorted(vector<int>& a, vector<int>& b) {
    set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());
    vector<int> res;
    for (const auto& x : sa) {
        if (sb.count(x)) res.push_back(x);
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 2};
    vector<int> B = {4, 5, 6, 1, 7, 4};

    cout << "A: "; printVec(A);
    cout << "B: "; printVec(B);
    cout << '\n';

    auto u2 = union_sorted(A, B);
    cout << "Union (sorted unique): "; printVec(u2);

    auto i2 = intersection_sorted(A, B);
    cout << "Intersection (sorted unique): "; printVec(i2);

    return 0;
}