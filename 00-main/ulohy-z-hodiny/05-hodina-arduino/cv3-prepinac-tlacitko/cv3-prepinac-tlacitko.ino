// Konstanty pro připojené piny
#define TLACITKO 2  // pin, na kterém je připojeno tlačítko
#define LED 12      // pin, na kterém je připojena LED dioda

// Proměnné
bool stavLed = false;   // proměnná, která si pamatuje, jestli LED svítí (false = zhasnutá)
bool predchoziStav;     // uloží stav tlačítka z předchozího cyklu

void setup()
{
  // Nastavení LED jako výstupního pinu
  pinMode(LED, OUTPUT);

  // Nastavení počátečního stavu LED – po zapnutí Arduina bude zhasnutá
  digitalWrite(LED, LOW);

  // Nastavení pinu s tlačítkem jako vstupního
  // Používáme INPUT (bez PULLUP), takže je potřeba mít v zapojení externí pull-down rezistor
  // (ten drží pin v logické 0, dokud se tlačítko nezmáčkne)
  pinMode(TLACITKO, INPUT);

  // Načteme aktuální stav tlačítka, abychom při startu nepřepnuli LED "falešně"
  predchoziStav = digitalRead(TLACITKO);
}

void loop()
{
  // Přečteme aktuální stav tlačítka (HIGH = zmáčknuté, LOW = nezmáčknuté)
  bool aktualniStav = digitalRead(TLACITKO);

  // Podmínka reaguje pouze na přechod z HIGH → LOW
  // (tedy v okamžiku, kdy uživatel tlačítko skutečně stiskne)
  if (aktualniStav == LOW && predchoziStav == HIGH)
  {
    // Přepneme logický stav proměnné stavLed
    // Pokud byla LED zhasnutá → rozsvítí se, pokud svítila → zhasne
    stavLed = !stavLed;

    // Nastavíme výstup LED podle proměnné stavLed
    digitalWrite(LED, stavLed);

    // Krátké zpoždění, aby se eliminovaly zákmitové (chvějivé) signály při stisku tlačítka
    delay(200);
  }

  // Na konci smyčky uložíme aktuální stav jako "předchozí" pro další porovnání
  predchoziStav = aktualniStav;
}
