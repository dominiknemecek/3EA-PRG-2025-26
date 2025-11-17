// Piny pro LED a tlačítko
#define TLACITKO_PIN 2
#define LED_PIN 12

// Proměnná, která říká, jestli bylo tlačítko právě zmáčknuté
bool tlacitkoDrzene = false;

// Čas, kdy bylo tlačítko stisknuto
unsigned long casZacatku = 0;

void setup() {
  pinMode(TLACITKO_PIN, INPUT);   // tlačítko -> používáme externí pulldown odpor
  pinMode(LED_PIN, OUTPUT);       // LED jako výstup
  Serial.begin(9600);             // otevření sériové komunikace
}

void loop() {
  // Přečtení aktuálního stavu tlačítka (HIGH = zmáčknuto)
  int stavTlacitka = digitalRead(TLACITKO_PIN);

  // ============================
  //  DETEKCE STISKU (LOW → HIGH)
  // ============================
  if (stavTlacitka == HIGH && !tlacitkoDrzene) 
  {
      tlacitkoDrzene = true;             // označíme, že je tlačítko právě drženo
      casZacatku = millis();             // uložíme čas začátku držení
      digitalWrite(LED_PIN, HIGH);       // rozsvítíme LED
  }

  // =============================
  //  DETEKCE PUŠTĚNÍ (HIGH → LOW)
  // =============================
  if (stavTlacitka == LOW && tlacitkoDrzene) 
  {
      tlacitkoDrzene = false;            // už nedržíme tlačítko
      digitalWrite(LED_PIN, LOW);        // zhasneme LED

      // spočítáme, jak dlouho bylo tlačítko drženo
      unsigned long delkaDrzeni = millis() - casZacatku;

      // vypíšeme dobu držení do Serial Monitoru
      Serial.print("Drzel jsi tlacitko ");
      Serial.print(delkaDrzeni);
      Serial.println(" ms");
  }
}
