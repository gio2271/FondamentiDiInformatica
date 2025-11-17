# Tipi di dato strutturato: Array - Lezione 13

## 1. Array: Definizione e Dichiarazione

Un **array** è un insieme di elementi **dello stesso tipo** (variabili, strutture, o oggetti). Gli elementi sono memorizzati in **locazioni di memoria consecutive (contigue)**.

-   **Dimensione (o Cardinalità):** Il numero totale di elementi che l'array può contenere.
    
-   **Dichiarazione:** Si specifica tipo, nome e dimensione.
    
    ```
    tipo nome_array[dimensione];
    
    ```
    
-   **Regola Fondamentale:** La `dimensione` deve essere un **valore costante** (noto a tempo di compilazione) affinché il compilatore possa allocare la memoria necessaria.
    
-   Se un array viene dichiarato senza inizializzazione, il suo contenuto non è definito (contiene valori "spazzatura" presi dall'interno della memoria).
    

----------

## 2. Inizializzazione degli Array

L'inizializzazione si effettua al momento della dichiarazione, indicando i valori tra parentesi graffe `{}` e separati da virgole.

```
// Array di 5 interi non inizializzato
// Il contenuto delle locazioni non è definito
int vettore[5]; [cite: 20, 22]

// Array di 3 float inizializzato
float numeri[3] = {0.5, -13.25, 12.2}; [cite: 24]

// Array di 5 char inizializzato
char lettere[5] = {'a', 'b', 'c', 'd', 'e'}; [cite: 26]

```

----------

## 3. Accesso agli Elementi

Si accede a un elemento specifico usando il nome dell'array seguito dall'indice tra parentesi quadre `[]`.

-   L'indice del primo elemento è **0**, l'ultimo è **dimensione - 1**.
    
-   L'indice può essere una costante, una variabile o un'espressione, purché sia di tipo intero.
    
-   **Attenzione:** Il programmatore è responsabile di assicurarsi che l'indice rimanga nei limiti (da 0 a dimensione-1). Usare un indice non valido (es. maggiore o uguale alla dimensione) porta a un comportamento indefinito (errore "out-of-bounds").
    

```
int voti[3] = {28, 30, 25};

// Assegnazione (Scrittura)
voti[0] = 29; // Modifica il primo elemento 

// Lettura
int mio_voto = voti[1]; // mio_voto ora vale 30 

// Accesso con variabile
int i = 2;
printf("%d", voti[i]); // Stampa 25 

```

----------

## 4. Gestione del Riempimento

Spesso non si sa quanti elementi serviranno (a tempo di compilazione), ma solo un numero massimo.

**Soluzione (Allocazione Statica):**

1.  Si dichiara un array con la **dimensione massima** possibile (caso peggiore).
    
2.  Si usa una **variabile contatore** (es. `riempimento`) per tenere traccia di quanti elementi sono _effettivamente_ presenti nell'array.
    

Questa tecnica spreca memoria, allocando più spazio di quello forse necessario15. Il programmatore deve gestire manualmente l'aggiornamento della variabile `riempimento`.

```
#define MAXDIM 100 // Dimensione massima

int main() {
    int v[MAXDIM];    // Alloca spazio per 100 interi [cite: 90]
    int riempimento = 0; // Inizialmente l'array è vuoto [cite: 91]

    // Aggiungo il primo elemento
    v[riempimento] = 10; // v[0] = 10 
    riempimento++;       // Ora ho 1 elemento 

    // Aggiungo il secondo elemento
    v[riempimento] = 20; // v[1] = 20 
    riempimento++;       // Ora ho 2 elementi 

    // Per "cancellare" l'ultimo elemento, basta decrementare il riempimento
    riempimento--; [cite: 132]
    // L'array ora ha logicamente 1 elemento (v[0])
    // v[1] contiene ancora 20, ma viene ignorato

    return 0;
}

```

----------

## 5. Passaggio di Array alle Funzioni

-   In C, i parametri sono passati **per valore** (viene creata una copia).
    
-   Tuttavia, il **nome di un array** è un'eccezione: identifica l'indirizzo di memoria del suo primo elemento.
    
-   Di conseguenza, `v` e `&v[0]` sono equivalenti.
    
-   Quando si passa un array a una funzione, si sta passando l'indirizzo del primo elemento. La funzione lavora sull'array originale 20, quindi **può modificarlo**.
    
```
// Prototipo di funzione
// Non serve specificare la dimensione nel prototipo
void stampa(int v[], int dimensione);

int main() {
    int mio_vettore[5] = {1, 2, 3, 4, 5};
    
    // Chiamata alla funzione
    stampa(mio_vettore, 5); 
    // È equivalente a: stampa(&mio_vettore[0], 5); 
    
    return 0;
}

```

### Keyword `const`

Poiché la funzione può modificare l'array originale, si può usare la keyword `const` per una **programmazione difensiva**. `const` rende l'array di **sola lettura** all'interno della funzione, impedendo modifiche accidentali.
```
// L'array 'v' è ora read-only dentro questa funzione
void stampa(const int v[], int dimensione) 
{ 
    for (int i = 0; i < dimensione; i++) 
    {
        printf("%d ", v[i]); [cite: 203]
        // v[i] = 0; // -> ERRORE DI COMPILAZIONE! 
    }
}

```

----------

## 6. Array Multidimensionali (Matrici)

È possibile dichiarare array a più dimensioni. Una matrice (array bidimensionale) è un esempio comune.

-   **Dichiarazione:**  `tipo nome_array[dim1][dim2];` (es. `int mat[2][3];` per 2 righe e 3 colonne).
    
-   **Memoria:** Anche le matrici sono allocate in locazioni consecutive, disponendo le righe una dopo l'altra (row-major order).
    
-   **Accesso:** Si usano due indici: `nome_array[indice_riga][indice_colonna]`.
    
-   **Iterazione:** Per accedere a tutti gli elementi, servono **due cicli for annidati**.
    


```
// Inizializzazione (2 righe, 3 colonne)
// La notazione con doppie graffe è più chiara
int mat[2][3] = { {1, 2, 3},   // Prima riga (indice 0)
                  {4, 5, 6} }; // Seconda riga (indice 1)


// Accesso
mat[1][2] = 10; // Modifica l'elemento in riga 1, colonna 2 (che era 6) 

// Scrittura/Iterazione di una matrice 3x3
int m[3][3];
for (int i = 0; i < 3; i++) 
{ // Scorre le righe 
    for (int j = 0; j < 3; j++) 
    { // Scorre le colonne 
        m[i][j] = 0; // Inizializza l'elemento 
    }
}

```

----------

## 7. Algoritmi Comuni su Array

(Si assume un array `vet` e un contatore `riemp`)

### Trovare il Massimo

Si inizializza `max` al primo elemento, poi si scorre il resto dell'array aggiornando `max` se si trova un elemento maggiore.


```
int max = vet[0]; [cite: 303]
for (int i = 1; i < riemp; i++) 
{ 
    if (vet[i] > max) 
    { 
        max = vet[i]; 
    }
}

```

### Somma degli Elementi

Si usa una variabile "accumulatore" inizializzata a 0.


```
int somma = 0; [cite: 318]
for (int i = 0; i < riemp; i++) 
{ 
    somma = somma + vet[i]; // Oppure somma += vet[i]; 
}

```

### Ricerca Lineare (Prima Occorrenza)

Si cerca un elemento `el` e ci si ferma non appena lo si trova.


```
bool trovato = false; 
int posizione = 0; 
int el = 5; // Elemento da cercare

while (!trovato && posizione < riemp) 
{ 
    if (vet[posizione] == el) 
    { 
        trovato = true; 
    } 
    else 
    {
        posizione++; 
    }
}

if (trovato) 
{
    // Trovato in 'posizione'
} else 
{
    // Non presente 
}

```

### Cancellazione di un Elemento (in posizione `pos`)

Si "elimina" l'elemento in posizione `pos` spostando **indietro di 1** tutti gli elementi successivi (`pos+1`, `pos+2`, ...). Infine, si decrementa `riemp`.

```
int pos = 1; // Posizione da cancellare

// Sposta all'indietro gli elementi da pos+1 fino alla fine
for (int i = pos; i < riemp - 1; i++) 
{ 
    vet[i] = vet[i+1]; 
}
riemp--; // Decrementa il numero di elementi effettivi 

```

### Inserimento di un Elemento (in posizione `pos`)

Per inserire `el` in posizione `pos`, si spostano **in avanti di 1** tutti gli elementi da `pos` fino alla fine. È cruciale eseguire lo scorrimento **partendo dalla fine** per non sovrascrivere i dati34343434.


```
int pos = 1; // Posizione in cui inserire
int el = 99; // Elemento da inserire

// Incrementa prima il riempimento
riemp++; 

// Sposta in avanti gli elementi partendo dalla fine
for (int i = riemp - 1; i > pos; i--) 
{ 
    vet[i] = vet[i-1]; 
}

// Inserisce il nuovo elemento nella posizione liberata
vet[pos] = el; 

```

----------

## 8. Accesso a Matrici

### Accesso a Righe/Colonne Specifiche

-   **Prima riga:** Indice di riga `0`.
    
-   **Prima colonna:** Indice di colonna `0`.
    
-   **Ultima riga:** Indice di riga `righe - 1`.
    
-   **Ultima colonna:** Indice di colonna `colonne - 1`.
    

### Accesso alle Diagonali (Matrici Quadrate)

Questo si applica a matrici quadrate (numero righe = numero colonne = `dim`).

#### Diagonale Principale

Gli elementi hanno indice di riga e colonna uguali (`[i][i]`).


```
// Scorre la diagonale principale
for (int i = 0; i < dim; i++) 
{ 
    // Accesso a mat[i][i]
    printf("%d", mat[i][i]); 
}

```

#### Diagonale Secondaria

Gli elementi hanno indici `[i][dim - 1 - i]`.

C

```
// Scorre la diagonale secondaria
for (int i = 0; i < dim; i++) { [cite: 458]
    // Accesso a mat[i][dim - 1 - i]
    printf("%d", mat[i][dim - 1 - i]); [cite: 459]
}

```
