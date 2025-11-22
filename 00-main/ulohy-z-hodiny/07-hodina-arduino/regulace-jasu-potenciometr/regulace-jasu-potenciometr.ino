// LED musí být připojena na PWM pin (3, 5, 6, 9, 10, 11)
// Potenciometr je připojený na analogový vstup A0
#define ledPin 3
#define potenciometrPin A0

int hodnotaPotenciometru;   // raw hodnota 0–1023
int hodnotaLed;             // přepočet 0–255 pro PWM

void setup()
{
  pinMode(ledPin, OUTPUT);           // LED výstup (PWM)
  pinMode(potenciometrPin, INPUT);   // analogový vstup
  Serial.begin(9600);                // start sériové komunikace
}

void loop()
{
  // ČTENÍ POTENCIOMETRU (0–1023)
  hodnotaPotenciometru = analogRead(potenciometrPin);

  // PŘEPOČET NA 8bit PWM (0–255)
  hodnotaLed = hodnotaPotenciometru / 4;

  // VÝPIS
  Serial.print("Hodnota potenciometru: ");
  Serial.println(hodnotaPotenciometru);

  Serial.print("Hodnota LED (PWM): ");
  Serial.println(hodnotaLed);

  // NASTAVENÍ JASU LED
  analogWrite(ledPin, hodnotaLed);

  delay(500); // zpomalení výpisu
}
