#include <bits/stdc++.h>
using namespace std;

int n;
int *arr;
int **matrix;

void bubbleSort() {
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j + 1 < n - i; j++) {
            if (matrix[0][j] > matrix[0][j + 1]) {
                swap(matrix[0][j], matrix[0][j + 1]);
                swap(matrix[1][j], matrix[1][j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int find(int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (matrix[0][mid] == key)
            return matrix[1][mid];
        if (matrix[0][mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    matrix = new int*[2];
    matrix[0] = new int[n];
    matrix[1] = new int[n];

    for (int i = 0; i < n; i++){
        matrix[0][i] = arr[i];
        matrix[1][i] = i;
    }
    bubbleSort();

    for (int i = 0; i < n; i++){
        cout << matrix[0][i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << matrix[1][i] << ' ';
    }

    cout << endl;
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << find(x) << endl;
    }
    return 0;
}