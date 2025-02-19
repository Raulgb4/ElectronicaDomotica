/**
 * Blink (Parpadeo infinito) del LED de la placa Arduino UNO
 *
 * Enciende el LED durante dos segundos,
 * luego lo apaga durante un segundo, y repite el ciclo.
 * 
*/

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
#define LED_PIN LED_BUILTIN // Usamos el LED integrado en la placa

/*
La función setup es una función especial de Arduino que
se ejecuta solo una vez al inicio del programa
*/
void setup()
{
  // Serial.begin(115200)
  /*
  Configurar el pin 13 (LED) como salida
  para que Arduino lo controle para encender
  o apagar el LED
  */
  pinMode(LED_PIN, OUTPUT);
}

/*
La función loop es una función especial de Arduino que
se ejecuta infinitamente en bucle
¿Por qué sucede esto?
Arduino no tiene un sistema operativo como un ordenador, 
por lo que siempre ejecuta el código en bucle hasta que 
se apaga o se sube otro programa
*/
void loop()
{ 
  /*
  Encender el LED, enviando una señal digital HIGH (5 voltios) 
  a un pin (configurado como OUTPUT) de la placa
  */
  digitalWrite(LED_PIN, HIGH);
  
  /*
  Esperar dos segundos (2000 milisegundos) antes de continuar
  Funciona deteniendo la ejecución del programa
  */ 
  delay(2000);
  
  // Apagar el LED, LOW significa 0 voltios
  digitalWrite(LED_PIN, LOW);
  
  // Esperar un segundo antes de repetir el ciclo
  delay(1000);
}

