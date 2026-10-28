/*
 * A05 - Programació ESP32. C. Variables
 * 
 * Objectiu: Mostrar els diferents tipus de variables en C/C++ per a ESP32
 * amb exemples pràctics i comentaris explicatius.
 * 
 * Autor: Khalid %%%%%%%% %% %%%%%%%
 * Data: 28-10-2026
 */

// ==================== DECLARACIÓ DE VARIABLES ====================

// 1. CONSTANTS (const) - Valors que NO canvien durant l'execució
// S'utilitzen principalment per definir pins del hardware
const int LED_INTERNE = 2;        // Pin GPIO2 on està connectat el LED intern de l'ESP32

// 2. VARIABLES ENTERES (int) - Números enters sense decimals
int contadorExecucions = 0;
int numeroPin = 16;

// 3. VARIABLES ENTERES LLARGUES (long) - Números enters molt grans
long tempsInicial = 0;
long tempsEspera = 500;

// 4. VARIABLES AMB DECIMALS (float) - Números reals
float temperatura = 23.5;
float voltatge = 3.3;
float velocitat = 1.75;

// 5. VARIABLES CARÀCTER (char) - Un sol caràcter
char lletraInicial = 'A';
char simbol = '#';

// 6. VARIABLES BOOLEANS (bool) - Vertader o Fals
bool ledEncès = false;
bool sistemaActivat = true;
bool wifiConnectat = false;

// 7. ALTRES EXEMPLES DE VARIABLES
long tempsMaximEspera = 3000;

// ==================== CONFIGURACIÓ INICIAL ====================

void setup() {
  Serial.begin(115200);
  pinMode(LED_INTERNE, OUTPUT);
  delay(1000);
  
  Serial.println("========================================");
  Serial.println("A05 - EXEMPLES DE VARIABLES AMB ESP32");
  Serial.println("========================================");
  Serial.println();
  
  Serial.println("### EXEMPLE 1: TIPUS DE VARIABLES ###");
  Serial.println();
  
  Serial.print("Variable int 'contadorExecucions': ");
  Serial.println(contadorExecucions);
  Serial.print("Variable int 'numeroPin': ");
  Serial.println(numeroPin);
  Serial.println();
  
  Serial.print("Variable long 'tempsEspera': ");
  Serial.print(tempsEspera);
  Serial.println(" ms");
  Serial.print("Variable long 'tempsMaximEspera': ");
  Serial.print(tempsMaximEspera);
  Serial.println(" ms");
  Serial.println();
  
  Serial.print("Variable float 'temperatura': ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Variable float 'voltatge': ");
  Serial.print(voltatge);
  Serial.println(" V");
  Serial.print("Variable float 'velocitat': ");
  Serial.println(velocitat);
  Serial.println();
  
  Serial.print("Variable char 'lletraInicial': ");
  Serial.println(lletraInicial);
  Serial.print("Variable char 'simbol': ");
  Serial.println(simbol);
  Serial.println();
  
  Serial.print("Variable bool 'ledEncès': ");
  Serial.println(ledEncès ? "true (VERITAT)" : "false (FALS)");
  Serial.print("Variable bool 'sistemaActivat': ");
  Serial.println(sistemaActivat ? "true (VERITAT)" : "false (FALS)");
  Serial.print("Variable bool 'wifiConnectat': ");
  Serial.println(wifiConnectat ? "true (VERITAT)" : "false (FALS)");
  Serial.println();
  
  Serial.println("========================================");
  Serial.println();
  
  delay(2000);
}

// ==================== BUCLE PRINCIPAL ====================

void loop() {
  contadorExecucions++;
  
  if (sistemaActivat) {
    
    Serial.println("### EXEMPLE 2: ÚS PRÀCTIC AMB LED I VARIABLES ###");
    Serial.print("Execució número: ");
    Serial.println(contadorExecucions);
    Serial.println();
    
    if (!ledEncès) {
      Serial.println("-> Encenem el LED...");
      digitalWrite(LED_INTERNE, HIGH);
      ledEncès = true;
      Serial.print("   LED encès. Estat: ");
      Serial.println(ledEncès ? "true" : "false");
    }
    
    Serial.print("   Esperant ");
    Serial.print(tempsEspera);
    Serial.println(" mil·lisegons...");
    delay(tempsEspera);
    
    Serial.println("-> Apaguem el LED...");
    digitalWrite(LED_INTERNE, LOW);
    ledEncès = false;
    Serial.print("   LED apagat. Estat: ");
    Serial.println(ledEncès ? "true" : "false");
    
    Serial.print("   Esperant ");
    Serial.print(tempsEspera);
    Serial.println(" mil·lisegons...");
    delay(tempsEspera);
    
    Serial.println();
    Serial.println("-> Modifiquem la variable tempsEspera:");
    Serial.print("   Valor anterior: ");
    Serial.print(tempsEspera);
    Serial.println(" ms");
    
    tempsEspera = tempsEspera + 500;
    
    Serial.print("   Valor actual: ");
    Serial.print(tempsEspera);
    Serial.println(" ms");
    Serial.println();
    
    if (tempsEspera >= tempsMaximEspera) {
      Serial.println("⚠ ATENCIÓ: S'ha arribat al temps màxim d'espera!");
      Serial.println();
      Serial.println("   Desactivant el sistema...");
      sistemaActivat = false;
    }
    
    Serial.println("========================================");
    Serial.println();
    
    delay(500);
    
  } else {
    Serial.println("### SISTEMA DESACTIVAT ###");
    Serial.println("El programa ha finalitzat.");
    Serial.println("Per reiniciar, prem el botó RESET de l'ESP32.");
    Serial.println("========================================");
    
    while (true) {
      delay(1000);
    }
  }
}
