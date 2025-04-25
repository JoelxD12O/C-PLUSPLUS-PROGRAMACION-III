#include <iostream>
using namespace std;

// Clase base generica para personajes
template<typename T, typename U>
class Personaje {
private:
    T nombre;
    U ocupacion;
public:
    Personaje(T name, U ocupa) : nombre(name), ocupacion(ocupa) {}

    virtual void usuario() = 0;
    virtual void anfitrion() = 0;

    T getNombre() { return nombre; }
    U getOcupacion() { return ocupacion; }

    // Sobrecarga del operador << para mostrar la informacion del personaje
    friend ostream& operator<<(ostream& out,  Personaje<T, U>& p) {
        out << "Nombre: " << p.getNombre() << ", Ocupacion: " << p.getOcupacion();
        return out;
    }
};

// Clase derivada para Usuario
template<typename T, typename U>
class Usuario : public Personaje<T, U> {
public:
    Usuario(T name, U ocupa) : Personaje<T, U>(name, ocupa) {}

    void usuario() override {
        cout << "Usuario: " << this->getNombre() << ", Ocupacion: " << this->getOcupacion() << endl;
    }

    void anfitrion() override {
        cout << "Este es un usuario, no un anfitrion." << endl;
    }
};

// Clase derivada para Anfitrion
template<typename T, typename U>
class Anfitrion : public Personaje<T, U> {
public:
    Anfitrion(T name, U ocupa) : Personaje<T, U>(name, ocupa) {}

    void usuario() override {
        cout << "Este es un anfitrion, no un usuario." << endl;
    }

    void anfitrion() override {
        cout << "Anfitrion: " << this->getNombre() << ", Ocupacion: " << this->getOcupacion() << endl;
    }
};

// Clase base para Alojamientos
template<typename T, typename U>
class Alojamiento {
protected:
    T nombre;
    U personas;
public:
    Alojamiento(T name, U pers) : nombre(name), personas(pers) {}

    T getNombre() { return nombre; }
    U getPersonas() { return personas; }

    // Sobrecarga del operador << para mostrar la informacion del alojamiento
    friend ostream& operator<<(ostream& out,  Alojamiento<T, U>& a) {
        out << "Alojamiento: " << a.getNombre() << ", Personas: " << a.getPersonas();
        return out;
    }
};

// Clase derivada para Casa
template<typename T, typename U>
class Casa : public Alojamiento<T, U> {
public:
    Casa(T name, U pers) : Alojamiento<T, U>(name, pers) {}

    void mostrarInfo() {
        cout << "Casa: " << this->getNombre() << ", Personas: " << this->getPersonas() << endl;
    }
};

// Clase derivada para Habitaciones
template<typename T, typename U>
class Habitaciones : public Alojamiento<T, U> {
public:
    Habitaciones(T name, U pers) : Alojamiento<T, U>(name, pers) {}

    void mostrarInfo() {
        cout << "Habitacion: " << this->getNombre() << ", Personas: " << this->getPersonas() << endl;
    }
};

// Sobrecarga del operador + para "reservar" (simulando la suma de dias)
template<typename T, typename U>
class Reserva {
private:
    T nombre;
    U dias;
public:
    Reserva(T name, U d) : nombre(name), dias(d) {}

    // Sobrecarga del operador + para sumar dias a la reserva
    Reserva operator+(U extraDias) {
        return Reserva(this->nombre, this->dias + extraDias);
    }

    void mostrarReserva() {
        cout << "Alojamiento: " << nombre << " | Dias reservados: " << dias << endl;
    }
};

// Función para imprimir información de múltiples personajes o alojamientos
template<typename T, typename U, typename... Args>
void imprimirInformacion(T& t, U& u, Args&... args) {
    cout << t << endl;
    cout << u << endl;
    ((cout << args << endl),...);  // Expansión de los argumentos
}

// Función para mostrar el menú y ejecutar las opciones seleccionadas
void mostrarMenu() {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Mostrar informacion de los personajes y alojamientos" << endl;
    cout << "2. Agregar dias a una reserva" << endl;
    cout << "3. Salir" << endl;
}

int main() {

    Usuario<string, string> usuario1("Juan", "Estudiante");
    Anfitrion<string, string> anfitrion1("Carlos", "Propietario");
    Casa<string, int> casa1("Casa en la playa", 5);
    Habitaciones<string, int> habitacion1("Habitacion privada", 2);

    Reserva<string, int> reserva1("Casa en la playa", 7);

    int opcion;
    do {
        // Mostrar el menú
        mostrarMenu();

        // Leer la opción seleccionada
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Imprimir la información de todos los objetos
                imprimirInformacion(usuario1, anfitrion1, casa1, habitacion1);
                break;

            case 2:
                // Agregar días a la reserva
                reserva1 = reserva1 + 3;  // Por ejemplo, sumar 3 días
                reserva1.mostrarReserva();  // Mostrar la reserva con los nuevos días
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);  // Salir cuando se elija la opción 3

    return 0;
};
    /*
     //TEST2
    // Crear objetos
    Usuario<string> usuario1("Juan", "Estudiante");
    Anfitrion<string> anfitrion1("Carlos", "Propietario");
    Casa<string> casa1("Casa en la playa", "5");
    Habitaciones<string> habitacion1("Habitacion privada", "2");

    // Sobrecarga del operador << para mostrar informacion
    cout << "Informacion del Usuario: " << usuario1 << endl;
    cout << "Informacion del Anfitrion: " << anfitrion1 << endl;
    cout << "Informacion de la Casa: " << casa1 << endl;
    cout << "Informacion de la Habitacion: " << habitacion1 << endl;

    // Crear una reserva y usar el operador + para agregar dias
    Reserva<string> reserva1("Casa en la playa", 7);
    reserva1.mostrarReserva();

    // Agregar dias a la reserva
    reserva1 = reserva1 + 3;
    reserva1.mostrarReserva();  // Ahora la reserva tiene 10 dias


    cout<<"template variadic"<<endl;

    imprimirInformacion(usuario1, anfitrion1, casa1, habitacion1);
    return 0;*/


