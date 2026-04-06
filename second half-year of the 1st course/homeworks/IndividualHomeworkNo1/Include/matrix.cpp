#include "Include\matrix.hpp"
using namespace std;

matrix::matrix() {
    m = nullptr;
    n = 0;
}

matrix::matrix(int size) {
    n = size;
    m = new gvector[n];
    for (int i = 0; i < n; i++) m[i].Init(n);
}

matrix::matrix(const matrix& other) {
    n = other.n;
    m = new gvector[n];
    for (int i = 0; i < n; i++) m[i] = other.m[i];
}

matrix& matrix::operator=(const matrix& other) {
    if (this == &other) return *this;
    delete[] m;
    n = other.n;
    m = new gvector[n];
    for (int i = 0; i < n; i++) m[i] = other.m[i];
    return *this;
}

matrix::~matrix() {
    delete[] m;
}

void matrix::Init(int size) {
    delete[] m;
    n = size;
    m = new gvector[n];
    for (int i = 0; i < n; i++) m[i].Init(n);
}

void matrix::Read() {
    for (int i = 0; i < n; i++) cin >> m[i];
}

void matrix::Display() const {
    for (int i = 0; i < n; i++) cout << m[i] << endl;
}

string matrix::toString() const {
    stringstream ss;
    for (int i = 0; i < n; i++) ss << m[i] << "\n";
    return ss.str();
}

int matrix::size() const {
    return n;
}

gvector& matrix::operator[](int i) {
    return m[i];
}

const gvector& matrix::operator[](int i) const {
    return m[i];
}

gvector operator*(const matrix& A, const gvector& x) {
    int n = A.n;
    gvector res(n);

    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 0; j < n; j++) {
            res[i] += A[i][j] * x[j];
        }
    }
    return res;
}

gvector operator*(const gvector& x, const matrix& A) {
    int n = A.n;
    gvector res(n);

    for (int j = 0; j < n; j++) {
        res[j] = 0;
        for (int i = 0; i < n; i++) {
            res[j] += x[i] * A[i][j];
        }
    }
    return res;
}

istream& operator>>(istream& in, matrix& mat) {
    for (int i = 0; i < mat.n; i++) in >> mat.m[i];
    return in;
}

ostream& operator<<(ostream& out, const matrix& mat) {
    for (int i = 0; i < mat.n; i++) out << mat.m[i] << endl;
    return out;
}