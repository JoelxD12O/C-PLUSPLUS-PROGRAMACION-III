//
// Created by user on 17/06/2025.
//
#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int dato) {
        this->dato = dato;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Nodo* raiz=nullptr;
    Nodo* insertarNodoAux(Nodo* nodo, int dato);
    Nodo* buscarNodoAux(Nodo* nodo, int dato);

public:
    void insertarNodo(int dato);
    Nodo* buscarNodo(int dato);
void imprimirEnOrdenAux(Nodo* nodo);
    void imprimirEnOrden();
    void imprimirPreOrdenAux(Nodo* nodo);
    void imprimirPreOrden();
};


void BST::insertarNodo(int dato) {
    raiz = insertarNodoAux(raiz, dato);
}

// Función auxiliar para insertar un nodo en el árbol
Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return new Nodo(dato);

    if (dato < nodo->dato)
        nodo->left = insertarNodoAux(nodo->left, dato);
    else
        nodo->right = insertarNodoAux(nodo->right, dato);
    return nodo;
}

void BST::imprimirEnOrden() {
    imprimirEnOrdenAux(raiz);
    cout << endl;
}

void BST::imprimirEnOrdenAux(Nodo* nodo) {
    if (nodo == nullptr)
        return;

    imprimirEnOrdenAux(nodo->left);
    cout << nodo->dato << " ";
    imprimirEnOrdenAux(nodo->right);
}

void BST::imprimirPreOrden() {
    imprimirPreOrdenAux(raiz);
    cout << endl;
}

void BST::imprimirPreOrdenAux(Nodo* nodo) {
    if (nodo == nullptr)
        return;

    cout << nodo->dato << " ";
    imprimirPreOrdenAux(nodo->left);
    imprimirPreOrdenAux(nodo->right);
}

int main() {
    BST arbol;

    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);
    cout<<"imprimir en orden: ";
    arbol.imprimirEnOrden();
    cout<<endl;
    cout<<"imprimir en pre orden: ";
    arbol.imprimirPreOrden();


    return 0;

}