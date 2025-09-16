#include <stdio.h>   // knihovna pro práci s konzolí (printf, scanf)

int main() {
    int zustatek = 1000;   // počáteční zůstatek na účtu (startujeme s 1000 Kč)
    int volba;             // proměnná pro uložení volby uživatele (1, 2 nebo 3)
    int castka;            // proměnná pro uložení částky, kterou chce uživatel vložit/vybrat

    // Úvodní text programu
    printf("# Start programu.\n");
    printf("Aktuální zůstatek: %d Kč\n", zustatek);

    // Nekonečná smyčka - běží, dokud uživatel nezvolí možnost "3 – Konec"
    while (1) {
        // Zobrazení nabídky akcí
        printf("Vyberte akci:\n");
        printf("1 – Vklad\n");
        printf("2 – Výběr\n");
        printf("3 – Konec\n");
        printf("> ");
        
        // Funkce scanf načítá vstup od uživatele
        // "%d" znamená, že očekáváme celé číslo
        // &volba = adresa proměnné, kam se hodnota uloží
        //
        // scanf vrací počet úspěšně načtených hodnot:
        // - když zadáme číslo, vrátí 1
        // - když zadáme neplatný vstup (např. text), vrátí 0
        // - při chybě nebo konci vstupu vrací EOF (většinou -1)
        if (scanf("%d", &volba) != 1) {
            printf("Neplatná volba!\n");
            return 1; // ukončí program s chybovým kódem
        }

        // --- Zpracování jednotlivých voleb ---
        if (volba == 1) {
            // Uživatel zvolil vklad
            printf("Zadejte částku:\n");
            printf("> ");
            scanf("%d", &castka);

            // Kontrola, zda není zadána záporná nebo nulová částka
            if (castka <= 0) {
                printf("Částka musí být kladná!\n");
            } else {
                // Přičteme částku k aktuálnímu zůstatku
                zustatek += castka;
                printf("Vklad úspěšný!\n");
            }
        }
        else if (volba == 2) {
            // Uživatel zvolil výběr
            printf("Zadejte částku:\n");
            printf("> ");
            scanf("%d", &castka);

            if (castka <= 0) {
                // Neplatná částka (nesmí být 0 nebo záporná)
                printf("Částka musí být kladná!\n");
            } else if (castka > zustatek) {
                // Uživatel nemá dostatek prostředků na účtu
                printf("Nedostatečný zůstatek!\n");
            } else {
                // Odečteme částku od zůstatku
                zustatek -= castka;
                printf("Výběr úspěšný!\n");
            }
        }
        else if (volba == 3) {
            // Uživatel zvolil konec programu
            printf("# Konec programu.\n");
            break; // ukončí nekonečnou smyčku
        }
        else {
            // Pokud uživatel zadal číslo mimo rozsah (např. 5)
            printf("Neplatná volba!\n");
        }

        // Po každé operaci se vypíše aktuální zůstatek
        printf("Aktuální zůstatek: %d Kč\n\n", zustatek);
    }

    return 0; // správné ukončení programu
}
