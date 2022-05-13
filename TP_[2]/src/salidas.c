/*
 * salidas.c
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "vectores.h"


int imprimirPosicionYNumero(char* mensajeInicializador, int posicion, char* mensajeFinalizador)
{
	int retorno;

	retorno =0;

	if(mensajeInicializador != NULL && mensajeFinalizador != NULL)
	{
		printf("%s%d%s", mensajeInicializador, posicion, mensajeFinalizador);
		retorno =1;
	}

	return retorno;
}
