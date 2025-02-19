/**
 * LED con pulsador (Modo Pulsador)
 * 
 * Este programa hace que un LED externo se encienda solo mientras 
 * el pulsador esté presionado. Al soltarlo, el LED se apaga.
 */

 #include "Arduino.h" // Omitir esta línea en TinkerCAD

 // Definir pines de conexión
 #define LED_PIN 2      // LED externo conectado al pin 2 con una resistencia de 220Ω
 #define BUTTON_PIN 3   // Pulsador conectado al pin 3
 
 void setup() {
   pinMode(LED_PIN, OUTPUT);         // Configurar el LED como salida
   pinMode(BUTTON_PIN, INPUT_PULLUP); // Configurar el pulsador como entrada con resistencia pull-up interna
 }
 
 void loop() {
   // Leer el estado del pulsador
   bool estadoBoton = digitalRead(BUTTON_PIN);
 
   // Si el botón está presionado (LOW), encender el LED
   if (estadoBoton == LOW) {
     digitalWrite(LED_PIN, HIGH); // Enciende el LED
   } else {
     digitalWrite(LED_PIN, LOW); // Apaga el LED al soltar el botón
   }
 }
 