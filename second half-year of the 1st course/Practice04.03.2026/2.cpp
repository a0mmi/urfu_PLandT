// main.cpp
#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.hpp"

using namespace std;

int main() {
    ifstream fin("input.txt");

    double eps = 1e-9;
    matrix A;
    while (fin >> A) {
        bool ans = false;
        try {
            if (A.getRows() == A.getCols()) {
                ans = A.isOrthogonal(eps);
            } else {
                ans = false; // не квадратная -> не ортогональна
            }
        } catch (const exception&) {
            ans = false;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}