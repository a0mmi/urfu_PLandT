#pragma once

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class matrix {
    private:
        ll n;
        ll m;
        double* data;

        void allocate_and_zero(ll rows, ll cols);
    public:
        // constructors / destructor / assignment
        matrix(int rows = 0, int cols = 0);
        matrix(const matrix& other);
        matrix(matrix&& other);
        matrix(initializer_list<initializer_list<double>> list);

        matrix& operator=(const matrix& other);
        matrix& operator=(matrix&& other);
        ~matrix();

        // accessors
        int getRows() const;
        int getCols() const;

        // element access (0-based) бросает out_of_range при неверных индексах
        double& operator()(int i, int j);
        double  operator()(int i, int j) const;

        // raw pointer
        const double* raw() const;

        // basic operations
        matrix transpose() const;
        matrix& operator+=(const matrix& other);
        matrix& operator-=(const matrix& other);
        matrix& operator*=(const matrix& other);
        matrix& operator+=(double s);
        matrix& operator-=(double s);
        matrix& operator*=(double s);

        friend matrix operator+(matrix a, const matrix& b);
        friend matrix operator-(matrix a, const matrix& b);
        friend matrix operator*(matrix a, const matrix& b);
        friend matrix operator*(matrix a, double s);
        friend matrix operator*(double s, matrix a);
        friend matrix operator+(matrix a, double s);
        friend matrix operator+(double s, matrix a);
        friend matrix operator-(matrix a, double s);
        friend matrix operator-(double s, matrix a);


        // checks
        bool isIdentity(double eps = 1e-9) const;
        bool isOrthogonal(double eps = 1e-9) const;

        //methods
        double determinant(double eps = 1e-12) const;
        pair<bool, matrix> solve(const matrix& b, double eps = 1e-12) const; // kramer

        // helpers
        void fill(double val = 0.0);

        // IO
        friend istream& operator>>(istream& in, matrix& A);
        friend ostream& operator<<(ostream& out, const matrix& A);
};