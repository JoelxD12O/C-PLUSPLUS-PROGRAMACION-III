//
// Created by joel on 10/04/2025.
//
//
// Created by joel on 10/04/2025.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
concept sumable= requires(T a, T b){
  {a+b};
};

template<sumable T, sumable Q>
auto sumar(T a, Q b){
  return a+b;
}
auto sumar(string a, int b){
  return a+ (char)(b);
}
int main(){
//debido a que a veces el tipo de dato de suma es string y int no nos da error, lo cual deberia
//por eso usamos el concept, seria como una restriccion.

cout<<sumar(6,-4)<<endl;
cout<<sumar(6.31,-4.22)<<endl;
cout<<sumar('B', 2)<<endl;
cout<<sumar("C++",3)<<endl;
return 0;
};