
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "aviso.h"

static int aviso_generarNuevoId (void);


/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */
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
/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */
int cliente_baja (Cliente * pArrays, int limite,Aviso *arrayAviso,int limit)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrarCliente;
	char confirmacionBaja[2];

	if (pArrays != NULL && limite>0)
	{
		cliente_imprimir(pArrays, limite);
		if(utn_getEntero("\nINGRESE EL ID QUE DESEA BORRAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idABorrar,3,9999,0)==0)
			if(cliente_buscarIndicePorIdRef(pArrays, limite, idABorrar,&indiceABorrarCliente)== 0 &&
				aviso_imprimirAvisoPorID(arrayAviso,limit,pArrays,limite,idABorrar)==0)
			{
				if(utn_getNombre("ATENCION!!!! EL REGITRO SERA ELIMINADO¿DESEA CONTINUAR? ","ERROR!!!!!!!!EL REGITRO SERA ELIMINADO¿DESEA CONTINUAR? ",confirmacionBaja, 3, 2))
				{
					aviso_bajaIdCliente(arrayAviso,limit,indiceABorrarCliente);
					pArrays[indiceABorrarCliente].isEmpty=TRUE;
				}
			}

	}
	return retorno;
}
/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */
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
			if(utn_getEntero("\nINGRESE ID DEL CLIENTE: ","\n ID NO ENCONTRADO ",&bufferAviso.idcliente,3,99999999,0)==0 &&
				cliente_buscarIndicePorId(pArrayClientes,limit,bufferAviso.idcliente) != -1 &&
				utn_getEntero("INGRESE NUMERO DE RUBRO ","ERROR!!!! NUMERO MAL INGRESADO ",&bufferAviso.numeroRubro,3,99999,0)==0 &&
				utn_getNombre("\nINGRESE EL AVISO QUE DESEA PUBLICAR: ","ERROR!!!!! EL AVISO PODRIA ESTAR EXEDIENDO LA CANTIDAD DE CARACTERES PERMITIDOS(64 CARACTERES)\n", bufferAviso.textoAviso,3,QTY_CARACTERES)==0)
			{
				bufferAviso.isEmpty=FALSE;
				arrayAviso[indice]=bufferAviso;
				arrayAviso[indice].isEmpty=FALSE;
				arrayAviso[indice].idAviso=aviso_generarNuevoId();
				arrayAviso[indice].estadoPublicacion=TRUE;
				printf("\n ////////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////////////////////\n"
						"                                        ID CLIENTE: %d - NUMERO DE RUBRO: %d - TEXTO DEL AVISO %s -ID AVISO: %d                       \n"
						"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
						,arrayAviso[indice].idcliente ,arrayAviso[indice].numeroRubro , arrayAviso[indice].textoAviso, arrayAviso[indice].idAviso);
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
/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */
int cliente_imprimirAvisos(Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit)
{
	int retorno = -1;
	int avisosdelcliente;

	if (pArrays != NULL && limite >0 && pArrayCliente!=NULL && limit>0)
	{
			for (int i=0 ; i<limit ; i++)
			{
				if(pArrayCliente[i].isEmpty == FALSE)
				{
					cliente_contadorAvisos(pArrays,limite,pArrayCliente[i].idCliente,&avisosdelcliente);
					printf("\nNombre: %s - Apellido: %s - Cuit: %s - ID: %d "
							"\n Avisos realizados: %d",pArrayCliente[i].nombre,pArrayCliente[i].apellido, pArrayCliente[i].cuit , pArrayCliente[i].idCliente,avisosdelcliente);
				}
			}
		retorno = 0;
	}
	return retorno;
}

/*int aviso_buscarIndicePorId (Aviso * pArrays, int limite,int idBuscar)
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
*/
int menu_Consultas(Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit)
{
	int retorno=-1;
	char opcionMenu;
	int contadorAvisosPausados=0;
	if (pArrays != NULL && limite >0 && pArrayCliente!=NULL && limit>0)
	{
		do
		{
			if(utn_getNombre("\n Ingrese: a) Cliente con más avisos.\n          b) Cantidad de avisos pausados. \n          c) Rubro con mas avisos", "ERROR!!! LETRA MAL INGRESADA",&opcionMenu,3,1)==0)
			{
				switch(opcionMenu)
				{
					case 'a':

						break;
					case 'b':
							for(int i = 0; i<limite; i++)
							{
								if (pArrays[i].estadoPublicacion == FALSE &&
										pArrays[i].isEmpty== FALSE)
								{
									contadorAvisosPausados++;
								}
							}
							printf("La cantidad de avisos pausados es: %d",contadorAvisosPausados);
						    break;
					case 'c':

						break;

				}
				retorno= 0;
			}
		}while(opcionMenu =='a' && opcionMenu =='b' && opcionMenu =='c');
	}
	return retorno;
}


/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */


int aviso_imprimirAvisoPorID (Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit, int id)
{
	int retorno =-1;
		if(pArrays != NULL && limite > 0 && pArrayCliente != NULL && limit>0)
		{
			for(int i = 0; i<limite; i++)
			{
				if (pArrays[i].idcliente == id)
				{
					retorno = 0;
					printf("\n ID CLIENTE: %d - ID PUBLICACION: %d - N° DE RUBRO %d -AVISO PUBLICADO %s ",pArrays[i].idcliente,pArrays[i].idAviso , pArrays[i].numeroRubro, pArrays[i].textoAviso);
				}
			}
		}

	return retorno;
}

int aviso_imprimirAvisoPorIDAviso (Aviso * pArrays, int limite,int id)
{
	int retorno =-1;
		if(pArrays != NULL && limite > 0)
		{
			for(int i = 0; i<limite; i++)
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




/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */

int aviso_bajaIdCliente(Aviso * pArrays, int limite,int idCliente)
{
	int retorno =-1;
	if(pArrays != NULL && limite > 0)
	{
		for(int i = 0; i<limite; i++)
		{
			if (pArrays[i].idcliente == idCliente)
			{
				pArrays[i].isEmpty=TRUE;
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */

int cliente_contadorAvisos(Aviso *arrayAviso,int limit,int idCliente,int *avisosdelcliente)
{
	int retorno =-1;
	int contadorAvisos=0;
	int i;
		if(arrayAviso != NULL && limit > 0)
		{
			for(i = 0; i<limit; i++)
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
/** \brief Recibe un valor**************************************************** numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable *respuesta
 * \param Valor correspondiente a la variable *mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable *mensajeError, se guarda el mensaje de error que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */
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


