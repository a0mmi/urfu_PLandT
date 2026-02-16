#include <iostream>
using namespace std;

int euclid(int a, int b) {
    if (a == 0) {
        return b;
    }
    return euclid(b % a, a);
}

int* fractionReduction(int a, int b) {
    int *pair = new int[2];
    int nod = euclid(a, b);
    0[pair] = a / nod; // pair[0] == *(pair + 0) == *(0 + pair) == 0[pair]
    1[pair] = b / nod;

    return pair;
}

int main() {
    int a, b;
    cin >> a >> b;

    int *temp = fractionReduction(a, b);
    a = *(temp);
    b = *(temp + 1);

    cout << a << ' ' << b;
}