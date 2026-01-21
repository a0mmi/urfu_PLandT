#include <iostream>
using namespace std;

int search(int *arr, int key){
    for(int i = 0; i < sizeof(arr); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int key;
    cin >> key;

    cout << search(a, key);

    return 0;
}