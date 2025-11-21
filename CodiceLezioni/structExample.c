#include <stdio.h>

// IN AMBIENTE GLOBALE

// Dichiarazione di un tipo strutturato (Tutto insieme)
typedef struct
{
    int Giorno;
    int Mese;
    int Anno;
}
DataNascita;

// Dichiarazione di una struttura
struct 
{
    char Nome[50+1]; // NB: 1 è il carattere di riempimento delle stringhe.
    char Cognome[50+1];
    int DataNascita;
} Persona;

typedef struct Persona utente;

