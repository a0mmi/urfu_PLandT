#include <bits/stdc++.h>
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
using bl = bool;
using vdb = vector<db>;

bool fits_pair(db p, db q, db A, db B) {
    const db PI = acos(-1.0);
    const db eps = 1e-12;
    if ((p <= A + eps && q <= B + eps) || (p <= B + eps && q <= A + eps)) return true;
    int steps = 10000;
    forn(i, 0, steps + 1) {
        db t = (PI / 2) * i / steps;
        db w1 = p * cos(t) + q * sin(t);
        db w2 = p * sin(t) + q * cos(t);
        if (w1 <= A + 1e-9 && w2 <= B + 1e-9) return true;
    }
    return false;
}
/*
w1(t) = p * cos(t) + q * sin(t) — ширина проекции по одной оси
w2(t) = p * sin(t) + q * cos(t) — по другой оси

Если существует угол t такой, что одновременно w1(t) ≤ A и w2(t) ≤ B (или наоборот w1 ≤ B и w2 ≤ A),
то грань помещается в отверстие при повороте на t.

Быстрая проверка: если p ≤ A и q ≤ B (или в swapped варианте p ≤ B и q ≤ A) — помещается без поворота.

Иначе — пробует множество углов t от 0 до π/2 (в коде — равномерно steps = 10000 шагов).
Для каждого t вычисляет w1, w2 и проверяет условие w1 ≤ A && w2 ≤ B. Если для какого-то шага условие выполняется — возвращает true.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    db x,y,z,a,b;
    cin >> x >> y >> z >> a >> b;

    bl ok = false;
    ok = ok || fits_pair(x, y, a, b);
    ok = ok || fits_pair(x, z, a, b);
    ok = ok || fits_pair(y, z, a, b);
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}
