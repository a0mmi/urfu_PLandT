#pragma once
#include "gvector.hpp"

class matrix {
private:
    gvector* m;
    int rows;
    int cols;

public:
    matrix();
    matrix(int size);
    matrix(int r, int c);
    matrix(const matrix& other);
    matrix(matrix&& other);

    matrix& operator=(matrix other);

    ~matrix();

    void Init(int r, int c);
    void Read();
    void Display() const;
    std::string toString() const;

    int rowCount() const;
    int colCount() const;

    gvector& operator[](int i);
    const gvector& operator[](int i) const;

    friend gvector operator*(const matrix& A, const gvector& x);
    friend gvector operator*(const gvector& x, const matrix& A);

    friend std::istream& operator>>(std::istream& in, matrix& m);
    friend std::ostream& operator<<(std::ostream& out, const matrix& m);
};