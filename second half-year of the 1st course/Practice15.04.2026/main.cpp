#include <bits/stdc++.h>
using namespace std;

using db = double;
using ldb = long double;

ldb f1(ldb x) {
    return x * x * x;
}

ldb f2(ldb x) {
    return x * x - 5.0L;
}

ldb f3(ldb x) {
    return 1.0L / x;
}

ldb integral(ldb (*f)(ldb), ldb a, ldb b, int n) {
    ldb h = (b - a) / n;
    ldb sum = 0.0L;

    for (int i = 0; i < n; ++i) {
        ldb x = a + (i + 0.5L) * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    ldb a, b;
    int n;

    cin >> a >> b >> n;

    cout << integral(f1, a, b, n) << '\n';
    cout << integral(f2, a, b, n) << '\n';
    cout << integral(f3, a, b, n) << '\n';

    return 0;
}