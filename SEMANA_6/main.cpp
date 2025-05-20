#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void minuscula(string& s) {
    for(char& c: s)
        c = tolower(c);
}

template<typename T>
auto moda(T it_begin, T it_end) {
    T it_max = it_begin;
    for(auto it=it_begin; it!=it_end; it++) {
        if (it->second > it_max->second)  // comparando valores
            it_max = it;
    }
    return it_max->first;  // retornamos la clave (moda)
}

bool es_compuesto(int x) {
    // retorna true si 'x' es un compuesto, y false si 'x' es primo
    // si 'x' es primo, entonces solo se divide entre 1 y 'x'
    // si 'x' es primo, los números 2,3,4,...,'x-1' no dividen a 'x'
    if (x == 1)
        return true; // el 1 no es primo
    for(int d=2; d < x; d++) {
        if (x % d == 0)
            return true;  // 'x' no es primo, es compuesto
    }
    return false;         // 'x' es primo
}
int main() {
    srand(time(0));
    list<int> lista;
    for (int i = 1; i <= 100; i++) {
        lista.push_back(rand()%50+1);
    }
    lista.remove_if(es_compuesto);
    for(int e: lista)
        cout << e << " ";
    cout << endl;
    set<int> primos(lista.begin(), lista.end());
    cout << "Primos: ";
    for(int e: primos)
        cout << e << " ";
    cout << endl;
    cout << "Minimo: " << *primos.begin() << endl;
    cout << "Maximo: " << *primos.rbegin() << endl;
    /*
    vector<int> v(100);
    generate(v.begin(), v.end(), [](){return rand()%20+1;});
    for(int e: v)
        cout << e << ' ';
    cout << endl;

    unordered_map<int,int> contador;
    for(int e: v)
        contador[e]++;
    for(auto e: contador)
        cout << e.first << " -> " << e.second << " rep."<< endl;
    cout << "Moda: " << moda(contador.begin(), contador.end()) << endl;
    */
    /*
    string palabra;
    map<string, int> contador;
    while (getline(cin, palabra)) {
        if (palabra.length() == 0)
            break;
        minuscula(palabra);
        cout << "Palabra ingresada: <" << palabra << '>'<< endl;
        if (contador.find(palabra) == contador.end())
            contador[palabra] = 1;
        else
            contador[palabra]++;
    }

    for (auto par: contador)
        cout << par.first << " : " << par.second << " rep."<< endl;
    */
    /*
    map<char, int> mimapa = {{'X',1},{'B',3}};
    mimapa['A'] = 2;    // creando un nueva clave 'A' con valor 2

    for(auto it=mimapa.begin(); it!=mimapa.end(); it++)
        cout << "clave: " << it->first << ", valor: " << it->second << endl;
    cout << "Otra forma: \n";
    mimapa['A'] = 5;    // modificar el valor de la clave 'A'
    mimapa['X']++;
    for(auto par: mimapa)
        cout << "clave: " << par.first << ", valor: " << par.second << endl;
    if (mimapa.find('A') == mimapa.end())
        cout << "No encontro la clave" << endl;
    else
        cout << "Encontro la clave!" << endl;

    unordered_map<char, int> mimapa2;

    unordered_set<int> s = {6,5,6,2,11,1,1,1,2};
    s.insert(8);
    for(auto e: s)
        cout << e << ' ';
    cout << endl;
    vector<int> v = {2,2,1,1,4,4};
    set<int> s2(v.begin(), v.end());
    for(auto e: s2)
        cout << e << ' ';
    cout << endl;

    unordered_map<char,int> hm;
    hm['A']=1;
    hm['C']=2;
    hm['G']=3;
    cout << hm.max_load_factor() << endl;
    cout << (float)hm.size()/hm.bucket_count() << endl;
    return 0;
    */
}
