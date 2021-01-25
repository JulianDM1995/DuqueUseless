//FUNCIONES

#include <Servo.h>
#include "LoopSwitch.h"

#define MUY_LENTO 16
#define LENTO 12
#define NORMAL 8
#define RAPIDO 4
#define INSTANTANEO 0

#define ESPERA_MODERADA 1200
#define ESPERA_NORMAL 800
#define ESPERA_POCA 400
#define ESPERA_NULA 100

Servo brazo;
Servo puerta;
LoopSwitch sw(switchPin);

int tipo = 0;

//ABRIR BRAZO

void abrirBrazo(int vel, int del, int desde, int hasta) {
  for (int i = desde; i > hasta; i--) {
    brazo.write(i);
    delay(vel);
  }
  delay(del);
}
void abrirBrazo(int vel, int del) {
  abrirBrazo(vel, del, BRAZO_CERRADO, BRAZO_ABIERTO);
}

//CERRAR BRAZO

void cerrarBrazo(int vel, int del, int desde, int hasta) {
  for (int i = desde; i < hasta; i++) {
    brazo.write(i);
    delay(vel);
  }
  delay(del);
}
void cerrarBrazo(int vel, int del) {
  cerrarBrazo(vel, del, BRAZO_ABIERTO, BRAZO_CERRADO);
}

//ABRIR PUERTA

void abrirPuerta(int vel, int del, int desde, int hasta) {
  for (int i = desde; i < hasta; i++) {
    puerta.write(i);
    delay(vel);
  }
  delay(del);
}
void abrirPuerta(int vel, int del) {
  abrirPuerta(vel, del, PUERTA_CERRADA, PUERTA_ABIERTA);
}

//CERRAR PUERTA

void cerrarPuerta(int vel, int del, int desde, int hasta) {
  for (int i = desde; i > hasta; i--) {
    puerta.write(i);
    delay(vel);
  }
  delay(del);
}
void cerrarPuerta(int vel, int del) {
  cerrarPuerta(vel, del, PUERTA_ABIERTA, PUERTA_CERRADA);
}
