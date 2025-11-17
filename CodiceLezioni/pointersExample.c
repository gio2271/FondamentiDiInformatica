#include <stdio.h>

int main()
{
    int x; 
    int *px;
    int **ppx;

    x = 4;
    px = &x;
    ppx = &px;

    printf("%d, %d, %d", x, *px, **ppx);
}