/*
 * Pràctica A07 - Programació ESP32. Button (Funcions en C)
 * Exemple 2: Funció encapsulada bool button() i Comptador de pulsacions.
 * 
 * Autor: Khalid IoT
 * Data: 2026-11-10
 */

#include <Arduino.h>

#define BUTTON_PIN 13       // Pin GPIO13 connectat al botó
#define DEBOUNCE_TIME 50    // Temps de debounce en mil·lisegons

int lastSteadyState = HIGH;
int lastFlickerableState = HIGH;
int currentState;
unsigned long lastDebounceTime = 0;

int pulsacionsCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("==========================================");
  Serial.println("  COMPTADOR DE PULSACIONS AMB ESP32       ");
  Serial.println("==========================================");
}

bool button() {
  currentState = digitalRead(BUTTON_PIN);

  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }
  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
    if (lastSteadyState != currentState) {
      lastSteadyState = currentState;
      return (currentState == LOW);
    }
  }
  return false;
}
void loop() {
  if (button()) {
    pulsacionsCount++;
    Serial.print(" Botó premut! Comptador actual: ");
    Serial.println(pulsacionsCount);
  }
}
