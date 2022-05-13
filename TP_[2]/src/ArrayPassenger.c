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

typedef struct
{
	int id;
	int name[51];
	int lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
} Passenger;

int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(list !=NULL && len > 0)
	{
		for(i=0;i< len-1;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno =0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno;
	int i;

	retorno =-1;
	i=0;

	if(list !=NULL && len > 0 && name != NULL && lastName != NULL && price > 0 && flycode !=NULL)
	{
		while(list[i].isEmpty == 0 && i<len)
		{
			i++;
		}
		if(list[i].isEmpty == 1)
		{
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			retorno =0;
		}
	}

	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && len>0 && id>0)
	{
		while(list[i].id !=id && i<len)
		{
			i++;
		}
		if(list[i].id == id)
		{
			retorno = id;
		}
	}
	return retorno;
}


