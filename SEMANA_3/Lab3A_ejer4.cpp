//
// Created by joel on 10/04/2025.
//
#include <iostream>
#include <vector>
using namespace std;


double r(){
  return (double)rand()/RAND_MAX;//genera un numero aleatorio entre 0 y 1
}
template<typename T>
struct range{
  int N;//cantidad de numero aleatorios generados
  T a,b;//limite inferior y superior
  range(int cantidad, T lim1, T lim2):N(cantidad),a(lim1),b(lim2){}
  void generar(){
    for(int i=0;i<N;i++){
      T numero= a+(b-a)*r();//genera un numero aleatorio entre a y b
      cout<<numero <<' ';
    }
    cout<<endl;
  }

};
int main(){
  srand(time(NULL));
  range<int> r1(5,-4,9);
  r1.generar();

  range<double> r2(5,9.3,10);
  r2.generar();




}