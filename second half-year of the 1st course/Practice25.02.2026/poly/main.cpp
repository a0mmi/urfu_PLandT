#include "polynomial.hpp"
#include <iostream>
using namespace std;

int main() {
    cout << "Creating polynomial A(x) = x^2 + 2x + 1\n";
    Polynomial A(2);
    A.set_coef(0, 1);
    A.set_coef(1, 2);
    A.set_coef(2, 1);
    cout << "A(x) = " << A << endl;
    
    cout << "\nCreating polynomial B(x) = x + 1\n";
    Polynomial B(1);
    B.set_coef(0, 1);
    B.set_coef(1, 1);
    cout << "B(x) = " << B << endl;
    
    cout << "\nCreating polynomial C(x) = 2x^3 - 3x^2 + 4x - 5\n";
    Polynomial C(3);
    C.set_coef(0, -5);
    C.set_coef(1, 4);
    C.set_coef(2, -3);
    C.set_coef(3, 2);
    cout << "C(x) = " << C << endl;
    
    ll x = 2;
    cout << "\nEvaluating at x = " << x << ":\n";
    cout << "A(" << x << ") = " << A.eval(x) << endl;
    cout << "B(" << x << ") = " << B.eval(x) << endl;
    cout << "C(" << x << ") = " << C.eval(x) << endl;
    
    cout << "\nDerivatives:\n";
    Polynomial dA = A.derivative();
    cout << "A'(x) = " << dA << endl;
    cout << "A'(" << x << ") = " << dA.eval(x) << endl;
    
    Polynomial dC = C.derivative();
    cout << "C'(x) = " << dC << endl;
    cout << "C'(" << x << ") = " << dC.eval(x) << endl;
    
    cout << "\nArithmetic operations:\n";
    
    Polynomial sum = A + B;
    cout << "A(x) + B(x) = " << sum << endl;
    
    Polynomial diff = A - B;
    cout << "A(x) - B(x) = " << diff << endl;
    
    Polynomial product = A * B;
    cout << "A(x) * B(x) = " << product << endl;
    
    Polynomial product2 = B * C;
    cout << "B(x) * C(x) = " << product2 << endl;
    
    cout << "\nDivision with remainder:\n";
    try {
        Polynomial quotient = C / B;
        Polynomial remainder = C % B;
        
        cout << "C(x) / B(x) (quotient) = " << quotient << endl;
        cout << "C(x) % B(x) (remainder) = " << remainder << endl;
        
        Polynomial check = B * quotient + remainder;
        cout << "Check: B(x) * quotient + remainder = " << check << endl;
        cout << "C(x) = " << C << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\nCompound operations:\n";
    cout << "Compute D(x) = (A(x) * B(x) + C(x)) / B(x)\n";
    
    Polynomial temp = A * B + C;
    cout << "A(x) * B(x) + C(x) = " << temp << endl;
    
    Polynomial D = temp / B;
    cout << "D(x) = " << D << endl;
    
    cout << "Check: D(x) * B(x) = " << D * B << endl;
    cout << "A(x) * B(x) + C(x) = " << A * B + C << endl;
    
    cout << "\nValue of D(x) at x = 3: " << D.eval(3) << endl;
    
    return 0;
}