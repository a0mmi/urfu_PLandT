#include <iostream>
using namespace std;

const int maxF = 10000;
int sieve[maxF];

void EratostheneSieve(int n) {
    for(int i = 2; i * i <= n; i++) {
        if (!sieve[i]) {
            for(int k = i * i; k <= n; k += i) {
                sieve[k] = 1;
            }
        }
    }
    
}

int main() {
    sieve[0] = sieve[1] = 1;

    int n;
    cin >> n;

    EratostheneSieve(n);

    for (int i = 2; i <= n; ++i) {
        if (!sieve[i]) {
            cout << i << ' ';
        }
    }
}