/*=============================================================================
 |   Asignatura:  Estructura de datos y algoritmos
 |      Autores:  Alfredo Robledano Abasolo, Ruben Sierra Serrano
 |     Lenguaje:  C
 |        Clase:  2-B
 |        Fecha:  08-12-2022
 +-----------------------------------------------------------------------------
 |  Descripcion:  Implementacion de arboles binarios
 |      Entrada:  Numeros o caracteres introducidos por el ususario
 |       Salida:  Arbol binario
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArbolCaracteres.h"
#include "ArbolSimple.h"

void operar_arbolcaracteres();
void operar_arbolenteros();
int main()
{
    int opc;
    do
    {
        printf("==============================================================================================\
        \n                                     MENU\
        \n==============================================================================================");
        printf("\n  1.  Uso de arbol de caracteres.\
        \n  2.  Uso de arbol de enteros.\
        \n  3.  Salir del programa.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Introduzca opcion (1-3): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
            operar_arbolcaracteres();
            break;
        case 2:
            operar_arbolenteros();
            break;
        case 3:
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
    } while (opc != 3);
    return 0;
}

void operar_arbolcaracteres()
{
    int contador, i;
    char base[20];
    struct nodoCadena *raiz = NULL;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("ARBOL DE CARACTERES\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Introduzca la cantidad de nodos que desea insertar: ");
	scanf("%d",&contador);
    fflush(stdin);
    printf("Introduzca la cadena raiz: ");
    fgets(base, 20, stdin);
    base[strlen(base)-1] = '\0';
    raiz = nuevoNodo(base);

    for(i = 0; i < contador-1; i++)
    {
    	printf("Introduzca el %d elemento: ", i + 2);
    	fgets(base, 20, stdin);
        base[strlen(base)-1] = '\0';
    	agregar(raiz,base);
	}

    printf("\nARBOL CREADO\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("RECORRIDOS\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\nInorden: \n");
    inorden(raiz);
    printf("\nPostorden: \n");
    postorden(raiz);
    printf("\nPreorden: \n");
    preorden(raiz);
    printf("\n");

    printf("----------------------------------------------------------------------------------------------\n");
    printf("EJEMPLO BUSQUEDA\n");
    printf("----------------------------------------------------------------------------------------------\n");

    printf("Introduzca la cadena a buscar: ");
    fgets(base, 20, stdin);
    base[strlen(base)-1] = '\0';
    struct nodoCadena *apuntador = buscar(raiz, base);
    if (apuntador == NULL)
    {
        printf("%s no existe en el arbol\n", base);
    }
    else
    {
        printf("%s si existe en el arbol\n", base);
    }
    return;
}

void operar_arbolenteros()
{
    int base_int, contador, i;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("ARBOL DE ENTEROS\n");
    printf("----------------------------------------------------------------------------------------------\n");
	printf("Introduzca la cantidad de nodos que desea insertar: ");
	scanf("%d",&contador);
	printf("Introduza el nodo base: ");
	scanf("%d",&base_int);
    struct Nodo *raiz_int = nuevoNodo_int(base_int);
    for(i = 0; i < contador-1; i++)
    {
    	printf("Introduzca el %d elemento: ", i + 2);
    	scanf("%d",&base_int);
    	insertar_int(raiz_int,base_int);
	}
    printf("\nARBOL CREADO\n");

    printf("----------------------------------------------------------------------------------------------\n");
    printf("RECORRIDOS\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\nImprimiendo preorden\n");
    preorden_int(raiz_int);
    printf("\nImprimiendo inorden\n");
    inorden_int(raiz_int);
    printf("\nImprimiendo postorden\n");
    postorden_int(raiz_int);
    printf("\n");

    printf("----------------------------------------------------------------------------------------------\n");
    printf("EJEMPLO BUSQUEDA\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Introduzca el entero a buscar: ");
    scanf("%d", &base_int);
    struct Nodo *apuntador = buscar_int(raiz_int, base_int);
    if (apuntador == NULL)
    {
        printf("%d no existe en el arbol\n", base_int);
    }
    else
    {
        printf("%d si existe en el arbol\n", base_int);
    }
    return;
}