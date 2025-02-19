# 🔘 Práctica 0: LED con Pulsador - Arduino

Este proyecto permite encender un **LED** solo mientras se mantiene presionado un **pulsador**.

## 📜 Descripción

Este programa de **Arduino** utiliza un **pulsador** como entrada para controlar el encendido de un **LED**.  
- Si el pulsador se **presiona**, el LED se **enciende**.  
- Si el pulsador se **suelta**, el LED se **apaga**.  

El código usa la resistencia **pull-up interna** de Arduino, por lo que el pulsador no requiere una resistencia externa.

El objetivo es mostrar por pantalla cuando el arduino lee un 0 y cuando lee un 1 (No debe
aparecer en bucle infinito, eso estaría incorrecto).
Muchas veces las placas protoboard no hacen bien el contacto, apretar para dentro el cable.
Si no hace bien el contacto te puede meter en bucle infinito.
En esta práctica estamos imitando el comportamiento de un sensor a partir de la 
señal recibida del pulsador

Se aconseja usar la alimentación de la fuente de alimentación para alimentar
el circuito y no el arduino.
El arduino ya recibe alimentación a partir del cable usb conectado
a nuestro portátil

En esta práctica el Arduino solo vale para mostrar la salida.

En la siguiente práctica que se explicará el viernes, se hace exactamente lo mismo pero usando
la placa arduino, abrirá la práctica en el cv hoy o mañana.

Esta práctica está compuesta de dos montajes, usando un mismo programa.

## 🛠️ Material necesario (incluido en la bolsa proporcionada)

- Una placa **Arduino** (UNO, Mega, Nano, etc.)
- Un **LED** (opcional si no usas el integrado)
- Una **Resistencia**
- Un **Pulsador**
- **Cables de conexión**

