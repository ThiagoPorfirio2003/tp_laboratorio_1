#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "memoriaDinamica.h"

int static myGets(char* direccionCadenaCaracteres, int longitud)
{
	int retorno;
	char* bufferString;

	retorno = 1;
	if(longitud>1 && direccionCadenaCaracteres != ((void*)0) && !memoria_NewCharConTamanio(&bufferString, longitud))
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(char)* longitud, stdin) != ((void*)0))
		{
			if(*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) == '\n')
			{
				*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) = '\0';
			}
			if(strnlen(bufferString, sizeof(char)* longitud) < longitud)
			{
				strncpy(direccionCadenaCaracteres, bufferString, longitud);
				retorno = 0;
			}
		}
		free(bufferString);
	}
	return retorno;
}

int utn_verificarSerInt(char* cadenaDeCaracteres)
{
	int retorno;
	retorno = 1;

	if(cadenaDeCaracteres != ((void*)0) && *cadenaDeCaracteres != '0')
	{
		retorno=0;

		if(*cadenaDeCaracteres == '-' ||
				*cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}

		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				retorno =1;
				break;
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');
	}
	return retorno;
}

int utn_verificarSerFloat(char* cadenaDeCaracteres)
{
	int retorno;
	int contadorPuntos;

	retorno = 1;
	contadorPuntos =0;

	if(cadenaDeCaracteres != ((void*)0) && *cadenaDeCaracteres!='\0')
	{
		retorno=0;
		if(*cadenaDeCaracteres == '-' || *cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}
		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				if(*cadenaDeCaracteres== '.')
				{
					if(contadorPuntos<1)
					{
						contadorPuntos++;
					}
					else
					{
						retorno=1;
						break;
					}
					if(*(cadenaDeCaracteres+1)=='\0')
					{
						retorno=1;
						break;
					}
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');

	}
	return retorno;
}

int utn_VerificarSerMinuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=((void*)0) && (islower(*caracter)||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerMayuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=((void*)0) && (isupper(*caracter)||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�'))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetra(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter!=((void*)0) && isalpha(*caracter))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetra_ASCII_EXTEND(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter != ((void*)0) && (*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�'))
	{
		retorno=0;
	}

	return retorno;
}

int utn_verificarSerNombre(char* cadenaDeCaracteres)
{
	int retorno;

	retorno=1;

	if(cadenaDeCaracteres != ((void*)0) && *cadenaDeCaracteres !=' ' && *cadenaDeCaracteres != '-')
	{
		retorno =0;

		do{
			if(utn_VerificarSerLetra(cadenaDeCaracteres))
			{
				if(isspace(*cadenaDeCaracteres) || *cadenaDeCaracteres == '-')
				{
					if(*(cadenaDeCaracteres+1)=='\0' && *(cadenaDeCaracteres+1) == '\0')
					{
						retorno=1;
						break;
					}
				}
				else
				{
					retorno=1;
					break;
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres != '\0');
	}
	return retorno;
}
/*
{
	int retorno;

	retorno=1;

	if(cadenaDeCaracteres != ((void*)0) && *cadenaDeCaracteres !=' ')
	{
		retorno =0;

		do{
			if(utn_VerificarSerLetra(cadenaDeCaracteres) && utn_VerificarSerLetra_ASCII_EXTEND(cadenaDeCaracteres))
			{
				retorno=1;
				break;
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres != '\0');
	}
	return retorno;
}*/

int utn_verificarSerCadenaAlfanumerica(char* cadenaCaracteres)
{
	int retorno;
	int banderaDigito;
	int banderaLetra;

	banderaDigito=0;
	banderaLetra=0;
	retorno=1;

	if(cadenaCaracteres != ((void*)0))
	{
		do
		{
			if(isdigit(*cadenaCaracteres))
			{
				banderaDigito=1;
			}
			else
			{
				if(isalpha(*cadenaCaracteres))
				{
					banderaLetra=1;
				}
				else
				{
					break;
				}
			}
			cadenaCaracteres++;
		}while(*cadenaCaracteres != '\0');

		if(*cadenaCaracteres == '\0' && banderaDigito && banderaLetra)
		{
			retorno=0;
		}
	}
	return retorno;
}

int static getInt(int* direccionInt, int cantidadDeCifras)
{
	int retorno;
	char* bufferInt;

	retorno=1;

	cantidadDeCifras+=2;
	if(direccionInt !=((void*)0) && cantidadDeCifras>2 && !memoria_NewCharConTamanio(&bufferInt,cantidadDeCifras))
	{
		if(!(myGets(bufferInt, cantidadDeCifras)) && !(utn_verificarSerInt(bufferInt)))
		{
			*direccionInt = atoi(bufferInt);
			retorno =0;
		}
		free(bufferInt);
	}
	return retorno;
}

int static getFloat(float* direccionFloat, int cantidadDeCifras)
{
	int retorno;
	char* bufferFloat;

	retorno=1;

	cantidadDeCifras+=2;
	if(direccionFloat !=((void*)0) && cantidadDeCifras>2 && !memoria_NewCharConTamanio(&bufferFloat,cantidadDeCifras))
	{
		if(!(myGets(bufferFloat, cantidadDeCifras)) && !(utn_verificarSerFloat(bufferFloat)))
		{
			*direccionFloat = atof(bufferFloat);
			retorno =0;
		}
		free(bufferFloat);
	}
	return retorno;
}

int static getNombre(char* direccionPalabra, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionPalabra!=((void*)0) && cantidadDeCaracteres>2 && !memoria_NewCharConTamanio(&bufferPalabra, cantidadDeCaracteres))
	{
		if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerNombre(bufferPalabra)))
		{
			retorno=0;
			strncpy(direccionPalabra, bufferPalabra, cantidadDeCaracteres);
		}
		free(bufferPalabra);
	}
	return retorno;
}

