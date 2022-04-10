/*
 * validar.c
 *
 *  Created on: 10 abr. 2022
 *      Author: thiag
 */

#include <stdio.h>

char vChar(char letra ,char opcionUno, char opcionDos)
{
	int retorno;

	while(letra != opcionUno && letra != opcionDos)
	{
		printf("La letra ingresada es invalida, ingrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
		fflush(stdin);
		scanf("%c", &letra);
	}

	retorno = letra;

	return retorno;
}

float vFloatMaIgual(float numero, float limite)
{
	while(numero<limite)
		{
			printf("El dato ingresado es incorrecto, este tiene que ser mayor igual a \"%.2f\": ", limite);
			scanf("%f", &numero);
		}

	return numero;
}

int vIntMaIgual(int numero, int limite)
{
	while(numero<limite)
	{
		printf("El dato ingresado es incorrecto, este tiene que ser mayor o igual a \"%d\": ", limite);
		scanf("%d", &numero);
	}
	return numero;
}

int vIntMeIgual(int numero, int limite)
{
	while(numero>limite)
	{
		printf("El dato ingresado es incorrecto, este tiene que ser menor o igual a \"%d\": ", limite);
		scanf("%d", &numero);
	}
	return numero;
}

int reIngresar(void)
{
	int opcion;
	printf("Si desea ingresar otro numero ingrese 1, de lo contrario ingrese cualquier otro numero: ");
	scanf("%d", &opcion);
	return opcion;
}

