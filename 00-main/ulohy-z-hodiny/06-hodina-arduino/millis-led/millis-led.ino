// Číslo pinu, na kterém je LED
#define LED_PIN 10

// Interval blikání LED v milisekundách
#define INTERVAL 1000   // 1 sekunda

// Uložíme si čas posledního přepnutí LED
unsigned long predchoziCas = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);   // Nastavení pinu jako výstup
}

void loop() {
  // Aktuální čas od spuštění programu (v ms)
  unsigned long aktualniMillis = millis();

  // Pokud od posledního přepnutí uplynul čas INTERVAL
  if (aktualniMillis - predchoziCas >= INTERVAL) 
  {
    predchoziCas = aktualniMillis;   // Uložíme aktuální čas pro další porovnání

    // Přepneme LED na opačný stav (zapnutá → vypnutá, vypnutá → zapnutá)
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));  
  }
}
