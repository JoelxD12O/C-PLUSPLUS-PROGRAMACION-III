//
// Created by joel on 10/04/2025.
//

#include <iostream>
using namespace std;
template<typename T>
//clase plantilla
class pointer{
  template<typename Q>
  friend ostream& operator<<(ostream& os, const pointer<Q>& p);
private:
    T* ptr;//puntero que almacenara la direccion de memoria de un objeto de tipo T
  public:
      pointer(T* dir):ptr(dir){}//recibe una direccion de memoria dir y le asigna a ptr
      ~pointer(){delete ptr;}//el destructor elimina la memoria apuntada por ptr usando delete ptr
      T operator*() const{return *ptr;}//(desreferenciacion), cuando se utiliza *ptr1, en realidad se invoca
      // este operador y devuelve
      // el valor apuntado por ptr1

};

template<typename T>
ostream& operator<<(ostream& os, const pointer<T>& p){
  os<<p.ptr;
  return os;
}

int main(){
  pointer<int> ptr1(new int(5));//int ptr1=new int(5)
  cout<<*ptr1<<endl;
  cout<<ptr1<<endl;
}