/**
 * Blink (Parpadeo infinito)
 *
 * Enciende el LED durante un segundo,
 * luego lo apaga durante un segundo, y repite el ciclo.
 */
#include "Arduino.h"

#define LED_PIN LED_BUILTIN // Usamos el LED integrado en la placa

void setup()
{
  // Configurar el LED como salida
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Encender el LED
  digitalWrite(LED_PIN, HIGH);
  
  // Esperar dos segundos
  delay(2000);
  
  // Apagar el LED
  digitalWrite(LED_PIN, LOW);
  
  // Esperar un segundo
  delay(1000);
}

