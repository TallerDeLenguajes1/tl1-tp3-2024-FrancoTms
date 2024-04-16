#include <stdio.h>
#include <time.h>

// Constantes
#define FILA 5
#define COLUMNA 12

// Main
int main()
{
    srand(time(NULL));

    float matriz[FILA][COLUMNA], gananciaAnio = 0, gananciaMax = 0, gananciaMin = 50001, gananciaMes;
    int mesMax, anioMax, mesMin, anioMin;

    // Llenar matriz
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = rand() % 50000 + 10001;
        }
    }

    // Mostrar matriz y ganancias por año y mes
    for (int i = 0; i < FILA; i++)
    {
        printf("\n\n**********Anio N. %d************", i + 1);
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("\n\tGanancia mes N. %d: $%.2f", j + 1, matriz[i][j]);

            // Sumar ganancia del año
            gananciaAnio += matriz[i][j];

            // Controlar ganancia maxima
            gananciaMes = matriz[i][j];
            if (gananciaMax < gananciaMes)
            {
                gananciaMax = gananciaMes;
                mesMax = j + 1;
                anioMax = i + 1;
            }

            // Controlar ganancia minima
            if (gananciaMin > gananciaMes)
            {
                gananciaMin = gananciaMes;
                mesMin = j + 1;
                anioMin = i + 1;
            }
        }

        // Mostrar ganancia total por año
        printf("\nGanancia Total Anio N. %d = $%.2f", i + 1, gananciaAnio);
        gananciaAnio = 0;

        // Mostrar ganancia maxima y minima
        printf("\n\nGanancia maxima = $%.2f - Anio %d - Mes %d", gananciaMax, anioMax, mesMax);
        printf("\n\nGanancia minima = $%.2f - Anio %d - Mes %d", gananciaMin, anioMin, mesMin);
    }
}
