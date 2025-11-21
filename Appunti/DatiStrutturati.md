

# Tipi di Dato Strutturato: Strutture in C


## Concetti Fondamentali

-   I tipi di dato strutturato includono array, stringhe, matrici, e strutture.
    
-   Una **struttura** (o `struct`, keyword in C/C++) è una collezione di elementi a cui viene dato un unico nome.
    
-   Gli elementi di una struttura sono detti **campi** o **membri**.
    
-   I campi possono essere dello stesso tipo, ma anche di **tipo diverso**.
    

----------

## Dichiarazione e Sintassi

La dichiarazione fissa il nome della struttura e ne elenca i campi, specificando per ognuno il tipo di appartenenza.

**Sintassi di Base**

C

```
struct nome_struttura {
    tipo_campo1 nome_campo1;
    tipo_campo2 nome_campo2;
    // ...
    tipo_campoN nome_campoN;
}; // Non dimenticare il punto e virgola finale!

```

**Esempi di Applicazione**

-   `struct punto3d` è definita con tre coordinate di tipo `float`: `x`, `y`, `z`.
    
-   `struct puntoCartesiano` usa coordinate `float coordX` e `float coordY`.
    
-   `struct POI` (Point of Interest) può avere `float latitudine`, `float longitudine` e `char tipologia [30]`.
    

----------

## Definizione e Inizializzazione di Variabili

Per la definizione si usa il nome del tipo struttura seguito dai nomi delle variabili:

-   **Definizione:** `struct nome_struttura struttura1, struttura2;`
    
-   **Definizione e Inizializzazione:** `struct nome_struttura struttura3 = {valore1, valore2, valoreN};` (inizializzando i campi).
    

Dichiarazione Unica

È possibile usare un'unica dichiarazione per il tipo e per le variabili:

C

```
struct nome_struttura {
    // ... campi
} struttura1, struttura2;

```

In una tale definizione si può anche omettere il nome della struttura, introducendo un tipo senza nome non più utilizzabile in seguito.

----------

## Accesso ai Campi (Dot Notation)

Una volta definita una variabile di tipo `struct`, si può operare con i suoi campi.

-   Si accede ai campi con il nome della variabile seguito da un **punto** (`.`) e dal nome del campo.
    
-   **Sintassi:** `nome_struttura.nome_campo`
    

**Esempio con data**

C

```
struct tipo_data data_esame; 
data_esame.giorno = 10;
strcpy(data_esame.mese, "Giugno"); 
data_esame.anno = 2022;

```

----------

## Definizione di Tipi Strutturati con `typedef`

È possibile introdurre un alias (un nuovo nome di tipo) per una struttura tramite `typedef`, il che è conveniente per dichiarare variabili in diverse parti del programma.

**Sintassi Consigliata**

C

```
typedef struct tipo_data {
    int giorno;
    char mese [15];
    int anno;
} Data; // Data è il nuovo tipo alias

Data data_esame = {10, "Giugno", 2022}; // Uso del tipo custom Data

```

Questo permette di usare l'alias `Data` al posto di `struct tipo_data` per dichiarare nuove variabili.

----------

## Dimensione di una Struttura e Padding

La dimensione di una `struct` ottenuta con `sizeof` potrebbe non essere la semplice somma dei byte dei singoli campi.

-   Il compilatore C aggiunge automaticamente dei byte di riempimento (**padding**) vuoti.
    
-   Il padding serve per **allineare i dati in memoria** e permettere un accesso più efficiente, in base al parallelismo della CPU (es. allineamento a 4 byte per processori a 32 bit).
    
-   L'uso dell'operatore **`&`** (indirizzo) su una variabile `struct` identifica l'indirizzo del **primo campo** della struttura.
    

----------

## Raccomandazioni Operative

### Assegnazione tra Struct

-   La copia di un intero record in un altro dello stesso tipo è ammessa (es. `s2 = s1`).
    
    -   Questa operazione esegue la copia dei campi.
        
-   **Attenzione:** Se la struttura contiene **stringhe**, **array** o tipi strutturati, l'assegnazione diretta potrebbe non avere il comportamento atteso.
    
-   È più sicuro assegnare **un campo alla volta**.
    

### Passaggio come Parametro

-   Una variabile di tipo `struct` viene passata alle funzioni per **copia del valore**.
    
-   Una modifica di un campo nella funzione chiamata **non si riflette** nel chiamante.
    

### Input/Output e Confronto

-   Per l'Input e l'Output (es. `printf` o `scanf`), è necessario operare **un campo alla volta**.
    
-   L'operatore di confronto **`==`** ha lo stesso comportamento del caso array.
    
-   Non esistono operatori di confronto diretti come `<` o `>`.
    

----------

## Array di Strutture

-   Gli array sono dati strutturati omogenei, e i loro elementi possono essere strutture.
    
-   È possibile definire un **array di record**.
    
    -   _Esempio:_ `struct persona info_utenti[100];`
        
-   Se il numero di strutture non è noto a priori, si dichiara un array grande a sufficienza (caso peggiore) e si usa una variabile **riempimento** per tenere traccia del numero effettivo di elementi.
    
-   **Esempio di modellazione:** Una biblioteca come un array di strutture `libro`, ognuna con titolo, autore e numero di pagine.
    

----------

Vorresti che ti fornissi un esempio di codice commentato per l'accesso ai campi di un array di strutture, come per l'esempio della biblioteca?Certamente! Ecco gli appunti in Markdown senza numeri o riferimenti di pagina, mantenendo la struttura logica e il contenuto accademico del documento.

