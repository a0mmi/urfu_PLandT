#pragma once
#include <bits/stdc++.h>

class gvector {
private:
    float* v;
    int n;

public:
    gvector();
    gvector(int size);
    gvector(const gvector& other);
    gvector& operator=(const gvector& other);
    ~gvector();

    void Init(int size);
    void Read();
    void Display() const;
    std::string toString() const;

    int size() const;

    float& operator[](int i);
    const float& operator[](int i) const;

    gvector& operator+=(const gvector& other);
    gvector& operator-=(const gvector& other);

    friend gvector operator+(gvector a, const gvector& b);
    friend gvector operator-(gvector a, const gvector& b);

    friend std::istream& operator>>(std::istream& in, gvector& v);
    friend std::ostream& operator<<(std::ostream& out, const gvector& v);
};
