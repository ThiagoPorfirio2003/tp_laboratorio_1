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
#define TAMANIO_NOMBRE -20
#define TAMANIO_CODIGO -15
#define CIFRAS_PRECIO -15
#define TAMANIO_ID -4

int main(void) {
	setbuf(stdout, NULL);
	char punto = 'ñ';
	char acento[30];
	float numero;
	int numeroEntero;
	int error;
	char juan []= "32.145";


	printf("%d",20>10);
	// Prueba
/*
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
			if(islower(punto) != 0)
	{
		printf("\nLa letrs es: %c\n", punto);
	}
	transformarMinusculaAMayuscula(&punto);

	printf("\nLa mayuscula es: %c", punto);
*/

	//error = getIntMayorA(&numeroEntero, 10, "Ingresa un numero Mayor a 2", "Te quedan intestos: ", 2, 3, "Vuelve a intentarlo");
	//error = getFloatMayorA(&numero, 10, "Ingresa un numero entre 2 y 10", "Te quedan intestos: ", 2, 3, "Vuelve a intentarlo");
	//error = getFloat(&numero, 30, "Ingrese el float");
	//error = verificarSerFloat(juan);



	/*
	 * 		if(error ==0)
			{
				printf("\nEl numero es: %f", numero);
				printf("\nEl numero ENTERO es: %d", numeroEntero);
			}
			if(error == -1)
			{
				printf("\nHubo un error de direccion");
			}
			if(error ==1)
			{
				printf("\nHubo un error despues de la direccion");
			}
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
*/	return EXIT_SUCCESS;
}
