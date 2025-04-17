//
// Created by joel on 16/04/2025.
//

#include <iostream>
#include <vector>
using namespace std;


template<typename T>

struct Vec{
  vector<T> datos;
  template<typename... Ts>
  void push_back_many(Ts... args){
    (datos.push_back(args), ...);
  }
  void print(){
    for(const  T& e: datos)
      cout<<e<<" ";
    cout<<endl;

  }
};


int main(){
Vec<int> vec;
vec.push_back_many(1);
vec.push_back_many(2);
vec.print();					// 1 2
vec.push_back_many(3,4,5);
vec.print();					// 1 2 3 4 5
}
