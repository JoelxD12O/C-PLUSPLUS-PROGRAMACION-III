#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    // Map ordenado con clave char y valor int
    map<char, int> mimapa = {{'X',1},{'B',3}};  // Inicialización
    mimapa['A'] = 2;    // Insertar nueva clave 'A'

    // Iterar y mostrar claves y valores
    for(auto it = mimapa.begin(); it != mimapa.end(); it++)
        cout << "clave: " << it->first << ", valor: " << it->second << endl;

    cout << "Otra forma: \n";

    mimapa['A'] = 5;    // Modificar valor de 'A'
    mimapa['X']++;      // Incrementar valor de 'X'

    for(auto par : mimapa)
        cout << "clave: " << par.first << ", valor: " << par.second << endl;

    // Buscar clave 'A'
    if (mimapa.find('A') == mimapa.end())
        cout << "No encontro la clave" << endl;
    else
        cout << "Encontro la clave!" << endl;

    // unordered_map (hash map) vacío
    unordered_map<char, int> mimapa2;

    // unordered_set elimina duplicados y no está ordenado
    unordered_set<int> s = {6,5,6,2,11,1,1,1,2};
    s.insert(8);  // Insertar elemento

    for(auto e : s)
        cout << e << ' ';
    cout << endl;

    // vector con elementos repetidos
    vector<int> v = {2,2,1,1,4,4};

    // set ordenado y sin duplicados
    set<int> s2(v.begin(), v.end());

    for(auto e : s2)
        cout << e << ' ';
    cout << endl;

    // unordered_map con algunos elementos
    unordered_map<char,int> hm;
    hm['A'] = 1;
    hm['C'] = 2;
    hm['G'] = 3;

    cout << "Max load factor: " << hm.max_load_factor() << endl;  // Factor máximo de carga
    cout << "Load factor: " << (float)hm.size() / hm.bucket_count() << endl;  // Carga actual

    return 0;
}

/*====================TEORIA====================
* unordered_map<char,int> hm
// Estructura de datos basada en tabla hash para almacenar pares clave-valor.
// - Clave: un carácter (char).
// - Valor: un entero (int).

* hm.max_load_factor()
// Retorna el factor máximo de carga permitido antes de que la tabla hash se redimensione.
// Indica cuántos elementos promedio puede tener cada cubeta antes de hacer rehash.
// Ejemplo: un valor típico es 1.0.

* hm.load_factor() o (float)hm.size() / hm.bucket_count()
// Factor de carga actual: cantidad promedio de elementos por cubeta.
// Se calcula dividiendo el número de elementos almacenados (size) entre el número de cubetas (bucket_count).
// Si este valor se acerca o supera al max_load_factor, la tabla hash se redimensiona para mantener eficiencia.

// Mantener el factor de carga bajo mejora la velocidad de acceso pero usa más memoria.
================================================*/
