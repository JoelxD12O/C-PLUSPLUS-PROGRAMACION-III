
// Created by joel on 11/04/2025.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
using namespace std;
//T : parametro template con tipo
double r(){
    return (double)rand()/RAND_MAX;//conseguir numeros aleatorios de 0 y 1

};

//sera como la restriccion para aquellos test donde el no sea valido la multiplicacion, ejm(string * int)
template <typename T>
concept coeficiente = requires(T a, T b){
    {a*b};
};

//template con tipoo
//grado: parametro template sin tipo
template<int grado=2, coeficiente T=int>
struct Polinomio{
    T* coefs = new T[grado+1];//aca estaran todos los coeficientes
    T coef(){
        return rand()%100-50;//-50--> 50
    }
    //no necesita constructor
    void print(){
        T an=coef();
        while(an==0){
            an=coef();
        }
        cout<<an<<"x^"<<grado;
        coefs[grado]=an;
        for(int e=grado-1;e>=0;e--){
            an= coef();
            coefs[e]=an;
            if(an!=0){
                if(an>0)
                    cout<<"+";
                cout<<an;
                if(e!=0)
                    cout<<"x^"<<e;;
            }

        }
        cout<<endl;
    }
    T evaluate(int x0){
        T resultado= 0;
        for(int e=0;e<=grado;e++){
            resultado+=pow(x0,e)*coefs[e];

        }
        return resultado;

    }


};

template<template<typename> typename C, typename T>

void print_poly(C<T> cont){
    int grado=cont.size()-1;
    int e=grado;
    for(const T& elemento: cont){
        if(e!=grado){
          if (elemento>0)
            cout<<"+";
        }
    cout<<elemento;
    if(e>0)
      cout<<"x^"<<e;
    e--;
  }
  cout<<endl;
  grado--;


};
//otro metodo

/*
template<typename T>

void print_poly(T cont){
    int grado=cont.size()-1;
    int e=grado;
    for(const auto& elemento: cont){
        if(e!=grado){
          if (elemento>0)
            cout<<"+";
        }
    cout<<elemento;
    if(e>0)
      cout<<"x^"<<e;
    e--;
  }
  cout<<endl;
  grado--;


};*/

int main(){
    srand(time(NULL));

    vector<int> v1{3,2,7};
    vector<float> v2{0.1,-3.2, 1.1};
    list<float> l1{2.1,-2.2, 4.4, 4.1};

    print_poly(v1); // Resultado: 3x^2+2x^1+7
    print_poly(v2); // Resultado: 0.1x^2-3.2x^1+1.1
    print_poly(l1); // Resultado: 2.1x^3-2.2x^2+4.4x^1+4.1


}