#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);

void quicksort(int array[], int length);

void quicksort_recursion(int arr[], int low, int high);

int partition(int array[], int low, int high);


void swap(int *a, int *b) // intercambia valores pasados por referencia
{
	int t = *a;
	*a = *b;
	*b = t;
}

void quicksort(int array[], int length) // ordena de manera ascendente usando el algoritmo quicksort
{
    srand(time(NULL)); // generamos una seed aleatoria
    quicksort_recursion(array, 0, length-1);
    return;
}

void quicksort_recursion(int array[], int low, int high) // ordena un intervalo de un array de manera ascendente usando el algoritmo quicksort
{
    if (low < high) // se detiene la recursion cuando low == high
    {
        int pivot_index = partition(array, low, high); // calculamos la posicion real de un pivote aleatorio (vease funcion partition())
        // de manera recursiva calculamos las posiciones reales de pivotes aleatorios en los intervalos a la izquierda y derecha de la posicion del pivote obtenido
        quicksort_recursion(array, low, pivot_index - 1); 
        quicksort_recursion(array, pivot_index + 1, high);
    }
    
    return;
}

int partition(int array[], int low, int high) // calcula la posicion real de un pivote aleatorio dentro de un intervalo con el fin de definir una particion del intervalo
{
    int pivot_index = low + (rand() % (high - low + 1)); // tomamos un pivote aleatorio entre high y low
    if (pivot_index != high) // si no obtenemos el ultimo
    {
        swap(&array[pivot_index], &array[high]); // lo intercambiamos con el ultimo
    }
    

    int pivot_value = array[high]; // valor del pivote aleatorio (ahora situado al final del intervalo)
    int i = low;    // se incrementara tantas veces como valores tenga el pivote menores que el                    
    int j;          // se incrementara hasta que no queden valores por comprobar en el intervalo
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[j]); // se mueve el pivote a su posicion real
    return i; // posicion real del pivote
}

/*  (EJEMPLO ALGORITMO)

    (Iteracion 1) (j=low, i=low)    (Iteracion 2) (j++)

    i                               i           6<=>3    i
    |                               |            i++     |
    6 3 7 [4]                       6 3 7 [4]    ->    3 6 7 [4]
    |                                 |                  |
    j                                 j                  j

    (Iteracion 3) (j++)             (Iteracion 4) (j++)

      i                               i         j==high
      |                               |
    3 6 7 [4]                       3 6 7 [4]    ->    Sale del bucle
        |                                  |
        j                                  j
    
    (swap final)

      i         6<=>4     i
      |                   |
    3 6 7 [4]    ->    3 [4] 7 6
           |                   |
           j                   j
    */