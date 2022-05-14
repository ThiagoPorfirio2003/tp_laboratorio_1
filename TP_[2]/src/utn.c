/*
 * utn.c
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char* direccionCadena, int tamanio)
{
	int retorno;
	char bufferString[256];

	retorno = -1;

	if(direccionCadena != NULL && tamanio > 0)
	{
		retorno =1;
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= tamanio)
			{
				strncpy(direccionCadena, bufferString, tamanio);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int verificarSerInt(char* cadena)
{
	int retorno;
	int i;
	retorno = -1;
	i=0;

	if(cadena != NULL && cadena[0] != '0')
	{
		retorno=1;
		while(cadena[i]!= '\0')
		{
			if((isdigit(cadena[i]) == 0 && cadena[i] != '-' )|| (i != 0 && cadena[i] == '-'))
			{
				break;
			}
			i++;
		}
		if(cadena[i] == '\0')
		{
			retorno = 0;
		}
	}

	return retorno;
}

int getInt(int* direccionInt, int tamanio,char* mensaje)
{
	int retorno;
	char bufferInt[256];
	int estadoError;

	retorno =-1;

	if(tamanio > 0 && direccionInt !=NULL && mensaje !=NULL)
	{
		retorno =1;
		printf("%s", mensaje);
		estadoError = myGets(bufferInt, tamanio);
		if(verificarSerInt(bufferInt) == 0 && estadoError ==0)
		{
			*direccionInt = atoi(bufferInt);
			retorno=0;
		}
	}

	return retorno;
}

int verificarSerFloat(char* cadena)
{
	int retorno;
	int i;
	int contadorPuntos;

	retorno = -1;
	i=0;
	contadorPuntos=0;

	if(cadena != NULL && cadena[0] != '0')
	{
		retorno = 1;

		while(cadena[i] != '\0')
		{
			if((isdigit(cadena[i])==0 && cadena[i] != '.'  && cadena[i] != '-') || (i != 0 && cadena[i] == '-') || contadorPuntos > 1)
			{
				break;
			}
			if(cadena[i] == '.')
			{
				contadorPuntos++;
			}
			i++;
		}
		if(cadena[i]== '\0')
		{
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float* direccionFloat, int tamanio,char* mensaje)
{
	int retorno;
	char bufferFloat[256];
	int estadoError;

	retorno=-1;

	if(direccionFloat !=NULL && tamanio > 0 && mensaje !=NULL)
	{
		retorno =1;
		printf("%s", mensaje);
		estadoError = myGets(bufferFloat, tamanio);
		if(verificarSerFloat(bufferFloat) == 0 && estadoError ==0)
		{
			*direccionFloat = atof(bufferFloat);
			retorno =0;
		}
	}

	return retorno;
}

int verificarSerPalabra(char* direccionPalabra)
{
	int retorno;
	int i;

	i=0;
	retorno =-1;

	if(direccionPalabra != NULL)
	{
		retorno = 1;
		while(isalpha(direccionPalabra[i]) !=0 || direccionPalabra[i] == 'á' || direccionPalabra[i] == 'é' || direccionPalabra[i] == 'í' || direccionPalabra[i] == 'ó' || direccionPalabra[i] == 'ú' || direccionPalabra[i] == 'Á' || direccionPalabra[i] == 'É' || direccionPalabra[i] == 'Í' || direccionPalabra[i] == 'Ó' || direccionPalabra[i] == 'Ú' || direccionPalabra[i] == 'ñ' || direccionPalabra[i] == 'Ñ')
		{
			i++;
		}
		if(direccionPalabra[i] == '\0')
		{
			retorno = 0;
		}
	}
	return retorno;
}

int getPalabra(char* direccionPalabra, int tamanio, char* mensaje)
{
	int retorno;
	char bufferPalabra[256];
	int estadoError;
	retorno=-1;

	if(direccionPalabra != NULL && tamanio > 0 && mensaje !=NULL)
	{
		retorno=1;
		printf("%s", mensaje);
		estadoError = myGets(bufferPalabra, tamanio);
		if(estadoError ==0 && verificarSerPalabra(bufferPalabra) ==0)
		{
			strcpy(direccionPalabra, bufferPalabra);
			retorno = 0;

		}
	}
	return retorno;
}

int transformarMinusculaAMayuscula(char* direccionCaracter)
{
	int retorno;
	char caracter;

	caracter = *direccionCaracter;
	retorno =-1;
	if(direccionCaracter !=NULL)
	{
		retorno =0;
		if(islower(caracter) !=0 || caracter == 'á' || caracter == 'é' || caracter == 'í' || caracter == 'ó' || caracter == 'ú' || caracter == 'ñ')
		{
			*direccionCaracter = toupper(caracter);
		}

	}
	return retorno;
}

int verificarSerCadenaCaracteres(char* direccionCadena)
{
	int retorno;
	int i;

	i=0;
	retorno =-1;

	if(direccionCadena !=NULL)
	{
		retorno =1;
		while(isspace(direccionCadena[i]) ==0)
		{
			i++;
			if(direccionCadena[i] == '\0')
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}

int getCadenaCaracteres(char* direccionCadena, int tamanio, char* mensaje)
{
	int retorno;
	char bufferPalabra[256];
	int estadoError;

	retorno=-1;

	if(direccionCadena != NULL && tamanio>0 && mensaje !=NULL)
	{
		retorno=1;
		printf("%s", mensaje);
		estadoError = myGets(bufferPalabra, tamanio);
		if(estadoError == 0 && verificarSerCadenaCaracteres(bufferPalabra) ==0)
		{
			strcpy(direccionCadena, bufferPalabra);
			retorno =0;
		}
	}
	return retorno;
}

int getIntRango(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, float minimo, float maximo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	int bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;


	if(direccionInt != NULL && mensaje != NULL && mensajeError !=NULL && minimo < maximo && minimo!=maximo && tamanio > 0 && intentos > 0)
	{
		retorno = 1;

		while(contadorIntentos!=0)
		{
			chequeoError = getInt(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0 && bufferNumero >= minimo  && bufferNumero <= maximo)
			{
				*direccionInt = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
			printf("%s", mensajeSinIntentos);
		}
	}
	return retorno;
}

int getFloatRango(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float minimo, float maximo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	float bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;


	if(direccionFloat != NULL && mensaje != NULL && mensajeError !=NULL && minimo < maximo && minimo!=maximo && tamanio > 0 && intentos > 0)
	{
		retorno = 1;

		while(contadorIntentos!=0)
		{
			chequeoError = getFloat(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0 && bufferNumero >= minimo  && bufferNumero <= maximo)
			{
				*direccionFloat = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
				printf("%s", mensajeSinIntentos);
		}
	}
		return retorno;
}

int getIntMayorA(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int minimo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	int bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;

	if(direccionInt != NULL && mensaje != NULL && mensajeError !=NULL && tamanio > 0 && intentos > 0)
	{
		retorno = 1;
		while(contadorIntentos!=0)
		{
			chequeoError = getInt(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0 && bufferNumero >= minimo)
			{
				*direccionInt = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
			printf("%s", mensajeSinIntentos);
		}
	}
		return retorno;
}

int getFloatMayorA(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float minimo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	float bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;


	if(direccionFloat != NULL && mensaje != NULL && mensajeError !=NULL && tamanio > 0 && intentos > 0)
	{
		retorno = 1;

		while(contadorIntentos!=0)
		{
			chequeoError = getFloat(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0 && bufferNumero >= minimo)
			{
				*direccionFloat = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
				printf("%s", mensajeSinIntentos);
		}
	}
		return retorno;
}

int getIntMenorA(int* direccionInt, int tamanio, char* mensaje, char* mensajeError, int maximo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	int bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;


	if(direccionInt != NULL && mensaje != NULL && mensajeError !=NULL && tamanio > 0 && intentos > 0)
	{
		retorno = 1;

		while(contadorIntentos!=0)
		{
			chequeoError = getInt(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0  && bufferNumero <= maximo)
			{
				*direccionInt = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
			printf("%s", mensajeSinIntentos);
		}
	}
	return retorno;
}

int getFloatMenorA(float* direccionFloat, int tamanio, char* mensaje, char* mensajeError, float maximo, int intentos, char* mensajeSinIntentos)
{
	int retorno;
	int chequeoError;
	float bufferNumero;
	int contadorIntentos;
	retorno = -1;
	contadorIntentos= intentos;


	if(direccionFloat != NULL && mensaje != NULL && mensajeError !=NULL && tamanio > 0 && intentos > 0)
	{
		retorno = 1;

		while(contadorIntentos!=0)
		{
			chequeoError = getFloat(&bufferNumero, tamanio, mensaje);
			if(chequeoError == 0 && bufferNumero <= maximo)
			{
				*direccionFloat = bufferNumero;
				retorno=0;
				break;
			}
			else
			{
				contadorIntentos--;
				printf("%s%d\n", mensajeError, contadorIntentos);
			}
		}
		if(contadorIntentos == 0)
		{
				printf("%s", mensajeSinIntentos);
		}
	}
		return retorno;
}
/*
int verificarSerNombre(char* direccionNombre)
{
	int retorno;
	int i;

	retorno =-1;
	i=0;

	if(direccionNombre !=NULL)
	{
		retorno=1;

		while(isalpha(direccionNombre[i]) !=0 && direccionNombre[i] != 'á' && direccionNombre[i] != 'é' && direccionNombre[i] != 'í' && direccionNombre[i] != 'ó' && direccionNombre[i] != 'ú' && direccionNombre[i] != 'Á' && direccionNombre[i] != 'É' && direccionNombre[i] != 'Í' && direccionNombre[i] != 'Ó' && direccionNombre[i] != 'Ú' && direccionNombre[i] != 'ñ' && direccionNombre[i] != 'Ñ')
		{
			i++;
		}
		if(direccionNombre[i] == '\0')
		{
			retorno =0;
		}
		if(direccionNombre[0] == 'ñ')
		{
			direccionNombre[0] = 'Ñ';
		}
		else
		{
			if(islower(direccionNombre[0]) == 0)
			{
				direccionNombre[0] = toupper(direccionNombre[0]);
			}
		}
	}
	return retorno;
}

int getNombre(char* direccionNombre, int tamanio, char* mensaje)
{
	int retorno;
	char bufferNombre[256];
	int estadoError;

	retorno=-1;

	if(direccionNombre != NULL && tamanio>0 && mensaje !=NULL)
	{
		retorno=1;
		printf("%s", mensaje);
		estadoError = myGets(bufferNombre, tamanio);
		if(estadoError == 0 && verificarSerNombre(bufferNombre) ==0)
		{
			strcpy(direccionNombre, bufferNombre);
			retorno =0;
		}
	}
	return retorno;
}
*/

/*
int verificarSerIntCero(char* cadena)
{
	int retorno;
	int i;
	retorno = -1;
	i=0;

	if(cadena != NULL)
	{
		retorno=1;
		while(cadena[i]!= '\0')
		{
			if((isdigit(cadena[i]) == 0 && cadena[i] != '-' )|| (i != 0 && cadena[i] == '-'))
			{
				break;
			}
			i++;
		}
		if(cadena[i] == '\0')
		{
			retorno = 0;
		}
	}
	return retorno;
}

int getIntCero(int* direccionInt, int tamanio,char* mensaje)
{
	int retorno;
	char bufferInt[256];
	int estadoError;

	retorno =-1;

	if(tamanio > 0 && direccionInt !=NULL && mensaje !=NULL)
	{
		retorno =1;
		printf("%s", mensaje);
		estadoError = myGets(bufferInt, tamanio);
		if(verificarSerIntCero(bufferInt) == 0 && estadoError ==0)
		{
			*direccionInt = atoi(bufferInt);
		}
	}
	return retorno;
}

*/


