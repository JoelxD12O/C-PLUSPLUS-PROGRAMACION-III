//
// Created by joel on 16/04/2025.
//
//para una secuencia de numeros x1,x2,x3,...,xn
//M. aritmetica: mA=(x1+x2+x3+x4+...+xn)/n
//M. geometrica: mG=(x1*x2+x3+x4+...x)**(1/n)
//M. armonica:   mH=n/(1/x1+1/x2+1/x3+...1/xn)
#include <iostream>
#include <cmath>
using namespace std;

template <typename... Ts>
double mA(Ts... args){
return (args+...)/sizeof...(args);}

template<typename... Ts>
double mG(Ts... args){
  double ln_mG=(1/sizeof...(args))*(log(args)+...);
  return exp(ln_mG);//e**(log(mG))=mG
}
template<typename... Ts>
double mH(Ts... args) {
  // Sumar los parámetros usando expansión de parámetros
  // Dividir la cantidad de parámetros entre la suma de los parámetros elevados a la potencia de -1
  return (double)sizeof...(args) / (pow(args, -1)+...);
}



int main() {
  cout << mA(5.5, 24.12, 6, 19, 18, 1.9, 3.4) << endl;  // Llamada a mA
  cout << mG(5.5, 24.12, 6, 19, 18, 1.9, 3.4) << endl;  // Llamada a mG
  cout << mH(5.5, 24.12, 6, 19, 18, 1.9, 3.4) << endl;  // Llamada a mH
  return 0;
}