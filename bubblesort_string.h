#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void bubblesort(char **strings, int n);
void str_tolower(char* string);

void bubblesort(char **strings, int n)
{
    int i, j, k;
    char *aux;
    char *copia_burbuja;
    char *copia_siguiente;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            copia_burbuja = (char*) malloc(sizeof(char) * (strlen(strings[i]) + 1));
            copia_siguiente = (char*) malloc(sizeof(char) * (strlen(strings[i+1]) + 1));

            strcpy(copia_burbuja, strings[i]); // realizamos una copia de la string actual y la siguiente
            strcpy(copia_siguiente, strings[i+1]);

            str_tolower(copia_burbuja); // convertimos a minusculas
            str_tolower(copia_siguiente);
            
                if (strcmp(copia_burbuja, copia_siguiente) > 0 || // Tomamos como una cadena mayor aquella que tenga valores ascii mayores al convertirla en minusculas
                    (strcmp(copia_burbuja, copia_siguiente) == 0 && strcmp(strings[i], strings[i+1]) < 0)) // Y en caso de que las cadenas sean iguales las que contengan mayusculas seran mayores
                {
                    aux = strings[i];
                    strings[i] = strings[i+1];
                    strings[i+1] = aux;
                }
            
            free(copia_burbuja);
            free(copia_siguiente);
        }
    }
    return;
}

void str_tolower(char* string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++) 
    {
        string[i] = tolower(string[i]);
    }
    return;
}