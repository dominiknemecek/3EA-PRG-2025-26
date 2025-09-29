#include <stdio.h>

#define VELIKOST 10  // pevná velikost pole

// Funkce Bubble Sort (seřazení pole vzestupně)
void tridPole(int pole[], int velikost) {
    // Vnější cyklus – opakuje průchod polem
    for (int i = 0; i < velikost - 1; i++) {
        // Vnitřní cyklus – porovnává dvojice sousedních prvků
        for (int j = 0; j < velikost - i - 1; j++) {
            // Pokud je aktuální prvek větší než následující → prohodíme
            if (pole[j] > pole[j + 1]) {
                int docasne = pole[j];       // uložíme si prvek
                pole[j] = pole[j + 1];       // menší vlevo
                pole[j + 1] = docasne;       // větší vpravo
            }
        }
        // Po každém průchodu je na konci pole jeden prvek na správném místě
    }
}

// Funkce pro výpis pole
void vypisPole(int pole[], int velikost, const char *text) {
    printf("%s", text);
    for (int i = 0; i < velikost; i++) {
        printf("%d ", pole[i]);
    }
    printf("\n");
}

int main(void) {
    int pole[VELIKOST];

    // Zadání pole uživatelem
    printf("Zadejte %d prvku pole: ", VELIKOST);
    for (int i = 0; i < VELIKOST; i++) {
        scanf("%d", &pole[i]);
    }

    // Výpis původního pole
    vypisPole(pole, VELIKOST, "Původní pole: ");

    // Seřazení pomocí Bubble Sort
    tridPole(pole, VELIKOST);

    // Výpis seřazeného pole
    vypisPole(pole, VELIKOST, "Seřazené pole: ");

    // Analýza pole
    int minimum = pole[0];                 // po seřazení je nejmenší první prvek
    int maximum = pole[VELIKOST - 1];      // a největší poslední prvek
    int pocetSudych = 0, pocetLichych = 0;
    int pocetKladnych = 0, pocetZapornych = 0;
    int soucet = 0;

    for (int i = 0; i < VELIKOST; i++) {
        soucet += pole[i];  // součet prvků pro výpočet průměru

        // Sudé / liché číslo
        if (pole[i] % 2 == 0)
            pocetSudych++;
        else
            pocetLichych++;

        // Kladné / záporné číslo
        if (pole[i] >= 0)
            pocetKladnych++;
        else
            pocetZapornych++;
    }

    double prumer = (double)soucet / VELIKOST;
    double procentoKladnych = (pocetKladnych * 100.0) / VELIKOST;
    double procentoZapornych = (pocetZapornych * 100.0) / VELIKOST;

    // Výsledky
    printf("Nejmenší číslo v poli: %d\n", minimum);
    printf("Největší číslo v poli: %d\n", maximum);
    printf("Počet sudých čísel: %d\n", pocetSudych);
    printf("Počet lichých čísel: %d\n", pocetLichych);
    printf("Počet kladných čísel: %d\n", pocetKladnych);
    printf("Počet záporných čísel: %d\n", pocetZapornych);
    printf("Procento kladných čísel: %.2f %%\n", procentoKladnych);
    printf("Procento záporných čísel: %.2f %%\n", procentoZapornych);
    printf("Průměr celého pole: %.2f\n", prumer);

    return 0;
}
