/**
 * PLANTILLA PARA LA PRÁCTICA 1
 *
 */
#include "Arduino.h" // Omitir esta línea en TinkerCAD

#define INTERVALO_LECTURA 200 // Tiempo mínimo entre lecturas en milisegundos (para evitar lecturas constantes)
#define PIN_BOTON 3           // Pin al que está conectado el botón

// Variables para controlar el tiempo y el estado del botón
unsigned long tiempoUltimaLectura = 0; // Guarda el último momento en que se verificó el estado del botón
bool estadoAnteriorBoton = HIGH;       // Estado previo del botón (HIGH significa que NO está presionado)
bool estadoActualBoton;                // Variable donde guardamos la lectura del botón en cada ciclo

void setup()
{
  // Para poder ver mensajes en la consola -> Serial.begin()
  Serial.begin(115200); // Iniciar la comunicación con el ordenador a 115200 baudios (velocidad estándar)

  pinMode(PIN_BOTON, INPUT); // Configurar el botón como entrada (modo sensor)

  Serial.println("El monitoreo del boton ha comenzado...");
}

void loop()
{
  // Leer el estado actual del botón (HIGH si no se presiona, LOW si se presiona)
  estadoActualBoton = digitalRead(PIN_BOTON);

  // Verificar si ha pasado suficiente tiempo desde la última lectura (para evitar rebotes y lecturas excesivas)
  if ((millis() - tiempoUltimaLectura) > INTERVALO_LECTURA)
  {

    // Actualizar el tiempo de la última lectura
    tiempoUltimaLectura = millis();

    // Si el estado del botón ha cambiado desde la última lectura, imprimirlo en la consola
    if (estadoActualBoton != estadoAnteriorBoton)
    {
      estadoAnteriorBoton = estadoActualBoton; // Guardar el nuevo estado para la próxima comparación

      Serial.print("Estado del boton: ");
      Serial.println(estadoActualBoton); // Muestra "0" cuando está presionado y "1" cuando se suelta
    }
  }
}