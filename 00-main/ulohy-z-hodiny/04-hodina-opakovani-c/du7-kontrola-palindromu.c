#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funkce pro kontrolu, zda je řetězec palindrom
int jePalindrom(char vstup[]) {
    char upraveny[1000];   // pole pro upravený řetězec (bez mezer, převedený na malá písmena)
    int i = 0, j = 0;

    // Úprava řetězce:
    // - odstraníme mezery
    // - převedeme znaky na malá písmena
    while (vstup[i] != '\0') {
        if (vstup[i] != ' ') {             // ignorujeme mezery
            upraveny[j] = tolower(vstup[i]); // převedeme znak na malé písmeno
            j++;
        }
        i++;
    }
    upraveny[j] = '\0';  // ukončovací znak řetězce

    // Kontrola palindromu:
    // porovnáváme znaky od začátku a od konce
    int delka = strlen(upraveny);
    for (i = 0; i < delka / 2; i++) {
        if (upraveny[i] != upraveny[delka - 1 - i]) {
            return 0; // není palindrom
        }
    }

    return 1; // je palindrom
}

int main(void) {
    char vstup[1000];  // pole pro načtený text

    // Zadání vstupu od uživatele
    printf("Zadejte text:\n");
    scanf(" %[^\n]", vstup); // načte celý řádek včetně mezer

    // Kontrola palindromu
    if (jePalindrom(vstup)) {
        printf("Výsledek: Jedná se o palindrom!\n");
    } else {
        printf("Výsledek: Nejedná se o palindrom.\n");
    }

    return 0;
}

