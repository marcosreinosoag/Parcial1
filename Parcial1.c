/*
 ============================================================================
 Name        : Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "aviso.h"
#include "informes.h"


int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	Cliente arrayCliente[QTY_CLIENTES];
	Aviso arrayAviso[QTY_AVISOS];
	cliente_init(arrayCliente, QTY_CLIENTES);
	aviso_init(arrayAviso,QTY_AVISOS);
	cliente_altaForzada(arrayCliente,QTY_CLIENTES,"Martin","Lopez","20-38515954-3");
	cliente_altaForzada(arrayCliente,QTY_CLIENTES,"Marcos","Reinoso","20-40304546-3");
	cliente_altaForzada(arrayCliente,QTY_CLIENTES,"Analia","Perez","20-20515954-2");
	cliente_altaForzada(arrayCliente,QTY_CLIENTES,"Juana","Perez","20-26304546-6");




	do
	{
			if(utn_getEntero("\n////////////////////////////////////////////////////////////////BIENVENIDO!!!!!!!!!!!!!!!!!!///////////////////////////////////////////////////////\n"
					         "///////1)-Cargar Cliente//////////////2)-Modificar Cliente//////////////3)-Dar de baja un Cliente////////4)-Realizar una Publicación//////////////"
			               "\n///////5)-Pausar Publicacion//////////6)-Reanudar Publicacion////////////7)-Imprimir Clientes/////////////8)-Realizar Informes////////////////////"
			               "\n/////////////////////////////////////////////////////////////////9)-Salir////////////////////////////////////////////////////////////////////////\n",
						   "\nError!!!! reingrese numero!!!", &opcionMenu,3,9,1)==0)
			{
				switch(opcionMenu)
				{
				case 1:
					cliente_alta(arrayCliente, QTY_CLIENTES);
					break;
				case 2:
					cliente_modificar (arrayCliente,QTY_CLIENTES);
					break;
				case 3:
					cliente_baja(arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
					break;
				case 4:
					aviso_alta(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
					break;
				case 5:
					aviso_pausarpublicacion (arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
					break;
				case 6:
					aviso_reaunudarpublicacion (arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
					break;
				case 7:
					cliente_imprimirAvisos(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
					break;
				case 8:
					menu_Consultas(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
					break;
				}
			}
	}while(opcionMenu !=9);
}
