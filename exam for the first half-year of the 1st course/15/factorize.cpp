#include <iostream>
using namespace std;

const int maxF = 1024;
int factors[maxF]{};

void factorize(int n, int res[], int &cnt) { // fast recursive factorize
    if (n <= 1) return;
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            factorize(i, res, cnt);
            factorize(n / i, res, cnt);
            return;
        }
    }
    res[cnt++] = n;
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    factorize(n, factors, cnt);

    int i = 0;
    while (factors[i] > 0){
        cout << factors[i] << ' ';
        i++;
    }
}