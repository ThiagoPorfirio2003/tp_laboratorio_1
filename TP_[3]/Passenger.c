#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

Passenger* Passenger_new()
{
	Passenger* nuevoPasajero;

	nuevoPasajero = ((void*)0);
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(nuevoPasajero != ((void*)0))
	{
		Passenger_setId(nuevoPasajero, 0);
		Passenger_setNombre(nuevoPasajero,"");
		Passenger_setApellido(nuevoPasajero,"");
		Passenger_setCodigoVuelo(nuevoPasajero,"");
		Passenger_setTipoPasajero(nuevoPasajero,0);
		Passenger_setPrecio(nuevoPasajero,0);
		Passenger_setEstadoVuelo(nuevoPasajero,0);
	}

	return nuevoPasajero;
}

Passenger* Passenger_newParametros(int* idStr,char* nombreStr, char* apellidoStr, float* precioStr, int* tipoPasajeroStr, char* codigoVueloStr, int* statusFlight)
{
	Passenger* nuevoPasajero;

	nuevoPasajero = ((void*)0);
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));


	if(nuevoPasajero != ((void*)0) && idStr != ((void*)0) &&
			nombreStr != ((void*)0) &&
			apellidoStr != ((void*)0) &&
			precioStr != ((void*)0) &&
			tipoPasajeroStr != ((void*)0) &&
			codigoVueloStr != ((void*)0) &&
			statusFlight != ((void*)0))
	{
		Passenger_setId(nuevoPasajero, *idStr);
		Passenger_setNombre(nuevoPasajero, nombreStr);
		Passenger_setApellido(nuevoPasajero, apellidoStr);
		Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
		Passenger_setTipoPasajero(nuevoPasajero, *tipoPasajeroStr);
		Passenger_setPrecio(nuevoPasajero, *precioStr);
		Passenger_setEstadoVuelo(nuevoPasajero, *statusFlight);
	}
	else
	{
		nuevoPasajero= ((void*)0);
		if(nuevoPasajero == ((void*)0))
		{
			printf("new NULL");
		}

	}



	return nuevoPasajero;
}


int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0))
	{
		this->id = id;
		retorno=0;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && id != ((void*)0))
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && nombre != ((void*)0) /*&& !utn_verificarSerNombre(nombre)*/)
	{
		strncpy(this->nombre, nombre,50);
		retorno=0;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && nombre != ((void*)0) /*&& !utn_verificarSerNombre(nombre)*/)
	{
		strncpy(nombre, this->nombre,50);
		retorno=0;
	}

	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && apellido != ((void*)0) /*&& !utn_verificarSerNombre(apellido)*/)
	{
		strncpy(this->apellido, apellido,50);
		retorno=0;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && apellido != ((void*)0) /* && !utn_verificarSerNombre(apellido)*/)
	{
		strncpy(apellido, this->apellido,50);
		retorno=0;
	}

	return retorno;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && codigoVuelo != ((void*)0) /*&& !controller_verificarSerCodigoDeVuelo(codigoVuelo)*/)
	{
		strncpy(this->codigoVuelo, codigoVuelo,50);
		retorno=0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && codigoVuelo != ((void*)0) /*&& !controller_verificarSerCodigoDeVuelo(codigoVuelo)*/)
	{
		strncpy(codigoVuelo, this->codigoVuelo, 50);
		retorno=0;
	}

	return retorno;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) /* && (tipoPasajero>1 || tipoPasajero<3)*/)
	{
		this->tipoPasajero = tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && tipoPasajero != ((void*)0))
	{
		*tipoPasajero = this->tipoPasajero;
		retorno=0;
	}

	return retorno;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) /*&& precio>0*/)
	{
		this->precio = precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && precio != ((void*)0))
	{
		*precio = this->precio;
		retorno=0;
	}

	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,int estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) /*&& (estadoDeVuelo>1 || estadoDeVuelo<3)*/)
	{
		this->statusFlight = estadoDeVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != ((void*)0) && estadoDeVuelo != ((void*)0) /*&& (estadoDeVuelo>1 || estadoDeVuelo<3)*/)
	{
		*estadoDeVuelo = this->statusFlight;
		retorno=0;
	}

	return retorno;
}
