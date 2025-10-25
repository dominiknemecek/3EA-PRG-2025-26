// Definujeme pin, ke kterému je připojeno tlačítko
#define TLACITKO_PIN 4

void setup() {
  // Spuštění sériové komunikace – umožní nám zobrazovat hodnoty v Serial Monitoru
  Serial.begin(9600);

  // Nastavení pinu jako vstupního s aktivovaným vnitřním pull-up rezistorem
  // To znamená, že pin je standardně v logické hodnotě HIGH (1)
  // a po stisku tlačítka se spojí se zemí (GND), čímž přejde do LOW (0)
  pinMode(TLACITKO_PIN, INPUT_PULLUP);
}

void loop() {
  // Přečteme aktuální stav tlačítka (HIGH = tlačítko není zmáčknuté, LOW = tlačítko je zmáčknuté)
  int stavTlacitka = digitalRead(TLACITKO_PIN);

  // Vypíšeme stav tlačítka do sériového monitoru
  Serial.println(stavTlacitka);

  // Krátká pauza, aby se výpis neobnovoval příliš rychle
  delay(10);
}
