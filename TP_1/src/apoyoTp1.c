/*
 * apoyoTp1.c
 *
 *  Created on: 8 abr. 2022
 *      Author: thiag
 */

#include "calcular.h"
#include <stdio.h>

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

void opcionCuatroAerolineasVacio(void)
{
	printf("\n\nPrecioAerolineas: No hay un precio ingresado"
			"\na) Precio con tarjeta de debito: No se puede calcular"
			"\nb) Precio con tarjeta de credito: No se puede calcular"
			"\nc) Precio pagando con bitcoin: No se puede calcular"
			"\nd) Mostrar precio unitario: No se puede calcular");
}

void opcionCuatroLatam(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\n\nPrecio Latam: %.2f"
			"\na) Precio con tarjeta de debito: %.2f"
			"\nb) Precio con tarjeta de credito: %.2f"
			"\nc) Precio pagando con bitcoin: %.2f"
			"\nd) Mostrar precio unitario: %.2f", precio, mDescuento, mIntereses, mBitcoin, mKilometros);
}

void opcionCuatroLatamVacio(void)
{
	printf("\n\nPrecioLatam: No hay un precio ingresado"
			"\na) Precio con tarjeta de debito: No se puede calcular"
			"\nb) Precio con tarjeta de credito: No se puede calcular"
			"\nc) Precio pagando con bitcoin: No se puede calcular"
			"\nd) Mostrar precio unitario: No se puede calcular");
}

//void opcionCincoArelineas(float precioFijo, float* uDescuentoFijo, float vDescuentoFijo, float* uInteresFijo, float vInteresFijo, float* uBitcoinFijo, float vBitcoinFijo, float* uKilometrosFijo, float vKilometrosFijo)
//{
//	opcionTres(precioFijo, &uDescuentoFijo, vDescuentoFijo, &uInteresFijo, vInteresFijo, &uBitcoinFijo, vBitcoinFijo, &uKilometrosFijo, vKilometrosFijo);
//	printf("\nKMs Ingresados: %.2f", vKilometrosFijo);
//	opcionCuatroAerolineas(precioFijo, vDescuentoFijo, vInteresFijo, vBitcoinFijo, uKilometrosFijo);
//}
//
//void opcionCincoLatam(float precioFijo, float* uDescuentoFijo, float vDescuentoFijo, float* uInteresFijo, float vInteresFijo, float* uBitcoinFijo, float vBitcoinFijo, float* uKilometrosFijo, float vKilometrosFijo)
//{
//	opcionTres(precioFijo, &uDescuentoFijo, vDescuentoFijo, &uInteresFijo, vInteresFijo, &uBitcoinFijo, vBitcoinFijo, &uKilometrosFijo, vKilometrosFijo);
//	opcionCuatroAerolineas(precioFijo, vDescuentoFijo, vInteresFijo, vBitcoinFijo, uKilometrosFijo);
//}
//
//					"\n\nPrecioAerolineas: No se puede calcular"
//					"a) Precio con tarjeta de debito: No se puede calcular"
//					"\nb) Precio con tarjeta de credito: No se puede calcular"
//					"\nc) Precio pagando con bitcoin: No se puede calcular"
//					"\nd) Mostrar precio unitario: No se puede calcular"
//					"\n\nPrecio Latam: No se puede calcular"
//  				"a) Precio con tarjeta de debito: No se puede calcular"
//					"\nb) Precio con tarjeta de credito: No se puede calcular"
//	    			"\nc) Precio pagando con bitcoin: No se puede calcular"
//			     	"\nd) Mostrar precio unitario: No se puede calcular"
//					"\n\nLa diferencia de precio es:  No se puede calcular";
