/*
 * utn.h
 *
 *  Created on: 13 may. 2022
 *      Author: thiag
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char* direccionCadena, int tamanio);

int verificarSerInt(char* cadena);

int getInt(int* direccionInt,int tamanio, char* mensaje);

int verificarSerFloat(char* cadena);

int getFloat(float* direccionFloat, int tamanio,char* mensaje);

int verificarSerPalabra(char* direccionPalabra);

int getPalabra(char* direccionPalabra, int tamanio, char* mensaje);

int transformarMinusculaAMayuscula(char* direccionCaracter);

int verificarSerCadenaCaracteres(char* direccionCadena);

int getCadenaCaracteres(char* direccionCadena, int tamanio, char* mensaje);

int getIntRango(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos, char* mensajeSinIntentos);

int getFloatRango(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float minimo, float maximo, int intentos, char* mensajeSinIntentos);

int getIntMayorA(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int minimo, int intentos, char* mensajeSinIntentos);

int getFloatMayorA(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float minimo, int intentos, char* mensajeSinIntentos);

int getIntMenorA(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int maximo, int intentos, char* mensajeSinIntentos);

int getFloatMenorA(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float maximo, int intentos, char* mensajeSinIntentos);


#endif /* UTN_H_ */
