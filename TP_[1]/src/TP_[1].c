/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
 */
#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"
#include "validar.h"
#include "entrada.h"
#include "apoyoTP_[1].h"

int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int kilometros;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int contador;
	int limite;
	int i;
	float precioAerolineas;
	float precioLatam;
	float precioVuelo;
	float descuento;
	float aumento;
	float valorBitcoin;
	float precioDescuentoAerolineas;
	float precioAumentoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioDescuentoLatam;
	float precioAumentoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;

	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;

	descuento = 10;
	aumento = 25;
	valorBitcoin = 4606954.55;
	limite = 1;

	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;
	contador = 0;

	do{
		if(contador > 0)
		{
			printf("\n");
		}
			printf("1. Ingresar Cantidad de kilometros: (km = " );
		if(banderaOpcionUno == 0)
		{
			printf("x)");
		}
		else
		{
			printf("%d)", kilometros );
		}

			printf("\n\n2. Ingresar Precio de Vuelos: (Aerolineas=");

		if(banderaOpcionDos == 1)
		{
			printf(" $%.2f, Latam= $%.2f)", precioAerolineas, precioLatam);
		}
		else
		{
			printf("y, Latam= z)");
		}

		printf("\n   - Precio vuelo Aerolineas: ");
		printf(	"\n   - Precio vuelo Latam: ");
		printf("\n\n3. Calcular Costos: ");
		printf("\n   a) Tarjeta de debito (Descuento 10%%)");
		printf("\n   b) Tarjeta de credito (interes 25%%)");
		printf("\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		printf("\n   d) Mostrar precio por km (precio unitario)");
		printf("\n   e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)");
		printf("\n\n4. Informar resultados");
		printf("\n Latam:");
		printf("\n a) Precio con tarjeta de débito: r");
		printf("\n b) Precio con tarjeta de crédito: r");
		printf("\n c) Precio pagando con bitcoin : r");
		printf("\n d) Precio unitario: r");
		printf("\n Areolineas:");
		printf("\n a) Precio con tarjeta de débito: r");
		printf("\n b) Precio con tarjeta de crédito: r");
		printf("\n c) Precio pagando con bitcoin : r");
		printf("\n d) Precio unitario: r");
		printf("\n La diferencia de precio es: r");
		printf("\n\n5. Carga forzada de datos");
		printf("\n6.Salir");
		printf("\n\n¿Que opcion desea realizar? ");

		opcionMenu = eInt();
		opcionMenu = vIntRango(opcionMenu, 1, 6);

		switch(opcionMenu)
		{
			case 1:
				printf("\nKilometros");
				kilometros = eInt();
				kilometros = vIntMaIgual(kilometros, limite);
				banderaOpcionUno = 1;
				contador++;
				break;

			case 2:
				for(i=0;i<2;i++)
				{
					printf("\nPrecio vuelo ");
					if(i==0)
					{
						printf("Aerolineas");
					}
					else
					{
						printf("Latam");
					}

					precioVuelo = eFloat();
					precioVuelo = vFloatMaIgual(precioVuelo, limite);

					if(i==0)
					{
						precioAerolineas = precioVuelo;

					}
					else
					{
						precioLatam = precioVuelo;
					}
				}

				contador++;
				banderaOpcionDos = 1;
				break;

			case 3:
				if(banderaOpcionUno == 1 && banderaOpcionDos ==1)
				{
					if(precioAerolineas > 0)
					{
						opcionTres(precioAerolineas, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometros);
					}
					if(precioLatam > 0)
					{
						opcionTres(precioLatam, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometros);
					}

					diferenciaPrecio = precioAerolineas - precioLatam;
					if(diferenciaPrecio <0)
					{
						diferenciaPrecio*=-1;
					}
					banderaOpcionTres = 1;

					printf("\nLos costos han sido calculados.\n");
				}
				else
				{
					printf("\nPara usar la opcion 3 requiere de haber elegido la opcion 1 y/o 2 previamente, elija una de esas: \n\n");
				}

				break;

			case 4:
				if(banderaOpcionTres ==1)
				{
					printf("\nKMs Ingresados: %d", kilometros);

					printf("\n\nPrecio Aerolineas: $%.2f", precioAerolineas);
					opcionCuatro(precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);

					printf("\n\nPrecio Latam: $%.2f", precioLatam);
					opcionCuatro(precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);

					printf("\n\nLa diferencia de precio es: %.2f \n\n", diferenciaPrecio);

					banderaOpcionUno = 0;
					banderaOpcionDos = 0;
					banderaOpcionTres = 0;
					contador = 0;

					kilometros = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;
				}
				else
				{
					printf("\nPara usar la opcion 4 requiere de haber elegido la opcion 3 previamente, elija otra opcion: \n\n");
				}

				break;

			case 5:
				if(contador == 0)
				{
					printf("\nCarga Forzada:\n");
					printf("\nKMs ingresados: %d km", kilometros);

					printf("\n\nPrecio Aerolineas: $%.2f", precioAerolineas);

					// variable : auxiliar = direccion1
					// auxiliar = direccion2

					opcionTres(precioAerolineas, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometros);
					opcionCuatro(precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);

					printf("\n\nPrecio Latam: $%.2f", precioLatam);
					opcionTres(precioLatam, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometros);
					opcionCuatro(precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);

					diferenciaPrecio = restaFloat(precioAerolineas, precioLatam);
					printf("\n\nLa diferencia de precio es: %.2f \n\n", diferenciaPrecio);
				}

				else
				{
					printf("\nComo ya hay datos cargados no se puede seleccionar la opcion 5, elija otra opcion: \n");
				}
				break;

			default:
				break;
		}

	}while(opcionMenu<6);



	return EXIT_SUCCESS;
}
