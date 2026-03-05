#include <iostream>
#include "Include/matrix.hpp"

using namespace std;

struct pairbd {
    bool ok;
    double* sol;
};

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

pairbd solveCramer(const matrix& A, const matrix& B, double eps = 1e-12) {
    pairbd res;
    res.ok = false;
    res.sol = nullptr;

    int n = A.getRows();
    if (n != A.getCols()) return res;
    if (B.getRows() != n || B.getCols() != 1) return res;

    double detA = A.determinant(eps);
    if (fabs(detA) <= eps) return res;

    double* sol = new double[n];
    for (int col = 0; col < n; ++col) {
        matrix C = A; // copy
        for (int i = 0; i < n; ++i) C(i, col) = B(i, 0);
        double detC = C.determinant(eps);
        sol[col] = detC / detA;
    }
    res.ok = true;
    res.sol = sol;
    return res;
}

int main() {
    int n;
    cin >> n;
    double* augmented = new double[n * (n + 1)];
    for (int i = 0; i < n * (n + 1); ++i) cin >> augmented[i];

    matrix A, B;
    buildMatricesFromAugmented(n, augmented, A, B);

    pairbd r = solveCramer(A, B);
    if (!r.ok) {
        cout << "No unique solution\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << r.sol[i];
        }
        cout << '\n';
        delete[] r.sol;
    }

    delete[] augmented;
    return 0;
}