#include <stdio.h>
#include <math.h>

// Prototipi 
void distanzaPunti(double, double, double, double, double*);
int batteryManager(double*, double, char);


int main()
{
    // Inizializzazione variabili
    double x1, x2, y1, y2, dist;
    double batteryLevel;
    double x;
    char batteryOp;

    // Inizio - PARTE 1
    printf("Inserisci i valori per calcoalre la distanza tra due punti.\n\n");

    printf("Inserisci x1: ");
    scanf("%lf", &x1);

    printf("Inserisci y1: ");
    scanf("%lf", &y1);

    printf("Inserisci x2: ");
    scanf("%lf", &x2);

    printf("Inserisci y2: ");
    scanf("%lf", &y2);

    // Chiamo la PROCEDURA per il calcolo della distanza
    distanzaPunti(x1, y1, x2, y2, &dist);

    // Stampo a schermo il risultato
    printf("La distanza tra i due punti inseriti e': %lf\n\n", dist);

    // Inizio - PARTE 2
    do
    {
        printf("Inserisci il livello di batteria (0, 100): ");
        scanf("%lf", &batteryLevel);

        if ( (batteryLevel < 0) || (batteryLevel > 100) )
            printf("Livello di batteria inserito non valido!. \n");

    }
    while( (batteryLevel < 0) || (batteryLevel > 100) );

    printf("Energia da applicare: ");
    scanf("%lf", &x);

    printf("Azione (+ per caricare, - per consumare): ");
    scanf(" %c", &batteryOp);

    // Chiamo la FUNZIONE per l'aggiornamento dello stato della batteria
    switch (batteryManager(&batteryLevel, x, batteryOp))    // Dato che la funzione restituisce un valore INTERO posso utilizzare il blocco switch-case
    {
        case 0:
            printf("Il livello della batteria attuale e': %d\n", batteryLevel);
            break;
        
        case -1:
            printf("Azione inserita non valida!\n");
            break;
        
        case -2:
            printf("Livello risultante fuori dal range consentito!\n");
            break;
    }
}

// Corpo della PROCEDURA distanzaPunti()
void distanzaPunti(double x1, double y1, double x2, double y2, double *dist)
{
    // Calcolo la distanza tra i 2 punti
    *dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return;
}

// Corpo della FUNZIONE batteryManager()
int batteryManager(double *batteryLevel, double x, char operation)
{
    
    // Controllo sull'operazione inserita
    switch (operation)
    {
        double newBatteryLevel
        case '+':
            newBatteryLevel = *batteryLevel + x;
            break;
        
        case '-':
            newBatteryLevel = *batteryLevel - x;
            break;

        default: 
            // Ritorno il codice di errore -1 legato alla validità dell'operazione inserita
            return -1;
            break;
    }

    // Controllo se la batteria è fuori il range preistabilito
    if ( (newBatteryLevel < 0) || (newBatteryLevel > 100) )
        return -2;

    // Se è tutto nel range aggiorno il valore della batteria
    *batteryLevel = newBatteryLevel;

    return 0;
    
}
