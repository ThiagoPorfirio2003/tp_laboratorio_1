/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
 */

#include "calcular.h"
#include <stdio.h>

void opcionTres(float precioEmpresa, float* uDescuento, float vDescuento, float* uInteres, float vInteres, float* uBitcoin, float vBitcoin, float* uKilometros, float vKilometros)
{
	*uDescuento = decremento(precioEmpresa, vDescuento);
	*uInteres = incremento(precioEmpresa, vInteres);
	*uBitcoin = divisionFloat(precioEmpresa, vBitcoin);
	*uKilometros= divisionFloat(precioEmpresa, vKilometros);
}

void opcionCuatroAerolineas(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\n\nPrecio Aerolineas: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con bitcoin: %.4f"
			"\nd) Mostrar precio unitario: $%.2f", precio, mDescuento, mIntereses, mBitcoin, mKilometros);
}

void opcionCuatroLatam(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\n\nPrecio Latam: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con bitcoin: $%.4f"
			"\nd) Mostrar precio unitario: $%.2f", precio, mDescuento, mIntereses, mBitcoin, mKilometros);
}

