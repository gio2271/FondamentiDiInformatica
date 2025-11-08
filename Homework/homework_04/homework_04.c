/*
Homework 4
Giovanni Iaquinto
DE3000077
*/

#include <stdio.h>
#include <ctype.h> // Includo "ctype.h" per utilizzare la funzione toupper()
int main()
{
    // Dichiarazione variabili
    int x;
    char dataType;

    // Inizio
    printf("Inserisci il tipo di variabile (i=int, f=float, d=double, c=char): ");
    scanf(" %c", &dataType);

    // Scelta del tipo e dichiarazione
    switch(toupper(dataType)) // Uso la funzione toupper() per normalizzare l'input dell'utente
    {
        case 'I':
            // Int
            int intVar;
            int *pIntVar = &intVar;

            
            printf("Tipo scelto: int\n");
            printf("Indirizzo della variabile: %p\n", pIntVar);

            
            printf("Inserisci un valore intero x: ");
            scanf("%d", &x);
            printf("Indirizzo precedente: %p\n", (pIntVar - x));
            printf("Indirizzo successivo: %p\n", (pIntVar + x));

            
            printf("Inserisci il nuovo valore di tipo int: ");
            scanf("%d", pIntVar); // Aggiorno usando il puntatore e %d
            
            printf("Il nuovo valore della variabile e': %d\n", intVar);
            break;

        case 'F':
            // Float
            float floatVar;
            float *pFloatVar = &floatVar;
            
            printf("Tipo scelto: float\n");
            printf("Indirizzo della variabile: %p\n", pFloatVar);

            
            printf("Inserisci un valore intero x: ");
            scanf("%d", &x);
            printf("Indirizzo precedente: %p\n", (pFloatVar - x));
            printf("Indirizzo successivo: %p\n", (pFloatVar + x));

            
            printf("Inserisci il nuovo valore di tipo float: ");
            scanf("%f", pFloatVar); // Aggiorno usando il puntatore e %f
            
            printf("Il nuovo valore della variabile e': %f\n", floatVar);
            break;

        case 'D':
            // Double
            double doubleVar;
            double *pDoubleVar = &doubleVar;

            printf("Tipo scelto: double\n");
            printf("Indirizzo della variabile: %p\n", pDoubleVar);

            
            printf("Inserisci un valore intero x: ");
            scanf("%d", &x);
            printf("Indirizzo precedente: %p\n", (pDoubleVar - x));
            printf("Indirizzo successivo: %p\n", (pDoubleVar + x));

            
            printf("Inserisci il nuovo valore di tipo double: ");
            scanf("%lf", pDoubleVar); // Aggiorno usando il puntatore e %lf
            
            printf("Il nuovo valore della variabile e': %lf\n", doubleVar);
            break;

        case 'C':
            // Char
            char charVar;
            char *pCharVar;
            
            printf("Tipo scelto: double\n");
            printf("Indirizzo della variabile: %p\n", pCharVar);

            
            printf("Inserisci un valore intero x: ");
            scanf("%d", &x);
            printf("Indirizzo precedente: %p\n", (pCharVar - x));
            printf("Indirizzo successivo: %p\n", (pCharVar + x));

            
            printf("Inserisci il nuovo valore di tipo char: ");
            scanf(" %c", pCharVar); // Aggiorno usando il puntatore e %c
            
            printf("Il nuovo valore della variabile e': %c\n", charVar);
            break;
    }
    return 0;
}