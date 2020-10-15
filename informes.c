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

int informes_contadorClienteAvisos(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador)
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



int menu_Consultas(Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente , int limitCliente)
{
	int retorno=-1;
	char opcionMenu;
	int contadorAvisosPausados=0;
	if (pArrayAviso != NULL && limiteAviso >0 && pArrayCliente!=NULL && limitCliente>0)
	{
		do
		{
			if(utn_getNombre("\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n/////INGRESE: a) Cliente con más avisos.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n//////////////b) Cantidad de avisos pausados.////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n//////////////c) Rubro con mas avisos///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
					         "\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
							 "\n\n////////////////////////////////////////////////////////ERROR!!! LETRA MAL INGRESADA!!!!/////////////////////////////////////////////////////////////////////////",
							 &opcionMenu,3,1)==0)
			{
				switch(opcionMenu)
				{
					case 'a':
						if(informes_clienteConMasAvisos(pArrayCliente, limitCliente, pArrayAviso, limiteAviso)==0)
						{
							retorno=0;
						}
						break;
					case 'b':
						if(aviso_contarAvisosPausadosRef(pArrayAviso,limiteAviso,&contadorAvisosPausados)==0)
						{
							printf("La cantidad de avisos pausados es: %d",contadorAvisosPausados);
							retorno=0;
						}
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



