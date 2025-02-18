/**
 * LED con Pulsador
 *
 * Enciende el LED solo mientras el pulsador esté presionado.
 */
#include "Arduino.h"

#define LED_PIN LED_BUILTIN // Usamos el LED integrado en la placa
#define BUTTON_PIN 2        // Pin donde está conectado el pulsador

void setup()
{
  pinMode(LED_PIN, OUTPUT);        // Configurar el LED como salida
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configurar el pulsador con resistencia pull-up interna
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN); // Leer el estado del pulsador

  if (buttonState == LOW) {  // Si el botón está presionado (con INPUT_PULLUP, LOW significa pulsado)
    digitalWrite(LED_PIN, HIGH); // Enciende el LED
  } else {
    digitalWrite(LED_PIN, LOW);  // Apaga el LED
  }
}


