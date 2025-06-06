//
// Created by user on 5/06/2025.
//
// El patrón de diseño Memento permite guardar y restaurar el estado de un objeto sin revelar su implementación interna.
// Este patrón es útil cuando necesitamos crear puntos de restauración que nos permitan revertir cambios realizados en un objeto
// y regresar a un estado anterior sin exponer los detalles de su estructura interna.

// Aplicaciones comunes del patrón Memento:
// 1. **Editor de texto**: Permite guardar versiones anteriores de un documento, lo que permite a los usuarios deshacer cambios
//    o volver a una versión previa. Esto se logra mediante el almacenamiento de momentos (estados) del documento,
//    permitiendo la restauración en cualquier punto anterior sin alterar la estructura del texto actual.
//
// 2. **Juego de video**: Los juegos a menudo requieren la capacidad de guardar el progreso y permitir que los jugadores
//    retomen su partida desde un punto específico sin perder el avance logrado. El patrón Memento guarda el estado del juego,
//    incluyendo variables y atributos del personaje, y lo restaura cuando el jugador decide continuar desde su última partida guardada.
//
// 3. **Transacciones financieras**: En el contexto de transacciones bancarias o financieras, es crucial mantener la integridad de los datos.
//    El patrón Memento permite guardar el estado de una transacción en cualquier punto del proceso, para poder restaurarlo en caso de errores
//    o interrupciones, garantizando que no haya pérdida de datos o inconsistencias.


// Implementación del patrón Memento:
// 1. **Creador (Originador)**: Es el objeto cuyo estado puede cambiar y que tiene la responsabilidad de crear un memento.
//    Este objeto contiene el estado que se desea guardar.
//    - El creador tiene un metodo para guardar su estado en un memento y otro para restaurarlo desde un memento.
//
// 2. **Memento**: Es el objeto que almacena el estado interno del originador. El memento es un objeto inmutable,
//    que no puede ser modificado una vez creado.
//    - Solo el originador tiene acceso a la información interna del memento.
//
// 3. **Caretaker**: Es el objeto responsable de almacenar los mementos.
//    No debe modificar el estado del memento, solo debe almacenarlos y proporcionarlos cuando se requiera restaurar el estado.
//
// Resumen:
// El patrón Memento es ideal para aplicaciones que requieren mantener un historial de cambios y proporcionar la capacidad de retroceder en el tiempo,
// sin exponer los detalles internos de los objetos a otros componentes del sistema.


//Ejercicio 2-diapositiva
//Se desea implementar un sistema de guardado y carga de partidas en un videojuego de aventura.
//Utilizando el patrón Memento, implementa la funcionalidad de guardar y restaurar el estado del
//juego en diferentes puntos.

#include <iostream>
#include <vector>
using namespace std;

class Memento {
private:
    int nivel;
    int X;
    int Y;

public:
    Memento (const int& niv, int posicionX, int posicionY)
        : nivel(niv), X(posicionX), Y(posicionY) {}

    int getNivel() const { return nivel;}
    int getPosicionX() const { return X;}
    int getPosicionY() const { return Y;}
    friend class Personaje; // Permite que la clase Personaje acceda a los miembros privados
};

// Clase que representa el personaje del juego
class Personaje {
    string nombre;
    int nivel;
    int X,Y;
    vector<Memento*> historial;

public:
    Personaje(const string& nombre)
        : nombre(nombre), nivel(1), X(0), Y(0) {}

    void info(){
        cout << "Nivel: " << nivel << ", Pos=(";
        cout << X << ", " << Y << ")"<< endl;
    }

    void restaurarEstado() {
        // Elegir un estado del video juego a restaurar

        for (int i=0; i<historial.size(); i++) {
         cout<<"-------(estado "<<i<<")-------"<<endl;
            cout<<"Nivel: " << historial[i]->getNivel() << ", Pos=(";
        cout<< historial[i]->getPosicionX() << ", " << historial[i]->getPosicionY() << ")"<< endl;
        }
        int estado;

        cout << "Estado: "  << endl;
        cin>> estado;
        if (estado < 0 || estado >= historial.size()) {
            cout << "Estado no válido, retorna el ultimo estado" << endl;
            return;
        }
        nivel=historial[estado-1]->nivel;
        X=historial[estado-1]->X;
        Y=historial[estado-1]->Y;
    }
    void guardarEstado() {
        // Guardar un estado del video juego
        nivel+=rand()%3;
        X+= rand()%3;
        Y+= rand()%3;
        historial.push_back(new Memento(nivel,X,Y));
    }
};

int main() {
    Personaje pj("Heroe");

    pj.guardarEstado();
    pj.guardarEstado();
    pj.guardarEstado();
    pj.restaurarEstado();

    pj.info();
}
