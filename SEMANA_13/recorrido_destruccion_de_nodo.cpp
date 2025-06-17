// recorrido_destruccion_de_nodo.cpp
// Creado por user el 17/06/2025.

#include <iostream>
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int dato;           // Valor almacenado en el nodo
    Nodo* left;         // Puntero al hijo izquierdo
    Nodo* right;        // Puntero al hijo derecho

    // Constructor
    Nodo(int dato) {
        this->dato = dato;
        left = nullptr;
        right = nullptr;
    }
};

// Definición de la clase BST (Árbol Binario de Búsqueda)
class BST {
private:
    Nodo* raiz = nullptr;   // Puntero a la raíz del árbol

    // Métodos auxiliares privados
    Nodo* insertarNodoAux(Nodo* nodo, int dato); // Inserta un nodo recursivamente
    Nodo* buscarNodoAux(Nodo* nodo, int dato);   // Busca un nodo recursivamente
    void imprimirEnOrdenAux(Nodo* nodo);         // Imprime en orden recursivamente
    void imprimirPreOrdenAux(Nodo* nodo);        // Imprime en preorden recursivamente
    void imprimirPostOrdenAux(Nodo* nodo);       // Imprime en postorden recursivamente
    Nodo* eliminarNodoAux(Nodo* nodo, int dato); // Elimina un nodo recursivamente
    void destruirArbol(Nodo* nodo);              // Metodo para destruir el árbol

public:
    void insertarNodo(int dato);                 // Inserta un nodo en el árbol
    Nodo* buscarNodo(int dato);                  // Busca un nodo en el árbol
    void imprimirEnOrden();                      // Imprime el árbol en orden
    void imprimirPreOrden();                     // Imprime el árbol en preorden
    void imprimirPostOrden();                    // Imprime el árbol en postorden
    void eliminarNodo(int dato);                 // Elimina un nodo del árbol
    ~BST();                                      // Destructor para liberar memoria
};

// Implementación de insertarNodo
void BST::insertarNodo(int dato) {
    raiz = insertarNodoAux(raiz, dato); // Llama al auxiliar recursivo
}

// Implementación auxiliar para insertar un nodo
Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return new Nodo(dato); // Si el nodo es nulo, crea uno nuevo

    if (dato < nodo->dato)
        nodo->left = insertarNodoAux(nodo->left, dato); // Inserta a la izquierda
    else
        nodo->right = insertarNodoAux(nodo->right, dato); // Inserta a la derecha
    return nodo;
}

// Implementación de buscarNodo
Nodo* BST::buscarNodo(int dato) {
    return buscarNodoAux(raiz, dato); // Llama al auxiliar recursivo
}

// Implementación auxiliar para buscar un nodo
Nodo* BST::buscarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr || nodo->dato == dato)
        return nodo; // Retorna el nodo si lo encuentra o si es nulo

    if (dato < nodo->dato)
        return buscarNodoAux(nodo->left, dato); // Busca a la izquierda
    else
        return buscarNodoAux(nodo->right, dato); // Busca a la derecha
}

// Imprime el árbol en orden
void BST::imprimirEnOrden() {
    imprimirEnOrdenAux(raiz);
    cout << endl;
}

// Auxiliar para imprimir en orden (izquierda, raíz, derecha)
void BST::imprimirEnOrdenAux(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    imprimirEnOrdenAux(nodo->left);
    cout << nodo->dato << " ";
    imprimirEnOrdenAux(nodo->right);
}

// Imprime el árbol en preorden
void BST::imprimirPreOrden() {
    imprimirPreOrdenAux(raiz);
    cout << endl;
}

// Auxiliar para imprimir en preorden (raíz, izquierda, derecha)
void BST::imprimirPreOrdenAux(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    cout << nodo->dato << " ";
    imprimirPreOrdenAux(nodo->left);
    imprimirPreOrdenAux(nodo->right);
}

// Imprime el árbol en postorden
void BST::imprimirPostOrden() {
    imprimirPostOrdenAux(raiz);
    cout << endl;
}

// Auxiliar para imprimir en postorden (izquierda, derecha, raíz)
void BST::imprimirPostOrdenAux(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    imprimirPostOrdenAux(nodo->left);
    imprimirPostOrdenAux(nodo->right);
    cout << nodo->dato << " ";
}

// Elimina un nodo del árbol
void BST::eliminarNodo(int dato) {
    raiz = eliminarNodoAux(raiz, dato);
}

// Auxiliar para eliminar un nodo
Nodo* BST::eliminarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return nullptr;

    if (dato < nodo->dato) {
        nodo->left = eliminarNodoAux(nodo->left, dato);
    } else if (dato > nodo->dato) {
        nodo->right = eliminarNodoAux(nodo->right, dato);
    } else {
        // Caso 1: sin hijos
        if (nodo->left == nullptr && nodo->right == nullptr) {
            delete nodo;
            return nullptr;
        }
        // Caso 2: un hijo
        else if (nodo->left == nullptr) {
            Nodo* temp = nodo->right;
            delete nodo;
            return temp;
        }
        else if (nodo->right == nullptr) {
            Nodo* temp = nodo->left;
            delete nodo;
            return temp;
        }
        // Caso 3: dos hijos
        else {
            Nodo* sucesor = nodo->right;
            while (sucesor->left != nullptr)
                sucesor = sucesor->left;
            nodo->dato = sucesor->dato;
            nodo->right = eliminarNodoAux(nodo->right, sucesor->dato);
        }
    }
    return nodo;
}

// Destructor
BST::~BST() {
    destruirArbol(raiz);
}

// Destruye el árbol recursivamente
void BST::destruirArbol(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    destruirArbol(nodo->left);
    destruirArbol(nodo->right);
    delete nodo;
}

// Función principal
int main() {
    BST arbol; // Crea un árbol binario de búsqueda

    // Inserta nodos en el árbol
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);

    cout << "imprimir en orden: ";
    arbol.imprimirEnOrden();
    cout << endl;

    cout << "imprimir en pre orden: ";
    arbol.imprimirPreOrden();
    cout << endl;

    cout << "imprimir en post orden: ";
    arbol.imprimirPostOrden();
    cout << endl;

    // Ejemplo de eliminación
    cout << "Eliminando nodo 30..." << endl;
    arbol.eliminarNodo(30);
    cout << "imprimir en orden: ";
    arbol.imprimirEnOrden();
    cout << endl;

    return 0; // Fin del programa
}