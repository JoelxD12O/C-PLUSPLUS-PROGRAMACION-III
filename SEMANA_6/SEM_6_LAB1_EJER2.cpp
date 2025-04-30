//
// Created by alumno08 on 29/04/2025.
//
#include <iostream>
#include <forward_list>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()
#include <cmath>
#include <iostream>
using namespace std;


template<typename T>
void print(T inicio, T fin) {
  for (auto it = inicio; it != fin; ++it) {
    cout << *it << ' ';
  }
  cout << endl;
}



bool esPrimo(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

using namespace std;
int main(){

  // 1. Crear forward_list con 100 números aleatorios <100
  forward_list<int> lista;
  srand(time(0)); // Semilla para números aleatorios

  for(int i = 0; i < 100; ++i) {
    lista.push_front(rand() % 100); // Inserta al frente (más eficiente)
  }

    print(lista.begin(), lista.end());
  cout << endl;
  // 3. Eliminar números pares
  cout<<"eliminamos a los pares"<<endl;
  lista.remove_if([](int n) { return n % 2 == 0; });

  print(lista.begin(), lista.end());
  cout<<"ordenamos la lista de forma ascendente"<<endl;
  // 5. Ordenar lista (ascendente)
  lista.sort();
  print(lista.begin(), lista.end());


  int contadorPrimos = 0;
  for (int num : lista) {
    if (esPrimo(num)) {
      contadorPrimos++;
    }
  }

  cout << "Cantidad de numeros primos generados: " << contadorPrimos << endl;


  return 0;
};