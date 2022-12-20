#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array_ints(int *array, int n);
void fill_array_ints(int *array, int length);

void print_array_strings(char **array, int length);
void fill_array_strings(char **array, int length);
void free_array_strings(char **array, int length);

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