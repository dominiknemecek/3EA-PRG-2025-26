// 0–1023 = hodnoty z analogového vstupu
// Arduino má 10bitový ADC převodník → 2^10 = 1024 úrovní (0 až 1023)
// 0–255 = rozsah PWM výstupu (8bit) → 2^8 = 256 úrovní

#define POTENCIOMETR A0        // potenciometr připojený na analogový vstup A0

int hodnotaPotenciometr;       // zde se bude ukládat přečtená hodnota (0–1023)

void setup()
{
  pinMode(POTENCIOMETR, INPUT); // nastavení vstupu
  Serial.begin(9600);           // spuštění sériové komunikace
}

void loop()
{
  // Čtení hodnoty z potenciometru (0–1023)
  hodnotaPotenciometr = analogRead(POTENCIOMETR);

  // Přepočet na napětí (0–5 V)
  // 5.0 / 1023.0 → velikost 1 kroku ADC převodníku (≈0.00489 V)
  float napeti = hodnotaPotenciometr * (5.0 / 1023.0);

  // Poznámka: 1023 / 4 ≈ 255 → takto se často mapuje 10bit → 8bit
  // (např. když chceš hodnotu použít pro PWM jas LED)

  // Výpis do sériového monitoru
  Serial.print("Hodnota potenciometru je: ");
  Serial.println(hodnotaPotenciometr);

  Serial.print("Hodnota napeti je: ");
  Serial.print(napeti);
  Serial.println(" V");

  delay(500); // půlsekundová pauza aby se výpis nezobrazoval příliš rychle
}
