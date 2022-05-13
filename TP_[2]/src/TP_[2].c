/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "utn.h"


int main(void) {
	setbuf(stdout, NULL);
	char punto[] = "Juána";
	char acento[] = "Juana";
	int error;
	// Prueba

	for(int i=0; i< 5; i++)
		{
			if(isalpha(punto[i])!=0)
			{
				printf("\nEl caracter si es una letra: %c", punto[i]);
			}
			else
			{
				printf("\nEl caracter NO es una letra: %c", punto[i]);
			}
		}



	error = getNombre(punto, 30, "Ingrese el nombre: ");
		if(error ==0)
			{
				printf("\nEl nombre es: %s", punto);
			}
			if(error == -1)
			{
				printf("\nHubo un error de direccion");
			}
			if(error ==1)
			{
				printf("\nHubo un error despues de la direccion");
			}


	/*
	char punto[30] = "Perez";
	char acento = 'I';
	int error;

	for(int i=0; i< 5; i++)
	{
		if(isalpha(punto[i])==1)
		{
			printf("\nEl caracter si es una letra: %c", punto[i]);
		}
		else
		{
			printf("\nEl caracter NO es una letra: %c", punto[i]);
		}
	}





		if(isalpha(acento))
	{
		printf("El acento es una letra\n");
	}
	else
	{
		printf("El acento NO una letra\n");
	}

	//error = verificarSerNombre(punto);


	printf("%.2f", juan);
	if(isdigit(punto))
	{
		printf("Punto es un digito");
	}
	else
	{
		printf("Punto NO un digito");
	}

	char prueba[30];


	int i;

	for(i=0; i < sizeof(prueba); i++)
	{
		prueba[i]= '1';
	}

     fflush(stdin);
     scanf("%s", prueba);
     //fgets(prueba, sizeof(prueba), stdin);
     //gets(prueba);

	printf("%s", prueba);
*/
	return EXIT_SUCCESS;
}
