#pragma once

using namespace std;

using ll = long long;

class Rational {
    private:
        ll num, den;
        void normalize();
    public:
        Rational (ll n = 0, ll d = 1);
        ll numg() const; ll deng() const;

        Rational& operator+=(const Rational &a);
        Rational& operator-=(const Rational &a);
        Rational& operator*=(const Rational &a);
        Rational& operator/=(const Rational &a);
        
        friend Rational operator+(Rational a, const Rational& b);
        friend Rational operator-(Rational a, const Rational& b);
        friend Rational operator*(Rational a, const Rational& b);
        friend Rational operator/(Rational a, const Rational& b);

        friend bool operator==(const Rational& a, const Rational& b);
        friend bool operator!=(const Rational& a, const Rational& b);
        friend bool operator<(const Rational& a, const Rational& b);
        friend bool operator>(const Rational& a, const Rational& b);
        friend bool operator<=(const Rational& a, const Rational& b);
        friend bool operator>=(const Rational& a, const Rational& b);


        // friend ofstream& operator<<(ofstream& out, const Rational& r);
        // friend ifstream& operator>>(ifstream& in, Rational& r);
};