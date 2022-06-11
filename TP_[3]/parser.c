#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

#define PRECIO_MINIMO 10000

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	char idCaracter[15];
	char nombre[50];
	char apellido[50];
	char precioCaracter[50];
	char tipoPasajeroCaracter[30];
	char codigoVuelo[8];
	char statusFlightCaracter[30];

	int idNumero;
	float precioNumero;
	int tipoPasajeroNumero;
	int statusFlightNumero;

	Passenger* nuevoPasajero;

	retorno=1;

	if(pFile != ((void*)0) && pArrayListPassenger != ((void*)0))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter);
		while(7 == fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter))
		{
			if(!utn_verificarSerInt(idCaracter) && (idNumero = atoi(idCaracter)) >0 && !utn_verificarSerNombre(nombre) && !utn_verificarSerNombre(apellido) &&
					!utn_verificarSerFloat(precioCaracter) && (precioNumero = atof(precioCaracter)) >= PRECIO_MINIMO &&
					!controller_verificarSerCodigoDeVuelo(codigoVuelo))
			{

				if(!strcmp(statusFlightCaracter, "Aterrizado"))
				{
					statusFlightNumero=1;
				}
				else
				{
					if(!strcmp(statusFlightCaracter, "En Horario"))
					{
						statusFlightNumero=2;
					}
					else
					{
						if(!strcmp(statusFlightCaracter, "Demorado"))
						{
							statusFlightNumero=3;
						}
						else
						{
							if(!strcmp(statusFlightCaracter, "En Vuelo"))
							{
								statusFlightNumero=4;
							}
							else
							{
								break;
							}

						}
					}
				}

				if(!strcmp(tipoPasajeroCaracter, "FirstClass"))
				{
					tipoPasajeroNumero=1;
				}
				else
				{
					if(!strcmp(tipoPasajeroCaracter, "ExecutiveClass"))
					{
						tipoPasajeroNumero=2;
					}
					else
					{
						if(!strcmp(tipoPasajeroCaracter, "EconomyClass"))
						{
							tipoPasajeroNumero=3;
						}
						else
						{
							break;
						}
					}
				}

				if( ((void*)0) != (nuevoPasajero = Passenger_newParametros(&idNumero, nombre, apellido, &precioNumero, &tipoPasajeroNumero, codigoVuelo, &statusFlightNumero)))
				{
					if(!ll_add(pArrayListPassenger, nuevoPasajero))
					{
						controller_MostrarUnPasajero(nuevoPasajero);
					}
					else
					{
						break;
					}
				}
				if(feof(pFile))
				{
					retorno=0;
					break;
				}
			}
 			else
			{
				break;
			}
		}

	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
