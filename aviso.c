/*
 * aviso.c
 *
 *  Created on: 10 oct. 2020
 *      Author: marcos

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "aviso.h"
#include"cliente.h"

static int aviso_generarNuevoId (void);

int aviso_init(Aviso * pArrays, int limite)
{
	int retorno = -1;
	if (pArrays != NULL && limite >0)
	{
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int aviso_alta(Aviso *arrayAviso,int limite)
{
	int retorno=-1;
	int indice;
	Cliente bufferAviso;
	if(arrayAviso!=NULL && limite>0 )
	{
		if(cliente_buscarLibreRef(arrayAviso,limite,&indice)==0)
		{
			if(utn_getNombre("\nINGRESE NOMBRE: ", "\ERROR!!!!! REINGRESE EL NOMBRE: ",bufferAviso.nombre,3,LONG_NOMBRE)==0 &&
				utn_getNombre("\nINGRESE APELLIDO: ","\n ERROR!!!!!! REINGRESE EL APELLIDO: ",bufferAviso.apellido,3, LONG_NOMBRE)==0 &&
				utn_getCuit("\nINGRESE CUIT: ", "\ERROR!!!!! REINGRESE CUIT: ", bufferAviso.cuit,3,LONG_NOMBRE)==0)
			{
				//bufferAlumno.isEmpty=FALSE;
				arrayAviso[indice]=bufferAviso;
				arrayAviso[indice].isEmpty=FALSE;
				arrayAviso[indice].idCliente=cliente_generarNuevoId();
				printf("\n/////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////\n"
						"\///////////////////////////////////////////nNombre: %s -Apellido: %s - Cuit %s -ID Cliente: %d ////////////////////////////////////////////////////////\n"
						,arrayAviso[indice].nombre ,arrayAviso[indice].apellido , arrayAviso[indice].cuit, arrayAviso[indice].idCliente);
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

int aviso_modificar (Aviso * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Aviso bufferAviso;

	if (pArrays != NULL && limite>0)
	{
		aviso_imprimir(pArrays, limite);

		if(utn_getEntero("ID:","ERROR!",&idBuscar,3,9999,0)==0)
		{
			if(aviso_buscarIndicePorIdRef(pArrays,limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferAviso = pArrays[indiceAModificar];

				if (utn_getNombre("\nINGRESE NUEVO NOMBRE","ERROR!!!REINGRESE NOMBRE",bufferAviso.nombre,3,LONG_NOMBRE) == 0 &&
					utn_getNombre("\nINGRESE NUEVO APELLIDO","ERROR!!!REINGRESE APELLIDO",bufferAviso.apellido,3,LONG_NOMBRE) == 0 &&
					utn_getCuit("INGRESE NUEVO CUIT","ERROR!!! REINGRESE CUIT", bufferAviso.cuit, 3, LONG_NOMBRE) == 0)
					{
						pArrays[indiceAModificar] = bufferAviso; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	return retorno;
}

int aviso_imprimir (Aviso * pArrays , int limite)
{
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Apellido: %s - Cuit %s - ID %d",pArrays[i].,pArrays[i].apellido, pArrays[i].cuit , pArrays[i].idAviso);
			}
		}
		retorno = 0;
	}
return retorno;
}
*/
/*
int aviso_buscarIndicePorIdRef (Aviso * pArrays, int limite,int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].idAviso == idBuscar)
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


int aviso_buscarLibreRef(Aviso pArrayAviso[],int limit, int *pindex)
{
	int retorno=-1;
	int i;
	if(pArrayAviso !=NULL && limit>0 && pindex!=NULL)
	{
		for(i = 0;i<limit;i++)
		{
			if(pArrayAviso[i].isEmpty==TRUE)
			{
				*pindex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

static int aviso_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}
*/
