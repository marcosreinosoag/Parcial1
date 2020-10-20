
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "aviso.h"


static int aviso_generarNuevoId (void);
/** \brief Inicializa el array de avisos con espacios vacios
*
 * \param Valor Aviso *pArrayAvisos es el puntero al array de avisos
 * \param Valor limiteAviso es el tamaño del array de avisos
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int aviso_init(Aviso * pArrayAvisos, int limiteAviso)
{
	int retorno = -1;
	if (pArrayAvisos != NULL && limiteAviso >0)
	{
		for (int i = 0; i<limiteAviso; i++ )
		{
			pArrayAvisos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Realiza la baja del cliente
*
 * \param Valor Cliente *pArraysCliente es el puntero al array de Clientes
 * \param Valor limiteCliente es el tamaño del array de clientes
 * \param valor Aviso *arrayAviso es el puntero al array de Avisos
 * \param valor limitAviso es el tamaño del array de Avisos
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int cliente_baja (Cliente * pArraysCliente, int limiteCliente,Aviso *arrayAviso,int limitAviso)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrarCliente;
	int confirmacion;

	if (pArraysCliente != NULL && limiteCliente>0 && arrayAviso !=NULL && limitAviso>0)
	{
		cliente_imprimir(pArraysCliente, limiteCliente);
		if(utn_getEntero("\nINGRESE EL ID QUE DESEA BORRAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idABorrar,3,9999,0)==0)
		{
			if(cliente_buscarIndicePorIdRef(pArraysCliente, limiteCliente,idABorrar,&indiceABorrarCliente)== 0 &&
				aviso_imprimirAvisoPorID(arrayAviso,limitAviso,pArraysCliente,limiteCliente,idABorrar)==0)
				{
					utn_getEntero("¿DESEA CONTINUAR LA BAJA DEL CLIENTE? 1(SI) 2(NO)", "ERROR!!!!!!!EL REGISTRO SERA ELIMINADO¿DESEA CONTINUAR? ",&confirmacion,3, 2, 1);
					if(confirmacion==1)
					{
					aviso_bajaIdCliente(arrayAviso,limitAviso,indiceABorrarCliente);
					pArraysCliente[indiceABorrarCliente].isEmpty=TRUE;
					}
				}
			    else
			    if(cliente_buscarIndicePorIdRef(pArraysCliente, limiteCliente,idABorrar,&indiceABorrarCliente)== 0 )
			    {
			    	utn_getEntero("¿DESEA CONTINUAR LA BAJA DEL CLIENTE? 1(SI) 2(NO)", "ERROR!!!!!!!EL REGISTRO SERA ELIMINADO¿DESEA CONTINUAR? ",&confirmacion,3, 2, 1);
			    	if(confirmacion==1)
			    	{
			    	pArraysCliente[indiceABorrarCliente].isEmpty=TRUE;
			    	}
			    }
		}
	}
	return retorno;
}

/** \brief Realiza el alta del aviso
*
 * \param valor Aviso *arrayAviso es el puntero al array de Avisos
 * \param valor limiteAviso es el tamaño del array de Avisos
 * \param Valor Cliente *pArrayClientes es el puntero al array de Clientes
 * \param Valor limiteCliente es el tamaño del array de clientes
 *
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int aviso_alta(Aviso *arrayAviso,int limiteAviso, Cliente *pArrayClientes,int limiteCliente)
{
	int retorno=-1;
	int indice;
	char estadoPublicacion[8];
	Aviso bufferAviso;
	if(arrayAviso!=NULL && limiteAviso>0 )
	{
		if(aviso_buscarLibreRef(arrayAviso,limiteAviso,&indice)==0)
		{
			cliente_imprimir(pArrayClientes,limiteCliente);
			if(utn_getEntero("\nINGRESE ID DEL CLIENTE: ","\n ID NO ENCONTRADO ",&bufferAviso.idcliente,3,99999999,0)==0 &&
				cliente_buscarIndicePorId(pArrayClientes,limiteCliente,bufferAviso.idcliente) != -1 &&
				utn_getEntero("\nINGRESE NUMERO DE RUBRO ","ERROR!!!! NUMERO MAL INGRESADO ",&bufferAviso.numeroRubro,3,99999,0)==0 &&
				utn_getNombre("\nINGRESE EL AVISO QUE DESEA PUBLICAR: ","ERROR!!!!! EL AVISO PODRIA ESTAR EXEDIENDO LA CANTIDAD DE CARACTERES PERMITIDOS(64 CARACTERES)\n", bufferAviso.textoAviso,3,QTY_CARACTERES)==0)
			{
				bufferAviso.isEmpty=FALSE;
				arrayAviso[indice]=bufferAviso;
				arrayAviso[indice].isEmpty=FALSE;
				arrayAviso[indice].idAviso=aviso_generarNuevoId();
				arrayAviso[indice].estadoPublicacion=TRUE;
				if(arrayAviso[indice].estadoPublicacion==TRUE)
				{
					strncpy(estadoPublicacion,"activa",8);
				}
				else
				{
					strncpy(estadoPublicacion,"pausada",8);
				}
				printf("\n ////////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////////////////////\n"
						"                                        ID CLIENTE: %d - NUMERO DE RUBRO: %d - TEXTO DEL AVISO %s-ESTADO DE LA PUBLICACION: %s -ID AVISO: %d                       \n"
						"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
						,arrayAviso[indice].idcliente ,arrayAviso[indice].numeroRubro , arrayAviso[indice].textoAviso,estadoPublicacion,arrayAviso[indice].idAviso);
				retorno = 0;
			}
			else
			{
				printf("ERROR!!!!!!!!!!!! ID NO ENCONTRADO");
			}
		}
		else
		{
			printf("\n NO QUEDAN ESPACIOS LIBRES");
		}
	}
	return retorno;
}
/** \brief Imprime una lista de clientes con todos sus datos junto con la cantidad de avisos activos.
*
 * \param valor Aviso * pArrayAviso es el puntero al array de Avisos
 * \param valor limiteAviso es el tamaño del array de Avisos
 * \param Valor Cliente *pArrayClientes es el puntero al array de Clientes
 * \param Valor limiteCliente es el tamaño del array de clientes
 *
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int cliente_imprimirAvisos(Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente , int limiteCliente)
{
	int retorno = -1;
	int avisosdelcliente;

	if (pArrayAviso != NULL && limiteAviso >0 && pArrayCliente!=NULL && limiteCliente>0)
	{
			for (int i=0 ; i<limiteCliente ; i++)
			{
				if(pArrayCliente[i].isEmpty == FALSE)
				{
					cliente_contadorAvisos(pArrayAviso,limiteAviso,pArrayCliente[i].idCliente,&avisosdelcliente);
					printf("\nNombre: %s - Apellido: %s - Cuit: %s - ID: %d "
							"\n Avisos realizados: %d",pArrayCliente[i].nombre,pArrayCliente[i].apellido, pArrayCliente[i].cuit , pArrayCliente[i].idCliente,avisosdelcliente);
				}
			}
		retorno = 0;
	}
	return retorno;
}

/** \brief Realiza el cambio de estado en la publicacion de activa a pausada
*
* \param Valor Cliente * pArrayCliente es el puntero al array de Clientes
* \param Valor limitCliente es el tamaño del array de clientes
* \param valor Aviso *arrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/

int aviso_pausarpublicacion (Cliente * pArrayCliente, int limiteCliente,Aviso *arrayAviso,int limiteAviso)
{
	int retorno = -1;
	int idAviso;
	int indiceCliente;
	int pIndice;
	int confirmacionPausa;

	if (pArrayCliente != NULL && limiteCliente >0 && arrayAviso!=NULL && limiteAviso>0)
	{
		avisos_imprimir(arrayAviso ,QTY_AVISOS);
		if(utn_getEntero("\nINGRESE EL ID DE LA PUBLICACION QUE DESEA PAUSAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idAviso,3,9999,0)==0 &&
			aviso_buscarIndicePorIdRef(arrayAviso,QTY_AVISOS,idAviso,&indiceCliente)==0)
			{
			cliente_buscarIndicePorIdRef (pArrayCliente,limiteCliente,arrayAviso[indiceCliente].idcliente,&pIndice);
			printf("\nID CLIENTE: %d - NOMBRE: %s - APELLIDO %s - CUIT %s",pArrayCliente[pIndice].idCliente,pArrayCliente[pIndice].nombre, pArrayCliente[pIndice].apellido , pArrayCliente[pIndice].cuit);
			utn_getEntero("ATENCION!!!¿LA PUBLICACION SERA PAUSADA ¿DESEA CONTINUAR? 1(SI) 2(NO)", "ERROR REINGRESE EL NUMERO!!!! EL REGISTRO SERA PAUSADO¿DESEA CONTINUAR? ",&confirmacionPausa,3, 2, 1);
			if(confirmacionPausa)
			{
				arrayAviso[indiceCliente].estadoPublicacion=FALSE;
			}
			else
			{
				printf("Usted esta voliviendo al menu");
			}
		}
		else
		{
			printf("ERRORRR!!!");
		}
	}
	return retorno;
}

/** \brief Realiza el cambio de estado en la publicacion de activa a pausada
*
* \param Valor Cliente * pArrayCliente es el puntero al array de Clientes
* \param Valor limitCliente es el tamaño del array de clientes
* \param valor Aviso *arrayAviso es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int aviso_reaunudarpublicacion (Cliente * pArrayCliente, int limiteCliente,Aviso *arrayAviso,int limiteAviso)
{
	int retorno = -1;
	int idAviso;
	int indiceCliente;
	int pIndice;
	int confirmacionReanudar;

	if (pArrayCliente != NULL && limiteCliente >0 && arrayAviso!=NULL && limiteAviso>0)
	{
		avisos_imprimir(arrayAviso ,QTY_AVISOS);
		if(utn_getEntero("\nINGRESE EL ID DE LA PUBLICACION QUE DESEA REANUDAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idAviso,3,9999,0)==0 &&
			aviso_buscarIndicePorIdRef(arrayAviso,limiteAviso,idAviso,&indiceCliente)==0)
		{
			cliente_buscarIndicePorIdRef (pArrayCliente,QTY_CLIENTES,arrayAviso[indiceCliente].idcliente,&pIndice);
			utn_getEntero("ATENCION!!! LA PUBLICACION SERA REACTIVADO ¿DESEA CONTINUAR? 1(SI) 2(NO)", "ERROR REINGRESE EL NUMERO!!!! EL AVISO SERA REACTIVADO¿DESEA CONTINUAR? ",&confirmacionReanudar,3, 2, 1);
			if(confirmacionReanudar)
			{
				arrayAviso[indiceCliente].estadoPublicacion=TRUE;
			}
			else
			{
				printf("Usted esta voliviendo al menu");
			}
		}
	}
	return retorno;
}
/** \brief Imprime los avisos publicados
*
* \param valor Aviso * pArrayAviso es el puntero al array de Aviso
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int avisos_imprimir (Aviso * pArrayAviso , int limiteAviso)
{
	int retorno = -1;
	int i;
	char estadoPublicacion[8];
	if (pArrayAviso != NULL && limiteAviso >0)
	{
		for (i=0 ; i<limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE)
			{
				if(pArrayAviso[i].estadoPublicacion == TRUE)
				{
					strncpy(estadoPublicacion,"activa",8);
				}
				else
				{
					strncpy(estadoPublicacion,"pausada",8);
				}
				printf("\nID de cliente: %d - Numero de rubro: %d - Texto del aviso %s - Estado de la publicacion: %s - ID Aviso %d",pArrayAviso[i].idcliente,pArrayAviso[i].numeroRubro, pArrayAviso[i].textoAviso,estadoPublicacion, pArrayAviso[i].idAviso);
			}
		}
		retorno = 0;
	}
return retorno;
}
/** \brief Busca el indice por ID y devuelve el indice por referencia
*
* \param valor Aviso * pArrayAvisos es el puntero al array de Aviso
* \param valor limiteAvisos es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int aviso_buscarIndicePorIdRef(Aviso * pArrayAvisos, int limiteAvisos,int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
		if (pArrayAvisos != NULL && limiteAvisos >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limiteAvisos; i++)
				{
					if(pArrayAvisos[i].isEmpty == FALSE &&
					   pArrayAvisos[i].idAviso == idBuscar)
					{
					*pIndice= i;
					retorno = 0;
					break;
					}
				}
		}
		else
		{
			printf("ERROR!!! ID NO ENCONTRADO!!!!!!!!!!!!");
		}
	return retorno;
}

/** \brief Imprime avisos por ID
*
* \param valor Aviso * pArrayAvisos es el puntero al array de Aviso
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor Cliente * pArrayCliente es el puntero al array de Cliente
* \param valor limitCliente es el tamaño del array de
* \return Devuelve 0 si no hubo errores y -1 si hubo errores *************
*
*/
int aviso_imprimirAvisoPorID (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente , int limitCliente, int id)
{
	int retorno =-1;
		if(pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limitCliente>0)
		{
			for(int i = 0; i<limiteAviso; i++)
			{
				if (pArrayAviso[i].idcliente == id)
				{
					retorno = 0;
					printf("\n ID CLIENTE: %d - ID PUBLICACION: %d - N° DE RUBRO %d -AVISO PUBLICADO %s ",pArrayAviso[i].idcliente,pArrayAviso[i].idAviso , pArrayAviso[i].numeroRubro, pArrayAviso[i].textoAviso);
				}
			}
		}

	return retorno;
}
/** \brief Imprime un aviso por ID
*
* \param valor Aviso * pArrays es el puntero al array de Aviso
* \param valor limiteAvisos es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int aviso_imprimirAvisoPorIDAviso (Aviso * pArrays, int limiteAvisos,int id)
{
	int retorno =-1;
		if(pArrays != NULL && limiteAvisos > 0)
		{
			for(int i = 0; i<limiteAvisos; i++)
			{
				if (pArrays[i].idAviso == id)
				{
					retorno = 0;
					printf("\n ID CLIENTE: %d - ID PUBLICACION: %d - N° DE RUBRO %d -AVISO PUBLICADO %s ",pArrays[i].idcliente,pArrays[i].idAviso , pArrays[i].numeroRubro, pArrays[i].textoAviso);
				}
			}
		}

	return retorno;
}

/** \brief Realiza la baja de la publicacion por el id de cliente
*
* \param valor Aviso * pArrays es el puntero al array de Aviso
* \param valor limiteAvisos es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/

int aviso_bajaIdCliente(Aviso * pArrayAviso, int limiteAviso,int idCliente)
{
	int retorno =-1;
	if(pArrayAviso != NULL && limiteAviso > 0)
	{
		for(int i = 0; i<limiteAviso; i++)
		{
			if (pArrayAviso[i].idcliente == idCliente)
			{
				pArrayAviso[i].isEmpty=TRUE;
				retorno = 0;
			}
		}
	}
	return retorno;
}


/** \brief Desarrolla la suma total de avisos realizados por el cliente y devuelve la suma por referencia
*
* \param valor Aviso *arrayAviso es el puntero al array de Aviso
* \param valor limitAviso es el tamaño del array de Avisos
* \param valor idCliente recibe el id del cliente para realizar la suma de los avisos
* \param valor *avisosdelcliente devuelve la suma total de aviso realiados por el cliente
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/

int cliente_contadorAvisos(Aviso *arrayAviso,int limitAviso,int idCliente,int *avisosdelcliente)
{
	int retorno =-1;
	int contadorAvisos=0;
	int i;
		if(arrayAviso != NULL && limitAviso > 0)
		{
			for(i = 0; i<limitAviso; i++)
			{
				if (arrayAviso[i].idcliente == idCliente &&
						arrayAviso[i].isEmpty==FALSE)
				{
					contadorAvisos++;
					retorno = 0;
				}
			}
		}
	*avisosdelcliente=contadorAvisos;
 return retorno;
}

/** \brief Busca un espacio vacio en el array de Avisos y devuelve el indice por referencia
*
* \param valor Aviso *arrayAviso es el puntero al array de Aviso
* \param valor limiteAviso es el tamaño del array de Avisos
* \param valor *pindex
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/

int aviso_buscarLibreRef(Aviso pArrayAviso[],int limiteAvisos, int *pindex)
{
	int retorno=-1;
	int i;
	if(pArrayAviso !=NULL && limiteAvisos>0 && pindex!=NULL)
	{
		for(i = 0;i<limiteAvisos;i++)
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
/** \brief Genera un Id para asociarlo a cada aviso
*
*/
static int aviso_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int aviso_altaForzada(Aviso *pArrayAviso,int limiteAviso)
{
	int retorno=-1;



	return retorno;
}

