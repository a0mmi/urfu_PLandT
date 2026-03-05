#pragma once
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Polynomial {
private:
    ll* coef;
    int degree;

public:
    Polynomial(int deg = 0);
    Polynomial(const Polynomial& other);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& other);
    
    ll get_coef(int i) const;
    void set_coef(int i, ll val);
    int get_degree() const;
    
    ll eval(ll x) const;
    Polynomial derivative() const;
    
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);
    Polynomial& operator/=(const Polynomial& other);
    Polynomial& operator%=(const Polynomial& other);

    friend istream& operator>>(istream& in, Polynomial& p);
    friend ostream& operator<<(ostream& out, const Polynomial& p);
    friend Polynomial operator+(Polynomial a, const Polynomial& b);
    friend Polynomial operator-(Polynomial a, const Polynomial& b);
    friend Polynomial operator/(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator%(const Polynomial& a, const Polynomial& b);
};