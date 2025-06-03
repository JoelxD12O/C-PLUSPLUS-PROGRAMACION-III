//
// Created by user on 3/06/2025.
//
/*
 Patrón de Diseño: Adapter

 Permite que objetos con interfaces incompatibles trabajen juntos, actuando como
 un puente entre el cliente y una clase existente. Evita modificar el código original.

 Ventajas:
 - Facilita la reutilización de código existente.
 - Promueve la integración entre sistemas o librerías con interfaces distintas.
 - No requiere modificar las clases originales.

 Elementos principales:
 - Cliente: Usa la interfaz esperada.
 - Interfaz objetivo: La interfaz que el cliente conoce y utiliza.
 - Adaptado (Adaptee): Clase con la lógica que se desea reutilizar.
 - Adaptador (Adapter): Implementa la interfaz objetivo y traduce las llamadas hacia el adaptado.

 Ejemplo típico: convertir formatos (JPEG a PNG) o adaptar bibliotecas con interfaces distintas.
*/
#include <iostream>
using namespace std;


// Interfaz base para pagos
class Pago {
public:
 // Método virtual puro que deben implementar las clases derivadas
 virtual void pagar() = 0;
};

// Implementación concreta de pago con tarjeta
class PagoTarjeta : public Pago {
public:
 void pagar() override {
  // Solicita los datos de la tarjeta al usuario
  int nt, cvv, fecha;
  cout << "# tarjeta: "; cin >> nt;
  cout << "# cvv: "; cin >> cvv;
  cout << "# fecha: "; cin >> fecha;
 }
};

// Clase que representa un sistema de pago diferente (PayPal)
// No implementa la interfaz Pago directamente
class PagoPayPal {
public:
 void pagar_dif() {
  // Solicita los datos de PayPal al usuario
  string correo, pass;
  cout << "correo: "; cin >> correo;
  cout << "password: "; cin >> pass;
 }
};

// Adaptador que permite usar PagoPayPal donde se espera un Pago
class AdaptadorPaypal : public Pago {
private:
 PagoPayPal pago; // Composición: contiene un objeto PagoPayPal
public:
 void pagar() override {
  // Traduce la llamada a la interfaz esperada
  pago.pagar_dif();
 }
};

// Función principal
int main() {
 Pago* pago; // Puntero a la interfaz base
 int op;
 cout << "¿Como quiere pagar? [Tarjeta:0, Paypal: 1]: ";
 cin >> op;
 if (op == 0)
  pago = new PagoTarjeta(); // Usa pago con tarjeta
 else
  pago = new AdaptadorPaypal(); // Usa pago con PayPal a través del adaptador

 pago->pagar(); // Realiza el pago usando la interfaz común

}
