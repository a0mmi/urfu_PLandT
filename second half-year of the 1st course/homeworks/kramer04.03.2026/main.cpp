#include <iostream>
#include "Include/matrix.hpp"

#define f first
#define s second

using namespace std;

void buildMatricesFromAugmented(int n, const double* augmented, matrix& A, matrix& B) {
    if (n < 0) throw invalid_argument("buildMatricesFromAugmented: n < 0");
    A = matrix(n, n);
    B = matrix(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A(i, j) = augmented[i * (n + 1) + j];
        }
        B(i, 0) = augmented[i * (n + 1) + n];
    }
}

int main() {
    int n;
    cin >> n;
    double* augmented = new double[n * (n + 1)];
    for (int i = 0; i < n * (n + 1); ++i) cin >> augmented[i];

    matrix A, B;
    buildMatricesFromAugmented(n, augmented, A, B);

    pair<bool, matrix> r = A.solve(B);
    if (!r.f) {
        cout << "No unique solution\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << r.s(i, 0);
        }
        cout << '\n';
        r.s = matrix(); // Очищаю матрицу заменяя на нулевую
    }

    delete[] augmented;
    return 0;
}