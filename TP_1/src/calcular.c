/*
 * calcular.c
 *
 *  Created on: 7 abr. 2022
 *      Author: thiag
 */
float decremento(int valorBase,float descenso)
{
	float resultado;
	resultado= valorBase - (valorBase * descenso /100);
	return resultado;
}

float incremento(int valorBase, float ascenso)
{
	float resultado;
	resultado= valorBase + (valorBase * ascenso /100);
	return resultado;
}

float restaD(float valorUno, float valorDos)
{
	float resultado;
	resultado = valorUno - valorDos;
	return resultado;
}

float divisionD(float dividendo,float divisor)
{
	float resultado;
	resultado = dividendo / divisor;
	return resultado;
}

