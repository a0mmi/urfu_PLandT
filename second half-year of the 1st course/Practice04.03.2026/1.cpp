#include <iostream>
#include <fstream>
#include <exception>
#include "Include/matrix.hpp"

using namespace std;

int main() {
    ifstream fin("input.txt");
    double eps = 1e-9;

    matrix A, B;
    while (fin >> A >> B) {
        bool ans = false;
        try {
            // проверяю квадратность и соответствие размеров
            if (A.getRows() == A.getCols() && B.getRows() == B.getCols() &&
                A.getRows() == B.getRows()) {
                matrix AB = A * B;
                matrix BA = B * A;
                if (AB.isIdentity(eps) && BA.isIdentity(eps)) ans = true;
            }
        } catch (const std::exception& ) { // Если будет вдруг ошибка
            ans = false;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}