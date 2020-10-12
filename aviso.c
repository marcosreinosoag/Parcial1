/*
 * aviso.c
 *
 *  Created on: 10 oct. 2020
 *      Author: marcos
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "aviso.h"

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

int aviso_alta(Aviso *arrayAviso,int limite, Cliente *pArrayClientes,int limit)
{
	int retorno=-1;
	int indice;
	Aviso bufferAviso;
	if(arrayAviso!=NULL && limite>0 )
	{
		if(aviso_buscarLibreRef(arrayAviso,limite,&indice)==0)
		{
			cliente_imprimir(pArrayClientes,limit);
			if(utn_getEntero("INGRESE ID ","\n ID NO ENCONTRADO ",&bufferAviso.idcliente,3,99999999,0)==0 &&
				cliente_buscarIndicePorId(pArrayClientes,limit,bufferAviso.idcliente) == 0 &&
				utn_getEntero("INGRESE NUMERO DE RUBRO ","ERROR!!!! NUMERO MAL INGRESADO ",&bufferAviso.numeroRubro,3,99999,0) &&
				utn_getNombre("INGRESE EL AVISO QUE DESEA PUBLICAR: ","ERROR!!!!! EL MENSAJE PODRIA ESTAR EXEDIENDO LA CANTIDAD DE CARACTERES", bufferAviso.textoAviso,3,10)==0)
			{
				bufferAviso.isEmpty=FALSE;
				arrayAviso[indice]=bufferAviso;
				arrayAviso[indice].isEmpty=FALSE;
				arrayAviso[indice].idAviso=aviso_generarNuevoId();
				arrayAviso[indice].estadoPublicacion=TRUE;
				printf("\n/////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////\n"
						"\///////////////////////////////////////////nID CLIENTE: %d - NUMERO DE RUBRO: %d - TEXTO DEL AVISO %s -ID AVISO: %d ////////////////////////////////////////////////////////\n"
						,arrayAviso[indice].idcliente ,arrayAviso[indice].numeroRubro , arrayAviso[indice].textoAviso, arrayAviso[indice].idAviso);
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
	static int idAviso = 0;
	idAviso = idAviso+1;
	return idAviso;
}


