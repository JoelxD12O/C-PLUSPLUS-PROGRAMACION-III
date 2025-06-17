// recorrido_postorden.cpp
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

public:
    void insertarNodo(int dato);                 // Inserta un nodo en el árbol
    Nodo* buscarNodo(int dato);                  // Busca un nodo en el árbol
    void imprimirEnOrden();                      // Imprime el árbol en orden
    void imprimirPreOrden();                     // Imprime el árbol en preorden
    void imprimirPostOrden();                    // Imprime el árbol en postorden
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
    arbol.imprimirEnOrden(); // Muestra en orden
    cout << endl;

    cout << "imprimir en pre orden: ";
    arbol.imprimirPreOrden(); // Muestra en preorden
    cout << endl;

    cout << "imprimir en post orden: ";
    arbol.imprimirPostOrden(); // Muestra en postorden
    cout << endl;

    return 0; // Fin del programa
}