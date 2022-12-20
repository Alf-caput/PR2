// Arbol caracteres
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMA_LONGITUD_CADENA 100

struct nodoCadena
{
    // El verdadero dato
    char cadena[MAXIMA_LONGITUD_CADENA];
    // Las ramas
    struct nodoCadena *izquierda;
    struct nodoCadena *derecha;
};

struct nodoCadena *nuevoNodo(char cadena[MAXIMA_LONGITUD_CADENA]);
void agregar(struct nodoCadena *nodo, char *cadena);
struct nodoCadena *buscar(struct nodoCadena *nodo, char *cadena);
void preorden(struct nodoCadena *nodo);
void inorden(struct nodoCadena *nodo);
void postorden(struct nodoCadena *nodo);

struct nodoCadena *nuevoNodo(char cadena[MAXIMA_LONGITUD_CADENA])
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct nodoCadena);
    struct nodoCadena *nodo = (struct nodoCadena *)malloc(tamanioNodo);
    // Asignar el dato e iniciar hojas
    strcpy(nodo->cadena, cadena);
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void agregar(struct nodoCadena *nodo, char *cadena)
{
    if (strcmp(cadena, nodo->cadena) > 0)
    {
        if (nodo->derecha == NULL)
        {
            nodo->derecha = nuevoNodo(cadena);
        }
        else
        {
            agregar(nodo->derecha, cadena);
        }
    }
    else
    {
        if (nodo->izquierda == NULL)
        {
            nodo->izquierda = nuevoNodo(cadena);
        }
        else
        {
            agregar(nodo->izquierda, cadena);
        }
    }
}

struct nodoCadena *buscar(struct nodoCadena *nodo, char *cadena)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->cadena) == 0)
    {
        return nodo;
    }
    else if (strcmp(cadena, nodo->cadena) > 0)
    {
        return buscar(nodo->derecha, cadena);
    }
    else
    {
        return buscar(nodo->izquierda, cadena);
    }
}
void preorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        printf("%s,", nodo->cadena);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        inorden(nodo->izquierda);
        printf("%s,", nodo->cadena);
        inorden(nodo->derecha);
    }
}

void postorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%s,", nodo->cadena);
    }
}
