/*
 * informes.c
 *
 *  Created on: 14 oct. 2020
 *      Author: marco
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "aviso.h"


/** \brief Desarrolla la suma de los avisos por clientes y devuelve por referencia el valor
*
* \param valor Aviso *pArrayAviso es el puntero al array de Aviso
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor id recibe el id del cliente
* \param valor *pContador devuelve la suma de los avisos por cliente
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int informes_contadorClienteAvisos(Aviso *pArrayAviso,int limiteAviso,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAviso>0)
	{
		for(int i=0;i<limiteAviso;i++)
		{
			if(pArrayAviso[i].idcliente==id)
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}


/** \brief Informa el cliente con mas avisos
*
* \param valor Cliente *pArrayCliente es el puntero al array de Cliente
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor Aviso *pArrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int informes_clienteConMasAvisos(Cliente *pArrayCliente,int limitCliente,Aviso *pArrayAviso,int limiteAviso)
{
	int retorno=-1;
	int contadorPublicaciones;
	int contadorMaximo;
	int indice;
	Cliente bufferMax;

	if(pArrayCliente!=NULL && limitCliente>0 && pArrayAviso!=NULL && limiteAviso>0)
	{
		for(int i=0;i<limitCliente;i++)
		{
			informes_contadorClienteAvisos(pArrayAviso,limiteAviso,pArrayCliente[i].idCliente, &contadorPublicaciones);
			if(i==0 || contadorPublicaciones>contadorMaximo)
			{
				contadorMaximo=contadorPublicaciones;
				bufferMax = pArrayCliente[i];
			}
		}
		if(cliente_buscarIndicePorIdRef(pArrayCliente,limitCliente,bufferMax.idCliente,&indice)==0)
		{
			printf("\n El cliente con mas avisos es: %s %s Cuit: %s",pArrayCliente[indice].nombre,pArrayCliente[indice].apellido,pArrayCliente[indice].cuit);
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Informa cuantos avisos estan pausados y devuelve el resultado por referencia
*
** \param valor Aviso *pArrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor contadorAvisosPausados devuelve la cantidad de avisos pausados
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/


int aviso_contarAvisosPausadosRef(Aviso *pArrayAviso,int limiteAviso,int *contadorAvisosPausados)
{
	int retorno=-1;
	int contador=0;
	for(int i = 0; i<limiteAviso; i++)
	{
		if (pArrayAviso[i].estadoPublicacion == FALSE &&
				pArrayAviso[i].isEmpty==FALSE)
		{
			contador++;
			retorno=0;
		}
	}
	*contadorAvisosPausados=contador;
	return retorno;
}


/** \brief Informa la cantidad de avisos por rubro y devuelve el resultado por referencia
*
** \param valor Aviso *pArrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor rubro recibe el rubro
* \param valor pcontador devuelve la cantidad de avisos por rubro
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/


int informes_contadorRubroAvisos(Aviso *pArrayAviso,int limiteAvisos,int rubro,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
		{
			if(pArrayAviso[i].numeroRubro==rubro)
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}

/** \brief Informa la cantidad de avisos por rubro
*
** \param valor Aviso *pArrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int aviso_contarRubrosConMasAvisos(Aviso *pArrayAviso,int limiteAviso)
{
	int retorno=-1;
	int contadorPublicaciones;
	int contadorMaximo;
	int i=0;
	Aviso bufferAux;
	if(pArrayAviso!=NULL && limiteAviso>0)
	{
		for(i=0;i<limiteAviso;i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE &&
			  informes_contadorRubroAvisos(pArrayAviso,limiteAviso,pArrayAviso[i].numeroRubro,&contadorPublicaciones)==0)
			{
				if(i==0 || contadorPublicaciones>contadorMaximo)
				{
					contadorMaximo = contadorPublicaciones;
					bufferAux = pArrayAviso[i];
					retorno=0;
				}
			}
		}
		printf("\nEl rubro con mas avisos es el: %d \n",bufferAux.numeroRubro);
	}
return retorno;

}

/** \brief Menu para realizar los informes
*
** \param valor Aviso *pArrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
** \param valor Aviso *pArrayCliente es el puntero al array de Cliente
* \param valor limitCliente es el tamaño del array de Cliente
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/

int menu_Consultas(Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente , int limitCliente)
{
	int retorno=-1;
	int opcionMenu;
	int contadorAvisosPausados=0;
	if (pArrayAviso != NULL && limiteAviso >0 && pArrayCliente!=NULL && limitCliente>0)
	{
		do
		{
			if(utn_getEntero("\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n/////INGRESE: 1) Cliente con más avisos.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n//////////////2) Cantidad de avisos pausados.////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n//////////////3) Rubro con mas avisos///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n//////////////4) Salir////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
							 "\n\n////////////////////////////////////////////////////////ERROR!!! NUMERO MAL INGRESADO!!!!////////////////////////////////////////////////////////////////////////",
							 &opcionMenu,3,4,1)==0)
			{
				switch(opcionMenu)
				{
					case  1:
						if(informes_clienteConMasAvisos(pArrayCliente, limitCliente, pArrayAviso, limiteAviso)==0)
						{
							retorno=0;
						}
						else
						{
							printf("No hay clientes con avisos");
						}
						break;
					case 2:
						if(aviso_contarAvisosPausadosRef(pArrayAviso,limiteAviso,&contadorAvisosPausados)==0)
						{
							printf("La cantidad de avisos pausados es: %d",contadorAvisosPausados);
							retorno=0;
						}
						else
						{
							printf("No hay avisos publicados");
						}
						break;
					case 3:
						if(aviso_contarRubrosConMasAvisos(pArrayAviso,limiteAviso)==0)
						{
							retorno=0;
						}
						else
						{
							printf("\n No hay rubros cargados");
						}
						break;

				}
				retorno= 0;
			}
		}while(opcionMenu !=4);
	}
	return retorno;


}



