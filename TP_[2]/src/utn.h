/*
 * utn.h
 *
 *  Created on: 11 may. 2022
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

int verificarSerNombre(char* direccionNombre);

int getNombre(char* direccionNombre, int tamanio, char* mensaje);

int verificarSerCadenaCaracteres(char* direccionCadena);

int getCadenaCaracteres(char* direccionCadena, int tamanio, char* mensaje);

int getIntRango(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

#endif /* UTN_H_ */

//int getIntCero(int* direccionInt, int tamanio,char* mensaje);

//int verificarSerIntCero(char* cadena);
