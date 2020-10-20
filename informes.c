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
int informes_contadorAvisosPausadosCliente(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
		{
			if(pArrayAviso[i].idcliente==id && pArrayAviso[i].estadoPublicacion==FALSE )
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}

int aviso_contarClientesConMasAvisosPausados(Aviso *pArrayAviso,int limiteAviso,Cliente* pArrayCliente,int limiteCliente)
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
			  informes_contadorAvisosPausadosCliente(pArrayAviso,limiteAviso,pArrayAviso[i].idcliente,&contadorPublicaciones)==0)
			{
				if(i==0 || contadorPublicaciones>contadorMaximo)
				{
					contadorMaximo = contadorPublicaciones;
					bufferAux = pArrayAviso[i];
					retorno=0;
				}
			}
		}
		cliente_imprimirClientePorID(pArrayCliente, limiteCliente, bufferAux.idcliente,"El cliente con mas avisos Pausados es:");
		printf("Con %d Avisos",contadorMaximo);
	}
return retorno;

}



int informes_contadorAvisosActivosCliente(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
		{
			if(pArrayAviso[i].idcliente==id && pArrayAviso[i].estadoPublicacion==TRUE )
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}

int aviso_contarClientesConMasAvisosActivos(Aviso *pArrayAviso,int limiteAviso,Cliente* pArrayCliente,int limiteCliente)
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
			  informes_contadorAvisosActivosCliente(pArrayAviso,limiteAviso,pArrayAviso[i].idcliente,&contadorPublicaciones)==0)
			{
				if(i==0 || contadorPublicaciones>contadorMaximo)
				{
					contadorMaximo = contadorPublicaciones;
					bufferAux = pArrayAviso[i];
					retorno=0;
				}
			}
		}
		cliente_imprimirClientePorID(pArrayCliente, limiteCliente, bufferAux.idcliente,"El cliente con mas avisos Activos es:");
		printf("Con %d Avisos",contadorMaximo);
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
*///////////////////////////////////////////////////////////////////////////////
int informes_contadorAvisosCliente(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
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

int aviso_contarClientesConMasAvisos(Aviso *pArrayAviso,int limiteAviso,Cliente* pArrayCliente,int limiteCliente)
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
			  informes_contadorAvisosCliente(pArrayAviso,limiteAviso,pArrayAviso[i].idcliente,&contadorPublicaciones)==0)
			{
				if(i==0 || contadorPublicaciones>contadorMaximo)
				{
					contadorMaximo = contadorPublicaciones;
					bufferAux = pArrayAviso[i];
					retorno=0;
				}
			}
		}
		cliente_imprimirClientePorID(pArrayCliente, limiteCliente, bufferAux.idcliente,"El cliente con mas avisos es:");
		printf("Con %d Avisos",contadorMaximo);
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
int aviso_contarRubrosConMasAvisos(Aviso *pArrayAviso,int limiteAviso )
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

