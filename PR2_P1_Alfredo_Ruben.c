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
#include "quicksort_int.h"

void ordenar_enteros();
void print_array_int(int arr[], int n);
void fill_array_int(int array[], int length);

int main()
{
    int opc;
    do
    {
        printf("==============================================================================================\
        \n                                     MENU\
        \n==============================================================================================");
        printf("\n  1.  Ordenacion de enteros de manera ascendente (Quick Sort).\
        \n  2.  Ordenacion de cadenas alfabeticamente.\
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
    int n = 0;
    int *v;

    printf("Introduzca el numero de elementos a ordenar: ");
    scanf("%d", &n);

    v = (int*) malloc(sizeof(int) * n);

    fill_array_int(v, n);
    print_array_int(v, n);

    quicksort(v, n);
    print_array_int(v, n);

    free(v);
    v = NULL;
    return;
}

void print_array_int(int array[], int length) // imprime un array de enteros
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void fill_array_int(int array[], int length) // rellena un array de enteros
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("Introduzca el elemento [%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    return;
}