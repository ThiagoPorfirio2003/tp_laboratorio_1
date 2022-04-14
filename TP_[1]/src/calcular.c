/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
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

float restaFloat(float valorUno, float valorDos)
{
	float resultado;
	resultado = valorUno - valorDos;
	return resultado;
}

float divisionFloat(float dividendo,float divisor)
{
	float resultado;
	resultado = dividendo / divisor;
	return resultado;
}

