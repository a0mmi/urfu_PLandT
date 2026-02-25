// smooth.cpp
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " input.txt output.txt\n";
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin) { cerr << "Cannot open input file\n"; return 1; }
    if (!fout) { cerr << "Cannot open output file\n"; return 1; }

    int T;
    fin >> T;
    fout.setf(std::ios::fixed); fout<<setprecision(6);

    for (int t = 1; t <= T; ++t) {
        int r, c;
        fin >> r >> c;
        vector<vector<double>> a(r, vector<double>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                fin >> a[i][j];

        vector<vector<double>> b(r, vector<double>(c, 0.0));
        // соседями считаем: up, down, left, right (без самого элемента)
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                double sum = 0.0; int cnt = 0;
                if (i - 1 >= 0) { sum += a[i-1][j]; ++cnt; }
                if (i + 1 < r)  { sum += a[i+1][j]; ++cnt; }
                if (j - 1 >= 0) { sum += a[i][j-1]; ++cnt; }
                if (j + 1 < c)  { sum += a[i][j+1]; ++cnt; }
                if (cnt > 0) b[i][j] = sum / cnt;
                else b[i][j] = a[i][j]; // случай 1x1: оставляем исходное
            }
        }

        double sumBelow = 0.0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (i > j) sumBelow += fabs(b[i][j]);

        fout << "Matrix " << t << ":\n";
        fout << r << " " << c << "\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (j) fout << " ";
                fout << b[i][j];
            }
            fout << "\n";
        }
        fout << "SumBelow = " << sumBelow << "\n";
    }

    fin.close(); fout.close();
    return 0;
}