int aviso_cantidadDeAvisosActivosTotales(Aviso *pArrayAviso,int limiteAviso, int *contadorAvisosActivos)
{
	int retorno=-1;
	int contador=0;
	for(int i = 0; i<limiteAviso; i++)
	{
		if (pArrayAviso[i].estadoPublicacion == TRUE &&
				pArrayAviso[i].isEmpty==FALSE)
		{
			contador++;
			retorno=0;
		}
	}
	*contadorAvisosActivos=contador;
	return retorno;

}
int informes_contadorClienteMenosAvisos(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
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
int avisos_clienteConMenosAvisos(Aviso *pArrayAviso,int limiteAviso,Cliente *pArrayCliente,int limiteCliente)
{
	int retorno=-1;
		int contadorPublicaciones;
		int contadorMinimo;
		int i=0;
		Aviso bufferAux;
		if(pArrayAviso!=NULL && limiteAviso>0)
		{
			for(i=0;i<limiteAviso;i++)
			{
				if(pArrayAviso[i].isEmpty == FALSE &&
					informes_contadorClienteMenosAvisos(pArrayAviso,limiteAviso,pArrayAviso[i].idcliente,&contadorPublicaciones)==0)
				{
					if(i==0 || contadorPublicaciones<contadorMinimo)
					{
						contadorMinimo = contadorPublicaciones;
						bufferAux = pArrayAviso[i];
						retorno=0;
					}
				}
			}
			cliente_imprimirClientePorID(pArrayCliente, limiteCliente, bufferAux.idcliente,"El cliente con menos avisos es:");
			printf("Con %d Avisos",contadorMinimo);
		}
	return retorno;
}


int informes_contadorAvisoPorCuit(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
		{
			if(pArrayAviso[i].idcliente==id && pArrayAviso[i].isEmpty==TRUE)
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}
//////////////////////////////////////////////
int avisos_imprimirAvisoPorCuit(Aviso *pArrayAviso,int limiteAviso,Cliente *pArrayCliente,int limiteCliente)
{
	int retorno=-1;
	char cuitAbuscar [14];
	int idCliente;
	int contadorAviso;
	if (pArrayAviso !=NULL && limiteAviso>0 && pArrayCliente != NULL && limiteCliente>0)
	{
		cliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getNombre("\nINGRESE EL CUIT : ", "\nERROR!!!!! ID NO ENCONTRADO",cuitAbuscar, 3, 14)==0)
		{
			if(cliente_buscarIdPorCuitRef(pArrayCliente, limiteCliente,cuitAbuscar,&idCliente)==0 &&
			informes_contadorAvisoPorCuit(pArrayAviso,limiteAviso,idCliente,&contadorAviso)==0)
			{
				printf("El Cuit: %s tiene %d avisos publicados.",cuitAbuscar,contadorAviso);
				retorno=0;
			}
			else
			{
				printf("El Cuit ingresado no posee avisos publicados");
			}
		}

	}
	return retorno;
}
/** \brief Realiza la suma de avisos por rubro y devuelve el resultado por referencia
 *
 *\param valor Aviso pArrayAviso es el puntero al array de Avisos
 *\param valor limiteAvisos es el tamaño del array de Avisos
 *\param recibe el rubro que va a ser buscado en el array de avisos
 *\param *pContador devuelve la suma total de avisos
 *\return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int informes_contadorAvisoPorRubro(Aviso *pArrayAviso,int limiteAvisos,int rubro,int *pContador)
{
	int retorno=-1;
	int contador=0;
	if(pArrayAviso!=NULL && limiteAvisos>0)
	{
		for(int i=0;i<limiteAvisos;i++)
		{
			if(pArrayAviso[i].numeroRubro==rubro && pArrayAviso[i].isEmpty==FALSE)
			{
				contador++;
			}
		}
		*pContador=contador;
		retorno=0;
	}
return retorno;
}
/** \brief Imprime la cantidad de avisos por rubro
 *
 ** \param valor Aviso pArrayAviso es el puntero al array de Avisos
 * \param valor limiteAviso es el tamaño del array de Avisos
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int informe_imprimirCantidadAvisosPorRubro(Aviso *pArrayAviso,int limiteAviso)
{
	int retorno=-1;
	int rubro;
	int pContador;
	if(pArrayAviso!=NULL && limiteAviso>0)
	{
		avisos_imprimir(pArrayAviso, limiteAviso);
		if(utn_getEntero("Ingrese numero de rubro","Error!!!! Reingrese rubro",&rubro,3,99999,0)==0)
		{
			if(informes_contadorAvisoPorRubro(pArrayAviso, limiteAviso, rubro,&pContador)==0)
			{
				printf("El rubro: %d tiene %d avisos publicados",rubro,pContador);
				retorno=0;
			}
		}
	}
	return retorno;
}
/** \brief Imprime los rubro de menor a mayor
*
** \param valor Aviso arrayAviso[] es el puntero al array de Avisos
* \param valor limiteAviso es el tamaño del array de Avisos
* \return Devuelve 0 si no hubo errores y -1 si hubo errores
*
*/
int informe_ordenarRubro(Aviso arrayAviso[], int limiteAviso)
{
	int ret=-1;
	int indice;
	int j;
	int aux;
	int flagEstadoDesordenado=1;

	if(arrayAviso!=NULL && limiteAviso >0)
	{
		while(flagEstadoDesordenado==1)
		{
			flagEstadoDesordenado=0;

			for(indice=0 ; indice<(limiteAviso-1)  ; indice++)
			{
				if(arrayAviso[indice].isEmpty==FALSE && arrayAviso[indice+1].isEmpty==FALSE && arrayAviso[indice].numeroRubro > arrayAviso[indice+1].numeroRubro)
				{
					aux= arrayAviso[indice].numeroRubro;
					arrayAviso[indice].numeroRubro = arrayAviso[indice+1].numeroRubro;
					arrayAviso[indice+1].numeroRubro = aux;
					flagEstadoDesordenado=1;

				}
			}

		}
		ret=0;
		for(j=0 ; j<limiteAviso; j++)
		{
			if(arrayAviso[j].isEmpty==FALSE && arrayAviso[j+1].isEmpty==FALSE && arrayAviso[j].numeroRubro != arrayAviso[j+1].numeroRubro )
			{
				printf("\n Numero de rubro: %d", arrayAviso[j].numeroRubro);
			}
			else
			{
				if(arrayAviso[j].isEmpty==FALSE && arrayAviso[j+1].isEmpty==TRUE && arrayAviso[j].numeroRubro != arrayAviso[j+1].numeroRubro)
				{
					printf("\n Numero de rubro: %d", arrayAviso[j].numeroRubro);
				}
			}
			/*if(j==limiteAviso &&)
			{
				printf("\n Numero de rubro: %d", arrayAviso[j].numeroRubro);
			}
			*/
		}

	}

	return ret;

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



int menu_Consultas(Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente , int limiteCliente)
{
	int retorno=-1;
	char opcionMenu;
	int contadorAvisosPausados;
	int contadorAvisosActivos;

	if (pArrayAviso != NULL && limiteAviso >0 && pArrayCliente!=NULL && limiteCliente>0)
	{
		do
		{
			if(utn_getChar("\n|///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|/////INGRESE: a) Cliente con más avisos.///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////b) Cantidad de avisos pausados.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////c) Rubro con mas avisos//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////d) Cliente con mas avisos activos////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
							 "\n|//////////////e) Cliente con mas avisos pausados///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////f) imprimir lista de rubros ordenados de menor a mayor///////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////g) Cantidad de avisos activos totales////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
					         "\n|//////////////h) Cliente con menos avisos//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
							 "\n|//////////////i) Cantidad por rubro: Ingresar://///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
				             "\n|//////////////j) Cantidad de avisos por cliente////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|"
							 "\n|//////////////k) Salir/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|",
							 "\n\n*|////////////////////////////////////////////////////////ERROR!!! LETRA MAL INGRESADA!!!!////////////////////////////////////////////////////////////////////////////////|*",
							 &opcionMenu,3)==0)
			{
				switch(opcionMenu)
				{
					case  'a':
						if(aviso_contarClientesConMasAvisos(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente)==0)
						{
							retorno=0;
						}
						else
						{
							printf("No hay clientes con avisos");
						}
						break;
					case 'b':
						if(aviso_contarAvisosPausadosRef(pArrayAviso,limiteAviso,&contadorAvisosPausados)==0)
						{
							printf("La cantidad de avisos pausados es: %d",contadorAvisosPausados);
							retorno=0;
						}
						else
						{
							printf("No hay avisos pausados");
						}
						break;
					case 'c':
						if(aviso_contarRubrosConMasAvisos(pArrayAviso,limiteAviso)==0)
						{
							retorno=0;
						}
						else
						{
							printf("\n No hay rubros cargados");
						}
						break;
					case 'd':
						if(aviso_contarClientesConMasAvisosActivos(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente)==0)
						{
							retorno=0;
						}
						else
						{
							printf("\n No hay avisos Activos cargados");
						}
						break;
					case 'e':
						if(aviso_contarClientesConMasAvisosPausados(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente)==0)
						{
							retorno=0;
						}
						else
						{
							printf("\n No hay clientes con avisos");
						}
						break;
					case 'f':
						informe_ordenarRubro(pArrayAviso,limiteAviso);
						break;
					case 'g':
						if(aviso_cantidadDeAvisosActivosTotales(pArrayAviso,limiteAviso,&contadorAvisosActivos)==0)
						{
							printf("La cantidad de avisos activos totales es: %d",contadorAvisosActivos);
							retorno=0;
						}
						else
						{
							printf("\nNo hay avisos Activos Publicados");
						}
						break;
					case 'h':
						if(avisos_clienteConMenosAvisos(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente)==0)
						{
							retorno=0;
						}
						else
						{
							printf("\nNo hay avisos Publicados");
						}
						break;
					case 'i':
						if(informe_imprimirCantidadAvisosPorRubro(pArrayAviso,limiteAviso)==0)
						{
							retorno=0;
						}
						else
						{
							printf("No hay avisos publicados");
						}
						break;
					case 'j':
						if(avisos_imprimirAvisoPorCuit(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente)==0)
						{
							retorno=0;
						}
						else
						{

						}
						break;
				}
				retorno= 0;
			}
		}while(opcionMenu !='k');
	}
	return retorno;


}



