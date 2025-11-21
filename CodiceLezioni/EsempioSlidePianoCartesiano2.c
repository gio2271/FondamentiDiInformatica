#include <stdio.h>
#include <math.h>
#include <float.h>

double distanzaPunti(double x1, double y1, double x2, double y2);
double distanzaAsseOrdinate(double x);
double distanzaAsseAscisse(double y);

typedef struct
{
    double x;
    double y;
}
Coordinate;


int main()
{
    int i;
    double minDistanza;
    double maxDistanza;
    double minDistanzaAsseY;
    double minDistanzaAsseX;
    double tempDist, tempDistAsseY, tempDistAsseX; 
    
    double maxDistanzaAsseX, maxDistanzaAsseY;
    minDistanzaAsseX = DBL_MAX; 
    maxDistanzaAsseX = 0; 
    maxDistanzaAsseY = 0; 
    

    Coordinate v[15];
    Coordinate puntoUtente;

    for(i = 0; i < 15; i++)
    {
        printf("Inserisci il %d punto\n", i+1);
        printf("Inserisci i punto x: ");
        scanf("%lf", &v[i].x);

        printf("Inserisci i punto y: ");
        scanf("%lf", &v[i].y);
    }

    printf("Inserisci il punto utente\n");
    printf("Inserisci i punto x: ");
    scanf("%lf", &puntoUtente.x);

    printf("Inserisci i punto y: ");
    scanf("%lf", &puntoUtente.y);

    minDistanza = distanzaPunti(puntoUtente.x, puntoUtente.y, v[0].x, v[0].y);
    maxDistanza = minDistanza;
    
    minDistanzaAsseY = distanzaAsseOrdinate(v[0].x); 
    
    minDistanzaAsseX = distanzaAsseAscisse(v[0].y);


    for(i = 1; i < 15; i++)
    {
        tempDist = distanzaPunti(puntoUtente.x, puntoUtente.y, v[i].x, v[i].y);
        
        if (tempDist > maxDistanza)
        {
            maxDistanza = tempDist;
        }
        if (tempDist < minDistanza)
        {
            minDistanza = tempDist;
        }

        tempDistAsseY = distanzaAsseOrdinate(v[i].x);
        
        if (tempDistAsseY < minDistanzaAsseY)
        {
            minDistanzaAsseY = tempDistAsseY;
        }
        
        tempDistAsseX = distanzaAsseAscisse(v[i].y);
        
        if (tempDistAsseX < minDistanzaAsseX)
        {
            minDistanzaAsseX = tempDistAsseX;
        }
    }
    
    printf("\n--- Risultati Distanze ---\n");
    printf("Minima distanza tra Punto Utente e array: %.4lf\n", minDistanza);
    printf("Massima distanza tra Punto Utente e array: %.4lf\n", maxDistanza);
    printf("Minima distanza dall'asse delle ordinate (Y) per i 15 punti: %.4lf\n", minDistanzaAsseY);
    printf("Minima distanza dall'asse delle ascisse (X) per i 15 punti: %.4lf\n", minDistanzaAsseX);
    
    return 0;
}


double distanzaPunti(double x1, double y1, double x2, double y2)
{
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

double distanzaAsseOrdinate(double x)
{
    return fabs(x);
}

double distanzaAsseAscisse(double y)
{
    return fabs(y);
}