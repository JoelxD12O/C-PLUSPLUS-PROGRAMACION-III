#include <iostream>
#include <stack>
#include <vector>
using namespace std;


string validar(const vector<vector<int>>& torres) {
    for (const auto& torre : torres) {
        if (!torre.empty()) {
            int top_prev = -1;
            for (int i = torre.size() - 1; i >= 0; --i) { // Recorre de arriba hacia abajo (simulando stack)
                int top = torre[i];
                if (top <= top_prev) {
                    cout << "top: " << top << ", top_prev: " << top_prev << endl;
                    return "Configuracion incorrecta!";
                }
                top_prev = top;
            }
        }
    }
    return "Configuracion correcta!";
}





int main() {
    vector<vector<int>> torres(3); // 3 torres

    // Agregar discos a las torres (configuración de ejemplo)
    torres[0].push_back(3);  // Torre 1: Disco con radio 3
    torres[0].push_back(2);
    torres[0].push_back(1);
    cout << validar(torres) << endl; // Salida: Configuracion correcta!

    torres[1].push_back(4);  // Torre 2: Disco con radio 4
    torres[1].push_back(5);  // Esto rompe la regla (5 > 4, pero está encima)
    cout << validar(torres) << endl; // Salida: Configuracion incorrecta!

    return 0;
}
