void setup() {
  Serial.begin(9600);      // Spustí sériovou komunikaci – můžeme psát do Serial Monitoru
}

void loop() {
  Serial.println(millis()); // Vypíše počet milisekund od spuštění programu
                            // Číslo stále roste, takže vidíme “běžící čas”

  delay(1000);              // Pauza 1 sekunda (1000 ms)
                            // Program nic nedělá, jen čeká
}
