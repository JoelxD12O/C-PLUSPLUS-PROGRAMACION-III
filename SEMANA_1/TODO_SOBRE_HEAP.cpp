//
// Created by joel on 28/03/2025.
//
/*EL HEAP ES UNA REGION DE LA MEMORIA RAM USADA PARA ASIGNACION DINAMICA DE MEMORIA ES ADMINISTRADO
 *POR EL SISTEMA OPERATIVO Y PERMITE RESERVAR Y LIBERAR MEMORIA NATURALMENTE DURANTE LA EJECUCION DEL
 *PROGRAMA

 *SE UTILIZA CUANDO NO SE CONOCE EL TAMAÑO EXACTO DE LA MEMORIA QUE SE NECESITARA DURANTE LA EJECUCION
 *DEL PROGRAMA
 *
*✔️ Estructuras de datos dinámicas (listas enlazadas, árboles, colas, etc.).
✔️ Asignación de objetos grandes que no caben en el Stack.
✔️ Retorno de datos desde funciones sin que desaparezcan cuando la función termina.
 *

STACK Y HEAP:
EL HEAP ES MAS GRANDE Y SE USA PARA OBJ GRANTES O DE DURACION INDEFINIDA
STACK ES MAS RAPIDO PERO TIENE UN TAMAÑANO LIMITAD, ADEMAS SE USA VARIABLES LOCALES Y LLAMADAS A FUNCIONES


//*--------------------
USAMOS NEW PARA SIGNAR MEMORIA EN EL HEAP Y DELETE PARA LIBERARLA[ES MUY IMPORTANTE LIBERARLA CON (DELETE)]
EJEMPLO:*/
#include <iostream>
using namespace std;

//para una clase
class Persona {
public:
 string nombre;
 Persona(string n) {nombre =n;}
 void print() {
  cout<<"Nombre: "<<nombre<<endl;
 }

};

int main() {
 int *ptr= new int;//aca reservamos en el heap
 *ptr = 42;
 cout<<*ptr<<endl;
 delete ptr;//liberamos memoria[importante]

 //-----------para un Array-------
int *arr=new int[5];//reserva memoria para 5 enteros en el heap
 for (int i=0;i<5;i++) {
  arr[i]=i*10;
 }//aca solo asigna pero no imprime

 //imprimios
 for (int i=0;i<5;i++) {
  cout<<arr[i]<<endl;
 }

 delete[] arr;//libera memoria

 //-------para un clase---------
 Persona *p=new Persona("JUAN");//esta en el heap
 p->print();//usa -> en lugar de .
 delete p;//liberamos memoria


 return 0;
}






