/*
 * apoyoTP_[1].c
 *
 *  Created on: 12 abr. 2022
 *      Author: thiag
 */

#include "calcular.h"
#include <stdio.h>

void menu(int contador, int banderaOpcionUno, int banderaOpcionDos, int kilometros, float precioAerolineas, float precioLatam)
{
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
				printf("%.2f, Latam= %.2f)", precioAerolineas, precioLatam);
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
}


void opcionTres(float precioEmpresa, float* uDescuento, float vDescuento, float* uInteres, float vInteres, float* uBitcoin, float vBitcoin, float* uKilometros, float vKilometros)
{
	*uDescuento = decremento(precioEmpresa, vDescuento);
	*uInteres = incremento(precioEmpresa, vInteres);
	*uBitcoin = divisionD(precioEmpresa, vBitcoin);
	*uKilometros= divisionD(precioEmpresa, vKilometros);
}

void opcionCuatroAerolineas(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\n\nPrecio Aerolineas: %.2f"
			"\na) Precio con tarjeta de debito: %.2f"
			"\nb) Precio con tarjeta de credito: %.2f"
			"\nc) Precio pagando con bitcoin: %.2f"
			"\nd) Mostrar precio unitario: %.2f", precio, mDescuento, mIntereses, mBitcoin, mKilometros);
}

void opcionCuatroLatam(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\n\nPrecio Latam: %.2f"
			"\na) Precio con tarjeta de debito: %.2f"
			"\nb) Precio con tarjeta de credito: %.2f"
			"\nc) Precio pagando con bitcoin: %.2f"
			"\nd) Mostrar precio unitario: %.2f", precio, mDescuento, mIntereses, mBitcoin, mKilometros);
}

