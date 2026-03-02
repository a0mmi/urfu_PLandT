#include "rational.hpp";
#include <stdexcept> // Поддержка ошибок

using namespace std;

ll gcd(ll a, ll b){
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (!a) { return b; }
    return gcd(b % a, a);
}

Rational::Rational(ll num, ll den) {
    if (den == 0) {
        throw invalid_argument("Rational: denominator must not be zero");
    }
    this->num = num;
    this->den = den;
    normalize();
}

ll Rational::numg() const { return num; }
ll Rational::deng() const { return den; }

void Rational::normalize() {
    if (den < 0) { num = -num; den = -den; }
    ll a = num >= 0 ? num : -num;
    ll g = gcd(a, den);
    if (g != 0) { num /= g; den /= g; }
}

Rational& Rational::operator+=(const Rational& other) {
    num = num * other.den + other.num * den;
    den = den * other.den;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    num = num * other.den - other.num * den;
    den = den * other.den;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    num = num * other.num;
    den = den * other.den;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    if (other.num == 0) {
        throw std::domain_error("Rational: division by zero");
    }
    num = num * other.den;
    den = den * other.num;
    normalize();
    return *this;
}

Rational operator+(Rational a, const Rational& b) { a += b; return a; }
Rational operator-(Rational a, const Rational& b) { a -= b; return a; }
Rational operator*(Rational a, const Rational& b) { a *= b; return a; }
Rational operator/(Rational a, const Rational& b) { a /= b; return a; }

bool operator==(const Rational& a, const Rational& b) {
    return a.numg() == b.numg() && a.deng() == b.deng();
}
bool operator!=(const Rational& a, const Rational& b) {
    return !(a == b);
}
bool operator<(const Rational& a, const Rational& b) {
    return a.numg() * b.deng() < b.numg() * a.deng(); // Возможно переполнение
}
bool operator>(const Rational& a, const Rational& b) {
    return a.numg() * b.deng() > b.numg() * a.deng(); // Возможно переполнение
}
bool operator>=(const Rational& a, const Rational& b) {
    return a.numg() * b.deng() >= b.numg() * a.deng(); // Возможно переполнение
}
bool operator<=(const Rational& a, const Rational& b) {
    return a.numg() * b.deng() <= b.numg() * a.deng(); // Возможно переполнение
}