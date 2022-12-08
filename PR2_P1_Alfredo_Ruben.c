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

int main()
{
    int opc;
    do
    {
        printf("==============================================================================================\
        \n                                     MENU\
        \n==============================================================================================");
        printf("\n  1.  Ordenacion de enteros de manera ascendente(Bubble Sort).\
        \n  2.  Ordenacion de cadenas alfabeticamente.\
        \n  3.  Ordenacion de geolocalizaciones por longitud ascendente.\
        \n  4.  Salir del programa.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Introduzca opcion (1-6): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
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
    } while (opc != 6);
    return 0;
}