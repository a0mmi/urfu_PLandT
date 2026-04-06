#pragma once
#include "Include\gvector.hpp"

class matrix {
private:
    gvector* m;
    int n;

public:
    matrix();
    matrix(int size);
    matrix(const matrix& other);
    matrix& operator=(const matrix& other);
    ~matrix();

    void Init(int size);
    void Read();
    void Display() const;
    std::string toString() const;

    int size() const;

    gvector& operator[](int i);
    const gvector& operator[](int i) const;

    friend gvector operator*(const matrix& A, const gvector& x);
    friend gvector operator*(const gvector& x, const matrix& A);

    friend std::istream& operator>>(std::istream& in, matrix& m);
    friend std::ostream& operator<<(std::ostream& out, const matrix& m);
};