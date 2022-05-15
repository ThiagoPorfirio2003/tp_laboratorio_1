/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"
#define TAMANIO_NAME -50
#define TAMANIO_CODIGO -15
#define CIFRAS_PRECIO -15
#define TAMANIO_ID -4

int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(list !=NULL && len > 0)
	{
		for(i=0;i< len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno =0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[])
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && len > 0 && name != NULL && lastName != NULL && flycode !=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				strcpy(list[i].flycode,flycode);
				list[i].isEmpty = 0;
				retorno =0;
				break;
			}
		}
	}

	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty ==0)
			{
				if(list[i].id == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(list !=NULL && len > 0 && id>-1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	int condicion;
	int condicionDos;
	int banderaAccionar;

	banderaAccionar = 0;
	Passenger baulPassenger;

	if(order == 1)
	{
		condicionDos =1;
		condicion =1;
	}
	else
	{
		condicion = -1;
		condicionDos=0;
	}
	retorno = -1;
	if(list!= NULL && len >0)
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty == 0)
				{
					if(strcmp(list[i].lastName, list[j].lastName) != 0)
					{
						if(strcmp(list[i].lastName, list[j].lastName) == condicion)
						{
							banderaAccionar =1;
						}
					}
					else
					{
						if((list[i].typePassenger > list[j].typePassenger ) == condicionDos)
						{
							banderaAccionar =1;
						}
					}
					if(banderaAccionar ==1)
					{
						baulPassenger = list[i];
						list[i] = list[j];
						list[j] = baulPassenger;
						banderaAccionar =0;
					}
				}
			}
		}
		if(i == len-1)
		{
			retorno =0;
		}
	}
	return retorno;
}

int printPassenger(Passenger* list, int length, int condicionAparicion)
{
	int retorno;
	int i;
	int contadorActivo;
	char typePassenger[12];
	char estadoDevuelo[10];
	contadorActivo =0;
	i=0;
	retorno = -1;

	if(list !=NULL && length >-1)
	{
		printf("Pasajeros:\n______________________________________________________________________________________________________________________________________________________________________________\n");
		printf("|%*s|%*s|%*s|%*s |%*s|%*s|%*s|\n",TAMANIO_ID, "ID", TAMANIO_NAME, "Apellido", TAMANIO_NAME, "Nombre", CIFRAS_PRECIO, "Precio", TAMANIO_CODIGO, "Codigo de Vuelo", 16, "Tipo de pasajero", 15,"Estado de vuelo");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == 0)
			{
				switch(list[i].typePassenger)
				{
					case 0: strcpy(typePassenger,"Adolescente");
						break;

					case 1: strcpy(typePassenger,"Adulto");
						break;

					case 2: strcpy(typePassenger,"Anciano");
						break;

					case 3:	strcpy(typePassenger,"Bebe");
						break;

					default:strcpy(typePassenger,"Niño");
						break;
				}

				if(condicionAparicion ==1)
				{
					contadorActivo++;
					strcpy(estadoDevuelo,"Activo");

					if(list[i].statusFlight ==0)
					{
						strcpy(estadoDevuelo,"Desactivo");
					}
					printf("|%*d|%*s|%*s|$%*.2f|%*s|%*s|%*s|\n",TAMANIO_ID, list[i].id, TAMANIO_NAME, list[i].lastName, TAMANIO_NAME, list[i].name, CIFRAS_PRECIO, list[i].price, TAMANIO_CODIGO, list[i].flycode, -16, typePassenger, -15,estadoDevuelo);
				}

				if(list[i].statusFlight ==1 && condicionAparicion ==3)
				{
					contadorActivo++;
					strcpy(estadoDevuelo,"Desactivo");

					if(list[i].statusFlight ==1)
					{
						strcpy(estadoDevuelo,"Activo");
						printf("|%*d|%*s|%*s|$%*.2f|%*s|%*s|%*s|\n",TAMANIO_ID, list[i].id, TAMANIO_NAME, list[i].lastName, TAMANIO_NAME, list[i].name, CIFRAS_PRECIO, list[i].price, TAMANIO_CODIGO, list[i].flycode, -16, typePassenger, -15,estadoDevuelo);
					}
				}

			}
		}
		if(contadorActivo ==0)
		{
			printf("Todos los pasajeros estan inactivos, por lo que no apareceran\n");
		}
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		if(i==length -1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int sortPassengerByFlycode(Passenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	int condicion;
	int condicionDos;
	int banderaAccionar;
	Passenger baulPassenger;

	banderaAccionar =0;

	if(order == 1)
	{
		condicionDos =1;
		condicion =1;
	}
	else
	{
		condicion = -1;
		condicionDos=0;
	}
	retorno = -1;
	if(list!= NULL && len >0)
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty == 0)
				{
					if(stricmp(list[i].flycode, list[j].flycode) != 0)
					{
						if(stricmp(list[i].flycode, list[j].flycode) == condicion)
						{
							banderaAccionar=1;
						}
					}
					else
					{
						if((list[i].statusFlight > list[j].statusFlight) == condicionDos)
						{
							banderaAccionar=1;
						}
					}
				}
				if(banderaAccionar ==1)
				{
					baulPassenger = list[i];
					list[i] = list[j];
					list[j] = baulPassenger;
					banderaAccionar =0;
				}
			}
		}
		if(i == len-1)
		{
			retorno =0;
		}
	}
	return retorno;
}

