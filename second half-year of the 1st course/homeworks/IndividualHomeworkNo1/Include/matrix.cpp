#include "matrix.hpp"

using namespace std;

matrix::matrix() {
    m = nullptr;
    rows = 0;
    cols = 0;
}

matrix::matrix(int size) {
    rows = size;
    cols = size;
    m = new gvector[rows];
    for (int i = 0; i < rows; i++) {
        m[i].Init(cols);
    }
}

matrix::matrix(int r, int c) {
    rows = r;
    cols = c;
    m = new gvector[rows];
    for (int i = 0; i < rows; i++) m[i].Init(cols);
}

matrix::matrix(const matrix& other) {
    rows = other.rows;
    cols = other.cols;
    m = new gvector[rows];
    for (int i = 0; i < rows; i++) m[i] = other.m[i];
}

matrix::matrix(matrix&& other) noexcept {
    m = other.m;
    rows = other.rows;
    cols = other.cols;
    other.m = nullptr;
    other.rows = 0;
    other.cols = 0;
}

matrix& matrix::operator=(matrix other) {
    swap(*this, other);
    return *this;
}

matrix::~matrix() {
    delete[] m;
}

void matrix::Init(int r, int c) {
    delete[] m;
    rows = r;
    cols = c;
    m = new gvector[rows];
    for (int i = 0; i < rows; i++) m[i].Init(cols);
}

void matrix::Read() {
    for (int i = 0; i < rows; i++) cin >> m[i];
}

void matrix::Display() const {
    for (int i = 0; i < rows; i++) cout << m[i] << endl;
}

string matrix::toString() const {
    stringstream ss;
    for (int i = 0; i < rows; i++) ss << m[i] << "\n";
    return ss.str();
}

int matrix::rowCount() const {
    return rows;
}

int matrix::colCount() const {
    return cols;
}

gvector& matrix::operator[](int i) {
    return m[i];
}

const gvector& matrix::operator[](int i) const {
    return m[i];
}

gvector operator*(const matrix& A, const gvector& x) {
    if (A.cols != x.size()) {
        throw invalid_argument("A * x: number of matrix columns must equal vector size");
    }

    gvector res(A.rows);

    for (int i = 0; i < A.rows; i++) {
        res[i] = 0;
        for (int j = 0; j < A.cols; j++) {
            res[i] += A[i][j] * x[j];
        }
    }
    return res;
}

gvector operator*(const gvector& x, const matrix& A) {
    if (x.size() != A.rows) {
        throw invalid_argument("x * A: vector size must equal number of matrix rows");
    }

    gvector res(A.cols);

    for (int j = 0; j < A.cols; j++) {
        res[j] = 0;
        for (int i = 0; i < A.rows; i++) {
            res[j] += x[i] * A[i][j];
        }
    }
    return res;
}

istream& operator>>(istream& in, matrix& mat) {
    for (int i = 0; i < mat.rows; i++) in >> mat.m[i];
    return in;
}

ostream& operator<<(ostream& out, const matrix& mat) {
    for (int i = 0; i < mat.rows; i++) out << mat.m[i] << endl;
    return out;
}