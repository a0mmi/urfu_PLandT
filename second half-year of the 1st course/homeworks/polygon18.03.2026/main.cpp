#include <bits/stdc++.h>
#include "Include/PointV.hpp"
#include "Include/Polygon.hpp"
using namespace std;

bool f(const Polygon& a, const Polygon& b) { // Функция сравнения
    return a.longestDiagonal() > b.longestDiagonal();
}

void merge(Polygon* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Polygon* L = new Polygon[n1];
    Polygon* R = new Polygon[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (f(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Polygon* arr, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    Polygon* res = nullptr;
    int cnt = 0;

    Polygon poly;
    while (fin >> poly) {

        if (poly.isConvex()) {
            Polygon* tmp = new Polygon[cnt + 1];

            for (int i = 0; i < cnt; ++i) {
                tmp[i] = res[i];
            }

            tmp[cnt] = poly;

            delete[] res;
            res = tmp;
            cnt++;
        }
    }

    if (cnt > 0) mergeSort(res, 0, cnt - 1);

    for (int i = 0; i < cnt; ++i) {
        fout << res[i] << "\n";
    }

    delete[] res;
    return 0;
}