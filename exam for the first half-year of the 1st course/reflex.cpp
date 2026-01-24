#include <iostream>
using namespace std;

int reversal(int num) {
    int nnum = 0;
    while (num) {
        nnum = nnum * 10 + num % 10;
        num /= 10;
    }
    return nnum;
}

bool reflex(int *arr1, const int &ln1, int *arr2, const int &ln2) {
    if (ln1 != ln2) return false;

    int i = ln1; bool flag = true;
    while (i--){
        if (reversal(arr1[i]) != arr2[abs(i - ln2 + 1)]){
            flag = false;
            break;
        }
        cout << reversal(arr1[i]) << ' ' << arr2[abs(i - ln2 + 1)] << endl;
    }
    return flag;
}

int main() {
    int n1;
    cin >> n1;
    int *a1 = new int[n1];
    for(int i = 0; i < n1; i++) cin >> a1[i];

    int n2;
    cin >> n2;
    int *a2 = new int[n2];
    for(int i = 0; i < n2; i++) cin >> a2[i];

    cout << reflex(a1, n1, a2, n2);
}