/*
 * validar-entrada.h
 *
 *  Created on: 8 abr. 2022
 *      Author: thiag
 */

#ifndef VALIDAR_ENTRADA_H_
#define VALIDAR_ENTRADA_H_

char eCharC(char opcionUno, char opcionDos);

char vChar(char letra ,char opcionUno, char opcionDos);

//////////
float eFloat();
int eInt();

float vFloatMa(int numero, float limite);
int vIntMaIgual(int numero, int limite);
int vIntMeIgual(int numero, int limite);

int reIngresar(void);
#endif /* VALIDAR_ENTRADA_H_ */
