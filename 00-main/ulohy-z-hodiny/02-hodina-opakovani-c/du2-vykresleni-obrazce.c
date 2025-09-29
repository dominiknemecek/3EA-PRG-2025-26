#include <stdio.h> 

int main(void) {
    int N;  // Velikost čtvercového rámu (minimálně 8)

    // Cyklus se opakuje, dokud není zadána platná velikost
    while (1) {
        printf("Zadejte velikost rámu (minimálně 8): ");
        
        // Kontrola, zda uživatel zadal číslo
        if (scanf("%d", &N) != 1) {
            printf("Chyba: zadejte celé číslo.\n");
            return 1; // Ukončí při nečíselném vstupu
        }

        // Pokud je číslo menší než 8, vypíšeme chybu a zeptáme se znovu
        if (N < 8) {
            printf("Chyba: velikost musí být alespoň 8.\n");
        } else {
            break; // Správný vstup → vyskočíme z cyklu
        }
    }

    // Vykreslení obrazce pomocí dvojitého cyklu
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            // Okraje (hvězdičky)
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                printf("*");
            }
            // Diagonály kříže (/)
            else if (j == i || j == (N - 1 - i)) {
                printf("/");
            }
            // Vnitřní mezery
            else {
                printf(" ");
            }
        }
        printf("\n"); // Nový řádek
    }

    return 0; // Konec programu
}

