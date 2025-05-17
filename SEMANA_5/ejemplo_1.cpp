#include <iostream>
#include <cmath>
using namespace std;

// Función cúbica: F1(x) = 3x³ + x
double F1(double x) {
    return 3*x*x*x + x;
}

// Función logarítmica: F2(x, y) = log(x), y no se usa
double F2(double x, int y) {
    return log(x);
}

// Estructura con función que evalúa F(x)
struct A {
    double G(double (*F)(double), double x) {
        return F(x);
    }
};

// Versión más flexible de la derivada numérica
template<typename Func>
double dF(Func F, double x) {
    double h = 1e-6;
    return (F(x + h) - F(x)) / h;
}

int main() {
    // Derivada de F1 en x = 2 → F1(x) = 3x^3 + x → F1'(x) = 9x^2 + 1
    cout << "Derivada de F1 en x = 2: " << dF(F1, 2) << endl;

    // Adaptamos F2 (que tiene 2 parámetros) como lambda con y = 0
    auto F2_fixed = [](double x) { return F2(x, 0); };

    // Derivada de F2 (log(x)) en x = 2 → F2'(x) = 1/x
    cout << "Derivada de F2 (con y = 0) en x = 2: " << dF(F2_fixed, 2) << endl;

    return 0;
}
