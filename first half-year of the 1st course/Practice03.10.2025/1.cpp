#include<bits/stdc++.h>
using namespace std;

#define forn(i, l, r) for(int i = l; i < r; ++i)
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using db = double;
using vdb = vector<double>;

struct Vec {
    db x{}, y{};
    Vec() = default;
    Vec(db _x, db _y): x(_x), y(_y) {}
    Vec operator+ (const Vec& o) const {
        return {x + o.x, y + o.y};
    }
    Vec operator- (const Vec& o) const {
        return {x - o.x, y - o.y};
    }
    Vec operator* (db k) const {
        return {x * k, y * k};
    }
    Vec operator/ (db k) const {
        return {x / k, y / k};
    }
    bool operator== (const Vec& o) const {
        return x == o.x && y == o.y;
    }
    friend ostream& operator<<(ostream& os, const Vec& v) { 
        return os << v.x << " " << v.y;
    }

    db dot(const Vec& o) const { // скалярное произведение
        return x*o.x + y*o.y;
    }
    db cross(const Vec& o) const {
        return x*o.y - y*o.x;
    }
    db norm2() const {
        return x*x + y*y;
    }
    db len() const {
        return sqrt(norm2());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Vec p[3];
    cin>>p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;

    forn(i, 0, 3) {
        Vec A = p[i], B = p[(i + 1) % 3], C = p[(i + 2) % 3];
        Vec AB = B - A, AC = C - A;
        if(AB.dot(AC) == 0 && AB.norm2() == AC.norm2() && AB.norm2() > 0){
            Vec D = B + C - A;
            cout << "YES\n" << D;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}