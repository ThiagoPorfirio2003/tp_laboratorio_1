/*
 * validar-entrada.c
 *
 *  Created on: 8 abr. 2022
 *      Author: thiag
 */
#include <stdio.h>

void pedirChar(char* letra, char opcionUno, char opcionDos)
{
	printf("\nIngrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
	scanf("%d", &letra);
}

char validarChar(char letra ,char opcionUno, char opcionDos)
{
	int retorno;

	while(letra != opcionUno && letra != opcionDos)
	{
		printf("\nLa letra ingresada es invalida, ingrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
		scanf("%c", &letra);
	}

	retorno = letra;

	return retorno;
}


////////////////////////////////////


void ingresoN(int* num)
{
	printf("\nIngresar el numero: ");
	scanf("%d",&num);
}
