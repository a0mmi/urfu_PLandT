#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class Line {
    private:
        double A, B, C;  // Ax + By + C = 0
        double EPS = 1e-12;

    public:
        Line() {
            A = 0.0; B = 0.0; C = 0.0;
        }
        Line(double a, double b, double c) {
            A = a; B = b; C = c;
        }

        bool isDegenerate() const {
            return fabs(A) < EPS && fabs(B) < EPS;
        }

        bool isParallelTo(const Line& other) const {
            // (A,B) и (other.A, other.B) коллинеарны
            return fabs(A * other.B - other.A * B) < EPS;
        }

        bool isCoincidentWith(const Line& other) const {
            if (!isParallelTo(other)) {
                return false;
            }
            return fabs(A * other.C - other.A * C) < EPS &&
                fabs(B * other.C - other.B * C) < EPS;
        }

        enum class Relation {
            DEGENERATE,
            PARALLEL,
            COINCIDENT,
            INTERSECT
        };

        Relation getRelationWith(const Line& other, double& x, double& y) const {
            x = y = NAN;

            if (isDegenerate() || other.isDegenerate()) {
                return Relation::DEGENERATE;
            }

            double det = A * other.B - other.A * B;

            if (fabs(det) < EPS) {
                return isCoincidentWith(other) ? Relation::COINCIDENT : Relation::PARALLEL;
            }

            // x = (B1*C2 - B2*C1) / D
            // y = (C1*A2 - C2*A1) / D
            x = (B * other.C - other.B * C) / det;
            y = (C * other.A - other.C * A) / det;

            return Relation::INTERSECT;
        }

        friend istream& operator>>(istream& is, Line& line) {
            is >> line.A >> line.B >> line.C;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Line& line) {
            os << line.A << "x";
            if (line.B >= 0) os << " + ";
            else os << " - ";
            os << fabs(line.B) << "y";
            if (line.C >= 0) os << " + ";
            else os << " - ";
            os << fabs(line.C) << " = 0";
            return os;
        }
};

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; ++test) {
        Line l1, l2;
        cin >> l1 >> l2;

        double x, y;
        auto relation = l1.getRelationWith(l2, x, y);

        cout << "\nTest #" << test << ":\n";
        cout << "  Line 1: " << l1 << '\n';
        cout << "  Line 2: " << l2 << '\n';

        switch (relation) {
            case Line::Relation::DEGENERATE:
                cout << "DEGENERATE\n"; // одна или обе прямые вырожденные (точка или пустое множество)
                break;

            case Line::Relation::PARALLEL:
                cout << "PARALLEL\n"; // ПАРАЛЛЕЛЬНЫ, НЕ СОВПАДАЮТ (нет общих точек)
                break;

            case Line::Relation::COINCIDENT:
                cout << "COINCIDENT\n"; // СОВПАДАЮТ (бесконечно много общих точек)
                break;

            case Line::Relation::INTERSECT:
                cout << "INTERSECT: (" << x << ", " << y << ")\n";
                break;
        }
    }
    return 0;
}