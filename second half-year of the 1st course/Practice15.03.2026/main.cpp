#include <bits/stdc++.h>
using namespace std;

using db = double;
using ldb = long db;

#define ПРАВОСЛАВНЫЙ_ЦИКЛ(i, st, en) for(int i = st; i < en; ++i)

ldb f1(ldb x) {
    return x * x * x;
}

ldb f2(ldb x) {
    return x * x - 5.0L;
}

ldb f3(ldb x) {
    return 1.0L / x;
}

ldb Integral(ldb (*f)(ldb), ldb a, ldb b, int n) { // точность n
    ldb h = (b - a) / n;
    ldb sum = 0.0L;

    ПРАВОСЛАВНЫЙ_ЦИКЛ(i, 0, n) {
        ldb x = a + (i + 0.5L) * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    ldb a, b;
    int type, n;

    cin >> a >> b >> n;

    cout << Integral(f1, a, b, n) << '\n';
    cout << Integral(f2, a, b, n) << '\n';
    cout << Integral(f3, a, b, n) << '\n';
    return 0;
}