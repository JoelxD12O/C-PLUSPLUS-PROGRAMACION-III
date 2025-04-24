//
// Created by joel on 16/04/2025.
//
#include <iostream>
#include <vector>
using namespace std;
//templade generico
template <typename T>
T Max(const vector<T>& v) {
    T max = v[0];  // Iniciar max con el primer valor del vector
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];  // Actualizar max si se encuentra un valor mayor
        }
    }
    return max;
}
//especializado para strings
template<>
string Max(const vector<string>& v) {
  string max = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i].length() > max.length()) { //cantidad de caracteres
      max=v[i];
    }
    return max;
  }
}
int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<double> v2 = {3.8, 0.1, -2.3, 8};
    vector<string> v3 = {"Hola", "Mundo", "en", "C++"};

    cout << Max(v1) << endl;  // Salida: 5
    cout << Max(v2) << endl;  // Salida: 8
    cout << Max(v3) << endl;  // Salida: Mundo (ya que "Mundo" es alfabéticamente mayor que los otros)

    return 0;
}