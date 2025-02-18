/**
 * LED con Pulsador e Interruptor
 *
 * Este programa permite controlar un LED externo mediante un pulsador, 
 * con dos modos de funcionamiento:
 * 
 * 1. **Modo Pulsador:** El LED se enciende solo mientras el botón esté presionado.
 * 2. **Modo Interruptor:** Al presionar el botón, el LED se enciende y permanece encendido
 *    hasta que se vuelva a presionar, momento en el cual se apagará.
 * 
 * Se puede cambiar entre los modos modificando la variable `modoFuncionamiento`.
 * 
 * Cómo usar el código

    Conectar el circuito
        LED Ánodo (+) → Pin 9 de Arduino
        LED Cátodo (-) → GND de Arduino (con una resistencia de 220Ω en serie).
        Pulsador un lado → Pin 2 de Arduino
        Pulsador otro lado → GND

    Cargar el código en Arduino
        Si quieres que funcione en modo pulsador, pon MODO_FUNCIONAMIENTO = 0.
        Si quieres modo interruptor, cambia MODO_FUNCIONAMIENTO = 1.
 * 
 */

 #include "Arduino.h"

 // Definir los pines de conexión
 #define LED_PIN 9         // Pin donde está conectado el LED externo
 #define BUTTON_PIN 2      // Pin donde está conectado el pulsador
 
 // Variable para definir el modo de funcionamiento
 #define MODO_FUNCIONAMIENTO 1 // 0 = Modo Pulsador, 1 = Modo Interruptor
 
 // Variable para el estado del LED en modo interruptor
 bool estadoLED = false;   
 
 // Variable para detectar cambios en la pulsación
 bool estadoAnteriorBoton = HIGH;
 
 void setup()
 {
   pinMode(LED_PIN, OUTPUT);        // Configurar el LED como salida
   pinMode(BUTTON_PIN, INPUT_PULLUP); // Configurar el pulsador con resistencia pull-up interna
 }
 
 void loop()
 {
   // Leer el estado actual del botón
   bool estadoBoton = digitalRead(BUTTON_PIN);
 
   // **Modo Pulsador:** El LED se enciende solo mientras el botón está presionado
   if (MODO_FUNCIONAMIENTO == 0) {
     if (estadoBoton == LOW) {  // Si el botón está presionado (LOW porque usamos INPUT_PULLUP)
       digitalWrite(LED_PIN, HIGH); // Enciende el LED
     } else {
       digitalWrite(LED_PIN, LOW);  // Apaga el LED
     }
   }
 
   // **Modo Interruptor:** El LED cambia de estado cada vez que se pulsa el botón
   else if (MODO_FUNCIONAMIENTO == 1) {
     if (estadoBoton == LOW && estadoAnteriorBoton == HIGH) { // Detectar flanco de bajada (botón pulsado)
       estadoLED = !estadoLED; // Alternar el estado del LED
       digitalWrite(LED_PIN, estadoLED ? HIGH : LOW);
       delay(50); // Pequeño retraso para evitar rebotes mecánicos en el pulsador
     }
   }
 
   // Guardar el estado actual del botón para la próxima iteración
   estadoAnteriorBoton = estadoBoton;
 }
 