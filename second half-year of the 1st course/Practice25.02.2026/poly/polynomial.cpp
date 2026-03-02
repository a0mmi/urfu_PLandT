#include "polynomial.hpp"
#include <stdexcept>

using namespace std;

Polynomial::Polynomial(int deg) {
    if (deg < 0) {
        throw invalid_argument("Polynomial: degree must be non-negative");
    }
    degree = deg;
    coef = new ll[degree + 1];
    for (int i = 0; i <= degree; ++i) coef[i] = 0;
}

Polynomial::Polynomial(const Polynomial& other) {
    degree = other.degree;
    coef = new ll[degree + 1];
    for (int i = 0; i <= degree; ++i) coef[i] = other.coef[i];
}

Polynomial::~Polynomial() {
    delete[] coef;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) return *this;
    delete[] coef;
    degree = other.degree;
    coef = new ll[degree + 1];
    for (int i = 0; i <= degree; ++i) coef[i] = other.coef[i];
    return *this;
}

ll Polynomial::get_coef(int i) const {
    if (i < 0) throw invalid_argument("Polynomial::get_coef: index must be non-negative");
    if (i > degree) return 0;
    return coef[i];
}

void Polynomial::set_coef(int i, ll val) {
    if (i < 0) throw invalid_argument("Polynomial::set_coef: index must be non-negative");
    if (i > degree) {
        // расширяем массив
        ll* newcoef = new ll[i + 1];
        for (int j = 0; j <= i; ++j) newcoef[j] = 0;
        for (int j = 0; j <= degree; ++j) newcoef[j] = coef[j];
        delete[] coef;
        coef = newcoef;
        degree = i;
    }
    coef[i] = val;
}

int Polynomial::get_degree() const {
    // логическая степень (высшая степень с ненулевым коэффициентом)
    for (int i = degree; i > 0; --i) {
        if (coef[i] != 0) return i;
    }
    // даже если все нули, возвращаем 0 (нулевой многочлен)
    return 0;
}

ll Polynomial::eval(ll x) const {
    // Horner
    int d = get_degree();
    ll res = 0;
    for (int i = d; i >= 0; --i) {
        res = res * x + coef[i];
    }
    return res;
}

