#include "matrix.hpp"

void matrix::allocate_and_zero(ll rows, ll cols) {
    if (rows < 0 || cols < 0) throw invalid_argument("matrix: negative dimension");
    n = rows; m = cols;
    if (n == 0 || m == 0) {
        data = nullptr;
        return;
    }
    data = new double[n * m];
    for (ll i = 0; i < n * m; ++i) data[i] = 0.0;
}

matrix::matrix(int rows, int cols) {
    allocate_and_zero(rows, cols);
}

matrix::matrix(const matrix& other) {
    allocate_and_zero(other.n, other.m);
    if (data && other.data) {
        for (ll i = 0, S = n * m; i < S; ++i) data[i] = other.data[i];
    }
}

matrix::matrix(matrix&& other) { // переношу указатель, а не копирую матрицу
    n = other.n;
    m = other.m;
    data = other.data;
    other.n = other.m = 0;
    other.data = nullptr; // обнуляю старый объект
} // matrix A = B * C; -- теперь эта матрица владеет тем же массивом памяти.

matrix& matrix::operator=(const matrix& other) {
    if (this == &other) return *this;
    delete[] data;
    allocate_and_zero(other.n, other.m);
    if (data && other.data) {
        for (ll i = 0, S = n * m; i < S; ++i) data[i] = other.data[i];
    }
    return *this;
}

matrix& matrix::operator=(matrix&& other) {
    if (this == &other) return *this;
    delete[] data;
    n = other.n; m = other.m; data = other.data;
    other.n = other.m = 0;
    other.data = nullptr;
    return *this;
}

matrix::~matrix() {
    delete[] data;
}

int matrix::getRows() const { return (int)n; }
int matrix::getCols() const { return (int)m; }

double& matrix::operator()(int i, int j) {
    if (i < 0 || j < 0 || ll(i) >= n || ll(j) >= m) throw out_of_range("matrix::operator(): index out of range");
    return data[i * m + j];
}

double matrix::operator()(int i, int j) const {
    if (i < 0 || j < 0 || ll(i) >= n || ll(j) >= m) throw out_of_range("matrix::operator() const: index out of range");
    return data[i * m + j];
}

const double* matrix::raw() const { return data; }

matrix matrix::transpose() const {
    matrix T((int)m, (int)n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            T.data[j * n + i] = data[i * m + j];
        }
    }
    return T;
}

matrix& matrix::operator*=(const matrix& other) {
    if (m != other.n) throw invalid_argument("matrix::operator*=: dimension mismatch");
    matrix R((int)n, (int)other.m);
    // простой тройной цикл -- можно оптимизировать
    for (ll i = 0; i < n; ++i) {
        for (ll k = 0; k < m; ++k) {
            double aik = data[i * m + k];
            if (aik == 0.0) continue;
            for (ll j = 0; j < other.m; ++j) {
                R.data[i * other.m + j] += aik * other.data[k * other.m + j];
            }
        }
    }
    this->n = n; this->m = other.m;
    for (ll i = 0; i < n; ++i)
        for (ll k = 0; k < m; ++k)
            data[i * m + k] = R.data[i * m + k];
    return *this;
}

matrix& matrix::operator-=(const matrix& other) {
    if (n != other.n || m != other.m) throw invalid_argument("matrix::operator*=: dimension mismatch");
}

matrix& matrix::operator+=(const matrix& other) {

}

matrix operator*(matrix a, const matrix &b) { a *= b; return a; }

bool matrix::isIdentity(double eps) const { // Проверка на единичную матрицу
    if (n != m) return false;
    if (n == 0) return false;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            double v = data[i * m + j];
            if (i == j) { // На диагонали
                if (fabs(v - 1.0) > eps) return false; // `Является ли матрица единичной с учётом погрешности eps`  
            } else {
                if (fabs(v) > eps) return false;
            }
        }
    }
    return true;
}

bool matrix::isOrthogonal(double eps) const {
    if (n != m) return false;
    matrix prod = (*this) * this->transpose();
    return prod.isIdentity(eps);
}

double matrix::determinant(double eps) const {
    int nn = getRows();
    if (nn != getCols()) throw invalid_argument("determinant: matrix must be square");
    if (nn == 0) return 1.0; // соглашение

    // создаём копию для приведения к верхнетреугольной форме
    matrix A = *this;
    int sign = 1;
    for (int i = 0; i < nn; ++i) {
        // partial pivot
        int pivot = i;
        double maxv = fabs(A.data[i * nn + i]);
        for (int r = i + 1; r < nn; ++r) {
            double v = fabs(A.data[r * nn + i]);
            if (v > maxv) { maxv = v; pivot = r; }
        }
        if (maxv <= eps) return 0.0;
        if (pivot != i) {
            // swap rows i and pivot
            for (int c = 0; c < nn; ++c) {
                double tmp = A.data[i * nn + c];
                A.data[i * nn + c] = A.data[pivot * nn + c];
                A.data[pivot * nn + c] = tmp;
            }
            sign = -sign;
        }
        double aii = A.data[i * nn + i];
        for (int r = i + 1; r < nn; ++r) {
            double factor = A.data[r * nn + i] / aii;
            if (factor == 0.0) continue;
            for (int c = i; c < nn; ++c) {
                A.data[r * nn + c] -= factor * A.data[i * nn + c];
            }
        }
    }
    double det = (sign == 1 ? 1.0 : -1.0);
    for (int i = 0; i < nn; ++i) det *= A.data[i * nn + i];
    return det;
}

void matrix::fill(double val) {
    if (!data) return;
    for (ll i = 0, S = n * m; i < S; ++i) data[i] = val;
}

// Формат ввода: rows cols followed by rows*cols чисел (по строкам).
istream& operator>>(istream& in, matrix& A) {
    int rows = 0, cols = 0;
    if (!(in >> rows >> cols)) return in;
    if (rows < 0 || cols < 0) {
        in.setstate(ios::failbit);
        return in;
    }
    delete[] A.data;
    A.allocate_and_zero(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double v;
            if (!(in >> v)) {
                in.setstate(ios::failbit);
                return in;
            }
            A.data[i * A.m + j] = v;
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const matrix& A) {
    out << A.getRows() << ' ' << A.getCols() << '\n';
    out << fixed << setprecision(10);
    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < A.getCols(); ++j) {
            out << A(i, j);
            if (j + 1 < A.getCols()) out << ' ';
        }
        out << '\n';
    }
    return out;
}