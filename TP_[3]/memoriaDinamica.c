#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int memoria_NewInt(int** punteroAPunteroFloatEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroFloatEstatico!=((void*)0))
	{
		*punteroAPunteroFloatEstatico=((void*)0);
		*punteroAPunteroFloatEstatico= (int*) malloc(sizeof(int));
		if(*punteroAPunteroFloatEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewFloat(float** punteroAPunteroFloatEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroFloatEstatico!=((void*)0))
	{
		*punteroAPunteroFloatEstatico=((void*)0);
		*punteroAPunteroFloatEstatico= (float*) malloc(sizeof(float));
		if(*punteroAPunteroFloatEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewChar(char** punteroAPunteroCharEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=((void*)0))
	{
		*punteroAPunteroCharEstatico=((void*)0);
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char));
		if(*punteroAPunteroCharEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewIntConTamanio(int** punteroAPunteroIntEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroIntEstatico!=((void*)0) && longitud>0)
	{
		*punteroAPunteroIntEstatico=((void*)0);
		*punteroAPunteroIntEstatico= (int*) malloc(sizeof(int) * longitud);
		if(*punteroAPunteroIntEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewFloatConTamanio(float** punteroAPunteroFloatEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroFloatEstatico!=((void*)0) && longitud>0)
	{
		*punteroAPunteroFloatEstatico=((void*)0);
		*punteroAPunteroFloatEstatico= (float*) malloc(sizeof(float) * longitud);
		if(*punteroAPunteroFloatEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewCharConTamanio(char** punteroAPunteroCharEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=((void*)0) && longitud>0)
	{
		*punteroAPunteroCharEstatico=((void*)0);
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char) * longitud);
		if(*punteroAPunteroCharEstatico!=((void*)0))
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeInt(int** punteroAPunteroIntDinamico ,int nuevaLongitud)
{
	int retorno;
	int* punteroAIntAuxiliar;

	retorno=1;

	if(punteroAPunteroIntDinamico!=((void*)0) && nuevaLongitud>0 && !memoria_NewInt(&punteroAIntAuxiliar))
	{
		punteroAIntAuxiliar = (int*)realloc(*punteroAPunteroIntDinamico,sizeof(int)* nuevaLongitud);

		if(punteroAIntAuxiliar!=((void*)0))
		{
			*punteroAPunteroIntDinamico = punteroAIntAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeFloat(float** punteroAPunteroFloatDinamico ,int nuevaLongitud)
{
	int retorno;
	float* punteroAFloatAuxiliar;

	retorno=1;

	if(punteroAPunteroFloatDinamico!=((void*)0) && nuevaLongitud>0 && !memoria_NewFloat(&punteroAFloatAuxiliar))
	{
		punteroAFloatAuxiliar = (float*)realloc(*punteroAPunteroFloatDinamico,sizeof(float)* nuevaLongitud);

		if(punteroAFloatAuxiliar!=((void*)0))
		{
			*punteroAPunteroFloatDinamico = punteroAFloatAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int memoria_ReSizeChar(char** punteroAPunteroCharDinamico ,int nuevaLongitud)
{
	int retorno;
	char* punteroAFloatAuxiliar;

	retorno=1;

	if(punteroAPunteroCharDinamico!=((void*)0) && nuevaLongitud>0 && !memoria_NewChar(&punteroAFloatAuxiliar))
	{
		punteroAFloatAuxiliar = (char*)realloc(*punteroAPunteroCharDinamico,sizeof(char)* nuevaLongitud);

		if(punteroAFloatAuxiliar!=((void*)0))
		{
			*punteroAPunteroCharDinamico = punteroAFloatAuxiliar;
			retorno=0;
		}
	}
	return retorno;
}
