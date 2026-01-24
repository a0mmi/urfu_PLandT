#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ipow(int base, int exp) {
    int r = 1;
    for (int i = 0; i < exp; ++i) r *= base;
    return r;
}

bool isArmstrongNumber(int num) {
    string num_s = to_string(num);
    int n = num_s.length();
    int sums = 0, temp = num;
    for(int i = 0; i < n; i++) {
        sums += ipow(temp % 10, n);
        temp /= 10;
    }
    return sums == num;
}

void armstrongArray(int *arr, const int &n) {
    for(int i = 0; i < n; i++){
        if(isArmstrongNumber(arr[i])) {
            cout << arr[i] << ' ';
        }
    }
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    armstrongArray(arr, n);
}