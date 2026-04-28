#include "PointV.hpp"

using namespace std;

PointV::PointV() {
    x = 0;
    y = 0;
}

PointV::PointV(double x, double y) {
    this->x = x;
    this->y = y;
}

double PointV::getX() const {
    return x;
}

double PointV::getY() const {
    return y;
}

void PointV::setX(double x) {
    this->x = x;
}

void PointV::setY(double y) {
    this->y = y;
}

double PointV::len() const {
    return sqrt(x * x + y * y);
}

double PointV::cross(const PointV& other) const {
    return x * other.y - y * other.x;
}

PointV& PointV::operator+=(const PointV& other) {
    x += other.x;
    y += other.y;
    return *this;
}

PointV& PointV::operator-=(const PointV& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

PointV& PointV::operator*=(double k) {
    x *= k;
    y *= k;
    return *this;
}

PointV& PointV::operator/=(double k) {
    x /= k;
    y /= k;
    return *this;
}

PointV& PointV::operator+=(double k) {
    x += k;
    y += k;
    return *this;
}

PointV& PointV::operator-=(double k) {
    x -= k;
    y -= k;
    return *this;
}

PointV operator+(PointV u, const PointV& v) { u += v; return u; }

PointV operator-(PointV u, const PointV& v) {u -= v; return u; }

PointV operator-(double k, const PointV& v) {
    return PointV(k - v.getX(), k - v.getY());
}

PointV operator+(double k, const PointV& v) {
    return PointV(k + v.getX(), k + v.getY());
}

PointV operator/(double k, const PointV& v) {
    return PointV(k / v.getX(), k / v.getY());
}

PointV operator*(double k, const PointV& v) {
    return PointV(k * v.getX(), k * v.getY());
}

PointV operator-(const PointV& v, double k) {
    return PointV(v.getX() - k, v.getY() - k);
}

PointV operator+(const PointV& v, double k) {
    return PointV(v.getX() + k, v.getY() + k);
}

PointV operator/(const PointV& v, double k) {
    return PointV(v.getX() / k, v.getY() / k);
}

PointV operator*(const PointV& v, double k) {
    return PointV(v.getX() * k, v.getY() * k);
}

istream& operator>>(std::istream& in, PointV& v) {
    in >> v.x >> v.y;
    return in;
}

ostream& operator<<(std::ostream& out, const PointV& v) {
    out << v.x << " " << v.y;
    return out;
}