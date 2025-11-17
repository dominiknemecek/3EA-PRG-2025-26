// Definice pinů pro LED
#define LED1_PIN 10
#define LED2_PIN 8

// Definice intervalů v milisekundách
#define INTERVAL1 500   // LED1 bliká každých 0,5 s
#define INTERVAL2 1000  // LED2 bliká každých 1 s

// Uložení času posledního přepnutí LED
unsigned long predchoziCas1 = 0;
unsigned long predchoziCas2 = 0;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  unsigned long aktualniMillis = millis();  // aktuální čas od spuštění

  // LED1 – bliká po INTERVAL1
  if (aktualniMillis - predchoziCas1 >= INTERVAL1) {
    predchoziCas1 = aktualniMillis; // záchytný bod pro millis
    digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));  // invertování stavu LED
  }

  // LED2 – bliká po INTERVAL2
  if (aktualniMillis - predchoziCas2 >= INTERVAL2) {
    predchoziCas2 = aktualniMillis; // záchytný bod pro millis
    digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));  // invertování stavu LED
  }
}
