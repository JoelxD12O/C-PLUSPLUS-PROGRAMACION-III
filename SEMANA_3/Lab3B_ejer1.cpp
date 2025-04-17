//
// Created by joel on 11/04/2025.
//
#include <iostream>
#include <cmath>
using namespace std;



//template sin tipoo
template<int grado>
struct Polinomio{
  int* coefs = new int[grado+1];//aca estaran todos los coeficientes
  int coef(){
    return rand()%100-50;//-50--> 50
  }
  //no necesita constructor
  void print(){
    int an=coef();
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
  int evaluate(int x0){
    int resultado= 0;
    for(int e=0;e<=grado;e++){
		resultado+=pow(x0,e)*coefs[e];

    }
    return resultado;

  }


};


int main(){
srand(time(NULL));
  Polinomio<4> pol1;
  pol1.print();
  cout<<pol1.evaluate(1)<<endl;

  Polinomio<2> pol2;
  pol2.print();
  cout<<pol2.evaluate(4)<<endl;
};