/**
 * �rboles binarios en C
 * Operaciones de:
 * Inserci�n
 * Recorrido inorden, postorden y preorden
 * Uso de malloc
 *
 * */
 
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo *nuevoNodo_int(int dato);
void insertar_int(struct Nodo *nodo, int dato);
void preorden_int(struct Nodo *nodo);
void inorden_int(struct Nodo *nodo);
void postorden_int(struct Nodo *nodo);
struct Nodo *buscar_int(struct Nodo *nodo, int dato);

struct Nodo *nuevoNodo_int(int dato) {
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar_int(struct Nodo *nodo, int dato) {
    // �Izquierda o derecha?
    // Si es mayor va a la derecha
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo_int(dato);
        } else {
            // Si la derecha ya est� ocupada, recursividad ;)
            insertar_int(nodo->derecha, dato);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo_int(dato);
        } else {
            // Si la izquierda ya est� ocupada, recursividad ;)
            insertar_int(nodo->izquierda, dato);
        }
    }
}


void preorden_int(struct Nodo *nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden_int(nodo->izquierda);
        preorden_int(nodo->derecha);
    }
}

void inorden_int(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden_int(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden_int(nodo->derecha);
    }
}

void postorden_int(struct Nodo *nodo) {
    if (nodo != NULL) {
        postorden_int(nodo->izquierda);
        postorden_int(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

struct Nodo *buscar_int(struct Nodo *nodo, int dato)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (dato == nodo->dato)
    {
        return nodo;
    }
    else if (dato > nodo->dato)
    {
        return buscar_int(nodo->derecha, dato);
    }
    else
    {
        return buscar_int(nodo->izquierda, dato);
    }
}
