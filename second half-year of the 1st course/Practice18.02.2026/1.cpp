#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    int *ns = new int[k];
    for (int i = 0; i < k; ++i) cin >> ns[i];

    ofstream out("out.txt");

    for (int t = 0; t < k; ++t) {
        int n = ns[t];

        int **matrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; ++j) matrix[i][j] = 0;
        }

        int i = 0, j = n / 2;
        for (int num = 1; num <= n * n; ++num) {
            matrix[i][j] = num;
            int ni = (i - 1 + n) % n;
            int nj = (j + 1) % n;
            if (matrix[ni][nj] != 0) { ni = (i + 1) % n; nj = j; }
            i = ni; j = nj;
        }

        out << "n = " << n << "\n";
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                out << matrix[r][c] << " ";
            out << "\n";
        }
        out << "\n";

        for (int r = 0; r < n; ++r) delete[] matrix[r];
        delete[] matrix;
    }

    delete[] ns;
    out.close();
    return 0;
}
