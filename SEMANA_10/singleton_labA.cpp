#include <iostream>
using namespace std;

// Creamos una clase llamada Singleton
class Singleton {
private:
    // Aquí guardamos un puntero especial que apunta al único objeto Singleton
    static Singleton* instancia;
    // El constructor es privado, así nadie puede crear objetos desde fuera
    Singleton(){};
public:
    // Esta función nos da acceso al único objeto Singleton
    static Singleton* crearAcceso() {
        // Si todavía no existe el objeto, lo creamos
        if (instancia == nullptr)
            instancia = new Singleton();
        // Devolvemos el puntero al único objeto
        return instancia;
    };
};

// Inicializamos el puntero a nullptr (no apunta a nada al principio)
Singleton* Singleton::instancia = nullptr;

int main() {
    // Pedimos el acceso al objeto Singleton por primera vez
    Singleton* acceso_usr1 = Singleton::crearAcceso();
    // Pedimos el acceso otra vez, pero nos da el mismo objeto
    Singleton* acceso_usr2 = Singleton::crearAcceso();
    // Imprimimos la dirección de memoria de ambos accesos
    cout << "acceso_usr1: " << acceso_usr1 << endl;
    cout << "acceso_usr2: " << acceso_usr2 << endl;
    // Verás que ambas direcciones son iguales, porque es el mismo objeto
    return 0;
}

// Teoría: ¿Qué es Singleton?
// Singleton es una forma de programar para que solo exista un objeto de una clase.
// Por ejemplo, imagina que tienes una caja de lápices en tu salón de clases y todos deben usar esa misma caja.
// No puedes tener dos cajas, solo una para todos. Así funciona Singleton: todos usan el mismo objeto.