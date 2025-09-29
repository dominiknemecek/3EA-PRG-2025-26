#include <stdio.h>

// Funkce pro načtení hodnot do pole
void nactiPole(int pole[], int velikost, char jmeno) {
    printf("Zadejte hodnoty pro pole %c:\n", jmeno);
    for (int i = 0; i < velikost; i++) {
        printf("%c[%d]: ", jmeno, i);
        scanf("%d", &pole[i]);
    }
}

// Funkce pro výpis pole
void vypisPole(int pole[], int velikost, char jmeno) {
    printf("Pole %c: ", jmeno);
    for (int i = 0; i < velikost; i++) {
        printf("%d ", pole[i]);
    }
    printf("\n");
}

// Funkce pro výměnu hodnot mezi dvěma poli
void vymenPole(int poleA[], int poleB[], int velikost) {
    for (int i = 0; i < velikost; i++) {
        int docasne = poleA[i];  // uložíme prvek z A
        poleA[i] = poleB[i];     // A dostane hodnotu z B
        poleB[i] = docasne;      // B dostane původní hodnotu z A
    }
}

int main(void) {
    int velikost;

    // Vstup velikosti pole
    printf("Zadejte velikost poli: ");
    if (scanf("%d", &velikost) != 1 || velikost <= 0) {
        printf("Chyba: zadejte kladnou velikost.\n");
        return 1; // ukončení programu při špatném vstupu
    }

    int poleA[velikost];
    int poleB[velikost];

    // Práce s poli pomocí funkcí
    nactiPole(poleA, velikost, 'A');  // načtení hodnot do pole A
    nactiPole(poleB, velikost, 'B');  // načtení hodnot do pole B

    vymenPole(poleA, poleB, velikost); // prohození prvků mezi poli

    printf("Po vymene:\n");
    vypisPole(poleA, velikost, 'A');   // výpis obsahu pole A
    vypisPole(poleB, velikost, 'B');   // výpis obsahu pole B

    return 0;
}

