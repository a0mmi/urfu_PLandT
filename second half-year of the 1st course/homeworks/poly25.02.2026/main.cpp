#include "polynomial.hpp"
#include <iostream>
#include <exception>

using namespace std;

int main() {
    cout << "Input format: <degree> <a0> <a1> ... <a_degree>\n";
    cout << "The polynomial is a0 + a1*x + ... + a_degree*x^degree\n\n";

    Polynomial P, Q;

    cout << "Enter the first polynomial P(x): ";
    cin >> P;

    cout << "Enter the second polynomial Q(x): ";
    cin >> Q;

    // Вывожу считанные многочлены в компактном формате (degree coeff0 coeff1 ...)
    cout << "\nPolynomials (compact format: degree coeff0 coeff1 ...):\n";
    cout << "P(x) = " << P << '\n';
    cout << "Q(x) = " << Q << '\n';

    // Выполняю сложение
    Polynomial sum = P + Q;
    cout << "\nP(x) + Q(x) = " << sum << '\n';

    // Выполняю вычитание
    Polynomial diff = P - Q;
    cout << "P(x) - Q(x) = " << diff << '\n';

    // Выполняю умножение
    Polynomial prod = P * Q;
    cout << "P(x) * Q(x) = " << prod << '\n';

    // Деление и вычисление остатка. Использую try/catch на случай деления на нулевой многочлен.
    try {
        // Частное P / Q
        Polynomial quot = P / Q;
        // Остаток P % Q
        Polynomial rem = P % Q;
        cout << "\nP(x) / Q(x) (quotient) = " << quot << '\n';
        cout << "P(x) % Q(x) (remainder) = " << rem << '\n';

        // Проверка корректности: Q * quot + rem должно равняться исходному P
        Polynomial check = Q * quot + rem;
        cout << "Check: Q(x) * (quotient) + (remainder) = " << check << '\n';
        cout << "Original P(x) = " << P << '\n';
    } catch (const exception& e) {
        // В случае ошибки
        cout << "\nError during division: " << e.what() << '\n';
    }

    // Производная первого многочлена P
    Polynomial dP = P.derivative();
    cout << "\nDerivative of the first polynomial P'(x) = " << dP << '\n';

    // Запрос значения x для вычисления производной в точке (для первого многочлена)
    cout << "\nEnter integer x at which to evaluate P'(x): ";
    long long x;
    cin >> x;

    // Вывод значения производной в точке x
    cout << "P'(" << x << ") = " << dP.eval(x) << '\n';

    cout << "\nAll operations demonstrated.\n";
    return 0;
}