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
#include "quicksort_int.h"
#include "bubblesort_string.h"

void ordenar_enteros();
void print_array_ints(int *array, int n);
void fill_array_ints(int *array, int length);

void ordenar_palabras();
void print_array_strings(char **array, int length);
void fill_array_strings(char **array, int length);
void free_array_strings(char **array, int length);

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

void print_array_ints(int *array, int length) // imprime un array de enteros
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void fill_array_ints(int *array, int length) // rellena un array de enteros
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("Introduzca el elemento [%d]: ", i+1);
        scanf("%d", &array[i]);
    }
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

void print_array_strings(char **array, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%s\n", array[i]);
    }
    printf("\n");
    return;
}

void fill_array_strings(char **array, int length) // rellena un array de strings
{
    char buffer[4096];
    int str_length;
    int i;

    while (getchar() != '\n'); // descartamos '\n' de stdin

    printf("\n");
    for (i = 0; i < length; i++)
    {
        printf("Introduzca palabra [%d]: ", i+1);
        fgets(buffer, 4096, stdin); // nota: fgets() guarda '\n'

        str_length = strlen(buffer); // no cuenta '\0' es decir {'h', 'o', 'l', 'a', '\n', '\0'} tiene longitud 5
        buffer[str_length - 1] = '\0'; // cambiamos '\n' por '\0'

        array[i] = malloc(str_length * sizeof(char)); // reservamos memoria para cada posicion de nuestro array de strings (no se suma 1 porque hemos sustituido '\n' por '\0')
        strcpy(array[i], buffer); // copiamos el contenido de buffer en la posicion de nuestro array de strings
    }
    return;
}

void free_array_strings(char **array, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        free(array[i]);
    }
    free(array);
    array = NULL;
    return;
}