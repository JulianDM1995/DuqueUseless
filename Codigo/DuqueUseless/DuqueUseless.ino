#define ledPin 10
#define switchPin 2
#define brazoPin 8
#define puertaPin 9

#define MAX_TIPOS 6

#define BRAZO_CERRADO 180
#define BRAZO_ABIERTO 0
#define PUERTA_CERRADA 0
#define PUERTA_ABIERTA 55

#define MEDIO_A 20
#define MEDIO_B 70

#include "funcionesMovimiento.h"

void setup() {
  Serial.begin(115200);
  brazo.attach(brazoPin);
  puerta.attach(puertaPin);
  pinMode(ledPin, OUTPUT);

  brazo.write(BRAZO_CERRADO);
  puerta.write(PUERTA_CERRADA);

  if (sw.getStatus() == SWITCH_OFF) ejecutarCaso();

}

void loop() {
  if (sw.getEvent() == CHANGED_OFF) ejecutarCaso();
}

void ejecutarCaso() {
  Serial.println("Renderizando: " + String(tipo));
  digitalWrite(ledPin, HIGH);
  switch (tipo) {

    case 0:
      abrirPuerta(NORMAL, ESPERA_NORMAL);
      abrirBrazo(NORMAL, ESPERA_POCA);
      cerrarBrazo(NORMAL, ESPERA_POCA);
      cerrarPuerta(RAPIDO, ESPERA_NORMAL);
      break;

    case 1:
      abrirPuerta(RAPIDO, ESPERA_POCA);
      abrirBrazo(RAPIDO, ESPERA_POCA);
      cerrarBrazo(RAPIDO, ESPERA_POCA);
      cerrarPuerta(RAPIDO, ESPERA_POCA);
      break;

    case 2:
      abrirPuerta(RAPIDO, 1500);
      cerrarPuerta(RAPIDO, ESPERA_NORMAL);
      abrirPuerta(RAPIDO, ESPERA_NULA);
      abrirBrazo(RAPIDO, ESPERA_NULA);
      cerrarBrazo(RAPIDO, ESPERA_NULA);
      cerrarPuerta(RAPIDO, ESPERA_NULA);
      break;

    case 3:
      abrirPuerta(LENTO, ESPERA_POCA);
      abrirBrazo(LENTO, ESPERA_MODERADA);
      cerrarBrazo(RAPIDO, ESPERA_NULA);
      cerrarPuerta(RAPIDO, ESPERA_NULA);
      break;

    case 4:
      abrirPuerta(RAPIDO, ESPERA_NORMAL);
      abrirBrazo(LENTO, ESPERA_MODERADA, BRAZO_CERRADO, MEDIO_A);
      for (int i = 0 ; i < 3 ; i++) {
        cerrarBrazo(RAPIDO, ESPERA_NULA, MEDIO_A, MEDIO_B);
        abrirBrazo(RAPIDO, ESPERA_NULA, MEDIO_B, MEDIO_A);
      }
      abrirBrazo(RAPIDO, ESPERA_NORMAL);
      cerrarBrazo(RAPIDO, ESPERA_NULA);
      cerrarPuerta(RAPIDO, ESPERA_NULA);
      break;

    case 5:
      abrirPuerta(RAPIDO, ESPERA_MODERADA);
      abrirBrazo(RAPIDO, ESPERA_NULA);
      cerrarBrazo(RAPIDO, ESPERA_NULA);
      cerrarPuerta(RAPIDO, ESPERA_NULA);
      break;

  }
  digitalWrite(ledPin, LOW);
  tipo = tipo + 1 == MAX_TIPOS ? 0 : tipo + 1;
}
