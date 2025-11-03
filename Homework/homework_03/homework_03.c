#include <stdio.h>
#include <math.h>

typedef unsigned int misura;
typedef float scalare;

int main()
{
    // Inizialiizazione variabili 
    misura bRettangolo, aRettangolo, area, perimetro;
    scalare s, d, aScalata;

    // Inserimenti
    printf("Insersici la base: ");
    scanf("%u", &bRettangolo);

    printf("Insersici l'altezza: ");
    scanf("%u", &aRettangolo);

    printf("Insersici la scala: ");
    scanf("%f", &s);

    // Calcoli 
    perimetro = 2u * (bRettangolo + aRettangolo);
    area = bRettangolo * aRettangolo;
    d = sqrt(pow(bRettangolo, 2) + pow(aRettangolo, 2));
    aScalata = area * pow(s, 2);

    // Stampa a video
    printf("Rettangolo: P = <%u>\t A = <%u>\t d = <%f>\n", perimetro, area, d);
    printf("Scala: <%f>\t A2=<%f>", s, aScalata);

    return 0;
}