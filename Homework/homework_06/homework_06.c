#include <stdio.h>
#include <stdlib.h> // Libreria inclusa per l'uso delle funzioni system() NON NECESSARIE

// Definisco la dimensione massima come costante
#define MAX_MISURE 50


// Definisco la struct (no typedef come da specifica)
struct Sensore
{
    int idSensore;
    double Valore;
    int timeStamp;
};

// Definisco i prototipi necessari
void insertMisurazioni(struct Sensore[], int);
void stampaMisurazioni(struct Sensore[], int);
double deleteValoreMinimo(struct Sensore[], int*);
int insertNewMisura(struct Sensore[], int*);
void sortArray(struct Sensore[], int);

int main()
{
    struct Sensore sensori[MAX_MISURE];
    int nMisure;
    int choice;


    // Gestisco l'inserimento iniziale prima di entrare nel menù
    do 
    {
        printf("Inserisci la quantità di misure da inserire: \n");
        scanf("%d", &nMisure);

        // Separo la condizione con elif per dare all'utente due messaggi di errore differenti
        if (nMisure <= 0) 
            printf("Deve essere inserita almeno una misura.\n");
        else if (nMisure > 50)
            printf("Non è possibile superare il massimo di 50 misure.\n");
         
    }
    while ( (nMisure <= 0) || (nMisure > 50) );
    
    insertMisurazioni(sensori, nMisure);

    system("CLS"); // OPZIONALE: Pulisco il terminale per la stampa del menù


    // CICLO DI GESTIONE DEL MENU
    do 
    {
        printf("========================================================\n");
        printf("||                  MENU GESTIONE SENSORI             ||\n");
        printf("========================================================\n");
        printf("|| 1. Stampa l'elenco delle misurazioni               ||\n");
        printf("|| 2. Cancella prima misurazione con valore minimo    ||\n");
        printf("|| 3. Inserisci una nuova misura in base al timestamp ||\n");
        printf("|| 4. Ordina l'array per timestamp crescente          ||\n");
        printf("|| 0. Esci dal programma                              ||\n");
        printf("=======================================================\n");
        printf("Inserisci la tua scelta: ");
        scanf(" %d", &choice);

        switch(choice)
        {
            case 1:
            {
                stampaMisurazioni(sensori, nMisure);
                break;
            }

            case 2:
            {
                printf("Eliminato il sensore con il seguente valore: %lf\n", deleteValoreMinimo(sensori, &nMisure));
                stampaMisurazioni(sensori, nMisure);
                break;
            }

            case 3:
            {
                if (insertNewMisura(sensori, &nMisure))
                {
                    printf("Nuova misura inserita con successo!\n");
                    stampaMisurazioni(sensori, nMisure);
                }
                else 
                {
                    printf("Errore! Il numero massimo di misure è stato raggiunto.\n");
                }
                break;
            }

            case 4:
            {
                sortArray(sensori, nMisure);

                printf("Array ordinato con successo!");
                stampaMisurazioni(sensori, nMisure);
                break;
            }

            default:
                printf("Ciao!!");
                break;
        }
        system("PAUSE");
        system("CLS"); // OPZIONALE: Pulisco il terminale per la stampa del menù
    }
    while (choice != 0);
    
    return 0;
}


void insertMisurazioni(struct Sensore sensori[MAX_MISURE], int nMisure)
{   
    int i;

    // Ciclo per inserimento delle misure scelte dall'utente
    for(i = 0; i < nMisure; i++)
    {
        printf("Inserisci la %d misura.\n", i+1);
        printf("Inserisci identificativo del sensore: ");
        scanf("%d", &sensori[i].idSensore);
        printf("\nInserisci il valore registrato dal sensore: ");
        scanf("%lf", &sensori[i].Valore);
        printf("\nInserisci il timestamp del valore registrato del sensore: ");
        scanf("%d", &sensori[i].timeStamp);

        printf("\n\n"); // Per staccare gli inserimenti tra i vari sensori
    }
    return;
}

void stampaMisurazioni(struct Sensore sensori[MAX_MISURE], int nMisure)
{
    int i;

    printf("LISTA SENSORI\n");
    // Ciclo per stampa dei dati relativi ad ogni sensore
    for(i = 0; i < nMisure; i++)
    {
        printf("Sensore %d\n", i+1);
        printf("Id: %d\n", sensori[i].idSensore);
        printf("Valore: %lf\n", sensori[i].Valore);
        printf("timeStamp: %d\n", sensori[i].timeStamp);
        
        printf("\n\n"); // Per staccare gli inserimenti tra i vari sensori
    }

    return;
}

double deleteValoreMinimo(struct Sensore sensori[], int *nMisure)
{
    double minValue;
    int posMinValue;
    int i;

    // Ricerco il minimo e ne segno la posizione
    minValue = sensori[0].Valore;

    for(i = 1; i < *nMisure; i++)
    {
        if (sensori[i].Valore < minValue)
        {
            minValue = sensori[i].Valore;
            posMinValue = i;
        }
    }
    printf("Minvalue %lf", minValue);
    *nMisure = *nMisure - 1;

    // Effettuo uno shift verso sx a partire dalla posizione del valore minimo da eliminare
    for(i = posMinValue; i < *nMisure; i++)
    {
        sensori[i] = sensori[i+1];
    }

    return minValue;
}

int insertNewMisura(struct Sensore sensori[], int *nMisure)
{
    int i;
    int found;
    int tempIdSensore, tempTimeStamp;
    double tempValore;
    int pos_to_insert;
    
    if (*nMisure < 50)
    {
        // Mi faccio inserire i valori del nuovo sensore
        printf("Inserisci identificativo del sensore: ");
        scanf("%d", &tempIdSensore);
        printf("\nInserisci il valore registrato dal sensore: ");
        scanf("%lf", &tempValore);
        printf("\nInserisci il timestamp del valore registrato del sensore: ");
        scanf("%d", &tempTimeStamp);

        i = 0; 
        found = 0;
        // Ricerco il sensore con lo stesso timeStamp di quello inserito dall'utente
        while ( (!found) && (i < *nMisure) )
        {
            if (tempTimeStamp == sensori[i].timeStamp)
                found = 1;
            else
               i++;     
        }
        
        // Inserisco il sensore dopo quello trovato se esiste, altrimenti aggiungo alla fine.
        pos_to_insert = i;
        
        if (found)
        {
            pos_to_insert = i + 1;
        }

        for (int j = *nMisure; j > pos_to_insert; j--) 
        {
            sensori[j] = sensori[j-1];
        }
        
        sensori[pos_to_insert].idSensore = tempIdSensore;
        sensori[pos_to_insert].Valore = tempValore;
        sensori[pos_to_insert].timeStamp = tempTimeStamp;
        
        (*nMisure)++;
        
        return pos_to_insert;
    }
    else
    {
        return -1;
    }
}

void sortArray(struct Sensore sensori[], int nMisure)
{
    int min, pos;
    struct Sensore temp;

    // Applico l'ordinamento al vettore per timeStamp
    for (int i = 0; i < nMisure - 1; i++) 
    {
        min = sensori[i].timeStamp;
        pos = i;
        for (int j = i + 1; j < nMisure; j++) 
        {
            if (sensori[j].timeStamp < min) 
            {
                min = sensori[j].timeStamp;
                pos = j;
            }
        }
        if (i != pos) 
        {
            temp = sensori[i];
            sensori[i] = sensori[pos];
            sensori[pos] = temp;
        }
    }
    return;
}