#include <bits/stdc++.h>
using namespace std;

int calcVal(int d, int m, int y){
    return m * 30 + 365 * y;
}

struct date {
    int d, m, y;
    int val;
};

struct student {
    string stud;
    date d;
};

void merge_sort_rec(student *arr, student *buf, size_t left, size_t right) {
    if (right - left <= 1) return;
    size_t mid = left + (right - left) / 2;
    merge_sort_rec(arr, buf, left, mid);
    merge_sort_rec(arr, buf, mid, right);

    size_t i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (arr[i].d.val <= arr[j].d.val) buf[k++] = arr[i++];
        else buf[k++] = arr[j++];
    }
    while (i < mid) buf[k++] = arr[i++];
    while (j < right) buf[k++] = arr[j++];

    for (k = left; k < right; ++k) arr[k] = buf[k];
}

int main() {
    fstream in("students.txt");
    
    int n;
    in >> n;
    
    student *arr = new student[n];

    for(int i = 0; i < n; i++) {
        string secondName;
        int d, m, y;
        in >> secondName >> d >> m >> y;
        student st;
        st.d.d = d; st.d.m = m; st.d.y = y; st.d.val = calcVal(d, m, y);
        st.stud = secondName;
    }
    student *buf = new student[n]; 
    merge_sort_rec(arr, buf, 0, n);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i].stud << ' ' << arr[i].d.d << ' ' << arr[i].d.m << ' ' << arr[i].d.y << endl;
    }
}

