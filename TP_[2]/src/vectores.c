/*
 * vectores.c
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int vectorInicializarInt(int* vector, int valorInicial,int tamanio)
{
	int retorno;
	int i;

	retorno=0;
	if(vector != NULL && tamanio > 0)
	{
		for(i=0; i<tamanio; i++)
		{
			vector[i]= valorInicial;
		}

		retorno = 1;
	}

	return retorno;
}

int vectorCargaSecuencial(int* vector,int tamanio, char* mensajePresentacion, char* mensajeFinalizacion)
{
	int retorno;
	int i;

	retorno = 0;

	if(vector != NULL && tamanio > 0)
	{
		for(i=0; i<tamanio; i++)
		{
			printf("%s", mensajePresentacion);
			printf("%d%s", i, mensajeFinalizacion);
			//getInt(&vector[i]);
		}
		retorno = 1;
	}

	return retorno;
}
