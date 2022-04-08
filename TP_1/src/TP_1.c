/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"
#include "validar-entrada.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	int precioVuelo;
	char opcionVuelo;

	do{
		printf("\n\n1.Ingresar Cantidad de kilometros"
		"\n2.Ingresar Precio de Vuelos"
		"\n3.Calcular Costos"
		"\n4.Informar resultados"
		"\n5.Carga forzada de datos (Datos precargados)"
		"\n6.Salir"
		"\nEscriba el numero de la opcion que desea realizar: ");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				ingresoN(&kilometros);
				break;

			case 2:
				ingresoN(&precioVuelo);


				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			default:
				break;
		}
	}while(opcion<6);
	/*
	int opcion;
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	float descuento;
	float aumento;
	float precioDescuentoAerolineas;
	float precioAumentoAerolineas;
	float precioBitcoinAerolineas;
	float valorBitcoin;
	float precioUnitarioAerolineas;
	float precioDescuentoLatam;
	float precioAumentoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	int contador;

	contador =0;
	descuento = 10;
	aumento = 25;
	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;
	valorBitcoin = 4606954.55;

	do{
		printf("\n1.Ingresar Cantidad de kilometros"
		"\n2.Ingresar Precio de Vuelos"
		"\n3.Calcular Costos"
		"\n4.Informar resultados"
		"\n5.Carga forzada de datos (Datos precargados)"
		"\n6.Salir"
		"\nEscriba el numero de la opcion que desea realizar: ");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				printf("\nIngrese la cantidad de KiloMetros de viaje: ");
				scanf("%d",&kilometros);
				break;

			case 2:
				printf("\nIngrese el precio X vuelo de Aerolineas: ");
			scanf("%d",&precioAerolineas);

			printf("Ingrese el precio X vuelo de Latam: ");
				scanf("%d",&precioLatam);
			break;

		case 3:
			case 5:
				if(precioAerolineas > 0)
				{
					precioDescuentoAerolineas = decremento(precioAerolineas, descuento);
					precioAumentoAerolineas = incremento(precioAerolineas, aumento);
					precioBitcoinAerolineas = division(precioAerolineas, valorBitcoin);
					precioUnitarioAerolineas = division(precioAerolineas, kilometros);
				}
				if(precioLatam > 0)
				{
					precioDescuentoLatam = decremento(precioLatam, descuento);
					precioAumentoLatam = incremento(precioLatam, aumento);
					precioBitcoinLatam = division(precioLatam, valorBitcoin);
					precioUnitarioLatam = division(precioLatam, kilometros);
				}

				break;

			case 4:
				if(kilometros == 0)
				{
					printf("KMs Ingresados: No se puede calcular"
							"\n\nPrecioAerolineas: No se puede calcular"
							"a) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular"
							"\n\nPrecio Latam: No se puede calcular"
							"a) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular"
							"\n\nLa diferencia de precio es:  No se puede calcular");
				}
				else
				{
					printf("KMs ingresados: %d",kilometros);
					if(precioAerolineas > 0)
					{
						printf("\n\nPrecio Aerolineas: %d"
								"\na) Precio con tarjeta de debito: %.2f"
								"\nb) Precio con tarjeta de credito: %.2f"
								"\nc) Precio pagando con bitcoin: %.2f"
								"\nd) Mostrar precio unitario: %.2f",precioAerolineas, precioDescuentoAerolineas,precioAumentoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas);
						contador++;
					}
					else
					{
						printf("\n\nPrecio Aerolineas: No se puede calcular"
							"\na) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular");
					}
					if(precioLatam >0)
					{
						printf("\n\nPrecio Latam: %d"
								"\na) Precio con tarjeta de debito: %.2f"
								"\nb) Precio con tarjeta de credito: %.2f"
								"\nc) Precio pagando con bitcoin: %.2f"
								"\nd) Mostrar precio unitario: %.2f", precioLatam, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);
						contador++;
					}
					else
					{
						printf("\n\nPrecio Latam: No se puede calcular"
								"\na) Precio con tarjeta de debito: No se puede calcular"
								"\nb) Precio con tarjeta de credito: No se puede calcular"
								"\nc) Precio pagando con bitcoin: No se puede calcular"
								"\nd) Mostrar precio unitario: No se puede calcular");
					}
					if(contador == 2)
					{
						diferenciaPrecios = precioAerolineas - precioLatam;
						if(diferenciaPrecios < 0)
						{
							diferenciaPrecios *=(-1);
						}
						printf("\n\nLa diferencia de precio es: %.2f", diferenciaPrecios);
					}
					else
					{
						printf("\n\nLa diferencia de precio es: No se puede calcular");
					}
				}

				break;

			default:
				break;

		}

	}while(opcion<5); */

	return EXIT_SUCCESS;
}

/*
 *				printf("\n\nPrecioLatams: %d"
						"a) Precio con tarjeta de debito: %f"
						"\nb) Precio con tarjeta de credito: %f"
						"\nc) Precio pagando con bitcoin: %f"
						"\nd) Mostrar precio unitario: %f"
						"\n\nPrecio Latam: %d"
						"a) Precio con tarjeta de debito: %f"
						"\nb) Precio con tarjeta de credito: %f"
						"\nc) Precio pagando con bitcoin: %f"
						"\nd) Mostrar precio unitario: %f"
						"\n\nLa diferencia de precio es:  ")
 *
 */

