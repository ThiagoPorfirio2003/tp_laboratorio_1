/*
 * entrada.c
 *
 *  Created on: 10 abr. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>

char eChar()
{
	char letra;

	printf("\nIngrese la letra: ");
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

float eFloat(void)
{
	float numero;
	printf("\nIngresar el numero: ");
	scanf("%f", &numero);

	return numero;
}

int eInt(void)
{
	int numero;

	printf("\nIngresar el numero: ");
	scanf("%d", &numero);

	return numero;
}
