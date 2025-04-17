//
// Created by joel on 16/04/2025.
//
#include <iostream>
#include <cmath>
using namespace std;

template<typename... Ts>
double norma2(Ts... args){
    return sqrt(((args * args) + ...));  // Expansión de parámetros variadic: suma de los cuadrados de los valores
}

int main(){
    cout << norma2(3.3, 4.4) << endl;   // Llamada con dos parámetros
    cout << norma2(-1, 23.4, 0.11, -9.8, 10) << endl;   // Llamada con varios parámetros
    return 0;
}
/*
Para norma2(3.3, 4.4):
Calcula: sqrt(3.3^2 + 4.4^2) = sqrt(10.89 + 19.36) = sqrt(30.25) = 5.5
El resultado sería: 5.5.

Para norma2(-1, 23.4, 0.11, -9.8, 10):
Calcula: sqrt((-1)^2 + 23.4^2 + 0.11^2 + (-9.8)^2 + 10^2)
Lo cual es igual a: sqrt(1 + 547.56 + 0.0121 + 96.04 + 100) = sqrt(744.6221)
El resultado sería: 27.28 (aproximadamente).
*/