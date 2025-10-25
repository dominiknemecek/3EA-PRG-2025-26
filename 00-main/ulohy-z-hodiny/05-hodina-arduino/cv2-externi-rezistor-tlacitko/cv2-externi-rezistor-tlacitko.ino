// Tlačítko je připojeno na pin číslo 2
#define TLACITKO_PIN 2

// Externí LED je připojena na pin číslo 12
// Arduino má i vestavěnou LED (obvykle na pinu 13)
// → Tu bychom mohli použít místo externí, pokud bychom chtěli:
// #define LED_PIN LED_BUILTIN
#define LED_PIN 12

// Proměnná pro uložení stavu tlačítka
int stavTlacitka = 0;

void setup()
{
  // Nastavení pinu s tlačítkem jako vstupního
  // Používáme INPUT (bez PULLUP), takže je nutné zapojit externí rezistor
  // Externí rezistor zajišťuje, že pin má vždy jasnou logickou úroveň
  // (ne „plovoucí“ hodnotu mezi 0 a 1)
  pinMode(TLACITKO_PIN, INPUT);

  // Nastavení pinu s LED jako výstupního
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Načtení stavu tlačítka pomocí funkce digitalRead()
  // Vrací hodnotu HIGH (1) nebo LOW (0)
  stavTlacitka = digitalRead(TLACITKO_PIN);

  // Zkrácený zápis podmínky:
  // Pokud je tlačítko stisknuté (HIGH), LED se rozsvítí
  // Pokud není stisknuté (LOW), LED zhasne
  // Tento zápis nahrazuje klasickou konstrukci if/else
  digitalWrite(LED_PIN, (stavTlacitka == HIGH) ? HIGH : LOW);

  /* Klasický zápis stejné podmínky:
  if (stavTlacitka == HIGH) {
    digitalWrite(LED_PIN, HIGH); // zapni LED
  } else {
    digitalWrite(LED_PIN, LOW);  // zhasni LED
  }
  */

  // Krátká pauza (volitelná) – zlepšuje čitelnost v simulátoru
  delay(10);
}
