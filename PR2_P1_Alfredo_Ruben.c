/*=============================================================================
 |   Asignatura:  Estructura de datos y algoritmos
 |      Autores:  Alfredo Robledano Abasolo, Ruben Sierra Serrano
 |     Lenguaje:  C
 |        Clase:  2-B
 |        Fecha:  08-12-2022
 +-----------------------------------------------------------------------------
 |  Descripcion:  Implementacion de tres metodos de ordenacion, para ordenar
 |                numeros, cadenas de caracteres (alfabeticamente) y otro
 |      Entrada:  Metodo que desea aplicar el usuario y elementos a ordenar
 |       Salida:  Array o TAD ordenado
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pila.h"
#include "utils.h"

#include "quicksort_int.h"
#include "bubblesort_string.h"

void leer_fichero(Pila pila);

void ordenar_enteros();
void ordenar_palabras();
void leer_ordenar_pila();

Pila ordenar_pila(Pila pila);
Pila ordenarPilaLatitud(Pila pila);
Pila ordenarPilaLongitud(Pila pila);

int main()
{
    int opc;
    do
    {
        printf("==============================================================================================\
        \n                                     MENU\
        \n==============================================================================================");
        printf("\n  1.  Ordenacion de enteros de manera ascendente (Quick Sort).\
        \n  2.  Ordenacion de cadenas alfabeticamente (Bubble Sort).\
        \n  3.  Ordenacion de geolocalizaciones de manera descendente (Temporary Stack Sort).\
        \n  4.  Salir del programa.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Introduzca opcion (1-4): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
            ordenar_enteros();
            break;
        case 2:
            ordenar_palabras();
            break;
        case 3:
            leer_ordenar_pila();
            break;
        case 4:
            printf("Saliendo del programa . . .\n");
            break;
        default:
            printf("Opcion no reconocida, por favor repita la operacion.\n");
            break;
        }
        printf("\n\nPulse enter para continuar . . .");
	    fflush(stdin);
	    getchar();

        system("cls");
    } while (opc != 4);
    return 0;
}

void ordenar_enteros() // ordena un array de enteros utilizando el algoritmo quicksort
{
    int n;
    int *v;

    printf("Introduzca el numero de elementos a ordenar: ");
    scanf("%d", &n);

    v = (int*) malloc(sizeof(int) * n);

    fill_array_ints(v, n);
    print_array_ints(v, n);

    quicksort(v, n);
    print_array_ints(v, n);

    free(v);
    v = NULL;
    return;
}

void ordenar_palabras()
{
    int n;
    char **v;

    printf("Introduzca el numero de palabras a ordenar: ");
    scanf("%d", &n);

    v = malloc(sizeof(char*) * n);

    fill_array_strings(v, n);
    printf("Ha introducido: \n");
    print_array_strings(v, n);
    
    bubblesort(v, n);
    printf("\nOrdenando . . .\n");
    print_array_strings(v, n);

    free_array_strings(v, n);

    return;
}

void leer_ordenar_pila()
{
    Pila pila = crearPila(60);
    Pila pila_ordenada = crearPila(60);
    leer_fichero(pila);
    
    printf("Mostrando pila obtenida del fichero. . .\n");
    mostrarPila(pila);

    printf("\n\nPulse enter para continuar . . .");
    fflush(stdin);
    getchar();

    system("cls");
    
    pila_ordenada = ordenar_pila(pila);
    printf("Mostrando pila ordenada. . .\n");
    mostrarPila(pila_ordenada);

    eliminarPila(pila);
    eliminarPila(pila_ordenada);
    return;
}

void leer_fichero(Pila pila)
{
    int line_count;
    ElementoPila aux;

    FILE *pfich = fopen("fichnum.csv", "r");

    if (pfich == NULL) 
    {
        printf("Error al abrir el fichero \"fichnum.csv\"\n");
    }
    else
    {   
        printf("Leyendo el fichero . . .\n");
        for (
            line_count = 0;
            fscanf(pfich, "%lf;%lf", &aux.longitud, &aux.latitud) == 2;
            line_count++
        )
        {
            apilar(aux, pila);
        }
        if (fclose(pfich) != 0) {
            printf("Error al cerrar el fichero \"fichnum.csv\"\n");
        }
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Fichero leido con exito\n");
        printf("----------------------------------------------------------------------------------------------\n");
    }
    return;
}

Pila ordenar_pila(Pila pila)
{
    int criterio;
    printf("Introduzca criterio de ordenacion (0:LONGITUD, 1:LATITUD): ");
    scanf("%d", &criterio);
    switch (criterio)
    {
    case 0:
        return ordenarPilaLongitud(pila);
        break;

    case 1:
        return ordenarPilaLatitud(pila);
        break;

    default:
        break;
    }
    return NULL;
}

Pila ordenarPilaLongitud(Pila pila)
{
    Pila pila_ordenada = crearPila(longitudPila(pila));
    ElementoPila aux = desapilar(pila);
    apilar(aux, pila_ordenada);
    while (!esPilaVacia(pila))
    {
        aux = desapilar(pila);
        while (aux.longitud > cimaPila(pila_ordenada).longitud && !esPilaVacia(pila_ordenada))
        {
            apilar(desapilar(pila_ordenada), pila);
        }
        apilar(aux, pila_ordenada);
    }
    return pila_ordenada;
}

Pila ordenarPilaLatitud(Pila pila)
{
    Pila pila_ordenada = crearPila(longitudPila(pila));
    ElementoPila aux = desapilar(pila);
    apilar(aux, pila_ordenada);
    while (!esPilaVacia(pila))
    {
        aux = desapilar(pila);
        while (aux.latitud > cimaPila(pila_ordenada).latitud && !esPilaVacia(pila_ordenada))
        {
            apilar(desapilar(pila_ordenada), pila);
        }
        apilar(aux, pila_ordenada);
    }
    return pila_ordenada;
}