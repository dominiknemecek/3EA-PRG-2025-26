#include <stdio.h>

// Konstanty (pevné kurzy dle zadání)
#define KURZ_CZK_EUR 25.14   // 1 EUR = 25.14 CZK
#define KURZ_CZK_USD 24.15   // 1 USD = 24.15 CZK
#define KURZ_EUR_CZK 0.040   // 1 CZK = 0.040 EUR
#define KURZ_USD_CZK 0.041   // 1 CZK = 0.041 USD

// Funkce pro převod CZK -> EUR
double czk_na_eur(double castkaCzk) {
    return castkaCzk * KURZ_EUR_CZK;
}

// Funkce pro převod EUR -> CZK
double eur_na_czk(double castkaEur) {
    return castkaEur * KURZ_CZK_EUR;
}

// Funkce pro převod CZK -> USD
double czk_na_usd(double castkaCzk) {
    return castkaCzk * KURZ_USD_CZK;
}

// Funkce pro převod USD -> CZK
double usd_na_czk(double castkaUsd) {
    return castkaUsd * KURZ_CZK_USD;
}

int main(void) {
    int volba;                  // proměnná pro volbu v menu
    double castka, prevedena;   // proměnné pro vstupní částku a výsledek

    while (1) {
        // Menu
        printf("Vyber typ prevodu:\n");
        printf("(1) CZK -> EUR\n");
        printf("(2) EUR -> CZK\n");
        printf("(3) CZK -> USD\n");
        printf("(4) USD -> CZK\n");
        printf("(5) Ukoncit aplikaci\n");
        printf(" > ");

        // Kontrola, zda uživatel zadal číslo
        if (scanf("%d", &volba) != 1) {
            printf("Neplatna volba (zadej cislo 1-5).\n\n");
            getchar(); // vyčistí špatný vstup
            continue;  // vrátíme se k menu
        }
        else if (volba == 5) {
            printf("Aplikace ukoncena.\n");
            break; // konec programu
        }
        else if (volba < 1 || volba > 4) {
            printf("Neplatna volba (zadej cislo 1-5).\n\n");
            continue; // zpět k menu
        }

        // Vstup částky
        printf("\nZadej castku pro prevod:\n > ");
        if (scanf("%lf", &castka) != 1) {
            printf("Chyba: zadej ciselnou hodnotu.\n\n");
            return 1; // při nečíselném vstupu program ukončíme
        }
        if (castka < 0) {
            printf("Chyba: castka nesmi byt zaporna.\n\n");
            continue; // zpět k menu
        }

        // Převod podle volby
        switch (volba) {
            case 1:
                prevedena = czk_na_eur(castka);
                printf("Castka v EUR: %.2f\n\n", prevedena);
                break;
            case 2:
                prevedena = eur_na_czk(castka);
                printf("Castka v CZK: %.2f\n\n", prevedena);
                break;
            case 3:
                prevedena = czk_na_usd(castka);
                printf("Castka v USD: %.2f\n\n", prevedena);
                break;
            case 4:
                prevedena = usd_na_czk(castka);
                printf("Castka v CZK: %.2f\n\n", prevedena);
                break;
        }
    }

    return 0;
}

