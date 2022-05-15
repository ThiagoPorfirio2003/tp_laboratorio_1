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
#include "utn.h"
#include "ArrayPassenger.h"
#define CANTIDAD_PASAJEROS 2000
#define TAMANIO_NAME 50
#define TAMANIO_FLYCODE 10
#define INTENTOS -1
#define PRECIO_MAXIMO 100000000
#define PRECIO_MINIMO 10000

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	int chequeoErrorOpcionMenu;
	int contador;
	int id;
	char name[TAMANIO_NAME];
	char lastName[TAMANIO_NAME];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int banderaOpcionCuatro;
	int banderaOpcionCinco;
	int opcionSubMenu;
	int errorSubMenu;
	float acumuladorPrecioPasajes;
	float promedioPrecioPasajes;
	int cantidadDePreciosSuperanPromedio;
	int posicionPasajero;
	int chequeoErrorCaseDos;
	int opcionCaseDos;
	int chequeErrorCaseTres;
	int cantidadPasajeros;

	Passenger list[CANTIDAD_PASAJEROS];
	Passenger hardcodeado[]={
			{1,"Pedra", "Racedo", 78030, "ADF231ASD", 3, 1, 0},
			{3,"Thiago", "Porfirio", 102003, "CVX124FDA", 1, 1, 0},
			{2,"Patricio", "Fernandez", 52000, "ASD536ADF", 4, 1, 0},
			{4,"Juana", "Racedo", 32000, "ABC456CVB", 2, 1, 0},
			{0,"Esteban", "Aguirre", 15000, "FDS346DAF", 3, 1, 0},
	};

	cantidadPasajeros=0;
	contador = 0;
	banderaOpcionDos=0;
	banderaOpcionTres=0;
	banderaOpcionCuatro=0;
	banderaOpcionCinco=1;
	errorSubMenu =1;
	acumuladorPrecioPasajes =0;
	cantidadDePreciosSuperanPromedio =0;

	initPassengers(list, CANTIDAD_PASAJEROS);
	printf("¡¡¡¡ Bienvendido !!!\n\n");
	do
	{
		printf("---------------------OPCIONES-----------------------\n"
				"1. Ingresar datos de un pasajero\n"
				"2. Modificar datos de un pasajero, se requiere su ID\n"
				"3. Eliminar un pasajero, se requiere su ID\n"
				"4. Informe sobre pasajeros:\n"
				"5. Usar datos Precargados\n\n");
		chequeoErrorOpcionMenu = getIntRango(&opcionMenu, "Ingrese el numero de la opcion que quiere realizar: ", "", 1, 5, INTENTOS, "\nDato erroneo, vuelva a intentarlo. ");
		if(chequeoErrorOpcionMenu ==0)
		{
			switch(opcionMenu)
			{
				case 1:
					initPassengers(list, CANTIDAD_PASAJEROS);
					id = contador;

					getPalabraTamanioDeterminado(name, "\nIngrese el nombre del pasajero: ", "", 2,TAMANIO_NAME, INTENTOS, "El dato ingresado es invalido. ");
					transformarMinusculaAMayuscula(&name[0]);
					getPalabraTamanioDeterminado(lastName, "\nIngrese el apellido del pasajero: ", "", 2,TAMANIO_NAME, INTENTOS, "El dato ingresado es invalido. ");
					transformarMinusculaAMayuscula(&lastName[0]);
					getCadenaAlfanumericaTamanioFijo(flycode, "\nIngrese el codigo de vuelo, debe tener 9 caracteres: ", "", 9, INTENTOS, "El dato ingresado es invalido");
					trasnformarCadenaAlfaNumericaAMayuscula(flycode, 9);
					getFloatRango(&price, "\nIngresa el precio del vuelo, debe estar entre $10000 y $100000000: ", "", PRECIO_MINIMO, PRECIO_MAXIMO, INTENTOS, "El dato ingresado es invalido. ");
					getIntRango(&typePassenger, "\nTipo de pasajero:\n1. Bebe \n2. Niño\n3. Adolescente\n4. Adulto\n5. Anciano\nIngrese el numero correspondiente al tipo: ", "", 1, 5, INTENTOS, "\nEl dato ingresado es incorrecto, intentos restantes: ");
					getIntRango(&statusFlight, "\nEstado de vuelo:\n 1. Activo\n 0. Inactivo\nIngrese el numero que corresponda: ", "", 0, 1, INTENTOS, "\nEl dato ingresado es invalido. ");
					printf("\n\n");
					addPassenger(list, CANTIDAD_PASAJEROS, id, name, lastName, price, typePassenger, statusFlight, flycode);


					contador++;
					cantidadPasajeros++;
					banderaOpcionDos =1;
					banderaOpcionTres =1;
					banderaOpcionCuatro =1;
					banderaOpcionCinco=0;
				break;

				case 2:
					if(banderaOpcionDos ==1)
					{
						chequeoErrorCaseDos = getIntRango(&id, "Ingrese el id perteneciente al pasajero: ", "\nEl dato ingresado es incorrecto, intentos restantes: ", 0, contador, -1, "Se ha quedado sin intentos");
						if(chequeoErrorCaseDos == 0)
						{
							posicionPasajero = findPassengerById(list, (contador+1), id);
							printf("\nOpciones a modificar: \n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Codigo de vuelo\n");
							chequeoErrorCaseDos = getIntRango(&opcionCaseDos, "\nElija una opcion: ", "", 1, 5, -1, "El dato ingresado es invalido. ");
							if(chequeoErrorCaseDos ==0)
							{
								chequeoErrorCaseDos = modifyPassengerById(list, posicionPasajero, opcionCaseDos, TAMANIO_NAME, INTENTOS, PRECIO_MINIMO, PRECIO_MAXIMO);
							}
						}
						else
						{
							printf("\nA ocurrido un error, lo mas probable es que hayas ingresado un id dado de baja.\n");
						}
					}
					else
					{
						printf("\nTenes que ingresar al menos un pasajero para poder realizar esta opcion\n");
					}
					printf("\n");
					break;

				case 3:
					if(banderaOpcionTres ==1)
					{
						getIntRango(&id, "Ingrese el id perteneciente al pasajero: ", "", 0, contador, -1, "El dato ingresado es invalido.");
						chequeErrorCaseTres =removePassenger(list, (contador+1), id);
						printf("\n");
						if(chequeErrorCaseTres == 0)
						{
							printf("Se ha removido al pasajero.");
							cantidadPasajeros--;
						}
						else
						{
							printf("Ocurrio un error al remover al pasajero.");
						}

						printf("\n\n");
					}
					else
					{
						printf("\nTenes que ingresar al menos un pasajero para poder realizar esta opcion\n\n");
					}
					break;

				case 4:
					if(banderaOpcionCuatro==1)
					{
						reasignarValoresParaComparar(list, (contador+1));
						printf("\n 1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo\n"
								" 2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n"
								" 3- Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
						getIntRango(&opcionSubMenu, "Ingrese la opcion deseada: ", "\nEl dato ingresado es incorrecto, intentos restantes: ", 1, 3, -1, "Dato invalido. ");

						switch(opcionSubMenu)
						{
							case 1:
								errorSubMenu =sortPassengers(list, (contador+1), 1);
								break;

							case 2:
								errorSubMenu = acumuladorPrecio(list, &acumuladorPrecioPasajes, (contador+1));
								if(errorSubMenu == 0)
								{
									errorSubMenu= calcularPromedioyCantidadEncimaPromedio(list, &promedioPrecioPasajes, &cantidadDePreciosSuperanPromedio, (contador+1), cantidadPasajeros, acumuladorPrecioPasajes);
								}
								break;

							default:
								errorSubMenu =sortPassengerByFlycode(list, (contador+1), 3);
								break;
						}
						if(errorSubMenu == 0)
						{
							if(opcionSubMenu!=2)
							{
								printPassenger(list, (contador+1), opcionSubMenu);
							}
							else
							{
								printf("	-Dinero total mediante la venta de pasajes: $%.2f\n	-Promedio de precio de los pasajes:  $%.2f\n	-Cantidad de pasajes que superaron el promedio: %d\n\n", acumuladorPrecioPasajes, promedioPrecioPasajes, cantidadDePreciosSuperanPromedio);
								acumuladorPrecioPasajes=0;
								cantidadDePreciosSuperanPromedio=0;
							}
						}
					}
					else
					{
						printf("\nTenes que ingresar al menos un pasajero para poder realizar esta opcion\n\n");
					}
					break;

				default:
					if(banderaOpcionCinco==1)
					{
						list[0] = hardcodeado[0];
						list[1] = hardcodeado[1];
						list[2] = hardcodeado[2];
						list[3] = hardcodeado[3];
						list[4] = hardcodeado[4];

						contador =4;
						cantidadPasajeros =5;
						banderaOpcionDos =1;
						banderaOpcionTres =1;
						banderaOpcionCuatro =1;
						banderaOpcionCinco =0;
						printf("\nSe activaron los 5 pasajeros precargados.\n\n");
					}
					else
					{
						printf("\nComo ya ingresaste al menos un pasajero o entraste aqui previamente, esta opcion se volvio inaccesible\n\n");
					}
					break;
			}
		}
	}while(opcionMenu < 6);


	return EXIT_SUCCESS;
}
