#include <stdio.h>
#define MAXDIM 60

int lunghezzaStringa(char[]);
int isEqual(char[], char[]);

int main()
{
    
    // Definizione di una stringa
    char stringa[10+1]; // +1 è per il carattere di terminazione (tappo)

    // Lettura di una stringa
    printf("Inserisci una stringa: ");
    // scanf("%s", stringa);
    // Metodo alternativo
    fgets(stringa, MAXDIM, stdin);

    // Assegnazione di una stringa
    // stringa = {'c', 'i', 'a', 'o', '\0'};


    // Stampa di una stringa
    printf("Stringa: %s\n", stringa);
    // Metodo alternativo
    // puts(string);

    // Verifico lunghezza stringa inserita
    printf("La stringa e' lunga: %d", lunghezzaStringa(stringa));

    char s2[MAXDIM] = {'c', 'i', 'a', 'o', '\0'};

    printf("Sono uguali: %d", isEqual(stringa, s2));
    return 0;
}

int lunghezzaStringa(char stringa[MAXDIM])
{
    int i = 0;
    
    while (stringa[i] != '\0')
    {
        i++;
    }

    return i;
}

int isEqual(char s1[MAXDIM], char s2[MAXDIM])
{
    int i;
    int equal = (lunghezzaStringa(s1), lunghezzaStringa(s2));

    i = 0;
    while ((equal) && s1[i] != '\0')
    {
        equal = s1[i] == s2[i];
        i++;
    }
    
    return equal;
}