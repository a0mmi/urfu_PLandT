#include <bits/stdc++.h>
using namespace std;

#define forn(i, l, r) for(int i = l; i < r; ++i)
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using db = double;
using vdb = vector<double>;
using vs = vector<string>;

template<typename T>
struct Matrix {
    int r = 0, c = 0;
    T **a = nullptr;

    // constructor
    Matrix(int rows = 0, int cols = 0) {
        if (rows <= 0 || cols <= 0) { r = c = 0; a = nullptr; return; }
        r = rows; c = cols;
        a = new T*[r];
        forn (i, 0, r) {
            a[i] = new T[c];
            forn (j, 0, c) a[i][j] = T(); // zero-init
        }
    }

    // copy constructor
    Matrix(const Matrix &other) {
        r = other.r; c = other.c;
        if (r == 0 || c == 0) { a = nullptr; return; }
        a = new T*[r];
        forn (i, 0, r) {
            a[i] = new T[c];
            forn (j, 0, c) a[i][j] = other.a[i][j];
        }
    }

    // move constructor
    Matrix(Matrix &&other) noexcept {
        r = other.r; c = other.c; a = other.a;
        other.r = other.c = 0; other.a = nullptr;
    }

    // destructor
    ~Matrix() {
        if (a) {
            forn (i, 0, r) delete[] a[i];
            delete[] a;
        }
    }

    // copy-and-swap
    Matrix& operator=(Matrix other) {
        swap(r, other.r);
        swap(c, other.c);
        swap(a, other.a);
        return *this;
    }

    // access
    T* operator[](int i) { return a[i]; }
    const T* operator[](int i) const { return a[i]; }

    // print
    void print(ostream &out = cout) const {
        forn (i, 0, r) {
            forn (j, 0, c) {
                out << a[i][j];
                if (j + 1 < c) out << ' ';
            }
            out << '\n';
        }
    }

    // read from stdin
    void read(istream &in = cin) {
        forn (i, 0, r)
            forn (j, 0, c)
                in >> a[i][j];
    }

    // operator+ (matrix sum)
    friend Matrix operator+(const Matrix &A, const Matrix &B) {
        if (A.r != B.r || A.c != B.c) throw runtime_error("Dimension mismatch in operator+");
        Matrix C(A.r, A.c);
        forn (i, 0, A.r)
            forn (j, 0, A.c)
                C.a[i][j] = A.a[i][j] + B.a[i][j];
        return C;
    }
};