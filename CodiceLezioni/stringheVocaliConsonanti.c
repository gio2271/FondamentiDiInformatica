#include <stdio.h>
#include <string.h>
#define MAXDIM 50

int main()
{
    char s[MAXDIM], vocali[MAXDIM], consonanti[MAXDIM];
    int j, k;

    printf("Inserisci una stringa: ");
    fgets(s, MAXDIM, stdin);

    j = 0;
    k = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vocali[j] = s[i];
                j++;
                break;

            default:
                consonanti[k] = s[i];
                k++;
                break;
        }
    }
    
    vocali[j] = '\0';
    consonanti[k] = '\0';

    printf("Array vocali: %s\nArray consonanti: %s\n", vocali, consonanti);

}