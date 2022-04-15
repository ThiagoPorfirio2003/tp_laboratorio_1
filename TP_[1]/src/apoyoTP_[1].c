/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
 */

#include "calcular.h"
#include <stdio.h>

//u: Ubicacion
//m: Mostrar
void opcionTres(float precioEmpresa, float* uDescuento, float Descuento, float* uInteres, float Interes, float* uBitcoin, float Bitcoin, float* uKilometros, float Kilometros)
{
	*uDescuento = decremento(precioEmpresa, Descuento);
	*uInteres = incremento(precioEmpresa, Interes);
	*uBitcoin = divisionFloat(precioEmpresa, Bitcoin);
	*uKilometros= divisionFloat(precioEmpresa, Kilometros);
}


void opcionCuatro(float mDescuento, float mIntereses, float mBitcoin, float mKilometros)
{
	printf("\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con bitcoin: %f"
			"\nd) Mostrar precio unitario: $%.2f", mDescuento, mIntereses, mBitcoin, mKilometros);
}

