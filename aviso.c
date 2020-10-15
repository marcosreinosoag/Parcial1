
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



int cliente_baja (Cliente * pArraysCliente, int limiteCliente,Aviso *arrayAviso,int limit)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrarCliente;
	int confirmacion;

	if (pArraysCliente != NULL && limiteCliente>0)
	{
		cliente_imprimir(pArraysCliente, limiteCliente);
		if(utn_getEntero("\nINGRESE EL ID QUE DESEA BORRAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idABorrar,3,9999,0)==0)
			if(cliente_buscarIndicePorIdRef(pArraysCliente, limiteCliente, idABorrar,&indiceABorrarCliente)== 0 &&
				aviso_imprimirAvisoPorID(arrayAviso,limit,pArraysCliente,limiteCliente,idABorrar)==0)
			{
				utn_getEntero("¿DESEA CONTINUAR LA BAJA DEL CLIENTE? 1(SI) 2(NO)", "ERROR!!!!!!!EL REGISTRO SERA ELIMINADO¿DESEA CONTINUAR? ",&confirmacion,3, 2, 1);
				if(confirmacion)
				{
					aviso_bajaIdCliente(arrayAviso,limit,indiceABorrarCliente);
					pArraysCliente[indiceABorrarCliente].isEmpty=TRUE;
				}
			}
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


int aviso_pausarpublicacion (Cliente * pArrays, int limite,Aviso *arrayAviso,int limit)
{
	int retorno = -1;
	int idAviso;
	int indiceCliente;
	int pIndice;
	char confirmacionPausa[2];

	if (pArrays != NULL && limite >0 && arrayAviso!=NULL && limit>0)
	{
		avisos_imprimir(arrayAviso ,QTY_AVISOS);
		if(utn_getEntero("\nINGRESE EL ID DE LA PUBLICACION QUE DESEA PAUSAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idAviso,3,9999,0)==0 &&
			aviso_buscarIndicePorIdRef(arrayAviso,QTY_AVISOS,idAviso,&indiceCliente)==0)
		{
			cliente_buscarIndicePorIdRef (pArrays,QTY_CLIENTES,arrayAviso[indiceCliente].idcliente,&pIndice);
			printf("\nID CLIENTE: %d - NOMBRE: %s - APELLIDO %s - CUIT %s",pArrays[pIndice].idCliente,pArrays[pIndice].nombre, pArrays[pIndice].apellido , pArrays[pIndice].cuit);
			if(utn_getNombre("ATENCION!!! LA PUBLICACION SERA PAUSADA ¿Desea continuar?","ERROR!!!!!!!! ",confirmacionPausa, 3, 2))
			{
				arrayAviso[indiceCliente].estadoPublicacion=FALSE;
			}
		}
		else
		{
			printf("ERRORRR!!!");
		}
	}
	return retorno;
}
int aviso_reaunudarpublicacion (Cliente * pArrays, int limite,Aviso *arrayAviso,int limit)
{
	int retorno = -1;
	int idAviso;
	int indiceCliente;
	int pIndice;
	char confirmacionReanudar [2];

	if (pArrays != NULL && limite >0 && arrayAviso!=NULL && limit>0)
	{
		avisos_imprimir(arrayAviso ,QTY_AVISOS);
		if(utn_getEntero("\nINGRESE EL ID DE LA PUBLICACION QUE DESEA REANUDAR: ","\nERROR!!!!! ID NO ENCONTRADO",&idAviso,3,9999,0)==0 &&
			aviso_buscarIndicePorIdRef(arrayAviso,QTY_AVISOS,idAviso,&indiceCliente)==0)
		{
			cliente_buscarIndicePorIdRef (pArrays,QTY_CLIENTES,arrayAviso[indiceCliente].idcliente,&pIndice);
			if(utn_getNombre("ATENCION!!! LA PUBLICACION SERA REACTIVADA ¿DESEA CONTINUAR?","ERROR!!!!!!!! ",confirmacionReanudar, 3, 2))
			{
				arrayAviso[indiceCliente].estadoPublicacion=TRUE;
			}

		}
	}
	return retorno;
}

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

int avisos_imprimir (Aviso * pArrays , int limite)
{
	int retorno = -1;
	if (pArrays != NULL && limite >0)
	{
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\nID de cliente: %d - Numero de rubro: %d - Texto del aviso %s - ID Aviso %d",pArrays[i].idcliente,pArrays[i].numeroRubro, pArrays[i].textoAviso , pArrays[i].idAviso);
			}
		}
		retorno = 0;
	}
return retorno;
}


int aviso_buscarIndicePorIdRef(Aviso * pArrays, int limite,int idBuscar, int * pIndice)
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
			printf("ERROR!!! ID NO ENCONTRADO!!!!!!!!!!!!");
		}
	return retorno;
}



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


