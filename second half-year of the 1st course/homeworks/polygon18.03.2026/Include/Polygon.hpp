#pragma once

#include "PointV.hpp"
#include <iostream>

class Polygon {
private:
    PointV* p;
    int n;

    double cross(const PointV& a, const PointV& b, const PointV& c) const;
    double dist(const PointV& a, const PointV& b) const;

public:
    Polygon();
    Polygon(int sz, const PointV* arr);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    ~Polygon();

    int size() const;
    bool isConvex(const double EPS = 1e-9) const;
    double perimeter() const;
    double area() const;
    double longestDiagonal() const;

    friend std::istream& operator>>(std::istream& in, Polygon& poly);
    friend std::ostream& operator<<(std::ostream& out, const Polygon& poly);
};
