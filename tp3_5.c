#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Constantes
#define MAX_NOMBRES 50

int main()
{
    int cantNombres;
    printf("Ingresar la cantidad de nombres a ingresar: ");
    scanf("%d", &cantNombres);

    char *nombres[cantNombres];
    int i;

    //Cargar Nombres
    printf("\n*********Ingresar nombres*********");
    for (i = 0; i < cantNombres; i++)
    {
        nombres[i]=(char *)malloc(MAX_NOMBRES * sizeof(char));
        printf("\nIngrese el nombre N. %d: ", i + 1);
        fgets(nombres[i], MAX_NOMBRES, stdin);
    }
    
    //Mostrar Nombres
    printf("\n*********Nombres ingresados*********");
    for (i = 0; i < cantNombres; i++)
    {
        printf("\n\tNombre N. %d: %s", i + 1, nombres[i]);
    }
    
    //Liberar memoria
    for (i = 0; i < cantNombres; i++)
    {
        free(nombres[i]);
    }

    return 0;
}
