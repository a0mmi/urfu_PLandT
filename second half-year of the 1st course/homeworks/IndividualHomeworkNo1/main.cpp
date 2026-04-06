#include "Include\matrix.hpp"
using namespace std;

int main() {
    int n = 4;

    matrix A(n);
    gvector x(n);

    cout << "Enter matrix:\n";
    cin >> A;

    cout << "Enter vector:\n";
    cin >> x;

    cout << "\nMatrix:\n" << A;
    cout << "Vector:\n" << x << endl;

    gvector res1 = A * x;
    gvector res2 = x * A;

    cout << "\nA * x = " << res1 << endl;
    cout << "x * A = " << res2 << endl;

    return 0;
}