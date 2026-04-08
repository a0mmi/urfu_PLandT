#include "gvector.hpp"

using namespace std;

gvector::gvector() {
    v = nullptr;
    n = 0;
}

gvector::gvector(int size) {
    n = size;
    v = new float[n]{};
}

gvector::gvector(const gvector& other) {
    n = other.n;
    v = new float[n];
    for (int i = 0; i < n; i++) v[i] = other.v[i];
}

gvector::gvector(gvector&& other) {
    v = other.v;
    n = other.n;
    other.v = nullptr;
    other.n = 0;
}

gvector& gvector::operator=(gvector other) {
    swap(*this, other);
    return *this;
}

gvector::~gvector() {
    delete[] v;
}

void gvector::Init(int size) {
    delete[] v;
    n = size;
    v = new float[n]{};
}

void gvector::Read() {
    for (int i = 0; i < n; i++) cin >> v[i];
}

void gvector::Display() const {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

string gvector::toString() const {
    stringstream ss;
    for (int i = 0; i < n; i++) ss << v[i] << " ";
    return ss.str();
}

int gvector::size() const {
    return n;
}

float& gvector::operator[](int i) {
    return v[i];
}

const float& gvector::operator[](int i) const {
    return v[i];
}

gvector& gvector::operator+=(const gvector& other) {
    if (n != other.n) throw invalid_argument("gvector +=: sizes do not match");
    for (int i = 0; i < n; i++) v[i] += other.v[i];
    return *this;
}

gvector& gvector::operator-=(const gvector& other) {
    if (n != other.n) throw invalid_argument("gvector -=: sizes do not match");
    for (int i = 0; i < n; i++) v[i] -= other.v[i];
    return *this;
}

gvector operator+(gvector a, const gvector& b) {
    return a += b;
}

gvector operator-(gvector a, const gvector& b) {
    return a -= b;
}

istream& operator>>(istream& in, gvector& vec) {
    for (int i = 0; i < vec.n; i++) in >> vec.v[i];
    return in;
}

ostream& operator<<(ostream& out, const gvector& vec) {
    for (int i = 0; i < vec.n; i++) out << vec.v[i] << " ";
    return out;
}