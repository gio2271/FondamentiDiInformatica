#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 50

// Definisco il tipo di dato strutturato
typedef struct
{
    char[6] Id;
    unsigned int nIngressi;
    unsigned int nOre;
} tipoAtleta;

void inserisciAtleti(tipoAtleta[], int*);
void stampaAtleti(tipoAtleta[], int);
void eliminazioneAtleti(tipoAtleta[], int*);
int ordinamentoESomma(tipoAtleta[], int);

int main()
{

    return 0;
}

void inserisciAtleti(tipoAtleta atleta[MAXDIM], int *n)
{

    do
    {
        printf("Inserisci il numero di atleti da memorizzare: ");
        scanf("%d", n);
    }
    while((*n <= 0) || (*n > MAXDIM));
    
}