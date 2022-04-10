/*
 * validar-entrada.c
 *
 *  Created on: 8 abr. 2022
 *      Author: thiag
 */
#include <stdio.h>

char eCharC(char opcionUno, char opcionDos)
{
	char letra;

	printf("Ingrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

char vChar(char letra ,char opcionUno, char opcionDos)
{
	int retorno;

	while(letra != opcionUno && letra != opcionDos)
	{
		printf("\nLa letra ingresada es invalida, ingrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
		fflush(stdin);
		scanf("%c", &letra);
	}

	retorno = letra;

	return retorno;
}


////////////////////////////////////


float eFloat()
{
	float numero;
	printf("\nIngresar el numero: ");
	scanf("%f", &numero);

	return numero;
}

int eInt()
{
	int numero;

	printf("\nIngresar el numero: ");
	scanf("%d", &numero);

	return numero;
}

float vFloatMa(float numero, float limite)
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
		printf("\nEl dato ingresado es incorrecto, este tiene que ser mayor o igual a \"%d\": ", limite);
		scanf("%d", &numero);
	}
	return numero;
}

int vIntMeIgual(int numero, int limite)
{
	while(numero>limite)
	{
		printf("\nEl dato ingresado es incorrecto, este tiene que ser menor o igual a \"%d\": ", limite);
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


