/*
 * A08 - Programació ESP32. KeyPad (Teclat Matricial 4x4)
 * 
 * Objectiu: Llegir les pulsacions d'un teclat matricial 4x4 connectat a l'ESP32
 *           i mostrar la tecla premuda pel Monitor Sèrie.
 * 
 * Autor: Khalid Mardi El Hilali
 * Curs: 2n ASIX - Institut Camí de Mar
 */

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {19, 18, 5, 17}; 
byte colPins[COLS] = {16, 4, 0, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("========================================");
  Serial.println("   A08 - PRÀCTICA TECLAT MATRICIAL ESP32   ");
  Serial.println("========================================");
  Serial.println("Prem qualsevol tecla del teclat 4x4...");
  Serial.println();
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    Serial.print("[TECLA PREMUDA] -> Caràcter: ");
    Serial.println(customKey);
  }
}