int modifyPassengerById(Passenger* list, int posicionPasajero, int opcion, int tamanioNombre, int intentos, float precioMinimo, float precioMaximo)
{
	int retorno;
	char name[256];
	char lastName[256];
	float price;
	int typePassenger;
	char flycode[256];

	retorno =-1;

	if(list != NULL && posicionPasajero>-1)
	{
		switch(opcion)
		{
			case 1:
				getPalabraTamanioDeterminado(name, "\nIngrese el nombre del pasajero: ", "", 2,tamanioNombre, intentos, "El dato ingresado es invalido. ");
				transformarMinusculaAMayuscula(&name[0]);
				strcpy(list[posicionPasajero].name, name);
				break;

			case 2:
				getPalabraTamanioDeterminado(lastName, "\nIngrese el apellido del pasajero: ", "", 2,tamanioNombre, intentos, "El dato ingresado es invalido. ");
				transformarMinusculaAMayuscula(&lastName[0]);
				strcpy(list[posicionPasajero].lastName, lastName);
				break;

			case 3:
				getFloatRango(&price, "\nIngresa el precio del vuelo, debe estar entre $10000 y $100000000: ", "", precioMinimo, precioMaximo, intentos, "El dato ingresado es invalido. ");
				list[posicionPasajero].price = price;
				break;

			case 4:
				getIntRango(&typePassenger, "\nTipo de pasajero:\n1. Bebe \n2. Niño\n3. Adolescente\n4. Adulto\n5. Anciano\nIngrese el numero correspondiente al tipo: ", "", 1, 5, intentos, "\nEl dato ingresado es incorrecto, intentos restantes: ");
				list[posicionPasajero].typePassenger = typePassenger;
				break;

			default:
				getCadenaAlfanumericaTamanioFijo(flycode, "\nIngrese el codigo de vuelo, debe tener 9 caracteres: ", "", 9, intentos, "El dato ingresado es invalido");
				trasnformarCadenaAlfaNumericaAMayuscula(flycode, 9);
				strcpy(list[posicionPasajero].flycode,flycode);
				break;
			}
		retorno =0;
		}

	return retorno;
}

int calcularPromedioyCantidadEncimaPromedio(Passenger* list, float* promedioPrecios, int* cantidadPreciosSobrePromedio, int cantidadPasajerosTotal, int cantidadPasajerosActual,float acumuladorPrecio)
{
	int retorno;
	int i;

	retorno=-1;

	if(promedioPrecios !=NULL && cantidadPreciosSobrePromedio != NULL && cantidadPasajerosActual > 0)
	{
		retorno=-1;
		*promedioPrecios = acumuladorPrecio / cantidadPasajerosActual;
		for(i=0;i<cantidadPasajerosTotal;i++)
		{
			if(list[i].price > *promedioPrecios && list[i].isEmpty ==0)
			{
				*cantidadPreciosSobrePromedio+=1;
			}
		}
		if(i == cantidadPasajerosTotal)
		{
			retorno =0;
		}
	}
	return retorno;
}

int acumuladorPrecio(Passenger* list, float* acumulador, int cantidadPasajeros)
{
	int retorno;
	int i;

	retorno= -1;

	if(list != NULL && acumulador !=NULL && cantidadPasajeros>-1)
	{

		for(i=0;i<cantidadPasajeros;i++)
		{
			if(list[i].isEmpty ==0)
			{
				*acumulador +=list[i].price;
				retorno=0;
			}
		}
		if(i == cantidadPasajeros)
		{
			retorno =0;
		}
	}
	return retorno;
}

int reasignarValoresParaComparar(Passenger* list, int cantidadPasajeros)
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && cantidadPasajeros>0)
	{
		retorno=0;
		for(i=0;i<cantidadPasajeros;i++)
		{
			switch(list[i].typePassenger)
			{
				case 1: list[i].typePassenger=3;
					break;

				case 2: list[i].typePassenger=4;
					break;

				case 3: list[i].typePassenger=0;
					break;

				case 4:	list[i].typePassenger=1;
					break;

				default:list[i].typePassenger=2;
					break;
			}
		}
	}

	return retorno;
}
/*



 */
