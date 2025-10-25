# CV3 – Přepínač (toggle): jedno tlačítko přepíná stav LED

## 🧩 Cíl
Ukázat, jak jedno tlačítko dokáže **přepínat stav LED diody** (zapnuto / vypnuto).  
V zapojení se používá **externí pull-down rezistor** (10 kΩ), který drží pin v logické nule, dokud není tlačítko stisknuté.

---

## 🔌 Zapojení

| Součástka | Popis |
|------------|--------|
| 1× Arduino UNO | řídicí deska |
| 1× Tlačítko | jeden kontakt na **pin D2**, druhý na **+5 V** |
| 1× Rezistor | **10 kΩ** mezi pinem **D2** a **GND** (pull-down) |
| 1× LED dioda | připojena na **pin D12** přes rezistor 220 Ω do GND |
| 1× Rezistor (pro LED) | 220 Ω |

**Schéma zapojení:**

![Zapojení – Přepínač tlačítko](zapojeni-cv3.png)

---

## 🧠 Princip
- Pin D2 je standardní **vstup (INPUT)** bez interního rezistoru.  
- Externí **pull-down** 10 kΩ drží pin v logické 0 (LOW), dokud není tlačítko stisknuté.  
- Po stisku tlačítka se pin připojí na +5 V → čteme **HIGH**.  
- Program rozpozná **přechod z HIGH → LOW** a přepne stav LED (z on → off nebo naopak).  
- Přidáno je krátké zpoždění (`delay(200)`) k odstranění zákmitů při stisku.

---

## 🎯 Zadání
1. Zapoj tlačítko s **externím pull-down rezistorem** (10 kΩ mezi D2 a GND).  
2. LED připoj na **pin D12** přes rezistor 220 Ω do GND.  
3. V programu nastav:
   - pin tlačítka jako `INPUT`,  
   - pin LED jako `OUTPUT`,  
   - logiku přepínání pomocí proměnné, která si pamatuje aktuální stav LED.  
4. Při každém **stisku tlačítka** se stav LED přepne.  
5. Přidej krátké zpoždění (`delay(200)`) kvůli zákmitům.  

---

## 💻 Program
Soubor: [`cv3-prepinac-tlacitko.ino`](./cv3-prepinac-tlacitko.ino)

---

## 🧪 Výsledek
- LED dioda se **rozsvítí nebo zhasne** při každém stisku tlačítka.  
- Po zapnutí Arduina je LED zhasnutá.  
- Díky pull-down rezistoru je vstup stabilní a nebliká náhodně.  
- Program eliminuje zákmit pomocí zpoždění 200 ms.

---

## 📘 Poznámka
Toto cvičení ukazuje, jak lze jednoduše vytvořit **logický přepínač** – velmi častý princip pro menu, zapínání funkcí nebo simulaci ON/OFF tlačítek.
