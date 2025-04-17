//
// Created by joel on 10/04/2025.
//

#include <iostream>
#include <vector>
using namespace std;


struct Foo{};


template<typename T>
concept imprimible= requires(ostream& os, T dato)
{
  {
    os<<dato
  };

};//crear restriccion

template<imprimible T>//usar restriccion

void print (T dato){
  cout<<dato<<endl;
}


int main(){

  print(10);
  print("Hola");
  print (9.3);
  print('x');
  return 0;

}