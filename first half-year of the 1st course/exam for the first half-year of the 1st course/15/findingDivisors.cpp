#include <iostream>
#include <cmath>
using namespace std;

const int maxF = 128;
int divisors[maxF];

void findingDivisors(int n, int &cnt) {
    for(int i = 1; i < (int)sqrt(n) + 1; i++) {
        if (n % i == 0) {
            divisors[cnt] = i;
            cnt++;
            if (i * i != n) {
                divisors[cnt] = n / i;
                cnt++;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    findingDivisors(n, cnt);

    int i = 0;
    while (divisors[i] > 0) {
        cout << divisors[i] << ' ';
        i++;
    }
}