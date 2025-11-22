#define LED_PIN 11              // PWM pin pro LED
#define TLACITKO_PLUS 4        // tlačítko pro zvýšení jasu
#define TLACITKO_MINUS 2       // tlačítko pro snížení jasu

int jas = 0;                   // aktuální jas LED (0–255)
unsigned long predchoziCas = 0;
const int interval = 50;       // rychlost změny jasu (ms)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TLACITKO_PLUS, INPUT_PULLUP);
  pinMode(TLACITKO_MINUS, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long aktualniCas = millis();

  // změna jasu probíhá jen po určitém intervalu
  if (aktualniCas - predchoziCas >= interval) {
    predchoziCas = aktualniCas;

    // čtení tlačítek (LOW = stisknuto)
    bool plusStisknuto = digitalRead(TLACITKO_PLUS) == LOW;
    bool minusStisknuto = digitalRead(TLACITKO_MINUS) == LOW;

    // zvýšení jasu
    if (plusStisknuto && jas < 255) {
      jas++;
    }

    // snížení jasu
    if (minusStisknuto && jas > 0) {
      jas--;
    }

    // nastavení jasu LED
    analogWrite(LED_PIN, jas);
    
    float napeti = jas * (5.0 / 255.0);
    
    // Výpis do Serial Monitoru
    Serial.print("Jas (0-255): ");
    Serial.print(jas);
    Serial.print("   |   Napeti ~ ");
    Serial.print(napeti, 2); // dvě desetinná místa
    Serial.println(" V");
  }
}
