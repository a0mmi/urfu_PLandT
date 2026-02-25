#include <bits/stdc++.h>

void bubble_sort_int(int *arr, size_t n) {
    if (!arr || n < 2) return;
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

static void merge_sort_int_rec(int *arr, int *buf, size_t left, size_t right) {
    if (right - left <= 1) return;
    size_t mid = left + (right - left) / 2;
    merge_sort_int_rec(arr, buf, left, mid);
    merge_sort_int_rec(arr, buf, mid, right);

    size_t i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) buf[k++] = arr[i++];
        else buf[k++] = arr[j++];
    }
    while (i < mid) buf[k++] = arr[i++];
    while (j < right) buf[k++] = arr[j++];

    for (k = left; k < right; ++k) arr[k] = buf[k];
}

void merge_sort_int(int *arr, size_t n) {
    if (!arr || n < 2) return;
    int *buf = (int*)malloc(n * sizeof(int));
    if (!buf) {
        bubble_sort_int(arr, n);
        return;
    }
    merge_sort_int_rec(arr, buf, 0, n);
    free(buf);
}
