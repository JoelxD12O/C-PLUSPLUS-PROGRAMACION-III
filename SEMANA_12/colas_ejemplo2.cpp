#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>  // para rand(), srand()
#include <ctime>    // para time()

using namespace std;

// Representa a un cliente con DNI y nombre
struct Cliente {
    int dni;
    string nombre;

    // Constructor para facilitar la creación
    Cliente(int _dni = 0, const string& _nombre = "")
        : dni(_dni), nombre(_nombre) {}
};

class Sistema {
private:
    queue<Cliente> clientes;

public:
    // Saca un ticket (añade un cliente a la cola)
    void sacarTicket(const Cliente& cliente) {
        clientes.push(cliente);
    }

    // Muestra la lista de espera sin modificar la cola original
    void lista_de_espera() {
        queue<Cliente> tmp = clientes;
        int i = 1;
        cout << "Lista de espera\n";
        cout << "----------------\n";
        while (!tmp.empty()) {
            Cliente c = tmp.front();
            cout << i << ": " << c.nombre << " (DNI: " << c.dni << ")\n";
            tmp.pop();
            ++i;
        }
        if (i == 1) {
            cout << "(vacía)\n";
        }
        cout << endl;
    }

    // Atiende al siguiente cliente (lo saca de la cola)
    void atender_cliente() {
        if (clientes.empty()) {
            cout << "No hay clientes en espera.\n\n";
        } else {
            Cliente c = clientes.front();
            cout << "Atender cliente: " << c.nombre
                 << " (DNI: " << c.dni << ")\n\n";
            clientes.pop();
        }
    }
};

// Genera un DNI "aleatorio" de 8 dígitos (entre 10.000.000 y 99.999.999)
int random_dni() {
    return rand() % 90000000 + 10000000;
}

int main() {
    // Para que rand() sea distinto en cada ejecución
    srand(static_cast<unsigned>(time(nullptr)));

    Sistema sistema;

    // Sacamos tickets para varios clientes
    sistema.sacarTicket(Cliente(random_dni(), "Jose"));
    sistema.sacarTicket(Cliente(random_dni(), "Jonas"));
    sistema.sacarTicket(Cliente(random_dni(), "Maria"));
    sistema.sacarTicket(Cliente(random_dni(), "Flor"));
    sistema.sacarTicket(Cliente(random_dni(), "Fernanda"));

    // Mostramos quiénes están en espera
    sistema.lista_de_espera();

    // Atendemos al primer cliente
    sistema.atender_cliente();

    // Volvemos a mostrar la lista de espera tras atender
    sistema.lista_de_espera();

    return 0;
}
