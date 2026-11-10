/*
 * Pràctica A07 - Programació ESP32. Button (Funcions en C)
 * Exemple 1: Lectura d'estat del botó amb Debounce per programari.
 * 
 * Autor: Khalid IoT
 * Data: 2026-11-10
 */

#include <Arduino.h>

#define BUTTON_PIN 13       // Pin GPIO13 connectat al botó
#define DEBOUNCE_TIME 50    // Temps de debounce en mil·lisegons

int lastSteadyState = HIGH;       // Estat estable anterior (INPUT_PULLUP -> HIGH per defecte)
int lastFlickerableState = HIGH;  // Estat inestable anterior
int currentState;                 // Lectura actual del pin

unsigned long lastDebounceTime = 0; // Últim registre de temps de canvi d'estat

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("ESP32 Inicialitzat. Prem el botó per provar el debounce...");
}

void loop() {
  currentState = digitalRead(BUTTON_PIN);

  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
    if (lastSteadyState == HIGH && currentState == LOW) {
      Serial.println("El botó s'ha PREMUT");
    } else if (lastSteadyState == LOW && currentState == HIGH) {
      Serial.println("El botó s'ha ANUL·LAT / ALLIBERAT");
    }

    lastSteadyState = currentState;
  }
}
