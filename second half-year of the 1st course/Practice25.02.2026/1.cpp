#include <bits/stdc++.h>
using namespace std;

void free(double **matrix, const int &n){
    for (int r = 0; r < n; ++r) delete[] matrix[r];
    delete[] matrix;
}

double **readMatrix(const int &n, const int& m, ifstream &in){
    double **matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[m];
        for(int j = 0; j < m; j++){
            in >> matrix[i][j];
        }
    }
    return matrix;
}

double **createZeroMatrix(const int &n, const int &m){
    double **matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[m];
        for(int j = 0; j < m; j++){
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}

void printResults(const int &n, const int &m, double **b, double sumBelow, ofstream &out, const int &t, const int &dt){
    out << "Matrix " << dt + 1 - t << ":\n";
    out << n << " " << m << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) out << " ";
            out << b[i][j];
        }
        out << "\n";
    }
    out << "SumBelow = " << sumBelow << "\n";
}

void solve(int dt, int t, ifstream &in, ofstream &out){
    if(!t){
        in.close();
        out.close();
        return;
    }

    int n, m;
    in >> n >> m;

    double **matrix = readMatrix(n, m, in);

    double **b = createZeroMatrix(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double sum = 0.0; int cnt = 0;
            if (i - 1 >= 0) { sum += matrix[i-1][j]; ++cnt; }
            if (i + 1 < n)  { sum += matrix[i+1][j]; ++cnt; }
            if (j - 1 >= 0) { sum += matrix[i][j-1]; ++cnt; }
            if (j + 1 < m)  { sum += matrix[i][j+1]; ++cnt; }
            if (cnt > 0) b[i][j] = sum / cnt;
            else b[i][j] = matrix[i][j];
        }
    }
    double sumBelow = 0.0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (i > j) sumBelow += fabs(b[i][j]);

    printResults(n, m, b, sumBelow, out, t, dt);

    free(matrix);
    free(b);

    solve(dt, --t, in, out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("out.txt");

    int t;
    in >> t;
    solve(t, t, in, out);
}