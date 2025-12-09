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

int main() {
    unsigned int n;
    cin >> n;

    shi **T = new shi*[n];
    forn(i, n) T[i] = new shi[n];

    forn(i, n)
        forn(j, n)
            T[i][j] = ((i + j) % 2 == (n - 1) % 2) ? 0 : 1;
    
    print_matrix(T);
}