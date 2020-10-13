/*
 * utn.c
 *
 *  Created on: 10 oct. 2020
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include<string.h>


static int myGets(char *cadena, int longitud);



/**
 * \brief Solicita un numero entero al usuario
 * \param Valor  mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor  mensajeError, se guarda el mesaje de error que va a ser leido por el usuario
 * \param Valor  pResultado, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param Valor  reintentos, cantidad de oportunidades para ingresar el dato.
 * \param Valor	 maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \param Valor  minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */

int utn_getEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int resultadoScanf;
	int retorno=-1;
	int bufferInt;
	if(mensaje != NULL && mensajeError != NULL && pResultado!= NULL && reintentos >= 0 && maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}

/**
 * \brief 	Verifica una cadena recibida como parametro para determinar si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1;

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z'))
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}

/**
 * \brief Solicita un nombre al usuario
 * \param Valor  mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor  mensajeError, se guarda el mesaje de error que va a ser leido por el usuario
 * \param Valor  pResultado, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param Valor  reintentos, cantidad de oportunidades para ingresar el dato.
 * \param Valor  limite, indica la cantidad de letras maxima del nombre
 * \return Devuelve si hubo error o no
 *
 */

int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 ) //verdadero
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esUnCuilValido(char* cadena,int limite)
{
	int respuesta = 1;

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		if(	(cadena[i] !=48 || cadena[i] !=49 ) &&
			(cadena[i] < '-'))
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/**
 * \brief Solicita el cuit al usuario
 * \param Valor *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor *mensajeError, se guarda el mesaje de error que va a ser leido por el usuario
 * \param Valor *pResultado, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param Valor reintentos, cantidad de oportunidades para ingresar el dato.
 * \param Valor limite, indica la cantidad de letras maxima del nombre
 * \return Devuelve si hubo error o no
 *
 */
int utn_getCuit(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnCuilValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



