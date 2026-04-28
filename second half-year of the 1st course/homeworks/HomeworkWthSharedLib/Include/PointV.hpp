#pragma once

#include <bits/stdc++.h>

class PointV {
private:
    double x;
    double y;

public:
    PointV();
    PointV(double x, double y);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    double len() const;
    double cross(const PointV& other) const;

    PointV& operator+=(const PointV& other);
    PointV& operator-=(const PointV& other);

    PointV& operator*=(double k);
    PointV& operator/=(double k);
    PointV& operator+=(double k);
    PointV& operator-=(double k);

    friend PointV operator+(PointV u, const PointV& v);
    friend PointV operator-(PointV u, const PointV& v);

    friend PointV operator-(double k, const PointV& v);
    friend PointV operator+(double k, const PointV& v);
    friend PointV operator/(double k, const PointV& v);
    friend PointV operator*(double k, const PointV& v);

    friend PointV operator-(const PointV& v, double k);
    friend PointV operator+(const PointV& v, double k);
    friend PointV operator/(const PointV& v, double k);
    friend PointV operator*(const PointV& v, double k);

    friend std::istream& operator>>(std::istream& in, PointV& v);
    friend std::ostream& operator<<(std::ostream& out, const PointV& v);
};