----------

# Tipi di Dato Strutturato: Strutture in C

Questo corso è di Fondamenti di Informatica, tenuto all'Università degli Studi di Napoli Federico II.

----------

## Concetti Fondamentali

-   I tipi di dato strutturato includono array, stringhe, matrici, e strutture.
    
-   Una **struttura** (o `struct`, keyword in C/C++) è una collezione di elementi a cui viene dato un unico nome.
    
-   Gli elementi di una struttura sono detti **campi** o **membri**.
    
-   I campi possono essere dello stesso tipo, ma anche di **tipo diverso**.
    

----------

## Dichiarazione e Sintassi

La dichiarazione fissa il nome della struttura e ne elenca i campi, specificando per ognuno il tipo di appartenenza.

**Sintassi di Base**

C

```
struct nome_struttura {
    tipo_campo1 nome_campo1;
    tipo_campo2 nome_campo2;
    // ...
    tipo_campoN nome_campoN;
}; // Non dimenticare il punto e virgola finale!

```

**Esempi di Applicazione**

-   `struct punto3d` è definita con tre coordinate di tipo `float`: `x`, `y`, `z`.
    
-   `struct puntoCartesiano` usa coordinate `float coordX` e `float coordY`.
    
-   `struct POI` (Point of Interest) può avere `float latitudine`, `float longitudine` e `char tipologia [30]`.
    

----------

## Definizione e Inizializzazione di Variabili

Per la definizione si usa il nome del tipo struttura seguito dai nomi delle variabili:

-   **Definizione:** `struct nome_struttura struttura1, struttura2;`
    
-   **Definizione e Inizializzazione:** `struct nome_struttura struttura3 = {valore1, valore2, valoreN};` (inizializzando i campi).
    

Dichiarazione Unica

È possibile usare un'unica dichiarazione per il tipo e per le variabili:

C

```
struct nome_struttura {
    // ... campi
} struttura1, struttura2;

```

In una tale definizione si può anche omettere il nome della struttura, introducendo un tipo senza nome non più utilizzabile in seguito.

----------

## Accesso ai Campi (Dot Notation)

Una volta definita una variabile di tipo `struct`, si può operare con i suoi campi.

-   Si accede ai campi con il nome della variabile seguito da un **punto** (`.`) e dal nome del campo.
    
-   **Sintassi:** `nome_struttura.nome_campo`
    

**Esempio con data**

C

```
struct tipo_data data_esame; 
data_esame.giorno = 10;
strcpy(data_esame.mese, "Giugno"); 
data_esame.anno = 2022;

```

----------

## Definizione di Tipi Strutturati con `typedef`

È possibile introdurre un alias (un nuovo nome di tipo) per una struttura tramite `typedef`, il che è conveniente per dichiarare variabili in diverse parti del programma.

**Sintassi Consigliata**

C

```
typedef struct tipo_data {
    int giorno;
    char mese [15];
    int anno;
} Data; // Data è il nuovo tipo alias

Data data_esame = {10, "Giugno", 2022}; // Uso del tipo custom Data

```

Questo permette di usare l'alias `Data` al posto di `struct tipo_data` per dichiarare nuove variabili.

----------

## Dimensione di una Struttura e Padding

La dimensione di una `struct` ottenuta con `sizeof` potrebbe non essere la semplice somma dei byte dei singoli campi.

-   Il compilatore C aggiunge automaticamente dei byte di riempimento (**padding**) vuoti.
    
-   Il padding serve per **allineare i dati in memoria** e permettere un accesso più efficiente, in base al parallelismo della CPU (es. allineamento a 4 byte per processori a 32 bit).
    
-   L'uso dell'operatore **`&`** (indirizzo) su una variabile `struct` identifica l'indirizzo del **primo campo** della struttura.
    

----------

## Raccomandazioni Operative

### Assegnazione tra Struct

-   La copia di un intero record in un altro dello stesso tipo è ammessa (es. `s2 = s1`).
    
    -   Questa operazione esegue la copia dei campi.
        
-   **Attenzione:** Se la struttura contiene **stringhe**, **array** o tipi strutturati, l'assegnazione diretta potrebbe non avere il comportamento atteso.
    
-   È più sicuro assegnare **un campo alla volta**.
    

### Passaggio come Parametro

-   Una variabile di tipo `struct` viene passata alle funzioni per **copia del valore**.
    
-   Una modifica di un campo nella funzione chiamata **non si riflette** nel chiamante.
    

### Input/Output e Confronto

-   Per l'Input e l'Output (es. `printf` o `scanf`), è necessario operare **un campo alla volta**.
    
-   L'operatore di confronto **`==`** ha lo stesso comportamento del caso array.
    
-   Non esistono operatori di confronto diretti come `<` o `>`.
    

----------

## Array di Strutture

-   Gli array sono dati strutturati omogenei, e i loro elementi possono essere strutture.
    
-   È possibile definire un **array di record**.
    
    -   _Esempio:_ `struct persona info_utenti[100];`
        
-   Se il numero di strutture non è noto a priori, si dichiara un array grande a sufficienza (caso peggiore) e si usa una variabile **riempimento** per tenere traccia del numero effettivo di elementi.
    
-   **Esempio di modellazione:** Una biblioteca come un array di strutture `libro`, ognuna con titolo, autore e numero di pagine.
    

----------

