#include "Polygon.hpp"
using namespace std;

Polygon::Polygon() {
    p = nullptr;
    n = 0;
}

Polygon::Polygon(int sz, const PointV* arr) {
    n = sz;
    p = new PointV[n];
    for (int i = 0; i < n; ++i) {
        p[i] = arr[i];
    }
}

Polygon::Polygon(const Polygon& other) {
    n = other.n;
    p = new PointV[n];
    for (int i = 0; i < n; ++i) {
        p[i] = other.p[i];
    }
}

Polygon& Polygon::operator=(const Polygon& other) {
    if (this == &other) return *this;
    delete[] p;
    n = other.n;
    p = new PointV[n];
    for (int i = 0; i < n; ++i) {
        p[i] = other.p[i];
    }

    return *this;
}

Polygon::~Polygon() {
    delete[] p;
}

double Polygon::cross(const PointV& a, const PointV& b, const PointV& c) const {
    PointV ab = b - a;
    PointV ac = c - a;
    return ab.cross(ac);
}

double Polygon::dist(const PointV& a, const PointV& b) const {
    return (a - b).len();
}

int Polygon::size() const {
    return n;
}

bool Polygon::isConvex(const double EPS) const {
    if (n < 3) return false;
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        double cr = cross(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (fabs(cr) < EPS) return false;
        int cur = (cr > 0) ? 1 : -1;
        if (sign == 0) sign = cur;
        else if (sign != cur) return false;
    }

    return true;
}

double Polygon::perimeter() const {
    double per = 0;
    for (int i = 0; i < n; ++i) {
        per += dist(p[i], p[(i + 1) % n]);
    }
    return per;
}

double Polygon::area() const {
    double s = 0;
    for (int i = 0; i < n; ++i) {
        s += p[i].cross(p[(i + 1) % n]);
    }
    return fabs(s) / 2.0;
}

double Polygon::longestDiagonal() const {
    if (n < 4) return 0;
    double mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (j == i + 1) continue;
            if (i == 0 && j == n - 1) continue;
            double d = dist(p[i], p[j]);
            if (d > mx) mx = d;
        }
    }
    return mx;
}

istream& operator>>(istream& in, Polygon& poly) {
    int sz;
    if (!(in >> sz)) return in;
    PointV* tmp = new PointV[sz];
    for (int i = 0; i < sz; ++i) {
        in >> tmp[i];
    }
    delete[] poly.p;
    poly.p = tmp;
    poly.n = sz;
    return in;
}

ostream& operator<<(ostream& out, const Polygon& poly) {
    out << poly.n << "\n";
    for (int i = 0; i < poly.n; ++i) {
        out << poly.p[i] << "\n";
    }
    out << "Perimeter: " << poly.perimeter() << "\n";
    out << "Area: " << poly.area() << "\n";
    out << "Longest diagonal: " << poly.longestDiagonal() << "\n";
    return out;
}