/*
 * cliente.c
 *
 *  Created on: 10 oct. 2020
 *      Author: marco
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include"cliente.h"

static int cliente_generarNuevoId (void);

int cliente_init(Cliente * pArrays, int limite)
{
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int cliente_alta(Cliente *arrayClientes,int limite)
{
	int retorno=-1;
	int indice;
	Cliente bufferClientes;
	if(arrayClientes!=NULL && limite>0 )
	{
		if(cliente_buscarLibreRef(arrayClientes,limite,&indice)==0)
		{
			if(utn_getNombre("\nINGRESE NOMBRE: ", "\ERROR!!!!! REINGRESE EL NOMBRE: ",bufferClientes.nombre,3,LONG_NOMBRE)==0 &&
				utn_getNombre("\nINGRESE APELLIDO: ","\n ERROR!!!!!! REINGRESE EL APELLIDO: ",bufferClientes.apellido,3, LONG_NOMBRE)==0 &&
				utn_getCuit("\nINGRESE CUIT: ", "\ERROR!!!!! REINGRESE CUIT: ", bufferClientes.cuit,3,LONG_NOMBRE)==0)
			{
				//bufferAlumno.isEmpty=FALSE;
				arrayClientes[indice]=bufferClientes;
				arrayClientes[indice].isEmpty=FALSE;
				arrayClientes[indice].idCliente=cliente_generarNuevoId();
				printf("\n/////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////\n"
						"\///////////////////////////////////////////nNombre: %s -Apellido: %s - Cuit %s -ID Cliente: %d //////////////////////////////////////////////////////////\n"
						,arrayClientes[indice].nombre ,arrayClientes[indice].apellido , arrayClientes[indice].cuit, arrayClientes[indice].idCliente);
				retorno = 0;
			}
			else
			{
				printf("Error!!!!");
			}
		}
		else
		{
			printf("\n No quedan espacios libres");
		}
	}
	return retorno;
}

int cliente_modificar (Cliente * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Cliente bufferCliente;

	if (pArrays != NULL && limite>0)
	{
		cliente_imprimir(pArrays, limite);

		if(utn_getEntero("ID:","ERROR!",&idBuscar,3,9999,0)==0)
		{
			if(cliente_buscarIndicePorIdRef(pArrays,limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferCliente = pArrays[indiceAModificar];

				if (utn_getNombre("\nINGRESE NUEVO NOMBRE","ERROR!!!REINGRESE NOMBRE",bufferCliente.nombre,3,LONG_NOMBRE) == 0 &&
					utn_getNombre("\nINGRESE NUEVO APELLIDO","ERROR!!!REINGRESE APELLIDO",bufferCliente.apellido,3,LONG_NOMBRE) == 0 &&
					utn_getCuit("INGRESE NUEVO CUIT","ERROR!!! REINGRESE CUIT", bufferCliente.cuit, 3, LONG_NOMBRE) == 0)
					{
						pArrays[indiceAModificar] = bufferCliente; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
}

int cliente_imprimir (Cliente * pArrays , int limite)
{
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Apellido: %s - Cuit %s - ID %d",pArrays[i].nombre,pArrays[i].apellido, pArrays[i].cuit , pArrays[i].idCliente);
			}
		}
		retorno = 0;
	}
return retorno;
}


int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].idCliente == idBuscar)
					{
					*pIndice= i;
					retorno = 0;
					break;
					}
				}
		}
		else
		{
			printf("errrror!!!!!!!!!!!!");
		}
	return retorno;
}
int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar)
{
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].idCliente == idBuscar)
					{
					retorno = i;
					break;
					}
				}
		}
		else
		{
			printf("ERROR!!!!!! ID NO ENCONTRADO");
		}
	return retorno;
}


int cliente_buscarLibreRef(Cliente pArrayCliente[],int limit, int *pindex)
{
	int retorno=-1;
	int i;
	if(pArrayCliente !=NULL && limit>0 && pindex!=NULL)
	{
		for(i = 0;i<limit;i++)
		{
			if(pArrayCliente[i].isEmpty==TRUE)
			{
				*pindex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

static int cliente_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}
