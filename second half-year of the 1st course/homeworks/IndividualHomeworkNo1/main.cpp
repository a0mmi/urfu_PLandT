#include "Include\matrix.hpp"
using namespace std;

int main() {
    matrix A(4, 4);
    gvector x(4);

    cout << "Enter matrix A (4x4):\n";
    cin >> A;

    cout << "Enter vector x (size 4):\n";
    cin >> x;

    cout << "\nMatrix A:\n" << A;
    cout << "Vector x:\n" << x << endl;

    try {
        gvector res1 = A * x;
        gvector res2 = x * A;

        cout << "\nA * x = " << res1 << endl;
        cout << "x * A = " << res2 << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}