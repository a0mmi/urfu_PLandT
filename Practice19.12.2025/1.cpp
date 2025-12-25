// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ifstream in("matrices.txt");
//     if (!in) { cerr << "! matrices.txt\n"; return 1; }
//     ofstream out("matrix_results.txt");
//     if (!out) { cerr << "! matrix_results.txt\n"; return 1; }

//     int n;
//     while (in >> n) {
//         if (n <= 0) continue;

//         size_t total = (size_t)n * (size_t)n;
//         int *mat = new (nothrow) int[total];

//         bool ok = true;
//         for (size_t i = 0; i < total; ++i) {
//             if (!(in >> mat[i])) { ok = false; break; }
//         }
//         if (!ok) { delete[] mat; break; }

//         long long best = LLONG_MIN;
//         for (int k = -(n - 1); k <= (n - 1); ++k) {
//             long long sum = 0;
//             int iStart = (k < 0) ? -k : 0;
//             int iEnd   = (k > 0) ? (n - 1 - k) : (n - 1);
//             for (int i = iStart; i <= iEnd; ++i) {
//                 int j = i + k;
//                 sum += mat[i * n + j];
//             }
//             if (sum > best) best = sum;
//         }
//         out << best << endl;
//         delete[] mat;
//     }

//     in.close();
//     out.close();
//     cout << "Done!";
//     return 0;
// }
    
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ifstream in("matrices.txt");
//     ofstream out("matrix_results.txt");

//     int n;
//     while (in >> n) {
//         if (n <= 0) continue;

//         int total = n * n;
//         int *mat = new int[total];

//         for (int i = 0; i < total; ++i) in >> mat[i];

//         long long best = LLONG_MIN;
//         for (int k = -(n - 1); k <= (n - 1); ++k) {
//             long long sum = 0;
//             int iStart = (k < 0) ? -k : 0;
//             int iEnd   = (k > 0) ? (n - 1 - k) : (n - 1);
//             for (int i = iStart; i <= iEnd; ++i) {
//                 int j = i + k;
//                 sum += mat[i * n + j];
//             }
//             if (sum > best) best = sum;
//         }

//         out << best << '\n';
//         delete[] mat;
//     }

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

bool readMatrix(istream &in, int **&matOut, int &n) {
    if (!(in >> n)) return false;
    if (n <= 0) { matOut = nullptr; return true; }
    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            in >> mat[i][j];
    matOut = mat;
    return true;
}


long long f(int **mat, int n) {
    long long best = LLONG_MIN;
    for (int k = -(n - 1); k <= (n - 1); ++k) {
        long long sum = 0;
        int iStart = (k < 0) ? -k : 0;
        int iEnd   = (k > 0) ? (n - 1 - k) : (n - 1);
        for (int i = iStart; i <= iEnd; ++i) {
            int j = i + k;
            sum += mat[i][j];
        }
        if (sum > best) best = sum;
    }
    return best;
}

void free(int **mat, int n) {
    for (int i = 0; i < n; ++i) delete[] mat[i];
    delete[] mat;
}

int main() {
    ifstream in("matrices.txt");
    ofstream out("matrix_results.txt");
    if (!in || !out) return 1;
    int **mat = nullptr;
    int n;
    while (readMatrix(in, mat, n)) {
        if (n <= 0) continue;
        long long best = f(mat, n);
        out << best << endl;
        free(mat, n);
    }
    return 0;
}
