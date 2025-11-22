#define LED_PIN 12
#define POT_PIN A0

unsigned long predchoziCas = 0;   // čas posledního přepnutí LED
int interval = 500;               // aktuální interval blikání (ms)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // načtení hodnoty potenciometru (0–1023)
  int hodnotaPotenciometru = analogRead(POT_PIN);

  // převod hodnoty na interval 1000–100 ms (delší = pomalejší blikání)

  // Funkce map() převádí hodnotu z jednoho rozsahu na jiný.
  // U potenciometru dostáváme hodnoty 0–1023 (10bit ADC převodník).
  // Pro blikání LED ale potřebujeme interval v jiném rozsahu (např. 1000–100 ms).
  // map() tedy zachová poměr mezi hodnotami a přepočítá je:
  // - když je vstup nízký (blízko 0), výstup bude blízko 1000 ms
  // - když je vstup uprostřed (kolem 512), výstup bude přibližně v polovině rozsahu
  // - když je vstup vysoký (blízko 1023), výstup bude blízko 100 ms
  // Je to tedy jednoduchý způsob, jak „škálovat“ jednu hodnotu na jiný rozsah bez ručního počítání poměrů.
  interval = map(hodnotaPotenciometru, 0, 1023, 1000, 100);

  // aktuální čas
  unsigned long aktualniCas = millis();

  // pokud uplynul interval → přepni LED
  if (aktualniCas - predchoziCas >= interval) {
    predchoziCas = aktualniCas;

    // invertování aktuálního stavu LED bez proměnné
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));

    // výpis do sériového monitoru
    Serial.print("Hodnota potenciometru: ");
    Serial.print(hodnotaPotenciometru);
    Serial.print(" | Interval blikání: ");
    Serial.print(interval);
    Serial.println(" ms");
  }
}
