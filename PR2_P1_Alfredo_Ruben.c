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

#include "utils.h"
#include "quicksort_int.h"
#include "bubblesort_string.h"


void ordenar_enteros();
void ordenar_palabras();

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
        \n  3.  Ordenacion de geolocalizaciones por longitud ascendente.\
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