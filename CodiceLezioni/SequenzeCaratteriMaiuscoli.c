#include <stdio.h>

int main()
{
    char c;
    printf("Inserisci un carattere: ");
    scanf(" %c", &c);

    if(c >= 'A' && c <= 'Z')
    {
        while(c <= 'Z')
        {
            printf(" %c", c);
            c++;
        }
    }


}