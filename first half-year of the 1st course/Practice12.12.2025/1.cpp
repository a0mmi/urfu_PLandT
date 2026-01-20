#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

using shi = short int;

void print_matrix(shi **matrix) {
        unsigned int n = sizeof(matrix) + 1;
        forn(i, n) {
            forn(j, n) {
                cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

// int main() {
//     unsigned int n;
//     cin >> n;

//     shi **T = new shi*[n];
//     forn(i, n) T[i] = new shi[n];

//     forn(i, n)
//         forn(j, n)
//             T[i][j] = ((i + j) % 2 == (n - 1) % 2) ? 0 : 1;
//             // T[i][j] = !((i + j) % 2 == (n - 1) % 2);
//     print_matrix(T);

//     delete[] T;
//     return 0;
// }

int main() {
    unsigned int n;
    cin >> n;

    shi *data = new shi[n * n];
    shi **T = new shi*[n];
    for (unsigned int i = 0; i < n; ++i)
        *(T + i) = data + i * n;
    
    for (unsigned int i = 0; i < n; ++i) {
        shi *row = *(T + i);
        for (unsigned int j = 0; j < n; ++j)
            *(row + j) = !((i + j) % 2 == (n - 1) % 2);
    }
    
    print_matrix(T);

    delete[] data;
    delete[] T;
    return 0;
}