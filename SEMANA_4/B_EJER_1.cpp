//
// Created by joel on 16/04/2025.
//
#include <iostream>
using namespace std;
// ...args : pack de parametros, es una unidad
//args... : los parametros separados
//args op ... -> (al op (a2 op)(...(a_{n-1} op a_n....))
//args + ... -> (a1 + (a2 + (...+ a_n)
//args - ... -> (a1 -(a2 -(a3- ...(a{n-1}-a))))=a1-a2+a3-4


template <typename ...Ts>
auto f(Ts ...args){
  return ((args * args) + ...);  // Elevar cada argumento al cuadrado y luego sumarlos
}

int main(){
  cout << f(4.4, 5.6) << endl;  // Resultado de 4.4^2 + 5.6^2
  cout << f(7.1) << endl;        // Resultado de 7.1^2
  cout << f(6, 3, 12, 1) << endl;  // Resultado de 6^2 + 3^2 + 12^2 + 1^2
  return 0;
}