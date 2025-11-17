// Nastavení čísla pinu, na kterém je LED
#define LED_PIN 12

// Proměnná, do které si uložíme počet bliknutí od uživatele
int pocetBliknuti = 0;

// Proměnná, která hlídá, jestli jsme už položili otázku
bool validace = false; 

void setup()
{
  pinMode(LED_PIN, OUTPUT);   // Nastavíme pin jako výstup (LED budeme ovládat)
  Serial.begin(9600);     // Spustíme komunikaci přes Serial monitor
}

void loop()
{
  // Pokud jsme ještě nevytiskli otázku, tak ji vytiskneme
  if (!validace)
  {
    Serial.println("Kolikrat ma LED zablikat?");
    validace = true;      // Nastavíme na true, abychom otázku tiskli jen jednou
  }
  
  // Pokud uživatel něco poslal do Serial monitoru
  if (Serial.available() > 0)
  {
    // Přečteme číslo jako integer (parseInt ignoruje písmena)
    pocetBliknuti = Serial.parseInt();

    // Smyčka, která zabliká LED daný počet krát
    for (int i = 1; i <= pocetBliknuti; i++)
    {
      digitalWrite(LED_PIN, HIGH);  // Zapnout LED
      delay(200);               // Počkat 200 ms
      digitalWrite(LED_PIN, LOW);   // Vypnout LED
      delay(200);               // Počkat 200 ms
    }
  
    // Vypsání potvrzení počtu bliknutí
    Serial.print("Zvoleny pocet bliknuti je: ");
    Serial.println(pocetBliknuti);

    // Oddělovač pro přehlednost
    Serial.println("-------------------------");

    // Vracíme se zpět na začátek – opět chceme zobrazit otázku
    validace = false;
  }
}
