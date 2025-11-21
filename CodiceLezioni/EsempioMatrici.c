#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void generaMatrice(int matrice[N][N]);
void stampaMatrice(int matrice[N][N]);
int minimoMatrice(int matrice[N][N]);
void stampaDiagonalePrincipale(int matrice[N][N]);
void stampaDiagonaleSecondaria(int matrice[N][N]);

int main()
{
    int matrice[N][N];

    srand(time(NULL));

    generaMatrice(matrice);
    stampaMatrice(matrice);

    // TROVO IL MINIMO ALL'INTERNO DELLA MATRICE (VEDI FUNZIONE)
    printf("Il numero minimo della matrice e': %d\n", minimoMatrice(matrice));

    // STAMPO LA DIAGONALE PRINCIPALE DELLA MATRICE
    stampaDiagonalePrincipale(matrice);
    stampaDiagonaleSecondaria(matrice);
    return 0;
}

void stampaDiagonalePrincipale(int matrice[N][N])
{
    int i;
    
    printf("Diagonale printipale = [ ");
    for(i = 0; i < N; i++)
    {
        printf(" %d ", matrice[i][i]);
    }
    printf("]\n");
}

void stampaDiagonaleSecondaria(int matrice[N][N])
{
    int i;
    
    // Il messaggio di output corrisponde al calcolo
    printf("Diagonale secondaria = [ "); 
    
    for(i = 0; i < N; i++)
    {
        // Gli indici per la diagonale secondaria sono [i][N - 1 - i]
        printf(" %d ", matrice[i][N - 1 - i]);
    }
    printf("]\n");
}

int minimoMatrice(int matrice[N][N])
{
    int i, j;

    int min = matrice[0][0];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (matrice[i][j] < min)
                min = matrice[i][j];
        }
    }
    return min;
}

void generaMatrice(int matrice[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrice[i][j] = (rand() % 100) + 1;
        }
    }
}

void stampaMatrice(int matrice[N][N])
{
    int i, j;
    printf("Matrice Casuale %d x %d:\n", N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", matrice[i][j]);
        }
        printf("\n");
    }
}