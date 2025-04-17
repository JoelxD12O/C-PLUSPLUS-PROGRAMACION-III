//
// Created by joel on 11/04/2025.
//
#include <iostream>
#include <cmath>
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


int main(){
    srand(time(NULL));

    Polinomio<4,double> pol3;
    pol3.print();
    cout<<"pol3(1)= "<<pol3.evaluate(1)<<endl;



    Polinomio<4> pol1;
    pol1.print();
    cout<<"pol1(1)= "<<pol1.evaluate(1)<<endl;

    Polinomio pol2;
    pol2.print();
    cout<<"pol2(4)= "<<pol2.evaluate(4)<<endl;
};

//error de cascada cuando usas un string en lugar de un int,float...
//ejm
//Polinomio <3,string>pol4;
