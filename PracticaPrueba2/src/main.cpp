/**
 * LED con pulsador (Modo interruptor)
 * 
 * Este proyecto hace que un LED externo a la placa Arduino UNO
 * se encienda y se apague alternativamente cada vez que se pulsa un botón.
 * 
 * No es necesario mantener presionado el botón (funciona como un interruptor).
*/

// Falta implementarlo en TINKERCAD

/*
Importa la librería de Arduino, que permite usar funciones como 
pinMode(), digitalWrite(), y delay().
Sin esta librería, Arduino no entendería las funciones 
específicas de hardware.
*/
#include "Arduino.h" // Omitir esta línea al importar en TinkerCAD

/*
Define una constante llamada LED_PIN, 
que representa el LED integrado en la placa
(normalmente conectado al pin 13 en un Arduino UNO).

LED_BUILTIN es un valor predefinido que ya 
indica el número del pin correcto.
*/
#define LED_PIN 2     // LED externo conectado al pin 2 con una resistencia de 220Ω
#define BUTTON_PIN 3  // Pulsador conectado al pin 3


// Variables para el estado del LED y la detección del botón
bool estadoLED = false;           // Estado del LED (encendido o apagado)
bool estadoAnteriorBoton = HIGH;  // Estado previo del botón

/*
La función setup es una función especial de Arduino que
se ejecuta solo una vez al inicio del programa
*/


void setup() {
  pinMode(LED_PIN, OUTPUT);         // Configurar el LED como salida
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configurar el pulsador como entrada con resistencia pull-up interna
}

/*
La función loop es una función especial de Arduino que
se ejecuta infinitamente en bucle
¿Por qué sucede esto?
Arduino no tiene un sistema operativo como un ordenador, 
por lo que siempre ejecuta el código en bucle hasta que 
se apaga o se sube otro programa
*/
void loop() {
  // Leer el estado del pulsador
  bool estadoBoton = digitalRead(BUTTON_PIN);

  // Detectar si el botón ha sido presionado (flanco de bajada)
  if (estadoBoton == LOW && estadoAnteriorBoton == HIGH) {
    estadoLED = !estadoLED; // Invertir el estado del LED
    digitalWrite(LED_PIN, estadoLED ? HIGH : LOW); // Cambiar estado del LED
    delay(50); // Pequeña pausa para evitar rebotes mecánicos
  }

  // Guardar el estado actual del botón para la próxima iteración
  estadoAnteriorBoton = estadoBoton;
}

