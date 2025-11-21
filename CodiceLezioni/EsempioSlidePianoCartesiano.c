#include <stdio.h>

typedef struct
{
    double x;
    double y;
}
Coordinate;


int main()
{
    int i;
    int primoQuadrante = 0;
    int secondoQuadrante = 0;
    int terzoQuadrante = 0;
    int quartoQuadrante = 0;
    Coordinate v[15];

    for(i = 0; i < 15; i++)
    {
        printf("Inserisci il %d punto\n", i+1);
        printf("Inserisci i punto x: ");
        scanf("%lf", &v[i].x);

        printf("Inserisci i punto y: ");
        scanf("%lf", &v[i].y);
    }

    // Verifico i quadranti
    for(i = 0; i < 15; i++)
    {
        if ( (v[i].x > 0) && (v[i].y > 0) )
        {
            primoQuadrante++;
        }
        else if ( (v[i].x > 0) && (v[i].y < 0) )
        {
            quartoQuadrante++;
        }
        else if ( (v[i].x < 0) && (v[i].y < 0) )
        {
            terzoQuadrante++;
        }
        else
        {
            secondoQuadrante++;
        }
    }

    printf("Numeri primo: %d\nNumeri secondo: %d\n Numeri terzo: %d\nNumeri Quarto: %d\n", primoQuadrante, secondoQuadrante, terzoQuadrante, quartoQuadrante);
    return 0;
}