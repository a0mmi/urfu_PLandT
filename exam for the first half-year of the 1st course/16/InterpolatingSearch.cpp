#include <iostream>
using namespace std;

void bubleSort(int *arr) {
    bool swapped;
    int n = sizeof(arr);

    for(int i = 0; i < n; i++) {
        swapped = false;
        for(int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int interpolatingSearch(int *arr, int key) {
    int l = 0, r = sizeof(arr);
    int mid;

    while (l < r) {
        int factor = (key - arr[l]) / (arr[r] - arr[l]);
        int diff = r - l;
        mid = l + factor * diff;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;

    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubleSort(a);

    int key;
    cin >> key;

    cout << interpolatingSearch(a, key) << endl;
    return 0;
}