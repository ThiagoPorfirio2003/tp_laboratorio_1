/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
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