Polynomial Polynomial::derivative() const {
    int d = get_degree();
    if (d == 0) {
        Polynomial r(0);
        r.coef[0] = 0;
        return r;
    }
    Polynomial r(d - 1);
    for (int i = 1; i <= d; ++i) {
        r.coef[i - 1] = coef[i] * (ll)i;
    }
    // остальные уже инициализированы нулями в конструкторе
    return r;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    int d1 = this->get_degree();
    int d2 = other.get_degree();
    int nd = max(d1, d2);
    // если текущий массив меньше, расширим
    if (nd > degree) {
        ll* newcoef = new ll[nd + 1];
        for (int i = 0; i <= nd; ++i) newcoef[i] = 0;
        for (int i = 0; i <= degree; ++i) newcoef[i] = coef[i];
        delete[] coef;
        coef = newcoef;
        degree = nd;
    }
    for (int i = 0; i <= d2; ++i) {
        coef[i] += other.coef[i];
    }
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    int d1 = this->get_degree();
    int d2 = other.get_degree();
    int nd = max(d1, d2);
    if (nd > degree) {
        ll* newcoef = new ll[nd + 1];
        for (int i = 0; i <= nd; ++i) newcoef[i] = 0;
        for (int i = 0; i <= degree; ++i) newcoef[i] = coef[i];
        delete[] coef;
        coef = newcoef;
        degree = nd;
    }
    for (int i = 0; i <= d2; ++i) {
        coef[i] -= other.coef[i];
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    int d1 = this->get_degree();
    int d2 = other.get_degree();
    int nd = d1 + d2;
    ll* newcoef = new ll[nd + 1];
    for (int i = 0; i <= nd; ++i) newcoef[i] = 0;
    for (int i = 0; i <= d1; ++i) {
        for (int j = 0; j <= d2; ++j) {
            newcoef[i + j] += coef[i] * other.coef[j];
        }
    }
    delete[] coef;
    coef = newcoef;
    degree = nd;
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& other) {
    // деление многочленов: this := this / other (частное)
    int da = this->get_degree();
    int db = other.get_degree();
    // проверка на деление на нулевой многочлен
    bool other_zero = true;
    for (int i = 0; i <= db; ++i) {
        if (other.coef[i] != 0) { other_zero = false; break; }
    }
    if (other_zero) {
        throw std::domain_error("Polynomial: division by zero polynomial");
    }
    if (da < db) {
        // частное = 0
        delete[] coef;
        degree = 0;
        coef = new ll[1];
        coef[0] = 0;
        return *this;
    }
    // временно копируем коэффициенты делимого в динамический массив (чтобы было удобно изменять)
    ll* rem = new ll[da + 1];
    for (int i = 0; i <= da; ++i) rem[i] = coef[i];
    ll b_lead = other.coef[db];
    int qdeg = da - db;
    ll* q = new ll[qdeg + 1];
    for (int i = 0; i <= qdeg; ++i) q[i] = 0;
    for (int k = da; k >= db; --k) {
        ll rcoef = rem[k];
        ll factor = 0;
        if (b_lead != 0) {
            factor = rcoef / b_lead; // целочисленное деление
        } else {
            // на практике b_lead не равен 0 (мы проверили), но оставим защиту
            delete[] rem;
            delete[] q;
            throw domain_error("Polynomial: unexpected zero leading coefficient in divisor");
        }
        int qi = k - db;
        q[qi] = factor;
        if (factor != 0) {
            for (int j = 0; j <= db; ++j) {
                rem[qi + j] -= factor * other.coef[j];
            }
        }
    }
    // запишем частное обратно в this
    delete[] coef;
    degree = qdeg;
    coef = new ll[degree + 1];
    for (int i = 0; i <= degree; ++i) coef[i] = q[i];

    delete[] rem;
    delete[] q;
    return *this;
}

istream& operator>>(istream& in, Polynomial& p) {
    int n;
    if (!(in >> n)) return in; // неудачное чтение
    if (n < 0) {
        in.setstate(ios::failbit);
        return in;
    }
    delete[] p.coef;
    p.degree = n;
    p.coef = new ll[p.degree + 1];
    for (int i = 0; i <= p.degree; ++i) {
        ll v;
        if (!(in >> v)) {
            // если чтение коэффициента неудачно, пометим поток и вернём
            in.setstate(ios::failbit);
            // оставшаяся память уже назначена — норм.
            return in;
        }
        p.coef[i] = v;
    }
    return in;
}

ostream& operator<<(ostream& out, const Polynomial& p) {
    int d = p.get_degree();
    out << d;
    for (int i = 0; i <= d; ++i) {
        out << " " << p.coef[i];
    }
    return out;
}

Polynomial operator+(Polynomial a, const Polynomial& b) { a += b; return a; }
Polynomial operator-(Polynomial a, const Polynomial& b) { a -= b; return a; }

Polynomial operator*(const Polynomial& a, const Polynomial& b) {
    Polynomial r = a;
    r *= b;
    return r;
}
Polynomial operator/(const Polynomial& a, const Polynomial& b) {
    Polynomial res = a;
    res /= b;
    return res;
}

Polynomial operator%(const Polynomial& a, const Polynomial& b) {
    // вернём остаток a % b
    int da = a.get_degree();
    int db = b.get_degree();
    // проверка на нулевой делитель
    bool b_zero = true;
    for (int i = 0; i <= db; ++i) {
        if (b.coef[i] != 0) { b_zero = false; break; }
    }
    if (b_zero) throw std::domain_error("Polynomial: division by zero polynomial");
    if (da < db) {
        // остаток = a
        return a;
    }
    ll* rem = new ll[da + 1];
    for (int i = 0; i <= da; ++i) rem[i] = a.coef[i];
    ll b_lead = b.coef[db];
    for (int k = da; k >= db; --k) {
        ll rcoef = rem[k];
        ll factor = 0;
        if (b_lead != 0) factor = rcoef / b_lead;
        int qi = k - db;
        if (factor != 0) {
            for (int j = 0; j <= db; ++j) rem[qi + j] -= factor * b.coef[j];
        }
    }
    // найдем степень остатка (макс индекс < db с ненулевым)
    int rdeg = 0;
    for (int i = db - 1; i >= 0; --i) {
        if (rem[i] != 0) { rdeg = i; break; }
    }
    Polynomial r(rdeg);
    for (int i = 0; i <= rdeg; ++i) r.coef[i] = rem[i];

    delete[] rem;
    return r;
}