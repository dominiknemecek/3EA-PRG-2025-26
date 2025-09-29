#include <stdio.h>
#include <stdlib.h> // funkce srand, rand, exit
#include <time.h> // time (pro inicializaci generátoru náhodných čísel)

// Maximální počet PIN kódů, které mohou být vygenerovány
#define MAX_PINY 100 

int main() {
    int N;
    int piny[MAX_PINY];  // Pole pro uchování unikátních PIN kódů

    // Inicializace generátoru náhodných čísel
    srand(time(NULL));

    printf("Zadejte počet PIN kódů, které chcete vygenerovat: ");
    scanf("%d", &N);

    // Ověření, že požadovaný počet PIN kódů není vyšší než limit
    if (N > MAX_PINY) {
        printf("Počet PIN kódů je příliš vysoký, maximálně %d.\n", MAX_PINY);
        return 1;
    }

    int vygenerovanePiny = 0;  // Počet vygenerovaných unikátních PIN kódů
    while (vygenerovanePiny < N) {
        // Vygenerování náhodného 4-místného PIN kódu
        // Pokud: rand() % 8000 = 0 až 7999
        // Pokud: rand() % 8000 + 1000 = 1000 až 8999
        int pin = rand() % 9000 + 1000; // 1000 až 9999

        // Kontrola, zda PIN kód již neexistuje
        int existuje = 0;
        for (int i = 0; i < vygenerovanePiny; i++) {
            if (piny[i] == pin) {
                existuje = 1;  // PIN již existuje
                break;
            }
        }

        // Pokud PIN neexistuje, přidáme ho do pole
        if (!existuje) {
            piny[vygenerovanePiny] = pin;
            vygenerovanePiny++;
        }
    }

    // Výpis vygenerovaných PIN kódů
    printf("Vygenerované PIN kódy:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", piny[i]);
    }

    return 0;
}

