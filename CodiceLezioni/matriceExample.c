#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RIGHE 5
#define COLONNE 4

int main() 
{
    int matrice[RIGHE][COLONNE];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < RIGHE; i++) 
    {
        for (j = 0; j < COLONNE; j++) 
        {
            matrice[i][j] = rand() % 100 + 1;
        }
    }

    printf("Matrice %dx%d generata:\n", RIGHE, COLONNE);

    for (i = 0; i < RIGHE; i++) 
    {
        for (j = 0; j < COLONNE; j++) 
        {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n\n\n\n");
    }

    // Azzerare la prima riga
    for(j = 0; j < COLONNE; j++)
        matrice[0][j] = 0;

    for (i = 0; i < RIGHE; i++) 
    {
        for (j = 0; j < COLONNE; j++) 
        {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n");
    }

    // Elimino l'ultima riga
    for(j = 0; j < COLONNE; j++)
        matrice[RIGHE - 1][j] = 0;

    for (i = 0; i < RIGHE; i++) 
    {
        for (j = 0; j < COLONNE; j++) 
        {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n");
    }

    // Stampo la diagonale principale
    for(i = 0; i < COLONNE; i++)
        printf("%d ", matrice[i][i]);

    return 0;
}