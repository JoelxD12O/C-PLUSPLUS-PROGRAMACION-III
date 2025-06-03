//
// Created by user on 3/06/2025.
//
/*
 Patrón de Diseño: Proxy

 Controla el acceso a un objeto actuando como intermediario, permitiendo realizar
 tareas adicionales (como validación, caché o auditoría) antes o después de acceder
 al objeto real.

 Ventajas:
 - Agrega una capa de control sin modificar el objeto original.
 - Permite implementar caché, control de acceso y registro de operaciones.
 - Promueve la separación de responsabilidades.

 Elementos principales:
 - Interfaz común: Define las operaciones disponibles para el cliente.
 - Objeto real: Contiene la lógica principal y responde a las solicitudes.
 - Proxy: Implementa la misma interfaz y delega llamadas al objeto real,
   añadiendo lógica adicional según sea necesario.

 Ejemplos típicos: control de acceso a recursos, sistema de autenticación,
 caché de datos y auditoría de operaciones.
*/
// Implementación concreta del objeto de sitio web
#include <iostream>
#include <string>
#include <set>
using namespace std;

// Interfaz común
class SitioWeb {
public:
    virtual void visualizar() const = 0;
    virtual ~SitioWeb() = default;
};

// Implementación concreta del objeto de sitio web
class SitioWebReal : public SitioWeb {
private:
    string url;
    void cargarDesdeServidor() {
        // Lógica para cargar el sitio web desde el servidor
        cout << "Descargando el sitio web desde el servidor: " << url << endl;
    }
public:
    SitioWebReal(const string& url) : url(url) {
        // Cargar el sitio web desde el servidor
        cargarDesdeServidor();
    }
    void visualizar() const override {
        // Lógica para cargar el sitio web
        cout << "Visualizando el sitio web: " << url << endl;
    }
};

// Proxy del objeto de sitio web
class ProxySitioWeb : public SitioWeb {
private:
    set<string> sitiosWebNoPermitidos = {
        "www.sitioprohibido1.com",
        "www.sitioprohibido2.com",
        "www.sitioprohibido3.com"};
    string url;
    SitioWebReal* sitioReal = nullptr;
public:
    ProxySitioWeb(const string& url) : url(url) {}
    ~ProxySitioWeb() { delete sitioReal; }
    void visualizar() const override {
        if (sitiosWebNoPermitidos.find(url) != sitiosWebNoPermitidos.end()) {
            cout << "Acceso denegado al sitio web: " << url << endl;
        } else {
            if (!sitioReal) {
                // Nota: const_cast se usa para modificar el puntero en un método const
                const_cast<ProxySitioWeb*>(this)->sitioReal = new SitioWebReal(url);
            }
            sitioReal->visualizar();
        }
    }
};

int main() {
    SitioWeb* sitio;
    sitio = new ProxySitioWeb("www.sitiopermitido1.com");
    sitio->visualizar();
    delete sitio;

    sitio = new SitioWebReal("www.sitioprohibido1.com");
    sitio->visualizar();
    delete sitio;

    sitio = new ProxySitioWeb("www.sitioprohibido1.com");
    sitio->visualizar();
    delete sitio;
}
