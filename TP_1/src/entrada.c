/*
 * entrada.c
 *
 *  Created on: 10 abr. 2022
 *      Author: thiag
 */

#include <stdio.h>


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

//char eCharC(char opcionUno, char opcionDos);
//
//
//
////////////
//float eFloat();
//int eInt();

//char eCharC(char opcionUno, char opcionDos)
//{
//	char letra;
//
//	printf("Ingrese \"%c\" o \"%c\": ", opcionUno, opcionDos);
//	fflush(stdin);
//	scanf("%c", &letra);
//
//	return letra;
//}
//
//
//
//
//////////////////////////////////////
//
//
//float eFloat()
//{
//	float numero;
//	printf("\nIngresar el numero: ");
//	scanf("%f", &numero);
//
//	return numero;
//}
//
//int eInt()
//{
//	int numero;
//
//	printf("\nIngresar el numero: ");
//	scanf("%d", &numero);
//
//	return numero;
//}
//
