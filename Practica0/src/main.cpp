/**
 * Lectura de pulsador con resistencia pull-down
 * 
 * Este programa muestra en la consola (Serial Monitor) 
 * el estado del botón SOLO cuando se pulsa o se suelta.
 * 
 * Basado en el esquema eléctrico proporcionado.
 */

 #include "Arduino.h" // Omitir en TinkerCAD

 // Definir pin de lectura
 #define BUTTON_PIN 3  // Pin donde está conectado el pulsador
 
 // Variable para almacenar el estado anterior del botón
 bool estadoAnteriorBoton = LOW;  
 
 void setup() {
   Serial.begin(115200);  // Iniciar la comunicación serie
   pinMode(BUTTON_PIN, INPUT); // Configurar el pin 3 como entrada
 
   // Leer el estado inicial del botón para evitar falsos positivos
   estadoAnteriorBoton = digitalRead(BUTTON_PIN);
   Serial.println("Monitoreo del pulsador iniciado...");
 }
 
 void loop() {
   // Leer el estado del pulsador
   bool estadoBoton = digitalRead(BUTTON_PIN);
 
   // Si el botón está presionado (LOW)
   if (estadoBoton == LOW) {
    Serial.print("Estado actual del pin 3: 0");
   } else {
    Serial.print("Estado actual del pin 3: 1");
   }
 }
 