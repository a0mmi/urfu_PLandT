#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << "0.";

    int MAX_B = 10000;
    int *pos = new int[MAX_B];

    for (int i = 0; i < MAX_B; ++i) {
        pos[i] = -1;
    }

    long long r = a;
    string fractional = "";

    while (r != 0) {
        if (pos[r] != -1) {
            fractional.insert(pos[r], "(");
            fractional += ")";
            cout << fractional << endl;
            return 0;
        }

        pos[r] = fractional.size();

        r *= 10;
        int digit = r / b;
        r = r % b;

        fractional += ('0' + digit);
    }
    cout << fractional << endl;
    return 0;
}