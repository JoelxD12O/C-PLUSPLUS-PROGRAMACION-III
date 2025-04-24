//
// Created by joel on 16/04/2025.
//
#include <iostream>
using namespace std;
/*
//<condicion> ? <instruccion1 : instruccion 2>
//<condicion> es una expresion booleana(true/false)
<instruccion1>se ejecuta si <condicion> es verdadera
<instruccion2>se ejecuta si <condicion> es falsa

 */
template<typename T, typename... Ts>
double maximo(T x1, Ts... pack){
    T max = x1;
    ((pack > max? max=pack: max=max), ... );  // Expansión de parámetros variadic
    return max;
}

int main(){
    cout << maximo(6.9, 1) << endl;            // Llamada con dos parámetros
    cout << maximo(-5.7, 88.9, -99) << endl;   // Llamada con tres parámetros
    cout << maximo(9.008, 0.001, 0.78, 4) << endl;  // Llamada con cuatro parámetros
    return 0;
}
