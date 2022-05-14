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
#define TAMANIO_NOMBRE -20
#define TAMANIO_CODIGO -15
#define CIFRAS_PRECIO -15
#define TAMANIO_ID -4

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

} Passenger;


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
			if(list[i].id == id)
			{
				retorno = i;
				break;
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
	int condicionador;
	int i;
	int j;
	Passenger baulPassenger;

	retorno =-1;
	if(list !=NULL && len>0)
	{
		if(order ==1)
		{
			condicionador = 1;
		}
		if(order ==0)
		{
			condicionador =-1;
		}

		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(stricmp(list[i].lastName, list[j].lastName) == condicionador)
				{			//A/////			//B
					baulPassenger = list[i];
					list[i] = list[j];
					list[j] = baulPassenger;
				}
				else
				{
					if((list[i].typePassenger > list[j].typePassenger ) == condicionador)
					{		// 0					// 1
						baulPassenger = list[i];
						list[i] = list[j];
						list[j] = baulPassenger;
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

int printPassenger(Passenger* list, int length)
{
	int retorno;
	int i;
	retorno = -1;

	if(list !=NULL && length >0)
	{
		printf("Pasajeros:\n_________________________________________________________________________________________________________________\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",TAMANIO_ID, "ID", TAMANIO_NOMBRE, "Nombre", TAMANIO_NOMBRE, "Apellido", CIFRAS_PRECIO, "Precio", TAMANIO_CODIGO, "Codigo de Vuelo", 16, "Tipo de pasajero", 15,"Estado de vuelo");
		for(i=0;i<length-1;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("|%*d|%*s|%*s|%*.2f|%*s|%*d|%*d|\n",TAMANIO_ID, list[i].id, TAMANIO_NOMBRE, list[i].name, TAMANIO_NOMBRE, list[i].lastName, CIFRAS_PRECIO, list[i].price, TAMANIO_CODIGO, list[i].flycode, 16, list[i].typePassenger, 15,list[i].statusFlight);
			}
		}
		printf("_________________________________________________________________________________________________________________\n");
		if(i==length -1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int sortUpPassengerByNameAndType(Passenger* list, int len, int condicion)
{
	int retorno;
	int i;
	int j;
	Passenger baulPassenger;

	retorno = -1;
	if(list!= NULL && len >0)
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(stricmp(list[i].lastName, list[j].lastName) == condicion)
				{			//B/////			//A
					baulPassenger = list[i];
					list[i] = list[j];
					list[j] = baulPassenger;
				}
				else
				{
					if(condicio(list[i].typePassenger > list[j].typePassenger ))
					{
						baulPassenger = list[i];
						list[i] = list[j];
						list[j] = baulPassenger;
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

