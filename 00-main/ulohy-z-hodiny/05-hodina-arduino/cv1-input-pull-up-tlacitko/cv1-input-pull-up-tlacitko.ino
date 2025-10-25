// Definujeme pin, ke kterému je připojeno tlačítko
#define TLACITKO_PIN 4

void setup() {
  // Spuštění sériové komunikace – umožní nám zobrazovat hodnoty v Serial Monitoru
  Serial.begin(9600);

  // Nastavení pinu jako vstupního s aktivovaným vnitřním pull-up rezistorem
  // Pin je standardně v logické hodnotě HIGH (1)
  // Po stisku tlačítka se spojí se zemí (GND) → přejde do LOW (0)
  pinMode(TLACITKO_PIN, INPUT_PULLUP);

  // Nastavení vestavěné LED jako výstup
  pinMode(LED_BUILTIN, OUTPUT);

  // Na začátku LED vypneme (bezpečný výchozí stav)
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Načteme stav tlačítka
  int stavTlacitka = digitalRead(TLACITKO_PIN);

  // Pokud je tlačítko stisknuté (LOW), rozsvítíme vestavěnou LED
  // Jinak ji zhasneme
  if (stavTlacitka == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);  // zapni LED
  } else {
    digitalWrite(LED_BUILTIN, LOW);   // zhasni LED
  }

  // Vypíšeme stav tlačítka do sériového monitoru (1 = puštěné, 0 = stisknuté)
  Serial.println(stavTlacitka);

  // Krátká pauza pro přehlednější výpis
  delay(10);
}
