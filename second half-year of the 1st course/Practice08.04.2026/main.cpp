#include <bits/stdc++.h>
using namespace std;

// Задача 1: Полиномы

struct Term {
    int degree;
    double coeff;
    Term* next;

    Term(int d, double c, Term* n = nullptr)
        : degree(d), coeff(c), next(n) {}
};

Term* insertTerm(Term* head, int deg, double coef) {
    if (coef == 0.0) return head;

    if (head == nullptr || deg > head->degree) {
        return new Term(deg, coef, head);
    }

    Term* prev = nullptr;
    Term* curr = head;

    while (curr != nullptr && curr->degree > deg) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr && curr->degree == deg) {
        curr->coeff += coef;

        if (curr->coeff == 0.0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            delete curr;
        }
        return head;
    }

    Term* node = new Term(deg, coef, curr);
    if (prev) prev->next = node;
    else head = node;

    return head;
}

Term* addPolynomials(Term* p1, Term* p2) {
    Term* result = nullptr;

    for (Term* t = p1; t != nullptr; t = t->next)
        result = insertTerm(result, t->degree, t->coeff);

    for (Term* t = p2; t != nullptr; t = t->next)
        result = insertTerm(result, t->degree, t->coeff);

    return result;
}

Term* multiplyPolynomials(Term* p1, Term* p2) {
    Term* result = nullptr;

    for (Term* t1 = p1; t1 != nullptr; t1 = t1->next) {
        for (Term* t2 = p2; t2 != nullptr; t2 = t2->next) {
            result = insertTerm(result, t1->degree + t2->degree, t1->coeff * t2->coeff);
        }
    }

    return result;
}

void printPolynomial(Term* head) {
    if (!head) {
        cout << "0\n";
        return;
    }

    Term* curr = head;
    bool first = true;

    while (curr) {
        if (!first && curr->coeff > 0) cout << " + ";
        if (curr->coeff < 0) cout << " - ";

        double a = curr->coeff < 0 ? -curr->coeff : curr->coeff;

        if (curr->degree == 0) {
            cout << a;
        } else if (curr->degree == 1) {
            if (a != 1.0) cout << a << "*";
            cout << "x";
        } else {
            if (a != 1.0) cout << a << "*";
            cout << "x^" << curr->degree;
        }

        first = false;
        curr = curr->next;
    }
    cout << '\n';
}

void deletePolynomial(Term* head) {
    while (head) {
        Term* next = head->next;
        delete head;
        head = next;
    }
}

// Задача 2: Матрицы

struct MatrixElement {
    int row;
    int col;
    double value;
    MatrixElement* next;

    MatrixElement(int r, int c, double v, MatrixElement* n = nullptr)
        : row(r), col(c), value(v), next(n) {}
};

MatrixElement* insertElement(MatrixElement* head, int r, int c, double v) {
    if (v == 0.0) return head;

    if (head == nullptr ||
        r < head->row ||
        (r == head->row && c < head->col)) {
        return new MatrixElement(r, c, v, head);
    }

    MatrixElement* prev = nullptr;
    MatrixElement* curr = head;

    while (curr != nullptr &&
          (curr->row < r || (curr->row == r && curr->col < c))) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr && curr->row == r && curr->col == c) {
        curr->value += v;

        if (curr->value == 0.0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            delete curr;
        }
        return head;
    }

    MatrixElement* node = new MatrixElement(r, c, v, curr);
    if (prev) prev->next = node;
    else head = node;

    return head;
}

MatrixElement* addMatrices(MatrixElement* m1, MatrixElement* m2) {
    MatrixElement* result = nullptr;

    for (MatrixElement* e = m1; e != nullptr; e = e->next)
        result = insertElement(result, e->row, e->col, e->value);

    for (MatrixElement* e = m2; e != nullptr; e = e->next)
        result = insertElement(result, e->row, e->col, e->value);

    return result;
}

void printMatrix(MatrixElement* head) {
    if (!head) {
        cout << "Пустая матрица\n";
        return;
    }

    MatrixElement* curr = head;
    while (curr) {
        cout << "(" << curr->row << ", " << curr->col << ") = " << curr->value << '\n';
        curr = curr->next;
    }
}

void deleteMatrix(MatrixElement* head) {
    while (head) {
        MatrixElement* next = head->next;
        delete head;
        head = next;
    }
}


// Тесты
int main() {
    cout << "Polynomials:\n";

    Term* p1 = nullptr;
    p1 = insertTerm(p1, 4, 3);   // 3x^4
    p1 = insertTerm(p1, 2, -2);  // -2x^2
    p1 = insertTerm(p1, 0, 7);   // +7

    Term* p2 = nullptr;
    p2 = insertTerm(p2, 3, 1);   // x^3
    p2 = insertTerm(p2, 2, 2);   // +2x^2
    p2 = insertTerm(p2, 0, -7);  // -7

    cout << "P1 = ";
    printPolynomial(p1);

    cout << "P2 = ";
    printPolynomial(p2);

    Term* sumP = addPolynomials(p1, p2);
    cout << "P1 + P2 = ";
    printPolynomial(sumP);

    Term* mulP = multiplyPolynomials(p1, p2);
    cout << "P1 * P2 = ";
    printPolynomial(mulP);

    cout << "\nMatrix:\n";

    MatrixElement* m1 = nullptr;
    m1 = insertElement(m1, 0, 1, 5);
    m1 = insertElement(m1, 1, 0, 3);
    m1 = insertElement(m1, 2, 2, -1);

    MatrixElement* m2 = nullptr;
    m2 = insertElement(m2, 0, 1, 2);
    m2 = insertElement(m2, 1, 2, 4);
    m2 = insertElement(m2, 2, 2, 1);

    cout << "M1:\n";
    printMatrix(m1);

    cout << "M2:\n";
    printMatrix(m2);

    MatrixElement* sumM = addMatrices(m1, m2);
    cout << "M1 + M2:\n";
    printMatrix(sumM);

    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(sumP);
    deletePolynomial(mulP);

    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(sumM);

    return 0;
}