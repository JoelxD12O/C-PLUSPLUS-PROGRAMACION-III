    //
// Created by user on 3/06/2025.
//
/*
 Patrón de Diseño: Decorator

 Permite añadir funcionalidades a un objeto de forma flexible y dinámica,
 sin modificar su estructura interna ni afectar a otros objetos de la misma clase.

 Ventajas:
 - Extiende comportamientos sin alterar la clase original.
 - Facilita la composición de funcionalidades.
 - Promueve el principio de abierto/cerrado (Open/Closed Principle).

 Elementos principales:
 - Componente: Interfaz común para objetos y decoradores.
 - Componente concreto: Implementación base del objeto.
 - Decorador: Clase abstracta que implementa la interfaz y envuelve un componente.
 - Decoradores concretos: Añaden nuevas funcionalidades al componente envuelto.

 Ejemplos comunes: agregar filtros a imágenes, funcionalidades extra a ventanas
 o cargos adicionales a un pedido en e-commerce.
*/


#include <iostream>
using namespace std;

// Interfaz para todos los informes
class Informe {
public:
    // Método virtual puro: obliga a las clases derivadas a implementar 'generar'
    virtual void generar() = 0;
};

// Clase base para informes sin decorar
class InformeBase : public Informe {
public:
    // Implementación concreta del método 'generar'
    void generar() override {
        std::cout << "Generando informe base..." << std::endl;
    }
};

/*
Ejemplo de uso básico de la clase base:
int main() {
    // Crear un informe base
    InformeBase* informeBase = new InformeBase();
    informeBase->generar(); // Resultado: Generando informe base...
}
*/

// Clase decoradora abstracta: permite añadir funcionalidades a un informe
class InformeDecorador : public Informe {
protected:
    Informe* informe; // Puntero al informe que se va a decorar

public:
    // Constructor: recibe el informe a decorar
    InformeDecorador(Informe* informe) : informe(informe) {}

    // Llama al método 'generar' del informe decorado
    void generar() override {
        informe->generar();
    }
};

// Decorador concreto para añadir un encabezado personalizado al informe
class EncabezadoDecorador : public InformeDecorador {
private:
    std::string encabezado; // Texto del encabezado

public:
    // Constructor: recibe el informe a decorar y el texto del encabezado
    EncabezadoDecorador(Informe* informe, const std::string& encabezado)
        : InformeDecorador(informe), encabezado(encabezado) {}

    // Sobrescribe 'generar' para añadir el encabezado antes del informe base
    void generar() override {
        std::cout << "Agregando encabezado personalizado: " << encabezado << std::endl;
        InformeDecorador::generar(); // Llama al método del decorador base (que a su vez llama al informe base)
    }
};

int main() {
    // Crear un informe base
    InformeBase* informeBase = new InformeBase();

    // Crear un informe decorado con un encabezado personalizado
    EncabezadoDecorador* informeConEncabezado = new EncabezadoDecorador(informeBase, "Informe de Empleados");

    // Generar el informe final (primero muestra el encabezado, luego el informe base)
    informeConEncabezado->generar();

    // Salida esperada:
    // Agregando encabezado personalizado: Informe de Empleados
    // Generando informe base...
}
