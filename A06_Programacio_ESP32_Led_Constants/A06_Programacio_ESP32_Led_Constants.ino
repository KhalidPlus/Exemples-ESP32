/*
 * Projecte: A06 Programació ESP32 - LED Blinking amb Constants
 * Curs: 2n ASIX - M14 Projecte 2 IoT (Institut %%%% %% %%%%)
 * Autor: Khalid %%%% %% %%%%
 * Descripció: Control d'un LED extern connectat al GPIO 23 amb temps
 *             d'encesa i apagat configurables mitjançant constants.
 */

// Definició del pin del LED
const int LED_PIN = 23;

// Constants de configuració dels temps de retard (en mil·lisegons)
const int TIME_ON  = 1000; // Temps que el LED romandrà encès (1s)
const int TIME_OFF = 500;  // Temps que el LED romandrà apagat (0.5s)

void setup() {
  // Configurem el pin digital GPIO 23 com a sortida (OUTPUT)
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Encendre el LED enviant un senyal alt (3.3V)
  digitalWrite(LED_PIN, HIGH);
  delay(TIME_ON); // Espera el temps definit per a l'encesa

  // Apagar el LED enviant un senyal baix (0V)
  digitalWrite(LED_PIN, LOW);
  delay(TIME_OFF); // Espera el temps definit per a l'apagat
}