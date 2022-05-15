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

int getInt(int* direccionInt, char* mensaje);

int verificarSerFloat(char* cadena);

int getFloat(float* direccionFloat, char* mensaje);

int verificarSerPalabra(char* direccionPalabra);

int getPalabra(char* direccionPalabra, char* mensaje);

int getPalabraConTamanioFijo(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadLetras, int intentos, char* mensajeSinIntentos);

int getPalabraConTamanioMaximo(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadLetras, int intentos, char* mensajeSinIntentos);

int transformarMinusculaAMayuscula(char* direccionCaracter);

//int verificarSerCadenaCaracteres(char* direccionCadena);

int getCadenaCaracteres(char* direccionCadena, char* mensaje);

int getIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos, char* mensajeSinIntentos);

int getFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int intentos, char* mensajeSinIntentos);

int getIntMayorA(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int intentos, char* mensajeSinIntentos);

int getFloatMayorA(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, int intentos, char* mensajeSinIntentos);

int getIntMenorA(int* direccionInt, char* mensaje, char* mensajeError, int maximo, int intentos, char* mensajeSinIntentos);

int getFloatMenorA(float* direccionFloat, char* mensaje, char* mensajeError, float maximo, int intentos, char* mensajeSinIntentos);

int transformarMinusculaAMayuscula(char* direccionCaracter);

int getCadenaAlfanumericaTamanioFijo(char* direccionCadena, char* mensaje, char* mensajeError, int cantidadCaracteres, int intentos, char* mensajeSinIntentos);

int getCadenaAlfaNumerica(char* direccionCadena, char* mensaje);

int trasnformarCadenaAlfaNumericaAMayuscula(char* direccionCadena, int cantidadCaracteres);

int getPalabraTamanioDeterminado(char* direccionPalabra, char* mensaje, char* mensajeError, int minimoCaracteres, int maximoCaracteres, int intentos, char* mensajeSinIntentos);

#endif /* UTN_H_ */