int static getCadenaAlfanumerica(char* direccionCadena, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionCadena!=((void*)0) && cantidadDeCaracteres>2 && !memoria_NewCharConTamanio(&bufferPalabra, cantidadDeCaracteres))
	{
		if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerCadenaAlfanumerica(bufferPalabra)))
		{
			retorno=0;
			strncpy(direccionCadena, bufferPalabra, cantidadDeCaracteres);
		}
		free(bufferPalabra);
	}
	return retorno;
}

int utn_trasnformarCadenaAMayuscula(char* direccionCadena)
{
	int retorno;

	retorno=1;

	if(direccionCadena!=((void*)0))
	{
		retorno= 0;
		do{
			if(!utn_VerificarSerLetra(direccionCadena))
			{
				*direccionCadena = toupper(*direccionCadena);
			}
			direccionCadena++;
		}while(*direccionCadena != '\0');
	}

	return retorno;
}

int utn_CorregirNombre(char* direccionPalabra)
{
	int retorno;
	int banderaEspacio;

	retorno=1;
	banderaEspacio=0;

	if(direccionPalabra !=((void*)0))
	{
		retorno =0;
		*direccionPalabra = toupper(*direccionPalabra);
		direccionPalabra++;

		while(*direccionPalabra !='\0')
		{
			if(isalpha(*direccionPalabra))
			{
				if(banderaEspacio)
				{
					*direccionPalabra = toupper(*direccionPalabra);
					banderaEspacio=0;
				}
				else
				{
					*direccionPalabra = tolower(*direccionPalabra);
				}
			}
			else
			{
				banderaEspacio=1;
			}
			direccionPalabra++;
		}
	}
	return retorno;
}

int utn_GetIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int cantidadDeCifras)
{
	int retorno;
	int bufferInt;

	retorno=1;

	if(direccionInt!=((void*)0) &&
			mensaje!=((void*)0) &&
			mensajeError!=((void*)0) &&
			minimo<=maximo
			&& cantidadDeCifras > 0)
	{
		printf("%s", mensaje);
		while(getInt(&bufferInt,cantidadDeCifras) || bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionInt = bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_GetFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int cantidadDeCifras)
{
	int retorno;
	float bufferFloat;

	retorno=1;

	if(direccionFloat!=((void*)0) &&
			mensaje!=((void*)0) &&
			mensajeError!=((void*)0) &&
			minimo<=maximo &&
			cantidadDeCifras>0)
	{
		printf("%s", mensaje);
		while(getFloat(&bufferFloat, cantidadDeCifras) || bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionFloat = bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_GetNombreRango(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;

	if(direccionPalabra != ((void*)0) &&
			mensaje != ((void*)0) &&
			mensajeError !=((void*)0) &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > 0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			!memoria_NewCharConTamanio(&bufferAuxiliar, cantidadDeCaracteres))
	{
		printf("%s", mensaje);
		while(getNombre(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionPalabra, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}
	return retorno;
}

int utn_GetCadenaAlfanumericaRango(char* direccionCadenaAlfanumerica, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;

	if(direccionCadenaAlfanumerica != ((void*)0) &&
			mensaje != ((void*)0) &&
			mensajeError !=((void*)0) &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > 0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			!memoria_NewCharConTamanio(&bufferAuxiliar, cantidadDeCaracteres))
	{
		printf("%s", mensaje);
		while(getCadenaAlfanumerica(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionCadenaAlfanumerica, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}
	return retorno;
}


/*
int utn_getLetraRango(char* direccionLetra, char* mensaje, char* mensajeError, char letraMinima, char letraMaxima)
{
	int retorno;
	char bufferLetra[1024];

	retorno=1;

	if(direccionLetra!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&

			letraMinima<=letraMaxima)
	{

		printf("%s", mensaje);
		while(utn_getNombre(bufferLetra) || *bufferLetra < letraMinima || *bufferLetra > letraMaxima || strnlen(bufferLetra, sizeof(bufferLetra)) != 1)
		{
			printf("%s", mensajeError);
		}
		*direccionLetra = *bufferLetra;
		retorno=0;
	}
	return retorno;
}



int utn_UnirNombreYApellido(char* nombre, char* apellido, char* depositoDeNombreYApellido)
{
	int retorno;
	int cantidadCaracteres;
	retorno=1;

	if(nombre!=NULL && apellido!=NULL && depositoDeNombreYApellido!=NULL)
	{
		cantidadCaracteres = strlen(nombre)+ strlen(apellido);
		cantidadCaracteres+=3;

		depositoDeNombreYApellido=memoria_PrepararPunteroChar(cantidadCaracteres);
		if(depositoDeNombreYApellido!=NULL)
		{
			sprintf(depositoDeNombreYApellido,"%s, %s", apellido,nombre);
		}
		if(*(depositoDeNombreYApellido+cantidadCaracteres)== '\0')
		{
			printf("\n\nHay BARRA0\n\n");
		}
		(depositoDeNombreYApellido+1+strnlen(depositoDeNombreYApellido, cantidadCaracteres))='\0';
		retorno=0;
	}

	return retorno;
}
*/

